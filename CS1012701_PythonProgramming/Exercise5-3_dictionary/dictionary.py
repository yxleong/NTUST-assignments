test_str = "Python best for AI"
repl_dict = {"best":"is the best language", "AI":"Artificial Intelligence"}
str_list = test_str.split()
out_str = ""
for s in str_list:
    flag = True
    for index in repl_dict.keys():
        if(index == s):
            out_str += repl_dict[index] + " "
            flag = False
    if(flag):
        out_str += s + " "
print(out_str)