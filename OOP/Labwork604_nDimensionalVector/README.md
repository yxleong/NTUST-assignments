# N Dim Vector

## Problem Statement
The `VecNf` class is designed to store a multidimensional vector and perform basic vector operations. It has three constructors:
* `VecNf()`: Constructs a one-dimensional zero vector by default.
* `VecNf(float *dest, int cnt)`: Constructs a cnt dimensional vector using the first cnt numbers in dest.
* `VecNf(const VecNf& rhs)`: Constructs a new vector from a VecNf.

Additionally, the class overloads several operators to perform vector operations:
* `operator=`: Assigns the value from one VecNf to another. When called, it prints "ASSIGNMENT!!!".
* `operator[]`: Returns the value of a certain dimension variable in the vector.
* `operator+`: Adds two vectors.
* `operator-`: Subtracts two vectors.
* `operator*`: Implements the inner product of two vectors, and the scalar multiplication of a floating-point number and a vector.

Suppose there were two VecNfs: `v1(2,2)`, `v2(6,1)`. The following requirements must be met:
1. **Assignment**: Assign the value from one `VecNf` to another using the = operator. For example, `vector = v1`; will assign the value of `v1` to `vector`, and `vector` will be `(2,2)`.
1. **Indexing**: Access a certain dimension variable in a `VecNf` using the `[]` operator. For example, `v1[0]` will return the value of the variable in dimension 0, which has a value of 2.
1. **Addition**: Add two `VecNf`s using the `+` operator. For example, `vector = v1 + v2`; will add `v1` and `v2` and assign the resulting vector to `vector`, which will be `(8,3)`.
1. **Subtraction**: Subtract two VecNfs using the - operator. For example, `vector = v1 - v2`; will subtract `v2` from `v1` and assign the resulting vector to `vector`, which will be `(-4,1)`.
1. **Inner Product**: Multiply two `VecNf`s using the `*` operator. For example, float `tmp = v1 * v2`; will multiply `v1` and `v2` and assign the result to `tmp`, which will be `14`.
1. **Scalar Multiplication**: Multiply a `VecNf` by a floating-point number using the `*` operator. For example, `vector = 5.0f * v1`; will multiply `v1` by `5.0f` and assign the resulting vector to `vector`, which will be `(10,10)`.
1. If two `VecNf`s of **different dimensions** are used in any operation, the output will be "dimensions inconsistent" and the operation will return 0.

## Sample Input / Output

# Sample Input
No inputs.

# Sample Output
```
ASSIGNMENT!!!
3 2
ASSIGNMENT!!!
1 2 3
ASSIGNMENT!!!
7 7 7
28
dimensions inconsistent
0
```

## Other Notes:

main.cpp
```
void doNothing(VecNf tar) { return; }

int main()
{
    float a_value[] = { 3.0, 2.0 };
    float b_value[] = { 1, 2, 3 };
    float c_value[] = { 6, 5, 4 };
    VecNf A(a_value, 2);
    VecNf B(b_value, 3);
    VecNf C(c_value, 3);
    VecNf T;
    T = A; // Assignment
    for (int i = 0; i < T.Size(); i++) {
        cout << T[i] << “ ”;
    } cout << endl;

    T = B; // Assignment
    for (int i = 0; i < T.Size(); i++) {
        cout << T[i] << “ ”;
    } cout << endl;

    T = B + C; // Vector addition
    for (int i = 0; i < T.Size(); i++) {
        cout << T[i] << “ ”;
    } cout << endl;

    doNothing(T); // call by value

    cout << C * B << endl; // Scale

    cout << A * C << endl; // Inconsistent

    system("pause");
    return 0;
}
```

## Additional Information
* Easy, only basic programming language syntax and structure are needed.
* Solving time: 40 minutes
* Contributors: 陳泳峰, 陳宥潤, 范茗翔


