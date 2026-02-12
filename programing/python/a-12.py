# Program to handle IndexError in list operation

my_list = [10, 20, 30, 40]

try:
    index = int(input("Enter index to access list element: "))
    print("Element at index:", my_list[index])
except IndexError:
    print("Error: Index out of range.")


# Program to handle TypeError for non-numerical input

try:
    a = float(input("Enter first number: "))
    b = float(input("Enter second number: "))
    print("Sum:", a + b)
except ValueError:
    print("Error: Please enter valid numerical values.")



# Program to handle ZeroDivisionError

try:
    numerator = float(input("Enter numerator: "))
    denominator = float(input("Enter denominator: "))
    result = numerator / denominator
    print("Result:", result)
except ZeroDivisionError:
    print("Error: Cannot divide by zero.")
except ValueError:
    print("Error: Please enter valid numbers.")
