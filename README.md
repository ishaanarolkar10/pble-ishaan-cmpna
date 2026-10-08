# Fractional Knapsack (Greedy Method) in C

A C program that solves the **Fractional Knapsack problem** using the greedy approach. Items are sorted by profit-to-weight ratio with **merge sort**, then picked in that order until the knapsack is full. The last item may be taken partially.

## How it works

1. Read the number of items `n` and the knapsack capacity.
2. For each item, read its profit and weight, and compute `ratio = profit / weight`.
3. Sort all items by ratio in **descending** order using merge sort.
4. Go through the sorted items:
   - If the whole item fits, take it fully and reduce the remaining capacity.
   - Otherwise, take only the fraction that fits (`ratio * remaining capacity`) and stop.
5. Print the maximum profit.

## Complexity

| Part | Time | Space |
|------|------|-------|
| Merge sort | O(n log n) | O(n) |
| Greedy selection | O(n) | O(1) |
| **Overall** | **O(n log n)** | **O(n)** |

## Files

- `fractional_knapsack.c` – source code
- `README.md` – this file

## Compile and run

```bash
gcc fractional_knapsack.c -o fractional_knapsack
./fractional_knapsack
```

On Windows (MinGW):

```bash
gcc fractional_knapsack.c -o fractional_knapsack.exe
fractional_knapsack.exe
```

## Input format

- Number of items, then knapsack capacity.
- For each item, enter **profit first, then weight**, separated by a space.

## Sample run

```
Enter number of items: 3
Enter capacity of knapsack: 50
Enter profit and weight of item 1: 60 10
Enter profit and weight of item 2: 100 20
Enter profit and weight of item 3: 120 30
Maximum profit = 240.00
```

Items 1 and 2 are taken fully (profit 160, weight 30). The remaining capacity of 20 takes two thirds of item 3, adding 80, for a total of 240.

## Limitations

- Supports up to 100 items (fixed-size arrays).
- Weights must be greater than zero, since the ratio divides by weight.
- No input validation is performed.

## Author

Girish Awade  
Computer Engineering, Vidyalankar Institute of Technology, Wadala
