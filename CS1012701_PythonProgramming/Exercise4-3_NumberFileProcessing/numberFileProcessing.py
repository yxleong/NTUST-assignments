with open("Numbers.txt") as file:
    numbers = file.readlines()
for i in range(len(numbers)):
    numbers[i] = int(numbers[i].strip())

answers = []
answers.append(f"The file Numbers.txt contains {len(numbers)} numbers.")
answers.append(f"The largest number in the file Numbers.txt is {max(numbers)}.")
answers.append(f"The smallest number in the file Numbers.txt is {min(numbers)}.")
answers.append(f"The sum of the numbers in the file Numbers.txt is {sum(numbers)}.")
answers.append(
    f"The average of the numbers in the file Numbers.txt is {sum(numbers) / len(numbers)}."
)
answers.append(f"The last number in the file Numbers.txt is {numbers[-1]}.")

for answer in answers:
    print(answer)

with open("ansNumbers.txt", mode="w") as output_file:
    output_file.write("\n".join(answers))