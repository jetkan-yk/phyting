import heapq

"""
Merge k sorted arrays into one sorted array
Assuming there are n items in total and k (non-empty) sorted arrays

1. Build a min-heap using the smallest element in all k sorted arrays, O(k) time
2. While min-heap is not empty do:
    2.1. Extract the root of the min-heap and append to the final array, O(log k) time
    2.2. Replace the extracted root with next smallest element from the origin array, O(log k) time

Since step 2 repeats until all n elements are extracted from the sorted arrays, the time complexity
of step 2 is O(n log k). Therefore, the total time complexity is O(n log k)

We need a n-size array to store the final answer since the implementation is not in-place, and a k-size
min-heap to perform heappush and heappop, the total space complexity os O(n + k).

- Jet Kan, 17 Jan 2022
"""
def MergeAll(arrays):
    # We reverse the order of every sorted arrays to make removal operation O(1) time
    arrays = [a[::-1] for a in arrays]

    # Build the min-heap, O(k) time
    # Each item in min-heap is (elem, array_index)
    # This configuration also ensures the final sorted array to be stable
    pq = [(a[-1], i) for i, a in enumerate(arrays)]
    heapq.heapify(pq)

    # Store the final sorted array in answer
    answer = []

    # While the min-heap is not empty
    while len(pq):
        # Extract the current smallest elem, O(log k) time
        elem, i = heapq.heappop(pq)

        # Insert the current smallest elem into the final array
        answer.append(elem)

        # Remove the elem from its origin array
        arrays[i].pop()
        # Then replace the elem with next smallest elem from the origin array
        if len(arrays[i]):
            heapq.heappush(pq, (arrays[i][-1], i))

    return answer


# Testing
arrays = [[1, 2], [2, 4, 7], [6]]
print(MergeAll(arrays))



