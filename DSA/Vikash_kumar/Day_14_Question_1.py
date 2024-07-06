Day14-Quiz2-Question1-
def min_moves(n, heights):
    moves = 0

    while True:
        to_remove = []
        for i in range(1, len(heights)):
            if heights[i - 1] > heights[i]:
                to_remove.append(i)

        if not to_remove:
            break

        heights = [heights[i] for i in range(len(heights)) if i not in to_remove]

        moves += 1

    return moves

n = int(input("Number of students : "))
heights = list(map(int, input("Enter the heights of students with space : ").split()))

# Output the result
print(min_moves(n, heights))
