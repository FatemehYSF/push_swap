#!/bin/bash

# Colors
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
MAGENTA='\033[0;35m'
NC='\033[0m' # No Color

# Counters
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0
LEAK_TESTS=0
NO_LEAKS=0

# Push_swap executable
PUSH_SWAP="./push_swap"

# Check for valgrind
VALGRIND_AVAILABLE=0
if command -v valgrind &> /dev/null; then
    VALGRIND_AVAILABLE=1
    echo -e "${GREEN}✓ Valgrind detected - Memory leak testing enabled${NC}"
else
    echo -e "${YELLOW}⚠ Valgrind not found - Memory leak testing disabled${NC}"
    echo -e "${YELLOW}  Install with: sudo apt-get install valgrind${NC}"
fi

echo -e "${BLUE}================================${NC}"
echo -e "${BLUE}   PUSH_SWAP TESTER (Mandatory)${NC}"
echo -e "${BLUE}  With Memory Leak Detection${NC}"
echo -e "${BLUE}================================${NC}\n"

# Check if push_swap exists
if [ ! -f "$PUSH_SWAP" ]; then
    echo -e "${RED}Error: push_swap executable not found!${NC}"
    echo "Please compile first: make"
    exit 1
fi

# Test function without valgrind
run_test() {
    local test_name="$1"
    local args="$2"
    local expected_result="$3"  # "sorted" or "error"
    local max_ops="$4"
    
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    # Run push_swap
    output=$($PUSH_SWAP $args 2>&1)
    exit_code=$?
    
    # Count operations
    op_count=$(echo "$output" | wc -l)
    if [ -z "$output" ]; then
        op_count=0
    fi
    
    # Check for errors
    if [[ "$output" == *"Error"* ]]; then
        if [ "$expected_result" == "error" ]; then
            echo -e "${GREEN}✓${NC} $test_name - ${GREEN}Correctly detected error${NC}"
            PASSED_TESTS=$((PASSED_TESTS + 1))
        else
            echo -e "${RED}✗${NC} $test_name - ${RED}Unexpected error${NC}"
            FAILED_TESTS=$((FAILED_TESTS + 1))
        fi
        return
    fi
    
    # If expecting error but didn't get one
    if [ "$expected_result" == "error" ]; then
        echo -e "${RED}✗${NC} $test_name - ${RED}Should have thrown error${NC}"
        FAILED_TESTS=$((FAILED_TESTS + 1))
        return
    fi
    
    # Check if operations limit is respected
    if [ ! -z "$max_ops" ] && [ $op_count -gt $max_ops ]; then
        echo -e "${YELLOW}⚠${NC} $test_name - ${YELLOW}Too many operations: $op_count (max: $max_ops)${NC}"
        FAILED_TESTS=$((FAILED_TESTS + 1))
        return
    fi
    
    echo -e "${GREEN}✓${NC} $test_name - ${GREEN}OK${NC} (ops: $op_count)"
    PASSED_TESTS=$((PASSED_TESTS + 1))
}

# Test function with valgrind
run_test_valgrind() {
    local test_name="$1"
    local args="$2"
    
    LEAK_TESTS=$((LEAK_TESTS + 1))
    
    # Run with valgrind
    valgrind_output=$(valgrind --leak-check=full --error-exitcode=1 --quiet \
                      $PUSH_SWAP $args 2>&1)
    exit_code=$?
    
    # Check for leaks (valgrind returns 1 if leaks detected)
    if [ $exit_code -eq 1 ]; then
        echo -e "${RED}✗ LEAK${NC} $test_name - ${RED}Memory leak detected!${NC}"
        echo -e "${RED}$valgrind_output${NC}"
        return 1
    else
        echo -e "${GREEN}✓ LEAK${NC} $test_name - ${GREEN}No leaks${NC}"
        NO_LEAKS=$((NO_LEAKS + 1))
        return 0
    fi
}

echo -e "${BLUE}=== Error Handling ===${NC}"
run_test "Non-numeric input" "1 2 three" "error"
run_test "Duplicate numbers" "1 2 2 3" "error"
run_test "Number too large" "2147483648" "error"
run_test "Number too small" "-2147483649" "error"
run_test "Invalid character" "1 2 3a" "error"
run_test "Empty argument" '""' "error"
run_test "Only spaces" '"   "' "error"
run_test "Leading zeros" "01 02 03" "sorted"

echo -e "\n${BLUE}=== Already Sorted ===${NC}"
run_test "Single number" "42" "sorted" 0
run_test "Two sorted" "1 2" "sorted" 0
run_test "Three sorted" "1 2 3" "sorted" 0
run_test "Five sorted" "1 2 3 4 5" "sorted" 0
run_test "Ten sorted" "1 2 3 4 5 6 7 8 9 10" "sorted" 0

echo -e "\n${BLUE}=== Two Numbers ===${NC}"
run_test "Two reversed" "2 1" "sorted" 1

echo -e "\n${BLUE}=== Three Numbers ===${NC}"
run_test "3-2-1" "3 2 1" "sorted" 3
run_test "2-3-1" "2 3 1" "sorted" 2
run_test "3-1-2" "3 1 2" "sorted" 2
run_test "2-1-3" "2 1 3" "sorted" 1
run_test "1-3-2" "1 3 2" "sorted" 2

echo -e "\n${BLUE}=== Five Numbers ===${NC}"
run_test "5-4-3-2-1" "5 4 3 2 1" "sorted" 12
run_test "2-5-3-1-4" "2 5 3 1 4" "sorted" 12
run_test "3-1-5-2-4" "3 1 5 2 4" "sorted" 12

echo -e "\n${BLUE}=== Edge Cases ===${NC}"
run_test "Negative numbers" "-5 -2 -8 -1" "sorted" 12
run_test "Mix pos/neg" "-2 5 -8 3 0" "sorted" 12
run_test "INT_MIN & INT_MAX" "-2147483648 2147483647" "sorted" 1
run_test "Zero included" "0 -1 1" "sorted" 3
run_test "All negative" "-10 -5 -20 -1 -15" "sorted" 12

echo -e "\n${BLUE}=== Performance Tests ===${NC}"

# 100 numbers - 3 tests
for i in {1..3}; do
    ARG=$(seq 1 100 | shuf | tr '\n' ' ')
    run_test "100 random #$i" "$ARG" "sorted" 1100
done

# 500 numbers - 2 tests
for i in {1..2}; do
    ARG=$(seq 1 500 | shuf | tr '\n' ' ')
    run_test "500 random #$i" "$ARG" "sorted" 7000
done

# Memory leak tests
if [ $VALGRIND_AVAILABLE -eq 1 ]; then
    echo -e "\n${MAGENTA}================================${NC}"
    echo -e "${MAGENTA}   MEMORY LEAK TESTS (Valgrind)${NC}"
    echo -e "${MAGENTA}================================${NC}\n"
    
    echo -e "${MAGENTA}=== Basic Leak Tests ===${NC}"
    run_test_valgrind "Empty (no args)" ""
    run_test_valgrind "Single number" "42"
    run_test_valgrind "Two numbers" "2 1"
    run_test_valgrind "Three numbers" "3 2 1"
    run_test_valgrind "Five numbers" "5 4 3 2 1"
    run_test_valgrind "Already sorted" "1 2 3 4 5"
    
    # echo -e "\n${MAGENTA}=== Error Case Leaks ===${NC}"
    # run_test_valgrind "Duplicate leak test" "1 2 2 3"
    # run_test_valgrind "Invalid input leak" "1 2 abc"
    # run_test_valgrind "Overflow leak" "2147483648"
    # run_test_valgrind "Underflow leak" "-2147483649"
    
    echo -e "\n${MAGENTA}=== Medium Stack Leaks ===${NC}"
    ARG=$(seq 1 10 | shuf | tr '\n' ' ')
    run_test_valgrind "10 numbers" "$ARG"
    
    ARG=$(seq 1 50 | shuf | tr '\n' ' ')
    run_test_valgrind "50 numbers" "$ARG"
    
    echo -e "\n${MAGENTA}=== Large Stack Leaks ===${NC}"
    ARG=$(seq 1 100 | shuf | tr '\n' ' ')
    run_test_valgrind "100 numbers" "$ARG"
    
    ARG=$(seq 1 500 | shuf | tr '\n' ' ')
    echo -e "${YELLOW}Testing 500 numbers with valgrind (this may take a minute...)${NC}"
    run_test_valgrind "500 numbers" "$ARG"
    
    echo -e "\n${MAGENTA}=== Edge Case Leaks ===${NC}"
    run_test_valgrind "Negative numbers" "-5 -2 -8 -1"
    run_test_valgrind "INT limits" "-2147483648 0 2147483647"
    run_test_valgrind "Mixed signs" "-100 -50 0 50 100"
fi

# Summary
echo -e "\n${BLUE}================================${NC}"
echo -e "${BLUE}         TEST SUMMARY${NC}"
echo -e "${BLUE}================================${NC}"
echo -e "Functionality tests:  $TOTAL_TESTS"
echo -e "${GREEN}  Passed:             $PASSED_TESTS${NC}"
echo -e "${RED}  Failed:             $FAILED_TESTS${NC}"

if [ $VALGRIND_AVAILABLE -eq 1 ]; then
    echo -e "\nMemory leak tests:    $LEAK_TESTS"
    echo -e "${GREEN}  No leaks:           $NO_LEAKS${NC}"
    echo -e "${RED}  Leaks detected:     $((LEAK_TESTS - NO_LEAKS))${NC}"
fi

# Final result
echo -e "\n${BLUE}================================${NC}"
if [ $FAILED_TESTS -eq 0 ] && { [ $VALGRIND_AVAILABLE -eq 0 ] || [ $((LEAK_TESTS - NO_LEAKS)) -eq 0 ]; }; then
    echo -e "${GREEN}🎉 All tests passed! 🎉${NC}"
    if [ $VALGRIND_AVAILABLE -eq 1 ]; then
        echo -e "${GREEN}✓ No memory leaks detected!${NC}"
    fi
    exit 0
else
    if [ $FAILED_TESTS -gt 0 ]; then
        echo -e "${RED}❌ $FAILED_TESTS functionality test(s) failed${NC}"
    fi
    if [ $VALGRIND_AVAILABLE -eq 1 ] && [ $((LEAK_TESTS - NO_LEAKS)) -gt 0 ]; then
        echo -e "${RED}❌ $((LEAK_TESTS - NO_LEAKS)) memory leak(s) detected${NC}"
    fi
    exit 1
fi