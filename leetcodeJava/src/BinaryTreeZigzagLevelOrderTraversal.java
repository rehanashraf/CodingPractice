import javax.lang.model.type.ArrayType;
import java.util.*;

public class BinaryTreeZigzagLevelOrderTraversal {

    public static List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue<TreeNode> queue = new LinkedList<>();
        List<List<Integer>> result = new ArrayList<>();
        if(root == null){
            return null;
        }
        queue.add(root);
        boolean zigZagFlag = false;
        while(!queue.isEmpty()){
            List<Integer> list = new ArrayList<>();
            int len = queue.size();
            while(len > 0){
                TreeNode cur = queue.poll();
                if(zigZagFlag){
                    list.add(0,cur.val);
                }
                else {
                    list.add(cur.val);
                }
                if(cur.left != null){
                    queue.add(cur.left);
                }
                if(cur.right!= null){
                    queue.add(cur.right);
                }
                len--;

            }
            zigZagFlag = !zigZagFlag;
            result.add(list);

        }
        return result;


    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);
        List<List<Integer>> list = zigzagLevelOrder(root);
        System.out.println(list.toString());
    }
}
