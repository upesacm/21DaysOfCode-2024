Day10-Question2-
class QueueUsingStacks:
    def __init__(self):
        self.stack_in = []
        self.stack_out = []

    def enqueue(self, item):
        self.stack_in.append(item)
        print(f"Enqueued {item}")

    def dequeue(self):
        if not self.stack_out:
            while self.stack_in:
                self.stack_out.append(self.stack_in.pop())
        if not self.stack_out:
            print("Queue is empty")
            return None
        return self.stack_out.pop()

queue = QueueUsingStacks()

while True:
    command = input("Enter a command (enqueue <value>, dequeue, or exit): ").strip().lower()
    if command.startswith("enqueue"):
        try:
            _, value = command.split()
            value = int(value)
            queue.enqueue(value)
        except ValueError:
            print("Please provide a valid integer value to enqueue.")
    elif command == "dequeue":
        result = queue.dequeue()
        if result is not None:
            print(f"Dequeued {result}")
    elif command == "exit":
        break
    else:
        print("Invalid command. Please enter 'enqueue <value>', 'dequeue', or 'exit'.")
