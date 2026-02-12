# (A) Write a program to find the maximum and minimum number in a numeric tuple.
n = int(input("How many numbers? "))
t = []
for i in range(n):
    num = int(input("Enter number: "))
    t.append(num)

t = tuple(t)
print("Maximum:", max(t))
print("Minimum:", min(t))



# (B) Write a program to find repeated elements in a tuple and display them.
n = int(input("How many numbers? "))
t = []
for i in range(n):
    num = int(input("Enter number: "))
    t.append(num)

t = tuple(t)
repeated = []

for i in t:
    if t.count(i) > 1 and i not in repeated:
        repeated.append(i)

if repeated:
    print("Repeated elements:", repeated)
else:
    print("No repeated elements found.")



# (C) Write a program to merge two tuples into one.
n1 = int(input("How many elements in first tuple? "))
t1 = []
for i in range(n1):
    num = int(input("Enter number: "))
    t1.append(num)

n2 = int(input("How many elements in second tuple? "))
t2 = []
for i in range(n2):
    num = int(input("Enter number: "))
    t2.append(num)

t1 = tuple(t1)
t2 = tuple(t2)
t3 = t1 + t2
print("Merged tuple:", t3)
