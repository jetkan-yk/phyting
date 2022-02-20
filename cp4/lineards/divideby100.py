"""
Use string char to process large integer (10**10**6)
"""

import sys


def main():
    n, m = [row.strip() for row in sys.stdin.readlines()]

    # Special case, just print n
    if m == "1":
        print(n)
        exit(0)

    # Convert string into a list of string
    result = [x for x in n]
    if len(n) < len(m):
        # Case 1: n is fraction
        result = ["0."] + ["0"] * (len(m) - len(n) - 1) + result
    else:
        # Case 2: n is decimal
        mid = len(n) - (len(m) - 1)
        result = result[:mid] + ["."] + result[mid:]

    # Remove trailing zeroes and decimal point
    while result[-1] == "0":
        result.pop()
    if result[-1] == ".":
        result.pop()

    print("".join(result))


if __name__ == "__main__":
    main()
