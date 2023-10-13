# Q1
my_tuple = (1, 5, 7, 8, 10)
size = len(my_tuple)
end_index = size - 1
result = ()
for i in range(size):
    sum = 0
    if(i > 0):
        front = my_tuple[i] * my_tuple[i-1]
        sum = front
    if(i < end_index):
        back = my_tuple[i] * my_tuple[i+1]
        sum += back
    result += (sum, )
print(result)
# ---------------------------------------------------
t = (1, 5, 7, 8, 10)
l = []
l.append(t[0]*t[1])
for i in range(1,len(t)-1):
    l.append(t[i]*t[i-1]+t[i]*t[i+1])
l.append(t[-1]*t[-2])
print(l)

# Q2
t1 = (1, 2, 3, 0)
t2 = (0, 1, 2, 3)
print("t1 and t2 are", end = " ")
if(t1 != t2):
    print("not", end = " ")
print("same")
# ---------------------------------------------------
t1 = (1, 2, 3, 0)
t2 = (0, 1, 2, 3)
print((zip(t1,t2))) # address
print(list(zip(t1,t2))) # see what save inside
flag = True
for i,j in zip(t1,t2): # check if at same index
    if i == j:
        continue
    else:
        flag = False
        break
if flag:
    print("same")
else:
    print("Not same")

# Q3
test_list = [(5,6), (5,7), (5,8), (6,10), (7,13)]
new_list = []
for i in test_list:
    new_tupple = ()
    flag = True
    for k in new_list:
        if(k[0] == i[0]):
            flag = False
            break
    if(flag):
        new_tupple += (i[0],)
        for j in test_list:
            if (j[0] == i[0]):
                new_tupple += (j[1],)
        new_list.append(new_tupple)
print(new_list)
