# Recursive
This dungeon project implements a dungeon map generation by using division recursion.

## Function implementation
The [Recursive Division](https://weblog.jamisbuck.org/2011/1/12/maze-generation-recursive-division-algorithm) algorithm is a method for generating mazes, particularly known for its fractal nature. It starts with an empty field and bisects it with a wall either horizontally or vertically. A single passage is added through the wall. This process is repeated recursively on each side of the wall until the desired resolution is reached.

Here's a step-by-step explanation of how the algorithm works:
1. Begin with an empty field.
1. Bisect the field with a wall, either horizontally or vertically. Add a single passage through the wall.
1. Repeat step #2 with the areas on either side of the wall.
1. Continue recursively until the maze reaches the desired resolution.

At each step, a valid maze is obtained, and each repetition of the algorithm increases the level of detail. The algorithm quickly converges, even on larger grids.

A recursive function `void recursiveDivision(int startRow, int endRow, int startCol, int endCol, bool isHorizontal)` is implemented as above, however, **an extra passage through the wall is added** to avoid seperated area disconnected. 

## How to Play
To use the program, run it and the maze form dungeon map will be generated with a path from the upper left corner to the lower right corner.
