from itertools import permutations
import sys

# Generates all possible rectangle permutations
# Returns a list of (h, w) tuples, where h and w are list of 3 items
def generate(h, w):
    ret = []
    for mask in range((1 << 3)):
        newH = h.copy()
        newW = w.copy()
        for j in range(3):
            # If j-th bit is on, swap its h and w values
            if mask & (1 << j):
                newH[j], newW[j] = newW[j], newH[j]
        ret.append((newH, newW))
    return ret


# Check if all rectangles can be stacked vertically
def canStack(a, b):
    return all(x == a[0] for x in a) and sum(b) == a[0]


# Check if any 2 rectangles can be stacked vertically and sided by the 3rd rectangle
def canSide(a, b):
    for perms in permutations(zip(a, b)):
        pa = [l for l, _ in perms]
        pb = [r for _, r in perms]
        if pa[0] == pa[1] and pa[0] + pa[2] == pb[2] and pb[0] + pb[1] == pb[2]:
            return True
    return False


if __name__ == "__main__":
    h = []
    w = []

    inputs = sys.stdin.readlines()
    for row in inputs:
        x, y = map(int, row.split())
        h.append(x)
        w.append(y)

    for a, b in generate(h, w):
        if canStack(a, b) or canSide(a, b):
            print("YES")
            exit(0)

    print("NO")
