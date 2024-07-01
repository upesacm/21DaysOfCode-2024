import java.util.Queue;
import java.util.LinkedList;
public class Day10_2{
  static Queue<Integer> queue;
  static void Print()
  {
    while (!queue.isEmpty())
    {
      System.out.print(queue.peek() + " ");
      queue.remove();
    }
  }
static Queue<Integer> revQueue(Queue<Integer> q)
{
  if (q.isEmpty())
    return q;
  int data = q.peek();
  q.remove();
  q = revQueue(q);
  q.add(data);
    
  return q;
}
public static void main(String args[])
{
  queue = new LinkedList<Integer>();
  queue.add(1);
  queue.add(2);
  queue.add(3);
  queue.add(4);
  queue.add(5);
  queue = revQueue(queue);
  Print();
}
}