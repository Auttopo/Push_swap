*This project has been created as part of the 42 curriculum by abenabde, jsam.*



# Push_swap

## Description

**push_swap** is a sorting project where the goal is to sort a list of integers using only two stacks (`a` and `b`) and a restricted set of operations.

The challenge is not only to sort correctly, but to minimize the number of operations while respecting the Push_swap operation model.

In our implementation, multiple sorting strategies are embedded, covering several complexity classes, and an **adaptive strategy based on a disorder metric and stack size** selects the most appropriate algorithm automatically.

A bonus **checker program** is also provided to verify the correctness of the generated operation sequences.

---

## Data Structure

To efficiently manage rotations and reverse rotations, both stacks are implemented as:

> **Circular doubly linked lists**

This structure allows:
- reverse rotations
- easy access to both top and bottom elements

Each node stores:
- the integer value
- its indexed rank (used by bucket and radix strategies)
- pointers to previous and next nodes


---

## Allowed Operations

Only the following operations are used:

- `sa`, `sb`,  — swap the first two elements
- `pa`, `pb` — push the top element between stacks
- `ra`, `rb`,  — rotate (top becomes bottom)
- `rra`, `rrb`,  — reverse rotate (bottom becomes top)

These operations are not performed, but their numbers are still counted for benchmark output:

- `ss`, `rr` ,`rrr` -- swap on the two stacks, rotate on the two stacks and reverse rotate on the two stacks

Each operation is printed followed by `\n` and nothing else.

---

## Instructions

### Compilation

```bash
make
```

### Execution

```bash
./push_swap 3 2 1
```

### Flags

Up to two flags are accepted:
- one strategy selector
- one benchmark flag

#### Strategy Selection

- `--simple`
- `--medium`
- `--complex`
- `--adaptive` (default)

#### Benchmark

- `--bench`

**Example:**

```bash
./push_swap --adaptive --bench 4 67 3 87 23
```

Benchmark data can be printed to stderr and operations to stdout, allowing piping to the checker_linux.

---

## Parsing and Error Handling

The program:
- Validates flags
- Parses all arguments as strings
- Splits allowed spaces (isspace)
- Validates integer format and overflow
- Detects duplicate values
- Builds the stack

Any invalid input or malloc failed results in:

```
Error\n
```

printed to stderr.

If no argument is given, nothing is printed.

---

## Disorder Metric and Adaptive Strategy

Before choosing an algorithm, the program computes a disorder metric between 0 and 1, estimating how far the stack is from being sorted.

This metric counts pairs of consecutive elements where the first element is greater than the second

### Selection Rules

#### Step 1 — Disorder Thresholds

| Disorder Range       | Strategy                |
|----------------------|-------------------------|
| 0   ≤ disorder < 0.2 | Simple strategy         |
| 0.2 ≤ disorder < 0.5 | Bucket / chunk strategy |
| 0.5 ≤ disorder ≥ 0.5 | Complex strategies      |

#### Step 2 — High Disorder Refinement

When disorder ≥ 0.5, algorithm selection depends on stack size:

| Stack Size | Algorithm |
|------------|-----------|
| 0 – 4 | Merge short version |
| 5 – 49 | Radix sort base 10 |
| ≥ 50 | Radix sort base 2 |

This enables efficient sorting tailored to the program's internal behavior and stack characteristics

---

## Implemented Algorithms

### Simple Strategy — Selection Sort Adaptation (O(n²))

**Files:** `selection.c`

**Method:**
- Find the minimum value in stack a
- Rotate in the shortest direction to bring the value to the top
- Push to stack b
- Repeat until stack a is empty
- Push everything back to stack a

**Complexity:**
- Each minimum search costs O(n)
- Repeated n times → O(n²)

---

### Medium Strategy — Bucket / Chunk Sorting (O(n√n))

**Files:** `buckets.c`, `buckets_utils.c`

**Method:**
- Values are normalized into ranks
- The range is divided into √n buckets and multiplied by 0.8 or 0.65 depending the stack size
- Elements of the smallest bucket indice are pushed to stack b, until all buckets are pushed
- Stack b is partially ordered during pushes
- All elements are returned to stack a in sorted order

**Complexity:**
- √n buckets
- O(√n) rotations per element on average
- Total → O(n√n)

---

### Complex Strategies — O(n log n)

#### Merge Short Version

**Files:** `merge.c`

Used for very small stacks when disorder is high.

A merge-inspired approach that splits and reinserts segments efficiently.

Upper bound complexity: O(n log n) in stack operation model.

#### Radix Sort — Base 10

**Files:** `radix.c`, `radix_utils.c`

Used for medium-size high-disorder stacks.

Sorting is done digit by digit using base 10. Each pass processes all elements.

**Complexity:** O(n log n)

#### Radix Sort — Base 2

**Files:** `radix.c`, `radix_utils.c`

Used for large high-disorder stacks.

Binary radix sorting based on bit positions of indexed values.

**Complexity:** O(n log n)

---

## Performance Targets

The project aims to satisfy official benchmarks:

### 100 Numbers
- **Pass:** < 2000 operations
- **Good:** < 1500 operations <-(reached)
- **Excellent:** < 700 operations

### 500 Numbers
- **Pass:** < 12000 operations
- **Good:** < 8000 operations <-(reached)
- **Excellent:** < 5500 operations

Bucket and radix strategies are responsible for reaching good and excellent levels.

---

## Bonus — Checker Program

A checker program is provided.

**Files:** `checker.c`, `checker_utils.c`, `get_next_line_bonus.c`

### Usage

```bash
./checker 3 2 1
```

The checker:
- reads instructions from stdin
- executes them on the stacks
- prints:
  - `OK` if stack a is sorted and stack b is empty
  - `KO` otherwise
  - `Error` if an instruction or argument is invalid

---

## Project Structure

### Core
- `main.c` — program entry and flag handling
- `parser.c` — argument parsing and validation
- `stack.c` — stack creation and memory management
- `rules1.c` — push, swap, rotate implementations
- `display.c` — operation output
- `disordermetric.c` — disorder computation

### Algorithms
- `selection.c` — O(n²) selection sort strategy
- `buckets.c`, `buckets_utils.c` — O(n√n) bucket strategy
- `merge.c` — merge short strategy
- `radix.c`, `radix_utils.c` — radix base 2 and base 10 strategies

### Bonus
- `checker.c`, `checker_utils.c` — checker program
- `get_next_line_bonus.c` — input reading

---

## Development Contributions

### abenabde
- Stack management
- Parsing and program structure
- Operation output
- Operation implementations
- Algorithms:
  - Selection sort (O(n²))
  - Bucket sorting (O(n√n))
  - Merge short version (O(n log n))

### jsam
- Stack management
- Operation implementations
- Checker program (structure and behavior)
- Disorder metric implementation
- Algorithms:
  - Radix base 2 (O(n log n))
  - Radix base 10 (O(n log n))

All code was developed collaboratively and tested using the official checker.

---

## Resources

AI tools were used to improve the clarity of the README and to help explain general concepts and development approaches.

### Algorithms
- [Radix sort - Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Merge sort - Wikipedia](https://en.wikipedia.org/wiki/Merge_sort)
- [Selection sort - Wikipedia](https://en.wikipedia.org/wiki/Selection_sort)
