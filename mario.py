# a program to print complete pyramid with central hole

# importing from the cs50 library
from cs50 import get_int

n = 0
while (n < 1 or n > 8):
    n = get_int("Height: ")

for i in range(0, n, 1):

    # for spaces
    for j in range(n-1, i, -1):
        print(" ", end="")

    # for left side of pyramid
    for k in range(0, i+1, 1):
        print("#", end="")

    # central hole
    print("  ", end="")

    # for right side of pyramid
    for l in range(0, i+1, 1):
        print("#", end="")

    # to start from the new line
    print("")
