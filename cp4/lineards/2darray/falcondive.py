def main():
    n, m, c = input().split()
    n = int(n)
    m = int(m)
    c = c[1]

    grid1 = []
    for _ in range(n):
        grid1.append([x for x in input()])
    input()
    grid2 = []
    for _ in range(n):
        grid2.append([x for x in input()])

    result = [["" for _ in range(m)] for _ in range(n)]

    found1 = found2 = False
    for i in range(n):
        for j in range(m):
            # Mark position 1
            if not found1 and grid1[i][j] == c:
                i1, j1 = i, j
                found1 = True
            # Mark position 2
            if not found2 and grid2[i][j] == c:
                i2, j2 = i, j
                found2 = True
            # Draw background
            result[i][j] = grid1[i][j] if grid1[i][j] != c else grid2[i][j]
    # Compute distance
    di, dj = i2 - i1, j2 - j1

    # Draw silhouette
    for i in range(n):
        for j in range(m):
            if grid2[i][j] == c and 0 <= i + di < n and 0 <= j + dj < m:
                result[i + di][j + dj] = c

    # Output answer
    for row in result:
        print("".join(row))


if __name__ == "__main__":
    main()
