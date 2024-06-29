#Binary Puzzle Quest
# Author - Ayush Dey

def min_operations(str):
    prefix_x_count = 0
    suffix_y_count = 0

    # Traversal r to l
    for char in str:
        if char == 'x':
            prefix_x_count += 1
        else:
            break

    # Traverseal l to r
    for char in reversed(str):
        if char == 'y':
            suffix_y_count += 1
        else:
            break

    #
    answer = min(prefix_x_count, suffix_y_count)
    return answer


input_str = input()
output = min_operations(input_str)

print(output)