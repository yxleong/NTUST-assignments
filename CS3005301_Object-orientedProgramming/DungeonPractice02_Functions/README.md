# Functions
This dungeon program implements character movement function which allows the user to control a character's movement within a specified movable range.

## Function Implementation
The program implements the following features:
* The initial position of the character is at `(0, 0)`.
* The character's movable range is (`[-4, 4]`, `[-4, 4]`).
* When `W`, `A`, `S`, and `D` are pressed, the character moves up, left, down, and right by one unit.
* After the move (whether successful or not), the program outputs the position of the character.
* The program continuously reads user input in a loop.
* The program moves the character's position based on user input.
* The program has a function to judge whether the character can move to the given (x, y) and correctly responds to user input.

## How to Play
To use the program, run it and enter `W`, `A`, `S`, or `D` to move the character up, left, down, or right, respectively. After each move, the program will output the position of the character. If the character reaches the movable range limits, it will not move any further in that direction.
