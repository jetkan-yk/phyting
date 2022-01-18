def reverse(s, i, j):
    return s[i::-1] + s[j:i:-1] + s[:j:-1]


s = input()

ans = s
for i in range(len(s) - 1):
    for j in range(i + 1, len(s) - 1):
        ans = min(ans, reverse(s, i, j))

print(ans)
