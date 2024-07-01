#Day9-Question1-
class MaxStack:
    def __init__(self):
        self.main_stack = []
        self.max_stack = []

    def push(self, x):
        self.main_stack.append(x)
        if not self.max_stack or x >= self.max_stack[-1]:
            self.max_stack.append(x)

    def pop(self):
        if not self.main_stack:
            raise IndexError("pop from empty stack")
        popped_element = self.main_stack.pop()
        if popped_element == self.max_stack[-1]:
            self.max_stack.pop()
        return popped_element

    def get_max(self):
        if not self.max_stack:
            raise IndexError("max from empty stack")
        return self.max_stack[-1]

def main():
    stack = MaxStack()

    while True:
        print("\nChoose an operation:")
        print("1. Push")
        print("2. Pop")
        print("3. Get Max")
        print("4. Exit")

        choice = input("Enter choice (1/2/3/4): ").strip()

        if choice == '1':
            try:
                value = int(input("Enter value to push: "))
                stack.push(value)
                print(f"Pushed {value} onto the stack.")
            except ValueError:
                print("Please enter a valid integer.")

        elif choice == '2':
            try:
                popped_value = stack.pop()
                print(f"Popped {popped_value} from the stack.")
            except IndexError as e:
                print(e)

        elif choice == '3':
            try:
                max_value = stack.get_max()
                print(f"Current max value in the stack is {max_value}.")
            except IndexError as e:
                print(e)

        elif choice == '4':
            print("Exiting...")
            break

        else:
            print("Invalid choice. Please choose a valid operation.")
main()
