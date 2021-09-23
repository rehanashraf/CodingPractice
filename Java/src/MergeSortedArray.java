public class MergeSortedArray {
    public static void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] result = new int[nums1.length];
        int x = 0;
        int y = 0;
        int ind = 0;
        while(x < m && y < n){
            if(nums1[x] <= nums2[y]){
                result[ind] = nums1[x];
                x++;

            }
            else{
                result[ind] = nums2[y];
                y++;

            }
            ind++;

        }

        while(x < m){
            result[ind] = nums1[x];
            x++;
            ind++;
        }
        while(y < n){
            result[ind] = nums2[y];
            y++;
            ind++;
        }
        for(int i=0 ;i  < nums1.length; i++){
            nums1[i] = result[i];
        }

    }

    public static void shift(int[] nums, int index){
        for(int i= nums.length-1; i >=0; i--){
            if(i > index){

                nums[i] = nums[i-1];

            }
        }
    }

    public static void main(String[] args) {
        int[] nums1 = {1,2,3,0,0,0};
        int m = 3;
        int[] nums2 = {2,5,6};
        int n = 3;
        merge(nums1, m, nums2, n);
        System.out.println(nums1);
    }
}
