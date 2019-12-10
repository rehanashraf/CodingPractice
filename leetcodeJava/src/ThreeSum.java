import java.util.*;

public class ThreeSum {

        public static List<List<Integer>> threeSum(int[] nums) {
            if(nums.length < 3)
            {
                List<List<Integer>> res = new ArrayList<List<Integer>>();
                return res;
            }
            List<List<Integer>> res = new ArrayList<List<Integer>>();
            for(int i=0; i < nums.length; i++)
            {
                ArrayList<Integer> lst = new ArrayList<Integer>();
                if(twoSumNew(nums, 0 - nums[i], i, lst))
                {
                    lst.add(nums[i]);
                    Collections.sort(lst);
                 //   boolean notToAdd = false;
//                    for(int x = 0; x < res.size(); x++)
////                    {
////
////                        if(res.get(x).contains(lst.get(0)) &&  res.get(x).contains(lst.get(1)) &&                                                       res.get(x).contains(lst.get(2)))
////                        {
////                            notToAdd = true;
////                        }
////                    }
//                    if(!notToAdd){
//                        res.add(lst);
//                    }
                    if(!res.contains(lst)) {
                        res.add(lst);
                    }
                }

            }
            return res;

        }

        public static boolean twoSumNew(int[] nums, int target, int miss, ArrayList<Integer> list) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if(i != miss) {
                if (map.containsKey(complement)) {
                    list.add(complement);
                    list.add(nums[i]);
                    return true;
                }
                map.put(nums[i], i);
            }
        }
        return false;
    }

        public static boolean twoSum(int[] arr, int sum, int miss, ArrayList<Integer> list)
        {
            // ArrayList<Integer> list = new ArrayList<Integer>();

            for(int i=0; i < arr.length && i != miss; i++)
            {
                for(int j = i+1; j < arr.length && i < arr.length && j != miss; j++ )
                {
                    if(arr[i] + arr[j] == sum)
                    {
                        list.add(arr[i]);
                        list.add(arr[j]);
                        return true;
                    }

                }
            }
            list.add(-1);
            list.add(-1);
            return false;
        }

    public static void main(String[] args) {
        int[] nums = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
        List<List<Integer>>  l = threeSum(nums);
        System.out.println();
        }
}

