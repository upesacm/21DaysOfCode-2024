class Node {
    int data;
    Node next;

    Node () {
        this.next = null;
    }

    Node (int data) {
        this.data = data;
        this.next = null;
    }
}

class LinkList {
    Node head;

    LinkList() {
        this.head = null;
    }

    LinkList(int[] arr) {
        this.head = null;
        for (int i : arr) {
            this.insert(i);
        }
    }

    public void insert(int data) {
        Node new_node = new Node(data);
        
        if (head == null) {
            head = new_node;
        }
        else {
            Node temp = head;

            while(temp.next != null) {
                temp = temp.next;
            }
            
            temp.next = new_node;
        }
    }

    public void display() {
        Node temp = head;

        while(temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }

        System.out.println("null");
    }

    public int length() {
        Node temp = head;
        int length = 0;

        while (temp != null) {
            length++;
            temp = temp.next;
        }

        return length;
    }

    public boolean hasLoop() {
        Node slow = head;
        Node fast = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
            
            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
}

public class Q2 {
    public static Node solution(LinkList list1, LinkList list2) {
        int len1 = list1.length();
        int len2 = list2.length();
        Node temp1 = list1.head;
        Node temp2 = list2.head;
        
        if (len1 > len2) {
            temp1 = moveKTimes(list1, len1 - len2);
        }
        else {
            temp2 = moveKTimes(list2, len2 - len1);
        }


        while (temp1 != null && temp2 != null) {
            if (temp1 == temp2) {
                return temp1;
            }

            temp1 = temp1.next;
            temp2 = temp2.next;
        }

        return null;
    }

    public static Node moveKTimes(LinkList list, int k) {
        Node temp = list.head;

        while (k > 0 && temp != null) {
            k--;
            temp = temp.next;
        }

        return temp;
    } 


    public static void main(String[] args) {
        LinkList list1 = new LinkList();
        list1.insert(1);
        list1.insert(2);
        list1.insert(3);
        Node mergeNode = new Node(4);
        list1.head.next.next.next = mergeNode; // 1 -> 2 -> 3 -> 4
        list1.insert(5);
        list1.insert(6);

        LinkList list2 = new LinkList();
        list2.insert(7);
        list2.head.next = mergeNode; // 7 -> 4
        list2.insert(8);
        list2.insert(9);

        list1.display(); // Display list 1: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> null
        list2.display(); // Display list 2: 7 -> 4 -> 5 -> 6 -> null

        Node mergePoint = solution(list1, list2);
        if (mergePoint != null) {
            System.out.println("Merge point data: " + mergePoint.data);
        } else {
            System.out.println("No merge point found.");
        }
    }
}