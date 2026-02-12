1. # string is Palindrome or not 
s = input("Enter a string: ")

rev = []
for i in range(len(s)-1, -1, -1):   
    rev.append(s[i])

rev_str = ""
for i in range(len(rev)):
    rev_str = rev_str + rev[i]

if s == rev_str:
    print("Palindrome")
else:
    print("Not Palindrome")


2. # Replace vowels with '*'
s = input("Enter a string: ")

vowels = ['a','e','i','o','u','A','E','I','O','U']
new_str = ""

for i in range(len(s)):
    is_vowel = False
    for j in range(len(vowels)):
        if s[i] == vowels[j]:
            is_vowel = True
            break
    if is_vowel:
        new_str = new_str + "*"
    else:
        new_str = new_str + s[i]

print("After replacing vowels:", new_str)


3. #count total number of characters, digits, special symbol, words in the text 

text = input("Enter the text: ")

digits = 0
digits_list = '1234567890'

special_count = 0
special_chars = "#@$%"

word_count = 1

char_count = len(text)

for i in text:
    if i in digits_list:
        digits += 1
    if i == " ":
        word_count += 1
    if i in special_chars:
        special_count += 1

print("Word count =", word_count)
print("Character count =", char_count)
print("Special character count =", special_count)
print("Digit count =", digits)
