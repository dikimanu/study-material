# (A) Copy contents of one file to another
f1 = input("Enter source file name: ")
f2 = input("Enter destination file name: ")

with open(f1, "r") as a, open(f2, "w") as b:
    b.write(a.read())

print("File copied successfully.")

# (B) Generate spy numbers in a range and store in a file
start = int(input("Enter start of range: "))
end = int(input("Enter end of range: "))
fname = input("Enter file name to save spy numbers: ")

with open(fname, "w") as f:
    for i in range(start, end + 1):
        s = 0
        p = 1
        n = i
        while n > 0:
            d = n % 10
            s += d
            p *= d
            n //= 10
        if s == p:
            f.write(str(i) + "\n")

print("Spy numbers written to file successfully.")

# (C) Read numbers from a file and write primes to another file
infile = input("Enter input file name: ")
outfile = input("Enter output file name: ")

with open(infile, "r") as a, open(outfile, "w") as b:
    for content in a:
        for word in content.split():
            n = int(word)
            if n > 1:
                for i in range(2, n):
                    if n % i == 0:
                        break
                else:
                    b.write(str(n) + "\n")

print("Prime numbers written to file successfully.")
