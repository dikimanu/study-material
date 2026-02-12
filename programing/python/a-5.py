# A) Convert text into list, then find vowels
txt = "I love my mother land India"

# Convert to list of characters
char_list = list(txt)

# Find vowels
vowels = "aeiouAEIOU"
vowel_list = [ch for ch in char_list if ch in vowels]

print("Character List:", char_list)
print("Vowels in text:", vowel_list)


# B) Segregate Even, Odd, and Prime numbers
# Only using append (no other predefined shortcuts)

# Input from user
n = int(input("Enter number of elements: "))
lst = []

for i in range(n):
    elem = int(input(f"Enter element {i+1}: "))
    lst.append(elem)

# Empty lists for results
even = []
odd = []
prime = []

for num in lst:
    # Check Even / Odd
    if num % 2 == 0:
        even.append(num)
    else:
        odd.append(num)

    # Check Prime
    if num > 1:   # prime numbers are > 1
        flag = 0
        for j in range(2, num):
            if num % j == 0:
                flag = 1
                break
        if flag == 0:
            prime.append(num)

print("\nEven Numbers:", even)
print("Odd Numbers:", odd)
print("Prime Numbers:", prime)


# C) Count frequency of each element in user-defined list
# Take input from user
n = int(input("Enter number of elements: "))
lst = []

for i in range(n):
    elem = input(f"Enter element {i+1}: ")
    lst.append(elem)

freq = {}

for item in lst:
    if item in freq:      # If item already exists, increment count
        freq[item] += 1
    else:                 # Otherwise initialize count as 1
        freq[item] = 1

# Print result
print("\nFrequency of each element:")
for key in freq:
    print(key, ":", freq[key])
