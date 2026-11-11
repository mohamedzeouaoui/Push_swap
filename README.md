*This project has been created as part of the 42 curriculum by mzeouaou.*

<h1 align="center">Push_swap</h1>

<p align="center">
  <em>Because Swap_push isn't as natural.</em><br>
  Sort a stack of integers using two stacks and the smallest possible number of operations.
</p>

<p align="center">
  <img alt="Language" src="https://img.shields.io/badge/language-C-blue">
  <img alt="Norm" src="https://img.shields.io/badge/norminette-passing-brightgreen">
  <img alt="42" src="https://img.shields.io/badge/school-42-black">
</p>

---

## Table of Contents

- [Description](#description)
- [Installation](#installation)
- [Usage](#usage)
- [The Operations](#the-operations)
- [Performance](#performance)
- [Algorithm](#algorithm)
- [Project Structure](#project-structure)
- [Error Handling](#error-handling)
- [Testing](#testing)
- [Author](#author)
- [Resources](#resources)

---

## Description

**Push_swap** is an algorithmic 42 project. You get a list of integers in a stack called **a**, and an empty stack called **b**. The goal is to sort `a` in ascending order (smallest number on top) using only a fixed set of operations, and to print the **shortest possible list of instructions**.

The program is judged on two things: it must always sort correctly, and it must do so in as few moves as possible.

## Installation

```bash
git clone https://github.com/mohamedzeouaoui/Push_swap.git
cd Push_swap
make
```

### Makefile rules

| Rule          | Description                                  |
|---------------|----------------------------------------------|
| `make`        | Compile `push_swap`                          |
| `make bonus`  | Compile the `checker` program (if implemented) |
| `make clean`  | Remove object files                          |
| `make fclean` | Remove object files and executables          |
| `make re`     | Recompile from scratch                       |

## Usage

Pass the numbers as arguments, or as a single quoted string:

```bash
./push_swap 2 1 3 6 5 8
./push_swap "2 1 3 6 5 8"
```

The program prints the instructions, one per line:

```text
pb
pb
sa
pa
pa
...
```

Count the moves, and check the result with the checker:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG      # prints OK or KO
```

## The Operations

| Operation | Name                  | Description                                          |
|-----------|-----------------------|------------------------------------------------------|
| `sa`      | swap a                | Swap the first two elements of stack `a`             |
| `sb`      | swap b                | Swap the first two elements of stack `b`             |
| `ss`      | swap both             | `sa` and `sb` at the same time                       |
| `pa`      | push a                | Move the top element of `b` onto `a`                 |
| `pb`      | push b                | Move the top element of `a` onto `b`                 |
| `ra`      | rotate a              | Shift all elements of `a` up by one (first becomes last) |
| `rb`      | rotate b              | Shift all elements of `b` up by one                  |
| `rr`      | rotate both           | `ra` and `rb` at the same time                       |
| `rra`     | reverse rotate a      | Shift all elements of `a` down by one (last becomes first) |
| `rrb`     | reverse rotate b      | Shift all elements of `b` down by one                |
| `rrr`     | reverse rotate both   | `rra` and `rrb` at the same time                     |

## Performance

The number of instructions is graded against these thresholds:

| Size of the list | Goal                                      |
|------------------|-------------------------------------------|
| 3 numbers        | No more than 3 instructions               |
| 5 numbers        | No more than 12 instructions              |
| 100 numbers      | Fewer than 700 instructions for the maximum score |
| 500 numbers      | Fewer than 5500 instructions for the maximum score |

> Add your own average results here, for example "100 numbers: ~600 moves, 500 numbers: ~5000 moves".

## Algorithm

The program picks a strategy depending on the size of the list:

- **2 numbers**: a single `sa` if needed.
- **3 numbers**: a hard-coded sort, with at most 2 moves.
- **5 numbers or fewer**: push the smallest values to `b`, sort the 3 remaining on `a`, then push back.
- **Larger lists**: values are first **normalized to indexes** (`0` to `n - 1`), then sorted with the main algorithm, which pushes elements between the two stacks while minimizing the number of rotations at each step.

> Replace this section with the exact algorithm you used (radix sort, chunk sort, Turk algorithm, and so on), and explain its main idea in a few lines.

## Project Structure

```text
Push_swap/
├── Makefile
├── push_swap.h           # Structures and prototypes
├── main.c                # Entry point
├── ...                   # Parsing, operations, small sorts, main sort, utils
└── checker               # Bonus program
```

> Adjust this tree to match your own files.

## Error Handling

On any error, the program prints `Error` followed by a newline on the **standard error** and exits. Errors include:

- Arguments that are not integers
- Numbers bigger than `INT_MAX` or smaller than `INT_MIN`
- Duplicate numbers

Special cases:

- No arguments: the program prints nothing and returns the prompt
- Already sorted list: the program prints nothing

## Testing

```bash
# Random list of 100 numbers
ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG

# Check for leaks
valgrind --leak-check=full ./push_swap $ARG
```

Edge cases worth testing:

- `./push_swap 0 -1 2147483647 -2147483648`
- `./push_swap 1 1 2` (duplicate, must print `Error`)
- `./push_swap 1 a 3` (not a number, must print `Error`)
- `./push_swap ""` and `./push_swap " "`
- Lists that are already sorted or sorted in reverse
- A single number
- Mixed quoted and unquoted arguments

Community testers:

- [push_swap_tester](https://github.com/LeoFu9487/push_swap_tester)
- [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)

## Author

- **Mohamed Zeouaoui**: [@mohamedzeouaoui](https://github.com/mohamedzeouaoui)

## Resources

- [Push_swap: a visual explanation of sorting algorithms](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- The 42 Norm

### Use of AI

> Describe here how AI was used in this project (which tasks, which parts), and what you checked and understood yourself.
