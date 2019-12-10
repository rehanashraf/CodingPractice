import java.util.*;

public class MergeIntervals
{

        public static int[][] merge(int[][] intervals)
            {
                List<int[]> list = new ArrayList<>();
                //  int[][] result = new int[intervals.length][];
                Arrays.sort(intervals, new Comparator<int[]>() {
                    public int compare(final int[] entry1,
                                       final int[] entry2) {
                        if (entry1[0] > entry2[0])
                            return 1;
                        else
                            return -1;
                    }
                });
                int current = 0;
                boolean done = false;
                while (!done){
                    int[] cur = intervals[current];
                    int[] toAdd= new int[2];
                    toAdd[0] = cur[0];
                    boolean flag = false;
                    done = true;
                    for(int i =current+1; i < intervals.length; i++){
                        int[] check = intervals[i];
                        if(check[0] <= cur[1]){
                            toAdd[1] = check[1];
                            //current++;
                            flag = true;
                            done = false;
                            current = i;
                        }
                        else{
                            //  toAdd[1] = cur[1];
                            // current++;
                            current = i;
                            done = false;
                            break;
                        }
                        //current = i;
                    }
                    if(!flag && current < intervals.length-1){
                        toAdd[1] = cur[1];
                    }

                    list.add(toAdd);


                }
                int[][] result = new int[list.size()][2];
                for(int i=0; i < list.size(); i++){
                    result[i] = list.get(i);
                }
                return result;




        }

        public static void main(String[] args){

            int[][] chunks = {{1,4},{4,5}};
            System.out.println("Before: ");
            print2DArray(chunks);


            int[][] r = merge(chunks);
            System.out.println("After: ");
            //System.out.println(l.toString());
            print2DArray(r);


        }

    private static void print2DArray(int[][] chunks) {
        for(int i=0; i < chunks.length; i++){
            for(int j = 0; j < chunks[0].length; j++){
                System.out.print(chunks[i][j] + " ");
            }
            System.out.println();
        }
    }

}
