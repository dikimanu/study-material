# 1. Average marks of a subject
num_subjects = int(input("Enter the number of subjects: "))
total = 0

for i in range(num_subjects):
    marks = float(input(f"Enter marks for subject {i+1}: "))
    total += marks

average = total / num_subjects
print("Average marks:", average)

# 2. Area and Perimeter of a Rectangle
length = float(input("Enter the length of the rectangle: "))
breadth = float(input("Enter the breadth of the rectangle: "))

area = length * breadth
perimeter = 2 * (length + breadth)

print("Area:", area)
print("Perimeter:", perimeter)


# 3. Compound Interest
principal = float(input("Enter the principal amount: "))
rate = float(input("Enter the rate of interest per annum: "))
time = float(input("Enter the time in years: "))

# Compound Interest formula
amount = principal * (1 + rate / 100) ** time
compound_interest = amount - principal

print("Compound Interest:", compound_interest)


# 4. Temperature Conversion
choice = input("Convert from (C)elsius or (F)ahrenheit? ").strip().upper()

if choice == 'C':
    celsius = float(input("Enter temperature in Celsius: "))
    fahrenheit = (celsius * 9/5) + 32
    print("Temperature in Fahrenheit:", fahrenheit)
elif choice == 'F':
    fahrenheit = float(input("Enter temperature in Fahrenheit: "))
    celsius = (fahrenheit - 32) * 5/9
    print("Temperature in Celsius:", celsius)
else:
    print("Invalid choice.")

