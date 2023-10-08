# Q1
my_list = [10, 20, [300, 400, [5000, 6000], 500], 30, 40]
my_list[2][2].append(7000)
print(my_list)

# Q2
candy_list = ['JellyBelly','KitKat','DoubleBubble','MilkyWay','ThreeMusketeers']
no_of_items = [10, 20, 34, 74, 32]
for candy, no in zip(candy_list, no_of_items):
    print(candy, "-", no)
    
# Q3
list1 = [1, 2, 3, 4, 5, 6]
sum = 0
sum_list = []
for i in list1:
    sum += int(i)
    sum_list.append(sum)
print(sum_list)
    