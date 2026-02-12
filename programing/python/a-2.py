 # 1. Compare Two Numbers
num1 = int(input("Enter the first number: "))
num2 = int(input("Enter the second number: "))

if num1 > num2:
    print("Smaller number squared:", num2 ** 2)
    print("Greater number cubed:", num1 ** 3)
elif num2 > num1:
    print("Smaller number squared:", num1 ** 2)
    print("Greater number cubed:", num2 ** 3)
else:
    print("Both the numbers are equal.")


    # 2. Even/Odd Number Handling
num = int(input("Enter a number: "))

if num > 0 and num % 2 == 0:
    print("Three succeeding even numbers:")
    for i in range(1, 4):
        print(num + 2 * i)
elif num < 0 and num % 2 != 0:
    print("Three preceding odd numbers:")
    for i in range(1, 4):
        print(num - 2 * i)
else:
    print("The number is neither a positive even nor a negative odd.")



# 3. Sum or Product Based on Choice
num1 = float(input("Enter first number: "))
num2 = float(input("Enter second number: "))
num3 = float(input("Enter third number: "))
choice = int(input("Enter your choice (1 for sum, 2 for product): "))

if choice == 1:
    print("Sum:", num1 + num2 + num3)
elif choice == 2:
    print("Product:", num1 * num2 * num3)
else:
    print("Invalid choice.")


    # 4. Grade Calculation Based on Average Marks
# Input marks for 3 subjects
physics = float(input("Enter marks in Physics: "))
chemistry = float(input("Enter marks in Chemistry: "))
biology = float(input("Enter marks in Biology: "))

# Calculate average marks
average = (physics + chemistry + biology) / 3

# Determine grade
if average >= 80:
    grade = "Distinction"
elif average >= 60:
    grade = "First Division"
elif average >= 45:
    grade = "Second Division"
elif average >= 40:
    grade = "Pass"
else:
    grade = "Promotion not granted"

# Output result
print(f"\nAverage Marks: {average:.2f}%")
print(f"Grade Obtained: {grade}")