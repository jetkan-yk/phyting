import itertools
import random

n = 3
sn = 30
lst = list(itertools.permutations([*range(1, n + 1), range(1, n + 1)]))
lst = random.sample(lst, sn)
print(sn)
for l in lst:
    print(n)
    print(l)
