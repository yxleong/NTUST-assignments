Relationships
=====================================================================

## Problem description

Follow the directions and include any queries requested. 

Complete the following predicates so that they correctly model the relationships between the people listed below as facts.
```
mother(X, Y) :-

father(X, Y) :-

daughter(X, Y) :-

son(X, Y) :-

child(X, Y) :-

sister(X, Y) :-

brother(X, Y) :-

sibling(X, Y) :-

uncle(X, Y) :-

aunt(X, Y) :-

cousin(X, Y) :-
```

Do not modify the following facts. Complete the predicates above so that they work with the following facts.
```
female(annie).
parent(annie, janny).
parent(annie, richard).
parent(annie, joan).

male(dylan).

male(ronnie).

female(leo).

female(haru).

female(janny).
parent(janny, leo).
parent(janny, ronnie).

female(joan).
parent(joan, haru).

male(mark).
parent(mark, janny).
parent(mark, richard).

male(mel).
parent(mel, joan).

male(richard).
parent(richard, dylan).
parent(richard, rose).

female(rose).
```

Show that using the rules by inferring that `dylan`, `rose` and `haru` are `leo`'s `cousin`s, and that `leo` and `ronnie` are one-another's `brother` and `sister`.

Also create queries that test all predicates.
