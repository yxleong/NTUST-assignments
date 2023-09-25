"""
Program: wageform.py
Author : GROUP G
            梁婭瑄 B11015016
            魏美芳 B11115014
            陳亮宏 B11215039
Analysis:
1. All employees are given a flat hourly wage rate of 1.5 for overtime hours.
2. Hourly wage, the number of regular hours and the overtime hours must be entered.
3. The total weekly pay is expressed with two decimal places.
4. The output as shown the following:
    Enter the wage: $100
    Enter the regular hours: 8
    Enter the overtime hours: 4
    The total weekly pay is $1400.00

Design — pseudocode:
1. Define significant constant
    rate
2. The inputs are
    hourly wage
    number of regular hours
    number of overtime hours    
3. Computations:
    total overtime pay = total overtime hours * 1.5 * hourly wage;
    total weekly pay = hourly wage * total regular hours + total overtime pay;
4. The output is
    the total weekly pay
"""

# Initialize the constant
RATE = 1.5;

# Request the inputs
hourlyWage = int(input("Enter the wage:$"))
regularHours = int(input("Enter the regular hours: "))
overtimeHours = int(input("Enter the overtime hours: "))

# Compute the overtime pay
overtimePay =  overtimeHours * RATE * hourlyWage

# Compute the total hourly wage
weeklyPay = hourlyWage * regularHours + overtimePay

# Display the total hourly wage
print("The total weekly pay is ${:.2f}".format(weeklyPay))