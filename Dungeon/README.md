# Dungeon Game
Welcome to Dungeon Game, an exciting adventure where you explore mazes, battle creatures, and collect items to aid you in your journey.

## How to Play
- Choose the game mode you prefer.
- Use the `W`, `A`, `S`, `D` to move your character `H` through the map.
- Explore the map to find valuable items `T`, `)` and `&`.
- Defeat or keep away creatures `B`, `G` and `W` when your character encounters them in map.
- Press `1` or `2` to save or load your game status when you want to stop or continue playing your game.
- Press `ESC` to exit the game.

## Game Progression
### Game Mode
- Basic Mode
    - Game with different difficulty levels
- Battle Mode
   - Game with different difficulty levels
   - Hero attack power is activated
- Custom Mode
    - Customize your dungeon maze size in normal mode

### Game Difficulty Level
- Easy Level
    - Map with only four walls 
- Normal Level
    - Map as a maze
- Hard Level
    - Maze with moving characters

## Game Object
### Hero
- Symbol: `B`
- Characteristics:
    - Attack Power: 10 (default)
    - Level: 1 (default)
    - Level up required experience: 15

### Creature
#### Bat
- Symbol: `B`
- Characteristics:
    - Attack Power: 10

#### Ghost
- Symbol: `G`
- Characteristics:
    - Attack Power: 5

#### Wolf
- Symbol: `W`
- Characteristics:
    - Attack Power: 20
    - Twice detect

### Item
#### Trigger
* Symbol: `T`
* Characteristics:
    * Award: experience +10

#### Weapon
* Symbol: `)`
* Characteristics:
    * Award: attack power +2

#### Potion
* Symbol: `&`
* Characteristics:
    * Award: health point +5

## REMINDERs
- Saving file name as "Easy", "Normal" and "Hard" are invalid.
- The map will be saved in folder `saveMap`.