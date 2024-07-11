import java.util.*;

public class pq {
    private List<Integer> heap;
    public pq() {
        heap = new ArrayList<>();
    }
    public void ins(int val) 
    {
        heap.add(val);
        int ind = heap.size() - 1;
        while (ind > 0) {
            int ptind = (ind - 1) / 2;
            if (heap.get(ptind) <= heap.get(ind) ) 
            {
                break;
            }
            swap(ptind, ind);
            ind = ptind;
        }
    }
    public int extmin() {
        if (heap.isEmpty()) {
            throw new RuntimeException("Priority queue is empty");
        }
        int min = heap.get(0);
        heap.set(0, heap.get(heap.size() - 1));
        heap.remove(heap.size() - 1);
        heapify(0);
        return min;
    }
    private void heapify(int ind) {
        int sml = ind;
        int l = 2 * ind + 1;
        int r = 2 * ind + 2;

        if (l <  heap.size() && heap.get(l) < heap.get(sml)) {
            sml = l;
        }
        if (r< heap.size() &&  heap.get(r) < heap.get(sml))  
        {
            sml = r;
        }
        if (sml != ind) {
            swap(sml, ind);
            heapify(sml);
        }
    }
    private void swap(int i, int j) 
    {
        int temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp) ;
    }
    public static void main(String[] args) 
    {
        pq ob = new pq();
        ob.ins(4);
        ob.ins(2);
        System.out.println(ob.extmin()) ; 
        System.out.println(ob.extmin()); 
    }
}
