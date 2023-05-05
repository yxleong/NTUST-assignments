# Number Game

## Problem Statement
This program implements a number game designed by a mathematician. The game involves finding a number in a list `S` that can be obtained by using the product of the digits decomposed by an integer `A`.

For example, given the integer `A = 456` which can be decomposed into `A1 = 4`, `A2 = 5` and `A3 = 6`. Assuming that one of the numbers we read from list `S` is `E = 30`, since `E = A2 * A3`, we consider `E` to be legitimate. But if we read the number `E = 12`, we can see that `E` cannot be derived from `A1`, `A2` and `A3` by multiplication, so we consider `E` to be illegitimate.

The program contains a class called `NumberGame` with the following member functions:

* `void SetInput(int)`: Sets the given integer `A`.
* `void ProcessInput()`: Splits the integer `A` into several digits.
* `void SetFileName(string)`: Sets the file name of the file where list `S` is located.
* `void LoadNumberList()`: Reads list `S` from the file.
* `void PrintAllValid()`: Prints all the valid numbers in `S` ascendingly.
* `void Reset()`: Resets all variables.

## Sample Input / Output

### Sample Input
No inputs.

### Sample Output
```
1
2
3
4
8
24
```

## Other Notes:
List `S` contains up to 50,000,000 numbers.

main.cpp
```
int main() {
    NumberGame Game;
    Game.SetInput(1234);
    Game.ProcessInput();
    Game.SetFileName("number.txt");
    Game.LoadNumberList();
    Game.PrintAllValid();

    Game.Reset();
    cout << "\n";
    Game.SetInput(2345);
    Game.ProcessInput();
    Game.SetFileName("number.txt");
    Game.LoadNumberList();
    Game.PrintAllValid();
    system("pause");
}
```

## Additional Information
* Easy, only basic programming language syntax and structure are needed.
* Solving time: 30 minutes
* Contributors: 陳泳峰, 袁瑋成, 范茗翔


