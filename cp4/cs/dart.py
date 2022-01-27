n = int(input())


def toString(k):
    if k == 1:
        return "single"
    elif k == 2:
        return "double"
    else:
        return "triple"


for i in range(21):
    for j in range(21):
        for k in range(21):
            for a in range(1, 4):
                for b in range(1, 4):
                    for c in range(1, 4):
                        if a * i + b * j + c * k == n:
                            if i:
                                print(f"{toString(a)} {i}")
                            if j:
                                print(f"{toString(b)} {j}")
                            if k:
                                print(f"{toString(c)} {k}")
                            exit()

print("impossible")
