str1 = "Practice problEms on Lists tUplE and DictiOnary"
vowel_lower = {'a', 'e', 'i', 'o', 'u'}
vowel_upper = {}
for v in vowel_lower:
    vowel_upper.add(v.upper())
count = 0
for c in str1:
    for i, j in vowel:
        if c == i or c == j:
            count += 1
print(count)