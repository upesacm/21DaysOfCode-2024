import java.util.LinkedList;

public class LinkedListequality {
public static void main(String []args){
    LinkedList<Integer> l1= new LinkedList<>();
    LinkedList<Integer> l2= new LinkedList<>();
     l1.add(1);
     l1.add(5);
     l1.add(6);
     l2.add(1);
     l2.add(5);
     l2.add(6);
 
   Linkedlistequality(l1,l2);
}

public static void Linkedlistequality(LinkedList<Integer>l1,LinkedList<Integer>l2)
{
     int flag=1;
       if (l1.size() != l2.size()) {
            flag=0;
        }
      else{
        for (int i = 0; i < l1.size(); i++) {
           if(l1.get(i)!=l2.get(i)){
                 flag=0;
                 break;
            };
        };
         }
       if(flag==0)
       {
        System.out.print("The two LinkedList's are not  equal");
        }
       else
       { 
        System.out.print("The two LinkedList's are equal");
       }

   }
}
