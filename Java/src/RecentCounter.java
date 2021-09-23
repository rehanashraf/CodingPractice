import java.util.LinkedList;
import java.util.Queue;

public class RecentCounter {

    public Queue<Integer> queue = null;

    public RecentCounter() {
        this.queue = new LinkedList<Integer>();


    }

    public int ping(int t) {
        boolean cond = false;
        queue.add(t);
        while (!cond) {
            int lTime = queue.peek();
            if (Math.abs(t - lTime) > 3000) {
                queue.poll();
            } else {
                cond = true;
            }

        }
        return queue.size();

    }

    /**
     * Your RecentCounter object will be instantiated and called as such:
     * RecentCounter obj = new RecentCounter();
     * int param_1 = obj.ping(t);
     */

    public static void main(String[] args) {
        RecentCounter counter = new RecentCounter();
        counter.ping(1);
        counter.ping(100);
        counter.ping(3001);
        int param_1 = counter.ping(3002);
        System.out.println(param_1);
    }
}

