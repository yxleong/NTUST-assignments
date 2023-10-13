str1 = "Practice problEms on Lists tUplE and DictiOnary"
vowel_lower = {'a', 'e', 'i', 'o', 'u'}
vowel_upper = set()
count = set()
for v in vowel_lower:
    vowel_upper.add(v.upper())
for c in str1:
    for i, j in zip(vowel_lower,vowel_upper):
        if c == i or c == j:
            count.add(c)
print("No of unique vowels:", len(count))