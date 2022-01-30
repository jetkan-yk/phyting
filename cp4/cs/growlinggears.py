import sys


def findTorque(a, b, c):
    R = -b / (2 * a)
    return a * R ** 2 + b * R + c


if __name__ == "__main__":
    inputs = sys.stdin.readlines()
    outputs = []

    # Read inputs
    tc = int(inputs[0])
    i = 1
    for _ in range(tc):
        n = int(inputs[i])
        i += 1

        gears = [tuple(map(int, row.split())) for row in inputs[i : i + n]]
        i += n

        maxTorque = ans = 0
        for id, (a, b, c) in enumerate(gears, start=1):
            torque = findTorque(-a, b, c)
            if torque > maxTorque:
                maxTorque = torque
                ans = id
        print(ans)
