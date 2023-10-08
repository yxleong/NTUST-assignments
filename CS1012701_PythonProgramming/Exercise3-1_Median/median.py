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
    charList = list of num
    numList = list of int(charList[i])
    sort the numList
3. Computations:
    middle = numList[numLength//2]
    if numLength is even number
        nextMiddle = numList[numLength//2 - 1]
        median = (middleNum + nextMiddleNum) / 2
    if numLength is odd number
        median = middleNum
4. The output is
    float(median)
"""

# Get the input from user
num = input("Enter the serial number: ")

# Convert the number string to a character list
charList = list(num)

# Convert the char list to a interger list
numList = []
for x in charList :
    intX = int(x)
    numList.append(intX)

# Sort the number list in ascending order to calculate median
numList.sort()

# Get the number of element in number list
numLength = len(numList)

# Find the middle element in number list
middleNum = numList[numLength // 2]

#####################################################################
# If the number of element in number list is even number, the median is the average of two middle numbers;
# Otherwise, the median is the middle number.
#######################
if numLength % 2 == 0:
    nextMiddleNum = numList[numLength//2 - 1]
    median = (middleNum + nextMiddleNum) / 2
else:
    median = middleNum

# Show the output
print("The median is", float(median))