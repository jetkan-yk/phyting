from itertools import permutations


def count_repeat(s1, s2):
    i = j = ans = 0

    while i < len(s1) and j < len(s2):
        if s1[i] == s2[j]:
            i += 1
            j += 1
            ans += 1
        elif s1[i] < s2[j]:
            i += 1
        else:
            j += 1

    return ans


if __name__ == "__main__":
    n = int(input())

    s = []
    for _ in range(n):
        s.append(input())

    repeat = [[0 for _ in range(n)] for _ in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            repeat[i][j] = count_repeat(s[i], s[j])
            repeat[j][i] = repeat[i][j]

    ans = 1000
    for perm in permutations(range(n)):
        cur = 0
        for i in range(n - 1):
            cur += repeat[perm[i]][perm[i + 1]]
        ans = min(ans, cur)

    print(ans)
