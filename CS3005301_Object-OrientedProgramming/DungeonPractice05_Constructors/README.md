# Constructors
This project implements classes `Hero` and `Trigger` for a dungeon game. Each class has specific methods to update the game state and handle interactions between objects.

## Function Implementation
### Trigger Class
* A constructor initializes the `Trigger` object with the given `x` and `y` coordinates and **experience** points value.
* An `update(Hero&)` function that increases the experience points of `Hero` object once `Hero` object has passed the `Trigger`.

### Hero Class
* Increases the level of `Hero` once `Hero`'s experience points value is increased by the specified amount 10.
* Reduces the `Hero`'s blood volume once Hero encounters `Creature`.