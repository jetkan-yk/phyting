"""
Iterative flood-fill
Special f-string formatting, align right with specific width and filled by character
"""


def neighbors(i, j, n, m):
    result = []
    if i - 1 >= 0:
        result.append((i - 1, j))
    if i + 1 < n:
        result.append((i + 1, j))
    if j - 1 >= 0:
        result.append((i, j - 1))
    if j + 1 < m:
        result.append((i, j + 1))
    return result


def main():
    n, m = map(int, input().split())
    # Pad 1 dummy layer around grid
    n += 2
    m += 2

    grid = [["."] * m]
    for i in range(n - 2):
        grid.append(["."] + [x for x in input()] + ["."])
    grid.append(["."] * m)

    rings = [[None for _ in range(m)] for _ in range(n)]
    # Mark ring 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] == ".":
                rings[i][j] = 0
    # Mark rings iteratively
    for depth in range(min(n, m)):
        for i in range(n):
            for j in range(m):
                if rings[i][j] == depth:
                    # Mark neighbors
                    for k, l in neighbors(i, j, n, m):
                        if rings[k][l] is None:
                            rings[k][l] = depth + 1

    # Output answer
    maxDepth = max(max(row) for row in rings)
    width = 2 if maxDepth < 10 else 3
    fill = "."
    align = ">"
    for i in range(1, n - 1):
        for j in range(1, m - 1):
            content = "" if rings[i][j] == 0 else str(rings[i][j])
            print(f"{content:{fill}{align}{width}}", end="")
        print()


if __name__ == "__main__":
    main()
