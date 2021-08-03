def check(a, b, c, n):
    return 6 * a + 9 * b + 20 * c == n


def McNuggets(n):
    """
    n is an int

    Returns True if some integer combination of 6, 9 and 20 equals n
    Otherwise returns False.
    """
    a = n // 6
    b = n // 9
    c = n // 20

    for k in range(c + 1):
        for j in range(b + 1):
            for i in range(a + 1):
                if check(i, j, k, n):
                    return True
    return False

while True:
    print(McNuggets(int(input())))