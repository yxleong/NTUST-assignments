def sum_list(numbers):
    total = 0
    for num in numbers:
        total += num
    return total
    
nums = [1, 2, 3, 4, 5]

# print("The sum of {nums} is:", sum_list(nums))
print(f"The sum of {nums} is:", sum_list(nums))
