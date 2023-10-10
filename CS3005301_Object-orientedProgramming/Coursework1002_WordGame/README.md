# Word Game

## Problem Statement
Word game is a popular puzzle game that involves finding words from a grid of randomly generated letters. Words must be at least three letters long and formed from neighboring letters. Letters are not allowed to be used more than once in one word, and it is valid to move diagonally.

As an example, consider the 4x4 grid of letters below:

| A | B | C | D |
|---|---|---|---|
| E | F | G | H |
| I | J | K | L |
| M | N | O | P |


The word "**FAB**" is valid (letters at the upper left region), and "**KNIFE**" is valid. "**BABE**" is invalid because it requires using "B" twice, and "**MINE**" is invalid because the "E" is not adjacent to the "N".

Write a program that uses a 4x4 two-dimensional array to represent the grid. The program will read the words from the text file **words.txt** and then use a recursive function to determine whether the word can be formed from the given grid or not. The program should output all the valid words in the text file.

## Input:
Each line contains 4 letters, and every 4 lines form a set for the game.
**All inputs are lowercase letters.**

## Output:
Output all the valid words in the text file for each game board given, and separate each game by an empty line.


## Sample Input / Output

### Input
```
abcd
efgh
ijkl
mnop
```
```
aabc
defg
hijk
llmn
```

### Output
```
abc
afb
fie
fin
fink
glop
ink
jim
knife
lop
min
mink
nim
pkg
plonk
pol
polk
```
```
abc
abed
afb
baa
baaed
bad
bade
bead
bed
bedim
dab
deaf
deb
dei
die
dill
dim
fad
fade
fed
fide
fie
fill
film
head
heil
hid
hide
hie
hied
hill
him
idea
ill
jill
jim
lid
lie
lied
lief
life
lim
limn
mid
mil
mill
```

## Additional Information
* Hard, need to use multiple program structures or complex data types.
* Solving time: 40 minutes
* Contributors: 謝公耀, 陳俊儒, 廖宣瑋, 葉定豪