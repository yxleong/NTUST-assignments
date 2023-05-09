# The Translation Machine

## Problem Statement
In this problem, there is a translation machine that can translate letters from one to another based on a set of rules. A list of word pairs will be given and need to verify whether the words in each pair match. Two words match if they have the same length and if each letter of the first word can be turned into the corresponding letter of the second word by using the available translations zero or more times.

### Input
The input contains several test cases, each of them as described below. The first line of input contains two integers `m` (**1 ≤ m ≤ 500**) and `n` (**1 ≤ n ≤ 50**), where `m` is the number of translations of letters and `n` is the number of word pairs. Each of the next `m` lines contains two distinct space-separated letters `a` and `b`, indicating that the letter `a` can be translated to the letter `b`. Each ordered pair of letters `(a, b)` appears at most once. Following this are `n` lines, each containing a word pair to check. Translations and words use only lowercase letters ‘`a`’…‘`z`’, and each word contains at least 1 and at most 50 letters. Exit the program while `m` and `n` are **both 0**.

### Output
For each pair of words, display ‘**yes**’ if the two words match, and ‘**no**’ otherwise, on a line by itself.

## Sample Input / Output

### Input
```
9 5
c t
i r
k p
o c
r o
t e
t f
u h
w p
we we
can the
work people
it of
out the
3 3
a c
b a
a b
aaa abc
abc aaa
acm bcm
0 0

```

### Output
```
yes
no
no
yes
yes
yes
no
yes

```

## Additional Information
* Medium, multiple programming grammars and structures are required.
* Solving time: 40 minutes
* Contributors: Cheryl Huang