# Operator
This dungeon program implements operator overloading in the `Position` class. 

## Function Implementation
The required implementation includes the following overloaded operators:
* Position + Position 
* Position += Position 
* Position - Position 
* Position -= Position 
* Position * int 
* Position == Position 
* Position != Position

### Addition (+)
Addition operator overload adds two `Position` objects and returns the result as a new object.
```
Position delta;
delta = delta + Position(1, 0);
```

### Compound Addition (+=)
Compound addition operator overload adds a `Position` object to the current object and modifies the current object in place.
```
Position delta;
delta += Position(0, 1);
```

### Subtraction (-)
Subtraction operator overload subtracts two `Position` objects and returns the result as a new object.
```
Position delta;
delta = delta - Position(1, 0);
```

### Compound Subtraction (-=)
Compound subtraction operator overload subtracts a `Position` object from the current object and modifies the current object in place.
```
Position delta;
delta -= Position(0, 1);
```

### Multiplication (*)
Multiplication operator overload multiplies a `Position` object by an integer and returns the result as a new object.
```
if (cPos + dir * count == hPos) {
    return true;
}
```

### Equality operator (==)
Equality operator overload compares two `Position` objects for equality and returns `true` if their x and y values are equal, `false` otherwise.
```
if (cPos + dir * count == hPos) {
    return true;
}
```

### Inequality operator (!=)
Inequality operator overload that compares two `Position` objects for inequality and returns `true` if their x and y values are not equal, `false` otherwise.
```
if (!(hPos != sPos)) {
    hero.damage(power);
}
```
