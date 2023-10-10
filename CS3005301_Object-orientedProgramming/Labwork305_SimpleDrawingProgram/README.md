# Simple Drawing Program

## Problem Statement
Please design a simple drawing program (fill the background with `*`) allow users to draw square, isosceles right triangle and lines on the console. (for figures, fill with Upper `X`)

## Input
In the beginning, allow users to enter two integers separated by space to set the size of the drawing board (`m*n`). After that, enter the corresponding drawing code. First input the type of the figure, `S` indicates square, `T` indicates Isosceles right triangle and `L` indicates lines. Finally, input the parameter of the figure. Following is the required parameters of each type of figure:
- `S <w> <x> <y>`
  -  The integer `w` is the width and two integers (`x`, `y`) is the origin of the square.
  -  The direction of the square extends from top to bottom, from left to right.
- `T <w> <x> <y> <LU/LD/RU/RD>`
  -  Integer `w` is the length of hypotenuse. (`x`, `y`) is the origin of the triangle. 
  -  `LU` (Left Up), `LD` (Left Down), `RU` (Right Up) and `RD` (Right Down) indicates the side that the triangle faces. 
  -  Draw an equilateral triangle with side length `w` from point (`x`, `y`) that facing the specified direction.
- `L <x1> <y1> <x2> <y2>`
  - Input two pairs of integers separated by space, (`x1`, `y1`) and (`x2`, `y2`). 
  - Draw a line segment with (`x1`, `y1`) and (`x2`, `y2`) as the endpoints.
- `EXIT`
  -  Exit the program.

## Output
After drawing a figure or an error message, output a newline.

## Sample Input / Output：

### Sample Input
```
5 6
S 2 0 0
S 2 100 100
L 0 4 4 4
T 2 1 3 LU
EXIT
```

### Sample Output
```
XX***
XX***
*****
*****
*****
*****

Out of range.

XX***
XX***
*****
*****
XXXXX
*****

XX***
XX***
*X***
XX***
XXXXX
*****
```

## Note
![](https://i.imgur.com/mYaUXV7.png)
* The origin point `(0, 0)` of the drawing board is left up.
* If the figure to be drawn exceeds the boundary of the drawing board, print "Out of range".
* For any figure, if the given width is 1, draw the origin point.
* Output the drawing board after each command and separates each with an empty line.
* All the input data is drawable.

## Additional Information
* Medium, multiple programming grammars and structures are required.
* Solving time: 30 minutes
* Contributors: 謝宜杭, 林承達, 廖宣瑋
