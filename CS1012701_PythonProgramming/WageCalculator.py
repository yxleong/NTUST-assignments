"""
Program: WageCalculator.py
Author : GROUP G
            梁婭瑄 B11015016
            魏美芳 B11115014
            陳亮宏 B11215039
Analysis:
1. ask user to input the wage
2. convert the wage into integer datatype
3. ask user to input the regular hours
4. convert the regular hours into integer datatype
5. ask user to input the overtime hours
6. convert the overtime hours into integer datatype
7. calculate overtime pay by calculating overtime hours multiplied by 1.5 times the hourly wage
8. calculate total wage by calculating the hourly wage multiplied by the total number of regular hours plus any overtime pay
9. displays an employee's total weekly pay with format

Design - pseudocode:
1. Define Constants
    rate
2. The inputs are
    wage
    regular hours
    ovetime hours    
3. Computations
    overtime pay =  overtime hours * 1.5 * wage;
    total wage = wage * regular hours + overtime pay;
4. The outputs are
    total wage
"""
# Initialize the constant
RATE = 1.5;

# Request the inputs
wage = int(input("Enter the wage:$"));
regular_hours = int(input("Enter the regular hours: "));
overtime_hours = int(input("Enter the overtime hours: "));
# takes as inputs the hourly wage, total regular hours, and total overtime hours

# Compute the overtime pay
overtime_pay =  overtime_hours * RATE * wage;
# Overtime pay equals the total overtime hours multiplied by 1.5 times the hourly wage

# Compute the total hourly wage
total_wage = wage * regular_hours + overtime_pay;
# total weekly pay equals the hourly wage multiplied by the total number of regular hours plus any overtime pay

# Display the total hourly wage
print("The total weekly pay is ${:.2f}".format(total_wage))