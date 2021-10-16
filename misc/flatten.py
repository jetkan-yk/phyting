def flatten(lst):
    for elem in lst:
        if isinstance(elem, int):
            yield elem
        else:
            yield from flatten(elem)


L = [[[1, 2, 3], [4, 5]], 6]

print(list(flatten(L)))
