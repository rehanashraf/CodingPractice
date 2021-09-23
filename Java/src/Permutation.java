import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class Permutation {

//       static List<List<Integer>> result = new ArrayList<>();
//        //static List<Integer> given = new ArrayList<>();
//
//        public static List<List<Integer>> permute(int[] nums) {
//            List<Integer> rest = new ArrayList<>();
//            for(int i: nums){
//                rest.add(i);
//                // given.add(i);
//            }
//
//            List<Integer> soFar = new ArrayList<>();
//            permuteHelper(soFar, rest);
//            return result;
//
//        }
//        public static void permuteHelper(List<Integer> soFar, List<Integer> rest){
//            if(rest.size() == 0){
//                result.add(soFar);
//                return;
//            }
//            for(int i=0 ; i < rest.size(); i++) {
//
//                int cur = rest.get(i);
//                ArrayList<Integer> newRest = new ArrayList<>(rest);
//                newRest.remove(i);
//                ArrayList<Integer> n = new ArrayList<>(soFar);
//                n.add(cur);
//                permuteHelper(n, newRest);
//            }
//        }


    public static void backtrack(int n,
                                 ArrayList<Integer> nums,
                                 List<List<Integer>> output,
                                 int first) {
        // if all integers are used up
        if (first == n)
            output.add(new ArrayList<Integer>(nums));
        for (int i = first; i < n; i++) {
            // place i-th integer first
            // in the current permutation
            Collections.swap(nums, first, i);
            // use next integers to complete the permutations
            backtrack(n, nums, output, first + 1);
            // backtrack
            Collections.swap(nums, first, i);
        }
    }

    public static List<List<Integer>> permute(int[] nums) {
        // init output list
        List<List<Integer>> output = new LinkedList();

        // convert nums into list since the output is a list of lists
        ArrayList<Integer> nums_lst = new ArrayList<Integer>();
        for (int num : nums)
            nums_lst.add(num);

        int n = nums.length;
        backtrack(n, nums_lst, output, 0);
        return output;
    }


    public static void main(String[] args)
    {
            int[] nums = {1,2,3};
            permute(nums);
            System.out.println();
    }
    }

