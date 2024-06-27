import java.util.HashSet;
import java.util.Scanner;

public class a6_q2 {

    int data;
    a6_q2 next;

    static void createList(a6_q2 head1, a6_q2 head2, int n, int k, Scanner scanner) {
        System.out.print("Enter data for element 1 of list 1: ");
        head1.data = scanner.nextInt();
        head1.next = null;
        a6_q2 temp = head1;
        for (int i = 1; i < n; i++) {
            a6_q2 newa6_q2 = new a6_q2();
            System.out.print("Enter data for element " + (i + 1) + " : ");
            newa6_q2.data = scanner.nextInt();
            newa6_q2.next = null;
            temp.next = newa6_q2;
            temp = newa6_q2;
        }
        System.out.print("Enter data for element 1 of list 2: ");
        head2.data = scanner.nextInt();
        head2.next = null;
        a6_q2 temp2 = head2;
        for (int i = 1; i < k; i++) {
            a6_q2 newa6_q2 = new a6_q2();
            System.out.print("Enter data for element " + (i + 1) + " : ");
            newa6_q2.data = scanner.nextInt();
            newa6_q2.next = null;
            temp2.next = newa6_q2;
            temp2 = newa6_q2;
        }

         a6_q2 jointa6_q2 = new a6_q2();
        jointa6_q2.data = 10;
        jointa6_q2.next = null;
        temp.next = jointa6_q2;
        temp2.next = jointa6_q2;

    }

    static a6_q2 checkJoint(a6_q2 head1, a6_q2 head2) {
        HashSet<a6_q2> set = new HashSet<>();
        a6_q2 temp= new a6_q2();
        temp.data=0;
        temp.next =null;
        a6_q2 temp1 = head1;
        a6_q2 temp2 = head2;
        if (temp1 == temp2) {
            return temp1;
        } else {
            while (temp1 != null) {
                set.add(temp1);
                temp1 = temp1.next;
            }
            while (temp2 != null) {
                if (!set.contains(temp2)) {
                    set.add(temp2);
                    temp2 = temp2.next;
                } else {
                    temp = temp2;
                    return temp;
                }
            }

        }

        return temp;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        a6_q2 head1 = new a6_q2();
        a6_q2 head2 = new a6_q2();
        System.out.println("Enter the length of the two list");
        int n1 = sc.nextInt();
        int n2 = sc.nextInt();

        createList(head1, head2, n1, n2, sc);
        a6_q2 point = checkJoint(head1, head2);

        System.out.println("the point of joint is:" + point.data);

        sc.close();

    }

}
