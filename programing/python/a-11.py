# Program to concatenate two files

# Input file names
file1 = input("Enter the first filename: ")
file2 = input("Enter the second filename: ")
output_file = input("Enter the output filename: ")

# Open files and concatenate contents
with open(file1, 'r') as f1, open(file2, 'r') as f2, open(output_file, 'w') :
    content1 = f1.read()
    content2 = f2.read()
    output_file.write(content1 + "\n" + content2)

print(f"Contents of '{file1}' and '{file2}' have been concatenated into '{output_file}'.")



# Program to count number of words in a file

filename = input("Enter the filename: ")

with open(filename, 'r') as f:
    content = f.read()
    words = content.split()
    print(f"Number of words in '{filename}' is: {len(words)}")


