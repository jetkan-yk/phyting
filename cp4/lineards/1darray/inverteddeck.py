def main():
    n = int(input())
    cards = list(map(int, input().split()))
    sorted_cards = sorted(cards)

    left = n
    right = 0
    for i in range(n):
        if cards[i] != sorted_cards[i]:
            left = min(left, i)
            right = max(right, i)

    l = left
    r = right
    while l < r:
        cards[l], cards[r] = cards[r], cards[l]
        l += 1
        r -= 1

    if left == n and right == 0:
        print(1, 1)
    elif cards == sorted_cards:
        print(left + 1, right + 1)
    else:
        print("impossible")


if __name__ == "__main__":
    main()
