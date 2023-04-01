# Class Hot Dog Stand

## Problem Statement
Define a class called `HotDogStand` to store and manage the hot dog stores.

The class `HotDogStand` has three variables:

- `char* standId`: The ID of the store.
- `int hotDogSellAmount`: The hot dog sales volume of the store.
- `static int totalSellAmount`: The total hot dog sales volume of all stores.

The class `HotDogStand` has two constructors:

- `HotDogStand(id)`: Construct a `HotDogStand` with the given `id` and set the sales volume to 0.
- `HotDogStand(id, amount)`: Construct a `HotDogStand` with the given `id` and sales volume.

You are required to implement the following member functions:

- `void justSold()`: Increase the hot dog sales volume by 1.
- `void print()`: Print the ID and sales volume of the store separated by spaces.
- `int thisStandSoldAmount()`: Return the sales volume of the store.
- `int allStandSoldAmount()`: Return the total sales volume of all stores.

## Sample Input/Output

The `main()` function in your submission will be replaced when judging. You can use the following `main()` function to test your program:

```c++
int main(void) {
    HotDogStand stand1("Stand1", 0);
    HotDogStand stand2("Stand2", 100);
    HotDogStand stand3("Stand3");
    stand1.justSold();
    stand2.justSold();
    stand3.justSold();
    stand1.print();
    stand2.print();
    stand3.print();
    std::cout << "Total Sold : " << HotDogStand::allStandSoldAmount() << std::endl;
    return 0;
}
```

The above code should output the following:
```
Stand1 1
Stand2 101
Stand3 1
Total Sold : 103
```

## Additional Information
* Eazy, only basic programming syntax and structure are required.
* Solving time: 15 minutes
* Contributors: 林承達, 陳俊儒, 廖宣瑋
