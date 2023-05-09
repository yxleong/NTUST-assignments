# Structures and Classes
This dungeon program implements the `Creature` class, which has its own location and icon. The program also includes functionality for detecting the Hero's location and moving the `Creature` accordingly.

## Function Implementation
The `Creature` class has the following properties:
* **location**: a tuple of integers representing the `Creature`'s location in the dungeon
* **icon**: a character representing the `Creature`'s icon in the dungeon

The class also has the following features:
* Check if the `Hero` is within 2 vertical, horizontal, and diagonal lines of the `Creature`.
* Move the `Creature` towards the `Hero` if the `Hero` is in the line of sight.
* Move the `Creature` randomly up, down, left, or right if the `Hero` is not in the line of sight.

The `Hero` class is not modified and can be controlled normally in the dungeon.

## How to Play
To use the program, simply run it and press the `W`, `S`, `A`, `D` keys to move the `Hero`. If `Hero` is detected, the `Creature` will move towards the `Hero`, otherwise, the `Creature` will move randomly.