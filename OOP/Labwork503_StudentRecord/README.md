# Advanced Class Point

## Problem Statement

The type `Point` is a fairly simple data type, but under another name (the template class pair) this data type is defined and used in the C++ Standard Template Library, although you need not know anything about the Standard Template Library to do this exercise. Write a definition of a class named `Point` that might be used to store and manipulate the location of a point in the plane. You will need to declare and implement the following member functions:

- A member function `Set` that sets the private data after an object of this class is created. Attention! The data must be an array of float in size 2, initialized by zero.
- A member function named `Move` to move the point along the horizontal and vertical directions specified by the first and second arguments.
- A member function named `Rotate` to rotate the point by 90 degrees clockwise around the origin.
- A member function named `Reflect` to reflect point in the origin.
- Two const getter functions to retrieve the current coordinates of the point (horizontal and vertical).
- A copy constructor used to copy value of other point.
- A destructor used to release memory before the instance of class destroyed. Avoiding memory leak!

### Input

There is no input required. You need to implement `Point.h` and `Point.cpp` classes.

### Output

Your program should output the following lines to stdout, after executing `main()`:
```
0 5
0 -5
1 -3
-3 -1
Copy point:
-3 -1
```

### Note
main.cpp
```cpp
#include<iostream>
#include"Point.h"
using namespace std;
int main(void) {
    Point point;
    point.Set(0, 5);
    cout << point. GetHorizontal() << " " << point. GetVertical() << endl;
    point.Reflect();
    cout << point. GetHorizontal() << " " << point. GetVertical() << endl;
    point.Move(1, 2);
    cout << point. GetHorizontal() << " " << point. GetVertical() << endl;
    point.Rotate();
    cout << point.GetHorizontal() << " " << point.GetVertical() << endl;
    Point copy = point;
    cout << "Copy point:" << endl;        
    cout << copy. GetHorizontal() << " " << copy. GetVertical() << endl;
    return 0;
}   
```

## Additional Information
* Medium, multiple programming grammars and structures are required.
* Solving time: 20 minutes
* Contributors: 鄭博安, 王聖文, 林岳儒
