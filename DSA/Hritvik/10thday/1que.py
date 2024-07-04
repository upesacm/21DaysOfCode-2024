def reverse_queue(queue):
    if len(queue) == 0:
        return queue
    
    front = queue.pop(0)
    reversed_queue = reverse_queue(queue)
    reversed_queue.append(front)
    return reversed_queue

if __name__ == "__main__":
    q = [1, 2, 3]
    print("Original queue:",q)  
    reversed_q = reverse_queue(q)
    print("Reversed queue:",reversed_q)  
