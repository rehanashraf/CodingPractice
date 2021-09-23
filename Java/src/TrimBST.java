public class TrimBST {

    public static TreeNode trimBST(TreeNode root, int L, int R) {
        if (root == null) {
            return root;
        }
        if (root.val >= L) {
            if (root.val > R) {
                root = null;

            }
            {
                trimBST(root.left, L, R);
                trimBST(root.right, L, R);
            }
        } else {
            root = root.right;  //trimBST(root.right, L,R);
        }

        return root;
    }


    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(0);
        root.right = new TreeNode(2);
        trimBST(root, 1, 2);
        System.out.println(root.val);
    }
}
