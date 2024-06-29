import java.util.HashSet;
import java.util.Scanner;

public class a6_q1 {
    int data;
    a6_q1 next;

    static void createList(a6_q1 head, int n) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter data for element 1 : ");
        head.data = scanner.nextInt();
        head.next = null;
        a6_q1 temp = head;
        for (int i = 1; i < n; i++) {
            a6_q1 newa6_q1 = new a6_q1();
            System.out.print("Enter data for element " + (i + 1) + " : ");
            newa6_q1.data = scanner.nextInt();
            newa6_q1.next = null;
            temp.next = newa6_q1;
            temp = newa6_q1;
        }
        temp.next =head;
        scanner.close();
    }


    static boolean checkLoop(a6_q1 head){
      HashSet<a6_q1> checkSet = new HashSet<>();
      a6_q1 temp = head;
      if(temp.next==null)
      {
        System.out.println("Not loop");
      }
      else{
        while(temp!=null){
            System.out.println(temp.data);
            if(!checkSet.contains(temp)){
                checkSet.add(temp);
                temp= temp.next;
            }
            else{
                return true;
            }
        }
      }
      return false;
    }


    public static void main(String[] args) {
        a6_q1 head = new a6_q1();
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter number of elements : ");
        int n = scanner.nextInt();
        createList(head, n);
        boolean loop = checkLoop(head);
        if(loop == true){
            System.out.println("loop");
        }
        else{
            System.out.println("Not Loop");
        }
        scanner.close();
    }
}