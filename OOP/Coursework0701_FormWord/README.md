# Form Word

## Problem Statement

Design a class named `Form` to implement a word game. 

In the beginning, the system will give a certain word and the file name of a file that contains all the valid words. The player needs to use the letters in the given word to compose new words. 

The program should read the file and find out all the valid words composed by the given word and print them.

You are required to implement the following member functions:
* `void SetInputWord(string inputWord)`: This function sets the given word of the game.
* `void ProcessInputWord()`: This function performs some necessary pre-processing of the given word (e.g. upper or lower case transition).
* `void SetFileName(string fileName)`: This function sets the file name of the file that contains all the valid words.
* `void Load_CompareWord()`: This function loads the valid words from the file, and finds out all the valid words composed by the letters in the given word.
* `void PrintFoundWords()`: This function prints the words found in the function Load_CompareWord().

## Input
There is no specific input for this problem.

## Output
The program should output all the valid words composed by the letters in the given word, in the order they appear in the input file.
```
g
gi
gim
gin
gins
gis
gm
gn
gns
gs
i
ign
ignis
ii
im
imi
immi
immis
in
ing
ins
is
ising
ism
isn
iw
iwis
m
mg
mi
mig
migs
mim
mimi
miming
min
ming
mini
minim
minims
minis
mins
mis
mm
mn
ms
msg
mw
n
ng
ni
nig
nim
nims
nis
nisi
nm
ns
s
sg
si
sig
sign
sim
sin
sing
sm
sn
snig
sw
swig
swim
swimming
swing
w
wg
wi
wig
wigs
wim
win
wing
wings
wins
wis
wising
wm
ws
```

## Note
The comparison is not case-sensitive, but the output should keep the case of the original letters.

main.cpp
```cpp
int main()
{
	Form form1;
	form1.SetInputWord("SWIMMING"); // set input
	form1.ProcessInputWord(); // process input
	form1.SetFileName("word.txt"); // set file name
	form1.Load_CompareWord(); // read-in data and compare
	form1.PrintFoundWords(); // print answers
	return 0;
}
```

## Additional Information
* Medium, multiple programming grammars and structures are required.
* Solving time: 30 minutes
* Contributors: 謝公耀, 陳俊儒, 廖宣瑋
