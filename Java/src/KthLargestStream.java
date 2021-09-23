import java.util.PriorityQueue;

public class KthLargestStream {
    int c = 0;
    PriorityQueue queue = null;

    public KthLargestStream(int k, int[] nums) {
        c = k;
        queue = new PriorityQueue<Integer>((n1, n2) -> n1 - n2);
        for(int i=0; i< nums.length; i++)
        {
            queue.add(nums[i]);
            if(queue.size() > k){
                queue.poll();
            }
        }

    }

    public int add(int val) {
        //System.out.println(queue.toString());
        if(!queue.isEmpty()){
            int z = (int) queue.peek();
            if(val > z){
                queue.poll();
                queue.add(val);
            }
            //System.out.println(queue.toString());
        }
        return (int) queue.peek();

    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
// */
//}
