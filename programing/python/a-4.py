# A. Largest and Smallest number in a list (user input)
# largest and smallest in a list (user input)

n = int(input("Enter the number of elements: "))
nums = []

for i in range(n):
    val = int(input(f"Enter element {i+1}: "))
    nums.append(val)

largest = nums[0]
smallest = nums[0]

for x in nums[1:]:
    if x > largest:
        largest = x
    if x < smallest:
        smallest = x

print("Largest =", largest)
print("Smallest =", smallest)


# B. Frequency of a number in a list (user input)
# frequency of a number in a list (user input)

n = int(input("Enter the number of elements: "))
nums = []
print("enter the nums")
for i in range(n):
    val = int(input())
    nums.append(val)

target = int(input("Enter the number whose frequency you want to find: "))
frequency = 0

for x in nums:
    if x == target:
        frequency += 1

print("Frequency of", target, "=", frequency)


# C. Sum of even numbers in a list (user input)
# sum of even numbers in a list (user input)

n = int(input("Enter the number of elements: "))
nums = []

for i in range(n):
    val = int(input(f"Enter element {i+1}: "))
    nums.append(val)

sum_even = 0
for x in nums:
    if x % 2 == 0:
        sum_even += x

print("Sum of even numbers =", sum_even)


# D. Linear search (user input)
# linear search in a list (user input)

n = int(input("Enter the number of elements: "))
nums = []

for i in range(n):
    val = int(input(f"Enter element {i+1}: "))
    nums.append(val)

key = int(input("Enter the number to search: "))

found = False

for i in range(len(nums)):
    if nums[i] == key:
        print("Element found at index", i)
        found = True
        break

if not found:
    print("Element not found in the list")