tc = int(input())

for _ in range(tc):
    a, b, c = map(int, input().split())

    ma = b - (c - b)
    mb = (a + c) / 2
    mc = b + (b - a)

    can = False
    if ma > 0 and ma % a == 0:
        # print(a, b, c, "a", ma)
        can = True
    elif mb > 0 and mb % b == 0:
        can = True
        # print(a, b, c, "b", mb)
    elif mc > 0 and mc % c == 0:
        can = True
        # print(a, b, c, "c", mc)

    if can:
        print("YES")
    else:
        print("NO")
