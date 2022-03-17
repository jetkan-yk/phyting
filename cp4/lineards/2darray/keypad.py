def main():
    tc = int(input())
    for _ in range(tc):
        r, c = map(int, input().split())

        grid = []
        # Mark all rows and cols that are fired
        rows_on = set()
        cols_on = set()
        for i in range(r):
            grid.append([x for x in input()])
            for j in range(c):
                if grid[i][j] == "1":
                    rows_on.add(i)
                    cols_on.add(j)

        # All cross sections of fired rows and cols must be on
        impossible = False
        for i in rows_on:
            for j in cols_on:
                if grid[i][j] == "0":
                    impossible = True
                    break

        if impossible:
            print("impossible")
        else:
            # Definitely pressed if only 1 row or 1 col is fired
            ON = "P" if len(rows_on) == 1 or len(cols_on) == 1 else "I"
            OFF = "N"
            for i in range(r):
                for j in range(c):
                    grid[i][j] = ON if grid[i][j] == "1" else OFF
                print("".join(grid[i]))
        print("----------")


if __name__ == "__main__":
    main()
