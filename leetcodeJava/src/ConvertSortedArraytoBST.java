public class ConvertSortedArraytoBST {

    public static TreeNode sortedArrayToBST(int[] nums) {
        if(nums.length == 0){
            return null;
        }
        int mid = nums.length/2;
        TreeNode root  = new TreeNode(nums[mid]);

        root.left = sortedArrayToBST(divArr(nums, 0, mid));
        root.right = sortedArrayToBST(divArr(nums, mid+1, nums.length));
        return root;

    }

    public static int[] divArr(int[] a, int start, int end){
        int[] res = new int[end - start];
        int ind = 0;
        for(int i= start; i < end; i++){
            res[ind] = a[i];
            ind++;
        }
        return res;
    }

    public static void main(String[] args) {
        int[] arr = {-10,-3,0,5,9};
        TreeNode root = sortedArrayToBST(arr);
        System.out.println(root.val);

    }
}
