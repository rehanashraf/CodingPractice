import java.util.Arrays;
import java.util.Collections;
import java.util.NoSuchElementException;

public class MaximumBinaryTree {

    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) { val = x; }
    }

    public static TreeNode constructMaximumBinaryTree(int[] nums) {
        if(nums == null || nums.length == 0){
            return null;
        }
        if(nums.length == 1){
            TreeNode node = new TreeNode(nums[0]);
        }
        int ind = findMaxIndex(nums);
        TreeNode root = new TreeNode(nums[ind]);
        root.left = constructMaximumBinaryTree(breakArray(nums, 0, ind));
        root.right = constructMaximumBinaryTree(breakArray(nums, ind+1, nums.length));
        return root;


    }

    public static int[] breakArray(int[] A, int start, int end){

         if(A.length == 0){
            return new int[0];
        }
        int res[] = new int[end - start];
         int c = 0;
        for(int s = start; s<end; s++){
            res[c] = A[s];
            c++;

        }
        return  res;
    }


       public static int findMaxIndex(int[] nums){

        int max = nums[0];
        int index = 0;
        for(int i=1; i < nums.length; i++){
            if(nums[i] > max){
                max = nums[i];
                index = i;
            }
        }
        return index;
    }

    public static void main(String[] args) {
        int[] arr = {3,2,1,6,0,5};
        TreeNode res = constructMaximumBinaryTree(arr);


    }




}
