import random

number = ""

for i in range(0, 9):
    number += str(random.randint(0, 9))
    print(number)