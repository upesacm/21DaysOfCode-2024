import java.util.ArrayList;
import java.util.List;

class pq {
    private List<Integer> heap;
    public pq() 
    {
        this.heap = new ArrayList<>() ;
    }
    public void ins(int val) {
        heap.add(val);
        siftup(heap.size() - 1) ;
    }
    public int exmin() {
        if (heap.isEmpty()) 
        {
            throw new IllegalStateException("Priority queue is empty");
        }
        int min = heap.get(0);
        int lastel = heap.remove(heap.size() - 1);
        if (!heap.isEmpty()) 
        {
            heap.set(0, lastel);
            siftdn(0);
        }

        return min;
    }
    private void siftup(int index) {
        int pind = (index - 1) / 2;
        while (index > 0 && heap.get(index) < heap.get(pind)) {
            swap(index, pind);
            index = pind;
            pind = (index - 1) / 2;
        }
    }
    private void siftdn(int index) {
        int minind = index;
        int lc = 2 * index + 1;
        int rc = 2 * index + 2;
        if (lc < heap.size() && heap.get(lc) < heap.get(minind)) {
          minind = lc;
        }
        if (rc < heap.size() && heap.get(rc) < heap.get(minind)) {
          minind = rc;
        }
        if (index != minind) {
            swap(index, minind);
            siftdn(minind);
        }
    }
    private void swap(int i, int j) 
    {
        int temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
    }
    public boolean isEmpty() 
     {
        return heap.isEmpty();
    }
    public static void main(String[] args) 
    {
        pq ob = new pq();
        ob.ins(4);
        ob.ins(2);
        System.out.println(ob.exmin()); 
        System.out.println(ob.exmin()) ; 
    }
}
