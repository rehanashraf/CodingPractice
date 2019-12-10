public class PathSum {

    static boolean Extreme = true;
    public static boolean hasPathSum(TreeNode root, int sum) {
        if(root == null){
            return false;
        }
        return pathHelper(root, sum);

    }

    public static boolean pathHelper(TreeNode root, int sum){
        if(root == null){
            if(sum != 0){
                return false;
            }
            else {
                return true;
            }
        }
        boolean l = false;
        boolean r = false;
        if(root.left != null){
            if(root.right != null){
                l = pathHelper(root.left, sum - root.val);
                r = pathHelper(root.right, sum - root.val);
            }
            else{
                l = pathHelper(root.left, sum - root.val);
                //   r = pathHelper(root.right, sum - root.val);
            }
        }
        else{
            if(root.right != null){
                //  boolean l = pathHelper(root.left, sum - root.val);
                r = pathHelper(root.right, sum - root.val);
            }
            else {
                l = pathHelper(root.left, sum - root.val);
                r = pathHelper(root.right, sum - root.val);
            }

        }



        if(l || r){
            return true;
        }
        return false;

    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(-2);
        root.left = null;
        root.right = new TreeNode(-3);

        boolean s = hasPathSum(root, -2);
        System.out.println(s);

    }
}

//    TreeNode ll = invertTreeHelper(root.left);
//    TreeNode rr = invertTreeHelper(root.right);
//    int llv = ll.val;
//    int llr = rr.val;
//
//        ll.val = llr;
//                rr.val = llv;
