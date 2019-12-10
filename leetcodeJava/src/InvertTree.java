/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class InvertTree {

    public static TreeNode invertTree(TreeNode root)
    {
        if(root == null){
            return null;
        }
        invertTreeHelper(root);
        return root;
    }

    public static void invertTreeHelper(TreeNode root){

        if(root == null){
            return;
        }

        invertTreeHelper(root.left);
        invertTreeHelper(root.right);
        if(root.left != null && root.right != null){
            TreeNode r = root.right;
            TreeNode l = root.left;
            root.left = r;
            root.right = l;
        }
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(7);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(9);
        invertTree(root);
    }





//         Queue<TreeNode> queue = LinkedList<>();
//         queue.push(root);
//         while(!queue.isEmpty()){
//             TreeNode cur = queue.poll();


//         }

}
