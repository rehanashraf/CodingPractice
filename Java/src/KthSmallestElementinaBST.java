import apple.laf.JRSUIUtils;

import java.util.PriorityQueue;

public class KthSmallestElementinaBST
{
    public static PriorityQueue<Integer> pq = null;
    public  static int kthSmallest(TreeNode root, int k)
    {
        pq = new PriorityQueue<>(k, (a,b)-> b-a);
        if(root == null){
            return -1;
        }
        kthSmallestHelper(root, k);
        return pq.poll();

    }
    public  static void kthSmallestHelper(TreeNode root, int k)
    {
        if(root == null)
        {
            return;
        }
        if(pq.size() < k){
            pq.add(root.val);
        }
        else{
            if(root.val < pq.peek()){
                pq.poll();
                pq.add(root.val);
            }
        }

        kthSmallestHelper(root.left, k);
        kthSmallestHelper(root.right, k);


    }


    public static void main(String[] args) {
        TreeNode root = new TreeNode(5);
        root.left = new TreeNode(3);
        root.right = new TreeNode(6);
        root.left.left = new TreeNode(2);
        root.left.right = new TreeNode(4);
        root.left.left.left = new TreeNode(1);

       // [5,3,6,2,4,null,null,1]

        System.out.println(kthSmallest(root, 1));
//        System.out.println(pq.poll());
//        System.out.println(pq.poll());
//        System.out.println(pq.toString());
    }
}
