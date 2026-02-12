filename = input("Enter the filename: ")
copy_file = input("Enter the copy filename: ")

with open(filename, 'r') as f, open(copy_file, 'w') as c:
    content = f.read()
    c.write(content)  # write words separated by spaces
    print(f'{copy_file}')
