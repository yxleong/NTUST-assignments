"""
Program: median.py
Author : GROUP F
            范美恩 B11215016
            梁婭瑄 B11015016
            賴柏宇 B11032030
            陳冠廷 B11215009
            許峰碩 B11230021
            李珮筠 B11215010
Analysis:
1. The input is a serial number in string form.
2. The list should be sorted before calculate the median.
3. The output is expressed with one decimal place.
4. The output as shown the following:
    Enter the serial number: 123456
    The median is 3.5

Design — pseudocode:
1. The input is
    num
2. Convertions:
    char_list = list of num
    num_list = list of int(char_list[i])
    sort the num_list
3. Computations:
    middle = num_list[num_length//2]
    if num_length is even number
        next_middle_num = num_list[num_length//2 - 1]
        median = (middle_num + next_middle_num) / 2
    if num_length is odd number
        median = middle_num
4. The output is
    float(median)
"""

# Get the input from user
num = input("Enter the serial number: ")

# Convert the number string to a character list
char_list = list(num)

# Convert the char list to a interger list
num_list = []
for x in char_list :
    digit = int(x)
    num_list.append(digit)

# Sort the number list in ascending order to calculate median
num_list.sort()

# Get the number of element in number list
num_length = len(num_list)

# Find the middle element in number list
middle_num = num_list[num_length // 2]

#####################################################################
# If the number of element in number list is even number, the median is the average of two middle numbers;
# Otherwise, the median is the middle number.
#######################
if num_length % 2 == 0:
    next_middle_num = num_list[num_length//2 - 1]
    median = (middle_num + next_middle_num) / 2
else:
    median = middle_num

# Show the output
print("The median is", float(median))