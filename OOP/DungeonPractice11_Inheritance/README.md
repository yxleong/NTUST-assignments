# Inheritance
This dungeon project is to inherit different hostile creatures under the original `Creature`.

The following hostile creatures can be encountered in the dungeon, each represented by a different symbol and having different characteristics:

### Bat
- Symbol: `B`
- Characteristics:
    - Attack Power: 10

### Ghost
- Symbol: `G`
- Characteristics:
    - Attack Power: 5

### Wolf
- Symbol: `W`
- Characteristics:
    - Attack Power: 20
    - Twice detect

## Creature Management
All creatures, including the original `Creature` class and its hostile subclasses, are managed using a `Creature**` array. 

This allows for unified management of different creature types within the game.