import java.util.ArrayList;
import java.util.HashMap;

public class ShortestWordDistance
{
    private static HashMap<String, Integer> map = map = new HashMap<>();;
    private static HashMap<String, ArrayList<Integer>> locations = new HashMap<>();


    public static int shortestDistance(String[] words, String word1, String word2) {

        //word1 indexes
        ArrayList<Integer> w1Indexes = new ArrayList<>();

        // word2 indexes
        ArrayList<Integer> w21Indexes = new ArrayList<>();
        int count  = 0;
        for(String word: words){
            if(word.equalsIgnoreCase(word1)){
                w1Indexes.add(count);
            }
            if(word.equalsIgnoreCase(word2)){
                w21Indexes.add(count);
            }
            count++;
        }

        int min = Integer.MAX_VALUE;
        for(int i=0; i < w1Indexes.size(); i++){
            for(int j =0; j < w21Indexes.size(); j++){
                int curDiff = Math.abs(w1Indexes.get(i) - w21Indexes.get(j));
                if(curDiff < min){
                    min = curDiff;
                }
            }
        }
        return min;
    }

    public static int shortestDistanceII(String[] words, String word1, String word2){
        String mapKey = word1+ "+"+word2;
        if(map.containsKey(mapKey)){
            return map.get(mapKey);
        }
        ArrayList<Integer> loc1 = locations.get(word1);
        ArrayList<Integer> loc2 = locations.get(word2);

        int minDist = Integer.MAX_VALUE;
        int l1 = 0;
        int l2 = 0;
        while(l1 < loc1.size() && l2 < loc2.size()){
            minDist = Math.min(minDist, Math.abs(loc1.get(l1) - loc2.get(l2)));
            if(loc1.get(l1) < loc2.get(l2)){
                l1++;
            }
            else{
                l2++;
            }
        }
        map.put(mapKey, minDist);
        return minDist;

    }

    public static int shortestDistanceIII(String[] words, String word1, String word2){
        for(int i=0; i < words.length; i++){
            ArrayList<Integer> loc = locations.getOrDefault(words[i], new ArrayList<Integer>());
            loc.add(i);
            locations.put(words[i], loc);
        }
        if(!word1.equals(word2))
            return sDIIIHelper(words, word1, word2);
        else{
            //same loc1 and loc2 array
            ArrayList<Integer> loc = locations.get(word1);
            int minDist = loc.get(1)- loc.get(0);
            for(int i=2 ; i < loc.size(); i++){
                int curDiff = loc.get(i) - loc.get(i-1);
                if(curDiff < minDist){
                    minDist = curDiff;
                }

            }
            return minDist;
        }

    }

    public static int sDIIIHelper(String[] words, String word1, String word2){

        String mapKey = word1+ "+"+word2;
        if(map.containsKey(mapKey)){
            return map.get(mapKey);
        }
        ArrayList<Integer> loc1 = locations.get(word1);
        ArrayList<Integer> loc2 = locations.get(word2);

        int minDist = Integer.MAX_VALUE;
        int l1 = 0;
        int l2 = 0;
        while(l1 < loc1.size() && l2 < loc2.size()){
            minDist = Math.min(minDist, Math.abs(loc1.get(l1) - loc2.get(l2)));
            if(loc1.get(l1) < loc2.get(l2)){
                l1++;
            }
            else{
                l2++;
            }
        }
        map.put(mapKey, minDist);
        return minDist;
    }

    public static void main(String[] args) {
        //String[] ws = {"practice", "makes", "perfect", "coding", "makes"};
        String[] ws = {"a", "a"};
        System.out.println(shortestDistanceIII(ws, "a", "a"));

    }

}
