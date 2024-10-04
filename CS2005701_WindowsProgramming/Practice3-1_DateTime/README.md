# Date & Time Demo Program

## Overview
This C# console application demonstrates basic date and time operations, including the use of the `DateTime` class and the `Random` class to generate random dates. The program includes sections for default values, setting specific dates, displaying the current date and time, and generating random dates.

## Code Description

### Default DateTime
- Initializes a `DateTime` object with default values (resulting in `1/1/0001`).
- Displays the year, month, and day, followed by the default `ToString()` representation.

### Set DateTime
- Creates a `DateTime` object for a specific date (September 2, 2021) and displays it.

### Current Date and Time
- Retrieves and displays the current date and time using `DateTime.Now`.
- Shows the year, month, day, hour, minute, and second.

### Random Dates
- Utilizes the `Random` class to generate two random dates within a specified range (from 2021 to 2025).
- Displays the generated random dates.

## Output
When you run the program, you would see output similar to the following (actual output may vary due to the random dates):
```
-----Default-----
1/1/1
0001/1/1 上午 12:00:00
-------Set-------
2021/9/2
-------Now-------
2024/10/4
17:57:21
2024/10/4 下午 05:57:21
-----Random-----
2025/4/3
2023/10/28
```

