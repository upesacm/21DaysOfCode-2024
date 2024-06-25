class Node {
    int data;
    Node next;

    Node(int data) {
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

    public boolean isEqual(LinkList list) {
        Node temp1 = this.head;
        Node temp2 = list.head;

        while (temp1 != null && temp2 != null) {
            if (temp1.data != temp2.data) {
                return false;
            }
            temp1 = temp1.next;
            temp2 = temp2.next;
        }
        
        if (temp1 != null || temp2 != null) {
            return false;
        }
        else {
            return true;
        }
    }
}

public class Q2 {
    public static void main(String[] args) {
        int[] input1 = {1, 2, 3};
        int[] input2 = {1, 2, 3};
        LinkList list1 = new LinkList(input1);
        LinkList list2 = new LinkList(input2);

        if (list1.isEqual(list2)) {
            System.out.println("identical");
        }
        else {
            System.out.println("different");
        }
    }
} 