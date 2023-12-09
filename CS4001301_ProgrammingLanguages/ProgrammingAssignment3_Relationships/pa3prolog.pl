% Discontiguous directives
:- discontiguous female/1. % one parameter
:- discontiguous male/1.
:- discontiguous parent/2. % two parameter

mother(X, Y) :- female(X), parent(X, Y).
% X is female
% X is parent of Y

father(X, Y) :- male(X), parent(X, Y).

daughter(X, Y) :- female(X), parent(Y, X).
% X is female
% Y is parent of X

son(X, Y) :- male(X), parent(Y, X).

child(X, Y) :- parent(Y, X).

sister(X, Y) :- female(X), sibling(X, Y).

brother(X, Y) :- male(X), sibling(X, Y).

sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.
% Z is parent of X and Y
% X is not Y

uncle(X, Y) :- male(X), sibling(X, Z), parent(Z, Y).
% X is sibling of Z
% Z is parent of Y

aunt(X, Y) :- female(X), sibling(X, Z), parent(Z, Y).

cousin(X, Y) :- parent(Z, X), sibling(Z, W), parent(W, Y), X \= Y.
% Z is parent of X
% Z is sibling of W
% W is parent of Y
% X is not Y

% Facts given
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