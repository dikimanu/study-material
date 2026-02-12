# Program to demonstrate Class and Object

class Student:
    def _init_(self, name, roll):
        self.name = name
        self.roll = roll

    def display(self):
        print(f"Name: {self.name}")
        print(f"Roll Number: {self.roll}")

# Create object
s1 = Student("Alice", 101)
s1.display()




# Program to calculate area of a room using Class and Object

class Room:
    def _init_(self, length, breadth):
        self.length = length
        self.breadth = breadth

    def calculate_area(self):
        return self.length * self.breadth

# Create object
length = float(input("Enter length of the room: "))
breadth = float(input("Enter breadth of the room: "))

room = Room(length, breadth)
print("Area of the room:", room.calculate_area(), "square units")
