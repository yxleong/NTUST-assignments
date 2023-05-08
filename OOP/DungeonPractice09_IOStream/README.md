# IO Stream

This dungeon project demonstrates the implementation of IO Stream in C++. The program is intended to read and write data from and to a file. It also implements operator overloading on the `Position` class, allowing it to be easily read and written from and to a file.

## Code Implementation
The following features are included in the program:
* **Archive Reading**: Read data from a file and store it in variables.
* **Canvas Size**: Read the canvas size from a file.
* **Canvas Configuration**: Read the canvas configuration from a file.
* **Hero Information**: Read the Hero's position, blood volume, level, experience value, and experience value required for an upgrade from a file.
* **Creature Information**: Read the Creature's location from a file.
* **Trigger Information**: Read the Trigger quantity and their respective locations from a file.
* **Operator Overloading**: Overload the `<<` and `>>` operators to enable input and output of `Position` objects using `iostream`.

## How to Play
To use the program, simply run it and provide the required input, which are `[Esc]` for **exit**, `1` for **save** file and `2` for **load** file. 

When prompted, input the **file name** to save/load the data. You can also input "**Exit**" to leave saving/loading. The program will read the input file and store the data in the appropriate variables.