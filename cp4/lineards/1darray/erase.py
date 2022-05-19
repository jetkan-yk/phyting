"""
Simple mapping
"""

def main():
    OUTPUT_SUCCESS = "Deletion succeeded"
    OUTPUT_FAILURE = "Deletion failed"

    n = int(input())
    old_line = input()
    new_line = input()

    if n % 2 == 0:
        expected = old_line
    else:
        expected = "".join(map(lambda x: "0" if x == "1" else "1", old_line))

    if new_line == expected:
        print(OUTPUT_SUCCESS)
    else:
        print(OUTPUT_FAILURE)


if __name__ == "__main__":
    main()
