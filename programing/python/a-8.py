# WAP TO ENTER THE ID AND THE SALARY OF THE EMPLOYEESAS INPUT AND STORE THEM INTO A DICTIONARY AND THEN FIND OUT THE HIGHEST SALARY ALONG WITH EMPLOYEE ID.

d={}
n=int(input("enter the no. of employees: "))
for i in range(n):
  id= int(input("enter the employee ID: "))
  sal = int(input("enter the employee salary: "))
  d[id] = sal
max = 0
for i in d:
  if(d[i]>max):
    max = d[i]
    j=i
print(d)
print("Highest salary:",max)
print("Employee ID:", j)      


# WAP TO CHECK WHETHER A GIVEN KEY ALREADY EXISTS IN A DICTIONARY OR NOT.

d={}
n=int(input("enter the number of elements in dictionary"))
for i in range(n):
  k = input("enter key: ")
  v= input("enter value: ")
  d[k] = v
print("\n Dictionary = ", d)
chk = input("enter a key to check: ") 
if chk in d:
  print("key exists in dictionary")
  print("value of this key = ", d[chk])
else:
  print("key does not exist in dictionary") 



# WAP TO COMBINE TWO DICTIONARY BY ADDING THE VALUES OF COMMON KEYS.
 
d1 = {}
d2 = {}

n1 = int(input("Enter number of items for first dictionary: "))
for i in range(n1):
    k = input("Enter key: ")
    v = (input("Enter value: "))
    d1[k] = v

n2 = int(input("\nEnter number of items for second dictionary: "))
for i in range(n2):
    k = input("Enter key: ")
    v = (input("Enter value: "))
    d2[k] = v

print("\nFirst dictionary:", d1)
print("Second dictionary:", d2)

combined = {}
for key in d1.keys() | d2.keys():  
    combined[key] = d1.get(key, 0) + d2.get(key, 0)

print("\nCombined dictionary (values added):", combined)
