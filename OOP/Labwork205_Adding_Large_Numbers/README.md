# Adding Large Numbers

## Problem Statement

Given two large integers `A` and `B`, calculate their sum. The maximum number of digits in `A` and `B` is approximately 10000.

### Input
The first line of input contains an integer `N` (100 > N > 0), which indicates there are N following data pairs. Note that every two lines make a data pair, and each pair contains two big integers `A` and `B` on a line by itself. The maximum bits of A, B is（10^l0000) – 1.
```
3
43789507384925798320000000000000000000000000001
44997439848794037580000000000000000000000000002
1bbbba45
1234567
1
9
```

### Output

Print the result of `A + B`.
```
8878694723371983590000000000000000000000000003
Not a valid number, please try again.
10
```

### Note
* Do not use **long long**, **long long int**, or **_m128**.
* The input numbers are valid, and each digit of the input is a valid digit (0-9). If the input is not valid, print "**Not a valid number, please try again.**"
* You should package the big number as a **structure** (e.g., struct BigInt...) with a simple object type for each bit.
* The function signature for adding two BigInts is provided.
```cpp
struct BigInt {
  // members and constructors
};

BigInt Add(const BigInt &lhs,const BigInt &rhs) {
  // Calculation
  return ...;
}

int main() {
  BigInt a, b;
  // Input a, b
  BigInt result = Add(a, b);
  // Output result
}
```

## Additional Information
* Medium, multiple programming grammars and structures are required.
* Solving time: 25 minutes
* Contributors: 謝宜杭, 林承達, 廖宣瑋
