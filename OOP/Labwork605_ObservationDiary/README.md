# Diary and Creature Class Implementation

## Problem Statement
This program is designed to automatically generate diary observation logs for unknown creatures. It includes two classes, `Diary` and `Creature`, that handle the task of recording the number of various body parts of each creature and generating diary observation logs.

Class `Diary`:
* Membership Functions
    * `static void NewDay(string day)`: Sets the current date code as a string of words which may not all necessarily be numbers.

Class `Creature`:
* Constructors
    * `Creature(string name)`: Creates a creature with the given name.
    * `Creature(string name, Creature base)`: Creates a creature with the same body parts as the base creature.
* Overloaded Operators
    * Obtain the specified body part of Creature. (Overload `operator []`)
        *  Returns the number of body parts of the specified type in the creature. 
        *  For example: `c["leg"]` returns the number of legs in creature `c`.
    * Assign a value to a body part in Creature. (Overload `operator =`)
        * Sets the number of body parts of the specified type in the creature and records the change in the diary log. 
        * For example: `c["leg"] = 3` sets the number of legs in creature `c` to 3 and records "sample's leg appeared (0 -> 3)" in the log.
        * Record `<name>'s <body_part> appeared (<original_value> -> <changed_value>)`
    * Increase the number of specified body parts in Creature. (Overload `operator +=`)
        * Increases the number of body parts of the specified type in the creature and records the change in the diary log. 
        * For example: `c["leg"] += 2` increases the number of legs in creature `c` by 2 and records "sample's leg increased (3 -> 5)" in the log.
        * Record `<name>'s <body_part> increased (<original_value> -> <changed_value>) `
    * Reduce the number of specified body parts in Creature (Overload `operator -=`)
        * Decreases the number of body parts of the specified type in the creature and records the change in the diary log. 
        * For example: `c["leg"] -= 2` decreases the number of legs in creature `c` by 2 and records "sample's leg decreased (5 -> 3)" in the log.
        * Record `<name>'s <body_part> decreased (<original_value> -> <changed_value>)`
* Member Functions
    * `void PrintStatus()`: Prints the value of each body part of the creature.
        ```
        sample's status:
        leg * 3
        ```

    * `void PrintLog()`: Prints the diary log of the creature since it was collected.
        ```
        sample's log:
        Day 00
        sample's leg appeared (0 -> 3).
        sample's leg increased (3 -> 5).
        sample's leg decreased (5 -> 3).
        ```

## Sample Input / Output

### Sample Input
No inputs.

### Sample Output
```
UA's log:
Day 0000
UA's leg appeared (0 -> 16).
Day 0102

UA's status:

UB's log:
Day 0102
UB's leg increased (16 -> 42).
Day 0227

UA's log:
Day 0000
UA's leg appeared (0 -> 16).
Day 0102
Day 0227
UA's leg decreased (16 -> 0).
Day 0353
UA's leg appeared (0 -> 6).
UA's wing appeared (0 -> 4).
```

## Other Notes:
* Suppose there was a Creature `c` named `sample` that has set the current date to "00". (`Diary::NewDay("00")`)
* Record in the log each time the **operation** is called 
* Default value for the number of body parts is 0
* Output an empty line after `PrintStatus()` and `PrintLog()`

main.cpp
```
int main() {

	Diary::NewDay("0000");
	Creature unknownA("UA");
	unknownA["leg"] = 16;

	Diary::NewDay("0102");
	Creature unknownB("UB", unknownA);
	unknownB["leg"] += 26;
	unknownA.PrintLog();

	Diary::NewDay("0227");
	unknownA["leg"] = 0;
	unknownA.PrintStatus();
	unknownB.PrintLog();

	Diary::NewDay("0353");
	unknownA["leg"] += 6;
	unknownA["wing"] += 4;
	unknownA.PrintLog();

}
```

## Additional Information
* Medium, multiple programming grammars and structures are required.
* Solving time: 50 minutes
* Contributors: 陳宥潤, 鄭永泰, 范茗翔


