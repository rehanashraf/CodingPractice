import java.util.*;

public class Testing {
        static List<List<Integer>> levels = new ArrayList<List<Integer>>();

        public static void helper(MaximumBinaryTree.TreeNode node, int level) {
            // start the current level
            if (levels.size() == level)
                levels.add( 0, new ArrayList<Integer>());

            levels.get(level).add(node.val);

            // process child nodes for the next level
            if (node.left != null)
                helper(node.left, level + 1);
            if (node.right != null)
                helper(node.right, level + 1);
            // fulfil the current level

        }


        public static List<List<Integer>> levelOrder(MaximumBinaryTree.TreeNode root) {
            if (root == null) return levels;
            helper(root, 0);
            return levels;
        }

    public static void main(String[] args) {
        MaximumBinaryTree.TreeNode root = new MaximumBinaryTree.TreeNode(1);
        root.left = new MaximumBinaryTree.TreeNode(2);
        root.right = new MaximumBinaryTree.TreeNode(3);
        root.left.left = new  MaximumBinaryTree.TreeNode(6);
        root.right.left = new MaximumBinaryTree.TreeNode(4);
        root.right.right = new MaximumBinaryTree.TreeNode(5);
        root.right.right.left = new MaximumBinaryTree.TreeNode(7);
        System.out.println(levelOrder(root));
    }
    public boolean uniqueOccurrences(int[] arr) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i: arr){
            if(!map.containsKey(i)){
                map.put(i, 1);
            }
            else{
                map.put(i, map.get(i)+1);
            }
        }
        Collection<Integer> valuess = map.values();
        HashSet<Integer> set = new HashSet<>();
        Iterator it =map.values().iterator();
        while(it.hasNext()){
            if(!set.add((int)it.next())){
                return false;
            }

        }
        return true;


    }

}
