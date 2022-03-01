import sys
from enum import Enum


class Moves(Enum):
    Left = 0
    Up = 1
    Right = 2
    Down = 3


# Rotates the 2d grid 90 degree counter-clockwise
def rotate(grid):
    res = list(zip(*grid))[::-1]
    return [list(x) for x in res]


def tilt(grid, move):
    if move is Moves.Left:
        return grid
    elif move is Moves.Up:
        return rotate(grid)
    elif move is Moves.Right:
        return rotate(rotate(grid))
    elif move is Moves.Down:
        return rotate(rotate(rotate(grid)))


def merge(grid):
    merged = [[False] * 4] * 4
    
    for row in range(4):
        for col in range(1, 4):
            while col:
                # Different values, cannot shift
                if grid[row][col - 1] != 0 and grid[row][col - 1] != grid[row][col]:
                    break
                # Merged before, cannot shift
                elif merged[row][col]:
                    break
                # Merge tile, then break
                to_break = grid[row][col - 1] == grid[row][col]
                # Shift(merge) tiles
                grid[row][col - 1] += grid[row][col]
                grid[row][col] = 0
                col -= 1
                if to_break:
                    merged[row][col - 1] = True
                    break
    print(merged)
    return grid


def output(grid):
    for row in grid:
        for item in row:
            print(item, end=" ")
        print()


def main():
    # Read input
    inputs = [row.strip() for row in sys.stdin.readlines()]
    grid = [[int(x) for x in row.split()] for row in inputs[:4]]
    move = Moves(int(inputs[4]))
    counter_move = Moves((4 - move.value) % 4)
    output(tilt(merge(tilt(grid, move)), counter_move))


if __name__ == "__main__":
    main()
