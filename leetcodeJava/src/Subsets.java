import org.omg.PortableInterceptor.INACTIVE;

import java.util.*;
import java.util.stream.Collectors;

public class Subsets
{
    private static HashSet<Integer> done = new HashSet<>();
    private static List<List<Integer>> subsetsList = new ArrayList<>();
    public static List<List<Integer>> subsets(int[] nums)
    {
        ArrayList<Integer> soFar = new ArrayList<>();

        subsetsHelper(soFar, nums,0);
        return subsetsList;


    }

    private static void subsetsHelper(ArrayList<Integer> soFar, int[] nums, int start) {

        if(start > nums.length-1){
            subsetsList.add(soFar);
        }
        else {
            subsetsHelper(new ArrayList<>(soFar), nums, start + 1);
            if (!done.contains(nums[start])) {
                soFar.add(nums[start]);
                done.add(nums[start]);
                subsetsHelper(new ArrayList<>(soFar), nums, start + 1);

            }
        }

//        if (nums.size() == 0) {
//            subsetsList.add(integers);
//        } else {
//                nums.remove(0);
//                subsetsHelper(integers, nums);
//            if(nums.size() > 0 ) {
//                integers.add(nums.get(0));
//            }
//                subsetsHelper(integers, nums);
//
//        }
    }


    public static void main(String[] args) {
        int[] nums = {1,2,2};
        subsets(nums);
        System.out.println();

    }


}
