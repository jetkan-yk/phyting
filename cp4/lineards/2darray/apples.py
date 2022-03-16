"""
Column major 2d array operation
Prefix count
"""


def main():
    r, c = map(int, input().split())

    grid = []
    for _ in range(r):
        grid.append([x for x in input()])

    result = [[0 for _ in range(c)] for _ in range(r)]
    for j in range(c):
        # Prefix count apples in each column
        col = [0 for _ in range(r)]
        for i in range(r):
            col[i] = 1 if (grid[i][j] == "a") else 0
            if i > 0 and grid[i - 1][j] != "#":
                col[i] += col[i - 1]

        # Draw from bottom to top
        num = col[-1]  # Number of apples to be drawn
        for i in range(r):
            k = -i - 1
            if grid[k][j] == "#":
                result[k][j] = "#"
                num = col[k]
            elif num > 0:
                result[k][j] = "a"
                num -= 1
            else:
                result[k][j] = "."

    for row in result:
        print("".join(row))


if __name__ == "__main__":
    main()
