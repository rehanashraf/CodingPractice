import java.util.ArrayList;
import java.util.List;

public class FindLeavesOfBinaryTree
{
    static List<List<Integer>> result = new ArrayList<>();
    public static List<List<Integer>> findLeaves(TreeNode root) {
            if(root == null){
                return result;
            }
            while(root.left != null || root.right != null) {
                ArrayList<Integer> lst = new ArrayList<>();
                findLeavesHelper(root, lst);
                result.add(lst);
            }
        ArrayList<Integer> lst = new ArrayList<>();
            lst.add(root.val);
            result.add(lst);
            return result;
    }

    public static boolean findLeavesHelper(TreeNode root, List<Integer> list) {
        if(root == null){
            return false;
        }
        if(root.left == null && root.right == null){
            list.add(root.val);
            root = null;
            return true;
        }
        boolean a1 = findLeavesHelper(root.left, list);
        boolean a2 = findLeavesHelper(root.right, list);
        if(a1){
            root.left = null;
        }
        if(a2){
            root.right = null;
        }
        return false;

    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
       // root.left.left.left = new TreeNode(1);

        findLeaves(root);
        System.out.println("Done");
    }




}
