import itertools


def triangleType(triangleToy):
    result = []

    for triangle in triangleToy:
        sides = map(int, triangle.split(" "))
        all_sides = list(itertools.permutations(sides))

        is_triangle = True
        for s in all_sides:
            if not (s[0] + s[1] > s[2] and abs(s[0] - s[1]) < s[2]):
                result.append("None of these")
                is_triangle = False
                break

        if is_triangle:
            if sides[0] == sides[1] == sides[2]:
                result.append("Equilateral")
            elif sides[0] == sides[1] or sides[1] == sides[2] or sides[0] == sides[2]:
                result.append("Isosceles")
            else:
                result.append("None of these")

    return result


if __name__ == "__main__":
    print(triangleType(["1 2 3"]))
