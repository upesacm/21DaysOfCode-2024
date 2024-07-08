class tn {
    int val;
    tn l ,r;

    tn(int val) 
    {
        this.val = val;
    }
}
public class day15q1 {
    public static int th(tn root) {
        if (root == null) {
            return -1;  
        }
        int lh = th(root.l);
        int rh = th(root.r);
        return Math.max(lh, rh) + 1 ;
    }
    public static void main(String[] args)
     {
        tn rt = new tn(3);
        rt.l = new tn(1) ;
        rt.r = new tn(4);
        rt.r.r = new tn(6);
        int height = th(rt);
        System.out.println("The height is: " + height) ;
    }
}
