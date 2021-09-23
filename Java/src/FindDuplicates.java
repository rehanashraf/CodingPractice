import java.util.ArrayList;
import java.util.List;

public class FindDuplicates {

    public static List<Integer> findDuplicates(int[] nums) {
       List<Integer> list = new ArrayList<>();
        int count = 0;
        for(int i=0; i < nums.length; i++){
            if(nums[i] == 0){
                continue;
            }
            int temp = nums[nums[i]-1];
            if(temp == 0){
                continue;
            }

            nums[nums[i]-1] = 0;
            nums[i] = temp;

//            (nums[i] == i+1){
//
//            }
            // nums[nums[i]];
        }

        for(int i=0; i < nums.length; i++){
            if(nums[i] == 0) {
                continue;
            }
            else {
                if(nums[nums[i]-1] == 0)
                {
                    list.add(nums[i]);
                }
            }
        }
        return list;

    }

    public static List<Integer> findDuplicatesNew(int[] nums) {
        List<Integer> list = new ArrayList<>();
        for(int i=0; i < nums.length; i++){
            if(nums[Math.abs(nums[i])-1] > 0){
                nums[Math.abs(nums[i])-1] = - (nums[Math.abs(nums[i])-1]);
            }
            else{
                list.add(nums[Math.abs(nums[i])-1]);
            }
        }
        return list;
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 1, 3, 6, 6};
        List<Integer> l = findDuplicatesNew(arr);
        System.out.println(l.toString());
    }
}
