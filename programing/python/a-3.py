# 1. Program to check whether a number is palindrome or not

# Palindrome check

num = int(input("Enter a number: "))
temp = num
rev = 0

while temp > 0:
    digit = temp % 10
    rev = rev * 10 + digit
    temp //= 10

if rev == num:
    print(f"{num} is a palindrome.")
else:
    print(f"{num} is not a palindrome.")

# 2. Program to generate spy numbers between a given range
# A number is a spy number if the sum of its digits is equal to the product of its digits.

# Spy numbers in a range

start = int(input("Enter start of range: "))
end = int(input("Enter end of range: "))

print("Spy numbers between", start, "and", end, "are:")

for num in range(start, end + 1):
    temp = num
    s = 0     # sum of digits
    p = 1     # product of digits
    while temp > 0:
        d = temp % 10
        s += d
        p *= d
        temp //= 10
    if s == p:
        print(num)
        
# 3. Program to generate prime numbers between a given range

# Prime numbers in a range

start = int(input("Enter start of range: "))
end = int(input("Enter end of range: "))

print("Prime numbers between", start, "and", end, "are:")

for num in range(start, end + 1):
    if num > 1:
        is_prime = True
        for i in range(2, int(num**0.5) + 1):
            if num % i == 0:
                is_prime = False
                break
        if is_prime:
            print(num)
