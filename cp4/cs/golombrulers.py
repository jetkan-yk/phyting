import sys

inputs = sys.stdin.readlines()
outputs = []

for line in inputs:
    mark = list(map(int, line.split(" ")))
    n = max(mark)
    # Use a dict to keep track of the distances
    count = {i: 0 for i in range(1, n)}

    # O(n^2) to find all possible distances
    for i in range(len(mark)):
        for j in range(i + 1, len(mark)):
            dist = abs(mark[i] - mark[j])
            if dist in count:
                count[dist] += 1

    # O(n) for checking distances
    missing = []
    is_ruler = True
    for dist, freq in count.items():
        if freq > 1:
            is_ruler = False
            break
        elif freq == 0:
            missing.append(dist)
    missing.sort()

    # Output answers
    if not is_ruler:
        outputs.append("not a ruler\n")
    elif missing:
        out = "missing"
        for i in missing:
            out = out + " " + str(i)
        out += "\n"
        outputs.append(out)
    else:
        outputs.append("perfect\n")

sys.stdout.writelines(outputs)
