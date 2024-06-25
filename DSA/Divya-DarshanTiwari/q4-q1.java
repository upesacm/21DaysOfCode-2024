import java.util.*;

class a4_q1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the string");
        String word = sc.nextLine();
        System.out.println("Enter the length of the sub string");
        int sub_len = sc.nextInt();
        int len = word.length();
        int z = distinct(word, len, sub_len);

        System.out.println(z);
        sc.close();
    }

    public static int distinct(String word, int len, int sub_len) {
        HashSet<String> set = new HashSet<>();

        for (int i = 0; i < len - sub_len + 1; i++) {
            String s = word.substring(i, sub_len + i);
            System.out.println(s);
            boolean z = panl(s, sub_len);
            if(z){
                set.add(s);
            }
        }

        return set.size();
    }

    public static boolean panl(String s,int sub_len) {
        int lenth = s.length();
        for(int i=0,j=lenth-1;i<lenth/2;i++)
        {
            if(s.charAt(i) != s.charAt(j)){
                return false;
            }
        }
        return true;
    }
}