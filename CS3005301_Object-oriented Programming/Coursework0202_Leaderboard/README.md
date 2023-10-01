# Leaderboard

## Problem Statement
Given a text file *scores.txt* that contains player scores for a game, write a function named `getHighScores` that takes two array parameters: an array of strings and an array of integers. The function should scan through the file and set the string array entry at index 0 to the name of the player with the highest score and set the integer array entry at index 0 to the score of the player with the highest score. The string array entry at index 1 should be set to the name of the player with the second highest score, and the integer array entry at index 1 should be set to the score of the player with the second highest score. Do the same for the entries at index 2. Together, these two arrays give you the names and scores of the top three players.

### Input

The input file `scores.txt` contains player's scores for a game.

### Output

Output the names and scores of the top three players.

### Sample Input / Output

Input:
```
scores.txt
```
Output:
```
Pele
12300
Ronaldo
10400
Didier
9800
```

## Note
* The input file scores.txt is provided.
* This problem requires defining a `getHighScores` function that takes two parameters: an array of strings and an array of integers. The function reads all the data in the input file and finds the top three players' names and scores. Call this function in `main` and output the top three players and scores.
* The problem does not consider ties.

## Additional Information
* Easy, only basic programming language syntax and structure are needed.
* Solving time: 20 minutes
* Contributors: 陳俊儒, 林承達, 廖宣瑋
