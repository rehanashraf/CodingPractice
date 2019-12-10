/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class BSTToGST {
 public static int cur = 0;
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public static TreeNode bstToGst(TreeNode root) {

        bstToGstHelper(root);
        return root;
    }

    public static void bstToGstHelper(TreeNode root)
    {
        if(root == null){
            return ;
        }
        bstToGstHelper(root.right);
        root.val = root.val + cur;
        cur = root.val;
        bstToGstHelper(root.left);
        return;

    }

    public static void main(String[] args) {

        TreeNode root = new TreeNode(4);
        root.left =  new TreeNode(3);
        root.right = new TreeNode(6);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(2);
        root.right.left = new TreeNode(5);
        root.right.right = new TreeNode(7);
        root.right.right.right = new TreeNode(8);

        bstToGst(root);
    }
}