import java.util.ArrayList;
import java.util.List;

public class PartitionLabels {
    public static List<Integer> list = new ArrayList<>();

    public static List<Integer> partitionLabels(String S) {
        if(S.length() == 0){
            return null;
        }
        if(S.length() == 1){
            list.add(1);
            return list;
        }
        char[] arr = S.toCharArray();
        int len = 1;
        int toGo = lastIndex(arr, arr[0]);
        int current = 1;
        while(current <= toGo){
            int newIndex = lastIndex(arr, arr[current]);
            if( newIndex > toGo){
                toGo = newIndex;
            }
            current++;
        }
        list.add(current);
        String nS = "";
        for(int i=current; i < arr.length; i++){
            nS = nS + arr[i];
        }
        partitionLabels(nS);
        return list;



    }

    public static int lastIndex(char[] S, char c){
        for(int i=S.length-1; i >= 0; i--){
            if(S[i] == c){
                return i;
            }
        }
        return -1;

    }

    public static void main(String[] args) {
        partitionLabels("ababcbacadefegdehijhklij");
        System.out.println("Done");
    }

}

/*
* Another approach which is more efficient:
*  int[] last = new int[26];
        for (int i = 0; i < S.length(); ++i)
            last[S.charAt(i) - 'a'] = i;

   have last array before which contains last index of all the chars in the String S. Use this array wherever need to find lastindex
   *
 */
