# Shisensho

## Problem Statement
Shisensho is a classic tile-matching game where the objective is to match all pairs and clear the board. The game follows specific rules for connecting and eliminating tiles.

### Rules

- Players choose a pair of identical tiles to connect.
- The connection path must not exceed **two turns**.
- If the requirements are met, the two tiles will be eliminated.
- The player's task is to eliminate all tiles on the board.
- The game is over if future moves are not possible and tiles are left on the board, or if the player successfully removes all tiles.

### Connection Path Examples
The legal patterns for the connection path are shown as follows:

![https://hackmd.io/_uploads/HkWh0W0r3.png](https://github.com/yxleong/NTUST-assignments/blob/main/CS3005301_Object-OrientedProgramming/Labwork706_Shisensho/1.png)![https://hackmd.io/_uploads/rJE3AZCS3.png](https://github.com/yxleong/NTUST-assignments/blob/main/CS3005301_Object-OrientedProgramming/Labwork706_Shisensho/2.png)![https://hackmd.io/_uploads/S183Rb0B3.png](https://github.com/yxleong/NTUST-assignments/blob/main/CS3005301_Object-OrientedProgramming/Labwork706_Shisensho/3.png)![https://hackmd.io/_uploads/B1dnAbArh.png](https://github.com/yxleong/NTUST-assignments/blob/main/CS3005301_Object-OrientedProgramming/Labwork706_Shisensho/4.png)


To simplify the game, we start with a 6x6 board and only have 9 different symbols represented by characters '1' to '9'.

## Input

### Beginning

- A 6x6 grid of characters representing the initial symbols on the board.

### Loop

- A pair of coordinates on the board represented by four integers: (`pos1.x`, `pos1.y`, `pos2.x`, `pos2.y`).

### Sample Input
```
9 2 4 8 9 7
6 9 1 7 1 5
5 3 3 7 2 2
3 4 7 1 9 5
4 6 8 8 2 6
6 5 1 4 3 8
2 1 3 3
3 1 3 2
2 1 3 3
5 1 5 3
1 1 4 3
0 1 5 4
3 0 3 4
```

## Output
The result message for each given pair: "**bad pair**" if the pair is not legal, or "**pair matched**" if the pair is legal and the tiles are eliminated.

The status of the board (the remaining tiles) should always be updated when a legal pair is found. Therefore, the same input may have different results over time.

### Sample Output
```
bad pair
pair matched
pair matched
pair matched
pair matched
bad pair
pair matched
```

## Note
The connection path is not restricted by the size of the board.

## Additional Information
* Medium, multiple programming grammars and structures are required.
* Solving time: 35 minutes
* Contributors: SHANG-YAN XUN
