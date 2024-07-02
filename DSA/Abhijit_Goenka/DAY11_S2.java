import java.util.ArrayList;
import java.util.NoSuchElementException;

class DAY11_S2
{
    public ArrayList<Integer> heap;

    public DAY11_S2() 
    {
        heap = new ArrayList<>();
    }

    public void insert(int value) 
    {
        heap.add(value);
        int index = heap.size() - 1;
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap.get(index) >= heap.get(parentIndex)) 
            {
                break;
            }
            swap(index, parentIndex);
            index = parentIndex;
        }
    }

    public int extractMin() {
        if (heap.isEmpty()) {
            throw new NoSuchElementException("Priority queue is empty");
        }
        int minValue = heap.get(0);
        int lastValue = heap.remove(heap.size() - 1);
        if (!heap.isEmpty()) {
            heap.set(0, lastValue);
            int index = 0;
            while (true) 
            {
                int leftChildIndex = 2 * index + 1;
                int rightChildIndex = 2 * index + 2;
                int smallestIndex = index;

                if (leftChildIndex < heap.size() && heap.get(leftChildIndex) < heap.get(smallestIndex)) 
                {
                    smallestIndex = leftChildIndex;
                }

                if (rightChildIndex < heap.size() && heap.get(rightChildIndex) < heap.get(smallestIndex)) 
                {
                    smallestIndex = rightChildIndex;
                }

                if (smallestIndex == index) 
                {
                    break;
                }

                swap(index, smallestIndex);
                index = smallestIndex;
            }
        }
        return minValue;
    }

    private void swap(int i, int j) 
    {
        int temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
    }

    public static void main(String[] args) 
    {
        DAY11_S2 priorityQueue = new DAY11_S2();
        
        priorityQueue.insert(4);
        priorityQueue.insert(2);
        
        System.out.println(priorityQueue.extractMin()); 
        System.out.println(priorityQueue.extractMin()); 
    }
}
