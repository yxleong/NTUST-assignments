# Minimum Height Trees

## Description
Given a tree with n nodes (labeled `0` to `n-1`) and an array representing `n-1` edges, where `Edge[i] = [ai, bi]` indicates an undirected edge between nodes `ai` and `bi` in the tree.

Choose any node as the root, and the corresponding representation of the tree varies when different roots are chosen.

Assuming choose `r` as the root node, the corresponding tree height is denoted as `h`. It is needed to design a program to find which nodes `r` (`r` may not be unique) result in the minimum value of `h`.

## Input
A list of `1 + (n - 1) * 2` integers separated by spaces, where the first integer `n` is the number of nodes in the tree, and then a list of `(n - 1) * 2` integers are the edges of the tree in the form of a pair of integers `(ai, bi)`.

### Constraints
- 1 <= n <= 100
- 0 <= ai, bi < n
- ai != bi

## Output
A list of nodes `r` (`r` may not be unique) that result in the minimum value of `h`. Return the list of all roots `r` in increasing order.

## Sample Input
```
4 1 0 1 2 1 3
```
```
6 3 0 3 1 3 2 3 4 5 4
```

## Sample Output
```
1
```
```
3 4
```