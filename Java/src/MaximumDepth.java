import java.util.LinkedList;
import java.util.Queue;

public class MaximumDepth {
    public static int maxDepth(TreeNode root) {
        LinkedList<TreeNode> stack = new LinkedList<>();
        LinkedList<Integer> depths = new LinkedList<>();
        if (root == null) return 0;

        stack.add(root);
        depths.add(1);

        int depth = 0, current_depth = 0;
        while (!stack.isEmpty()) {
            root = stack.pollLast();
            current_depth = depths.pollLast();
            if (root != null) {
                depth = Math.min(depth, current_depth);
                stack.add(root.left);
                stack.add(root.right);
                depths.add(current_depth + 1);
                depths.add(current_depth + 1);
            }
        }
        return depth;
    }

    public static int minDepthHelper2(TreeNode root) {
        if(root == null){
            return 0;
        }
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        int minDepth = 0;
        boolean found = false;
        while(!queue.isEmpty()) {
            int len = queue.size();
            minDepth++;
            for(int i=0; i < len; i++) {
                TreeNode current = queue.poll();
                if(current.left == null && current.right == null){
                    found = true;
                    break;
                }
                if(current.left != null) queue.add(current.left);
                if(current.right != null) queue.add(current.right);

            }


            if(found){
                break;
            }
            // minDepth++;


        }
        return minDepth;

    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(9);
        root.right = new TreeNode(20);
        root.right.left = new TreeNode(15);
        root.right.right = new TreeNode(7);

        int dep = minDepthHelper2(root);
        System.out.println(dep);


    }


}