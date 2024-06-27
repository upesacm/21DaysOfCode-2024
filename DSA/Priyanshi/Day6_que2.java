import java.util.*;
import java.io.*;


class Day6_que2
{

    static class Node 
    {
        int data;
        Node next;
        Node(int d)
        {
            data = d;
            next = null;
        }
    }


    public Node getMergePoint(Node head1, Node head2)
    {
        while (head2 != null) {
            Node temp = head1;
            while (temp != null) {
                if (temp == head2) {
                    return head2;
                }
                temp = temp.next;
            }
            head2 = head2.next;
        }
        return null;
    }

    public static void main(String[] args)
    {
        Day6_que2 list = new Day6_que2();

        Node head1, head2;

          /*
                Create two linked lists

                1st 3->6->9->15->30
                2nd 10->15->30

                15 is the intersection point
        */


        head1 = new Node(10);
        head2 = new Node(3);

        Node newNode = new Node(6);
        head2.next = newNode;

        newNode = new Node(9);
        head2.next.next = newNode;

        newNode = new Node(15);
        head1.next = newNode;
        head2.next.next.next = newNode;

        newNode = new Node(30);
        head1.next.next = newNode;

        head1.next.next.next = null;

        Node MergePoint
            = list.getMergePoint(head1, head2);

        if (MergePoint == null) {
            System.out.print(" No Merge Point \n");
        }
        else {
            System.out.print("Merge Point: " + MergePoint.data);
        }
    }
}
