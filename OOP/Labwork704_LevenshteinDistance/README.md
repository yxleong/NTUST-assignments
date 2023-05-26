# Levenshtein Distance

## Problem Statement
Levenshtein distance is a measurement of the degree of similarity between two words. It calculates the minimum number of steps required to transform one word into another by **inserting**, **deleting**, or **replacing** characters.

For example, the Levenshtein distance between "kiitten" and "sitting" is 4. There is no other way to make the switch with fewer steps.

1. `k`iitten -> `s`iitten (substitution of "s" for "k")
2. si`i`tten -> sitten (deletion of "i" at the third place of siitten)
3. sitt`e`n -> sitt`i`n (substitution of "i" for "e")
4. sittin -> sittin`g` (insertion of "g" at the end)

## Input
A series of words, with each pair of words forming a set. The program calculates the Levenshtein distance between each set of words.
```
Google
Facebook
```
```
Winter is coming
Here comes Winter
```
```
I am the bone of my sword. Steel is my body and fire is my blood. I have created over a thousand blades. Unknown to death. Nor known to life.
I am the bone of my code. Steel is my structure, and fire is my algorithm. I have fixed over a thousand bugs. Unknown to dawn. Nor known to night.
```

## Output
The program outputs the minimum distance between the two words in each set as `int`.
```
8
```
```
14
```
```
37
```

## Note
Uppercase and lowercase letters are considered different.

## Additional Information
* Easy, only basic programming syntax and structure are required.
* Solving time: 30 minutes
* Contributors: 溫勇威, 陳靖升, 鍾賢廣 