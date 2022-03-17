def main():
    r, c = map(int, input().split())
    # Pad input with dummy #
    grid = []
    for _ in range(r):
        grid.append([x for x in input()] + ["#"])
    grid.append(["#" for _ in range(c + 1)])
    r += 1
    c += 1

    words = []
    # Scan in row-major fashion
    for i in range(r):
        buffer = []
        for j in range(c):
            # Flush buffer when encounter "#"
            if grid[i][j] == "#":
                # Only add to word list when length > 1
                if len(buffer) > 1:
                    words.append("".join(buffer))
                buffer = []
            # Otherwise keep adding to buffer
            else:
                buffer.append(grid[i][j])

    # Scan in column-major fashion
    for j in range(c):
        buffer = []
        for i in range(r):
            if grid[i][j] == "#":
                if len(buffer) > 1:
                    words.append("".join(buffer))
                buffer = []
            else:
                buffer.append(grid[i][j])

    print(sorted(words)[0])


if __name__ == "__main__":
    main()
