"""
Use string char to process large integer (10**10**6)
"""

import sys


def main():
    n, m = [row.strip() for row in sys.stdin.readlines()]
    result = ""

    # Special case, just print n
    if m == "1":
        result = n
    else:
        # Case 1: n is fraction
        if len(n) < len(m):
            zeroes = "0" * (len(m) - len(n) - 1)
            result = "0." + zeroes + n
        # Case 2: n is decimal
        else:
            mid = len(n) - (len(m) - 1)
            result = n[:mid] + "." + n[mid:]

        # Remove trailing zeroes and decimal point
        result = result.rstrip("0").rstrip(".")

    print(result)


if __name__ == "__main__":
    main()
