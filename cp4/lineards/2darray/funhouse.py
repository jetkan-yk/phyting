"""
2D grid travesal
Enum
"""

from enum import Enum, auto


ENTRANCE = "*"
EXIT = "&"
WALL = "x"
ML = "/"
MR = "\\"


class Direction(Enum):
    UP = auto()
    DOWN = auto()
    LEFT = auto()
    RIGHT = auto()


def getDirection(i, j, w, l):
    if i == 0:
        return Direction.DOWN
    elif i == l - 1:
        return Direction.UP
    elif j == 0:
        return Direction.RIGHT
    elif j == w - 1:
        return Direction.LEFT


def changeDir(dir, mirror):
    if mirror == ML:
        if dir == Direction.UP:
            return Direction.RIGHT
        elif dir == Direction.DOWN:
            return Direction.LEFT
        elif dir == Direction.LEFT:
            return Direction.DOWN
        elif dir == Direction.RIGHT:
            return Direction.UP
    else:
        if dir == Direction.UP:
            return Direction.LEFT
        elif dir == Direction.DOWN:
            return Direction.RIGHT
        elif dir == Direction.LEFT:
            return Direction.UP
        elif dir == Direction.RIGHT:
            return Direction.DOWN


def move(i, j, dir):
    if dir == Direction.UP:
        return i - 1, j
    elif dir == Direction.DOWN:
        return i + 1, j
    elif dir == Direction.LEFT:
        return i, j - 1
    elif dir == Direction.RIGHT:
        return i, j + 1


def main():
    case = 1
    while True:
        w, l = map(int, input().split())
        if w == 0 and l == 0:
            break

        grid = []
        for _ in range(l):
            grid.append([x for x in input()])

        # Find entrance and determine direction
        for i in range(l):
            for j in range(w):
                if grid[i][j] == ENTRANCE:
                    start = i, j
                    dir = getDirection(i, j, w, l)
                    break

        # Keep moving until reach a wall
        i, j = start
        while grid[i][j] != WALL:
            # Meets mirror, change direction
            if grid[i][j] == ML or grid[i][j] == MR:
                dir = changeDir(dir, grid[i][j])
            i, j = move(i, j, dir)
        # Mark as exit
        grid[i][j] = EXIT

        # Output answer
        print(f"HOUSE {case}")
        for row in grid:
            for x in row:
                print(x, end="")
            print()
        case += 1


if __name__ == "__main__":
    main()
