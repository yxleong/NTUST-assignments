# Exception Handling
This dungeon project is to implement exception handling using **try**, **throw**, and **catch**.

## Function Implementation
The class `MyException` inherited from standard library exception class `std::exception` are declared with member variable `message` to handle the exception.

## Implemented of code
Kindly refer to source code below:
> MyException.h
> MyException.cpp

For `main.cpp`, kindly refer to the lines:
```cpp=13
#include "MyException.h"
```
```cpp=112
// Execute the game loop
if (timeFrame >= gTimeLog) {
    try {
        update(gKeyState);
    }
    catch (MyException& error) {
        std::cout << error.message;
        draw();
        drawInfo();
    }
    startT = clock();
}
```
```cpp=504
if (allInvalid) {
    MyException errorMessage("Invalid input\n");
    throw errorMessage;
}
```
For `Hero.h`, kindly refer to the lines:
```cpp=12
#include "MyException.h"
```
For `Hero.cpp`, kindly refer to the lines:
```cpp=145
if (isPositionValid(next)) {
    this->sPos = next;
}
else {
    MyException errorMessage("Invalid location\n");
    throw errorMessage;
}
```

## How to Play
To use the program, simply run it. Press `W`, `A`, `S`, or `D` to move Hero. 

When moving towards a wall, the program will raise an exception and output the message "**Invalid location**".

If any inappropriate input is detected, the program will handle it by raising an exception and outputting the message "**Invalid input**".

