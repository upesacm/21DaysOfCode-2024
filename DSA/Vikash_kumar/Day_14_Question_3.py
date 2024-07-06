Day14-Quiz2-Question3-
def min_bulbs(n, hallway):
    ranges = []

    for i in range(n):
        if hallway[i] != -1:
            ranges.append((max(0, i - hallway[i]), min(n - 1, i + hallway[i])))

    ranges.sort()

    bulbs = 0
    covered_end = -1
    i = 0

    while covered_end < n - 1:
        new_covered_end = covered_end
        while i < len(ranges) and ranges[i][0] <= covered_end + 1:
            new_covered_end = max(new_covered_end, ranges[i][1])
            i += 1

        if new_covered_end == covered_end:
            return -1

        covered_end = new_covered_end
        bulbs += 1

    return bulbs

n = int(input("Enter the number of partitions in the hallway: "))
hallway = list(map(int, input("Enter the power of bulbs at each partition (space-separated): ").split()))

result = min_bulbs(n, hallway)

print(result)
