# Read input and convert to float type
num1 = float(input("Input first number: "))
num2 = float(input("Input second number: "))

# Calculate and print the result
print("Sum:", num1 + num2)
print("Sub:", num1 - num2)
print("Mul:", num1 * num2)

# Handle the "Division by Zero" error
if(num2 != 0):
   print("Div:",num1 / num2)
else:
   print("Div: ERROR! Division by Zero")