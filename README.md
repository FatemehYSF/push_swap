*This project has been created as part of the 42 curriculum by fyousefi.*

# push_swap

## Description

**push_swap** is a sorting algorithm project that challenges you to sort a list of integers using two stacks and a limited set of operations, with the goal of achieving the minimum number of moves.

The project focuses on algorithmic thinking and optimization, requiring implementation of efficient sorting strategies using stack data structures. The program must validate input, store values in a stack, and output the sequence of operations needed to achieve a sorted stack A with minimal moves.

**Key concepts covered:**
- Algorithmic thinking and optimization
- Stack data structures (linked lists)
- Bitwise operations and radix sort
- Memory management (zero leaks)
- Clean, modular C programming

**Project goals:**
- Sort integers in ascending order using two stacks (A and B)
- Use only a limited set of operations (swap, push, rotate, reverse rotate)
- Minimize the number of operations required
- Handle edge cases and validate all input

---

## Instructions

### Prerequisites

- C compiler (cc/gcc)
- Make
- Standard C libraries

### Compilation

From the project root directory:

```bash
make
```

This will:
- Compile all source files
- Build the `libft` dependency
- Generate the `push_swap` executable

**Additional commands:**

```bash
make clean    # Remove object files
make fclean   # Remove object files and executable
make re       # Recompile everything from scratch
```

### Execution

Run the program with a list of integers as arguments:

```bash
./push_swap 3 2 1
```

**Output format:**
- One operation per line
- Printed to standard output
- No additional text or debug messages

**Example:**

```bash
./push_swap 3 2 1
```

Output:
```
sa
rra
```

### Error Handling

The program prints `Error` to standard error and exits if:
- Non-numeric arguments are provided
- Duplicate numbers exist
- Numbers exceed `INT_MIN` or `INT_MAX`
- Input is empty or malformed

**Example:**

```bash
./push_swap 1 2 abc
```

Output:
```
Error
```

---

## Operations

The program uses the following operations to sort the stacks:

| Operation | Description                          |
|-----------|--------------------------------------|
| `sa`      | Swap top two elements of stack A     |
| `sb`      | Swap top two elements of stack B     |
| `ss`      | `sa` and `sb` simultaneously         |
| `pa`      | Push top element from B to A         |
| `pb`      | Push top element from A to B         |
| `ra`      | Rotate stack A upward                |
| `rb`      | Rotate stack B upward                |
| `rr`      | `ra` and `rb` simultaneously         |
| `rra`     | Reverse rotate stack A downward      |
| `rrb`     | Reverse rotate stack B downward      |
| `rrr`     | `rra` and `rrb` simultaneously       |

---

## Algorithm Overview

### Sorting Strategy

The algorithm adapts based on input size for optimal performance:

| Stack Size | Strategy                                    |
|------------|---------------------------------------------|
| 1          | Already sorted (no operations)              |
| 2          | Single swap if needed                       |
| 3          | Optimized hardcoded sort (max 2 operations) |
| 4–5        | Push smallest values to B, then sort        |
| > 5        | Binary radix sort                           |

### Radix Sort Implementation

For larger inputs (more than 5 elements), the program uses **binary radix sort** on indexed values:

1. **Indexing:** Replace values with their sorted position (0 to n-1)
2. **Bit-by-bit sorting:**
   - For each bit position (from least to most significant):
     - If bit = 0 → push to stack B
     - If bit = 1 → rotate in stack A
   - Push all elements back from B to A
3. **Dynamic bit calculation:** Automatically handles any input size

**Time complexity:** O(n log n)

---

## Testing

### Using the Checker

Verify your output with the provided checker:

```bash
./push_swap 3 2 1 | ./checker_mac 3 2 1
```

Expected output: `OK` (if sorted correctly)

### Counting Operations

Check the number of operations performed:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
```

### Memory Leak Check

Use Valgrind to ensure no memory leaks:

```bash
valgrind --leak-check=full ./push_swap 3 2 1
```

### Random Testing

Generate random test cases:

```bash
ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')")
./push_swap $ARG | ./checker_mac $ARG
```

---

## Project Structure

```
push_swap/
├── src/
│   ├── check_utils.c
│   ├── errors.c
│   ├── fill_stack.c
│   ├── indexing.c
│   ├── parse.c
│   ├── push_swap_logic.c
│   ├── small_sort.c
│   ├── radix.c
│   ├── push_operations.c
│   ├── swap_operations.c
│   ├── rotate_operations.c
│   ├── rr_operations.c
│   ├── list_utils.c
│   └── node_utils.c
├── Libft/
├── push_swap.c
├── push_swap.h
├── Makefile
└── README.md
```

---

## Resources

**Classic References:**
- [42 push_swap subject PDF] - Official project requirements
- [Stack data structures](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) - Understanding stack operations
- [Radix sort algorithm](https://en.wikipedia.org/wiki/Radix_sort) - Conceptual foundation for the sorting approach
- [Bitwise operations in C](https://en.wikipedia.org/wiki/Bitwise_operation) - Understanding bit manipulation
- [Linked lists in C](https://www.learn-c.org/en/Linked_lists) - Implementation reference

**AI Usage:**

AI tools (ChatGPT/Claude) were used for the following purposes:
- **Documentation improvement:** Refining README structure, grammar, and clarity
- **Concept clarification:** Understanding radix sort principles and bitwise operations
- **Debugging assistance:** Explaining error messages and suggesting debugging approaches
- **Code review:** Requesting feedback on code structure and potential improvements

**Important note:** All algorithmic logic, implementation code, and debugging were performed independently. AI was used solely as a learning aid and documentation tool, not for generating core project code or solving algorithmic challenges.

---

## Notes

- **Norminette compliant:** Follows 42 coding standards
- **Allowed functions only:** No unauthorized library functions used
- **Strict output format:** Follows subject requirements exactly
- **Zero memory leaks:** All allocated memory is properly freed
- **Comprehensive error handling:** Validates all input and handles edge cases
