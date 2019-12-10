import java.util.LinkedList;
import java.util.Queue;

public class MaxLevelSum
{
    public static int maxLevelSumBFS(TreeNode root) {
        if(root == null){
            return -1;
        }
        int level = 0;
        int curLevel  =0;
        int sum = Integer.MIN_VALUE;
        // int[] sums = new int[];
        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);
        while(!queue.isEmpty()){
            curLevel++;
            int curSum = 0;
            int len = queue.size();
            for(int i=0 ; i<len; i++){
                TreeNode node = queue.poll();
                curSum += node.val;
                if(node.left != null) queue.add(node.left);
                if(node.right != null) queue.add(node.right);

            }
            if(curSum > sum){
                level = curLevel;
                sum =curSum;
            }



        }
        return level;



    }


   static int n = 10000;
   static int[] levelSum = new int[n];

    public static void inorder(TreeNode node, int level) {
        if (node != null) {
            inorder(node.left, level + 1);
            levelSum[level] += node.val;
            inorder(node.right, level + 1);
        }
    }

    public static int maxLevelSum(TreeNode root) {
        inorder(root, 1);

        int maxIdx = 0;
        for (int i = 0; i < n; ++i)
            maxIdx = levelSum[i] > levelSum[maxIdx] ? i : maxIdx;
        return maxIdx;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(7);
        root.right = new TreeNode(0);
        root.left.left = new TreeNode(7);
        root.left.right = new TreeNode(-8);


        int level = maxLevelSum(root);
        System.out.println(level);
    }
}
