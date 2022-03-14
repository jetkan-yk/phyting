import sys

black = "B"
white = "W"


def check(grid):
    for row in grid:
        # Check same number of black & white squares
        if row.count(black) != row.count(white):
            return False

        # Check 3 or more same color consecutive squares
        for i in range(len(row) - 2):
            if row[i] == row[i + 1] == row[i + 2]:
                return False
    return True


def transpose(grid):
    return [[grid[j][i] for j in range(len(grid))] for i in range(len(grid[0]))]


def main():
    inputs = [row.strip() for row in sys.stdin.readlines()]

    grid = inputs[1:]
    print(int(check(grid) and check(transpose(grid))))


if __name__ == "__main__":
    main()
