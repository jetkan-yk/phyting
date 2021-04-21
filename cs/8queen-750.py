# UVa - 750 8 Queens Chess Problem
'''
    Classic N-Queens Problem
    Recursive backtracking Complete Search with Pruning and Bit Manipulation
    Sub O(n!) solution
'''
import sys


def check_row(i):
    global row_mask
    return not (row_mask & (1 << i))


def check_ld(i):
    global ld_mask
    return not (ld_mask & (1 << i))


def check_rd(i):
    global rd_mask
    return not (rd_mask & (1 << i))


def canPlace(r, c):
    if c == C and r != R:  # must place 1 queen at (R, C)
        return False
    return check_row(r) and check_ld(r - c + 7) and check_rd(r + c)


def toggle(r, c):
    global row_mask, ld_mask, rd_mask
    row_mask ^= (1 << r)
    ld_mask ^= (1 << (r - c + 7))
    rd_mask ^= (1 << (r + c))
    ans[c] = r if ans[c] is None else None


def solve(c):
    global numSolved, outputs
    if c == 9:
        numSolved += 1
        return outputs.append('{:2d}      {}'.format(
            numSolved, ' '.join(map(str, ans[1:]))))

    for r in range(1, 9):
        if canPlace(r, c):
            toggle(r, c)  # set bits on
            solve(c + 1)
            toggle(r, c)  # set bits off


inputs = sys.stdin.read().splitlines()
outputs = []

TC = int(inputs[0])

for i in range(1, TC + 1):
    R, C = map(int, inputs[i * 2].split())

    if i > 1:
        outputs.append('')
    outputs.append('SOLN       COLUMN')
    outputs.append(' #      1 2 3 4 5 6 7 8\n')
    numSolved = row_mask = ld_mask = rd_mask = 0
    ans = [None] * 9
    solve(1)

sys.stdout.write('\n'.join(outputs) + '\n')