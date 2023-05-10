# Strings
This dungeon project implements Hero movement by string input.

## Function implementation
The program reads a whole line of input and checks for the following formats:
* `Move (a,b)`: If the specified coordinates are within 1 unit of the current position, the character can be moved to the new position.
* `Jump (a,b)`: The character will jump directly to the specified coordinates.
* `Exit`: The program will exit.
* `W`,`A`,`S`,`D`: If the input is not in any of the above formats, the program will look at the **last** character of the line and decide whether to move the character up, down, left, or right based on W, A, S, or D respectively.

## How to Play
To use the program, run it and enter input in one of the four supported formats mentioned above. The program will then perform the corresponding action based on the input.

Note that for the `Move` and `Jump` formats, the specified coordinates should be within the movable range of the character.

To exit the program, simply enter "**Exit**".
