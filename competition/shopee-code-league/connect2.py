# Write your code here
T = int(input())

while T > 0:
    int_list = [int(x) for x in input().split()]
    up_down_store = {}
    start_end_index = {}
    visited = set()
    printed_no = False

    for i in range(len(int_list)):
        int_list[i] = int(int_list[i])
        if int_list[i] not in start_end_index:
            start_end_index[int_list[i]] = i
        else:
            start_end_index[int_list[i]] = (start_end_index[int_list[i]], i)

    todo = []
    for num in int_list:
        if num in visited:
            continue
        visited.add(num)
        start, end = start_end_index[num]
        can_be_assigned = True
        # try assigning up
        # in_visited = set()
        for i in range(start + 1, end):
            test_num = int_list[i]
            # if test_num in in_visited:
            # continue
            # in_visited.add(test_num)
            if test_num in up_down_store and up_down_store[test_num] == True:
                test_start, test_end = start_end_index[test_num]
                if start < test_start < end and start < test_end < end:
                    continue
                else:
                    can_be_assigned = False
                    break
        if can_be_assigned == True:
            up_down_store[num] = True
        else:
            todo.append()

            # try assigning down
            can_be_assigned = True
            # in_visited = set()
            for i in range(start + 1, end):
                test_num = int_list[i]
                # if test_num in in_visited:
                # continue
                # in_visited.add(test_num)
                if test_num in up_down_store and up_down_store[test_num] == False:
                    test_start, test_end = start_end_index[test_num]
                    if start < test_start < end and start < test_end < end:
                        continue
                    else:
                        can_be_assigned = False
                        break

            if can_be_assigned == True:
                up_down_store[num] = False
            else:
                printed_no = True
                print("no")
                break
    if not printed_no:
        print("yes")

    T -= 1
