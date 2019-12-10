import java.util.*;

public class GroupAnagram {

    public static List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String, ArrayList<String>> map = new HashMap<>();
       // String[] sortedStrs = new String[strs.length];

//        for(int i=0; i < strs.length; i++){
//            char[] c = strs[i].toCharArray();
//            Arrays.sort(c);
//            String n = new String(c);
//
//           // sortedStrs[i] = n;
//        }

        for (String s : strs) {
            //int sum = countChars(s);
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            String n = new String(chars);

            if (map.containsKey(n)) {
                map.get(n).add(s);
            } else {
                ArrayList<String> list = new ArrayList<String>();
                list.add(s);
                map.put(n, list);
            }
        }
        List<List<String>> results = new ArrayList<>();
        for (Map.Entry<String, ArrayList<String>> m : map.entrySet()) {
            results.add(m.getValue());
        }

        return results;


    }

    public static int countChars(String s) {
        char[] chars = s.toCharArray();
        int sum = 0;
        for (int i = 0; i < chars.length; i++) {
            sum = sum + chars[i];
        }
        return sum;
    }

    public static void main(String[] args) {

        String[] strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
            String[] sortedStrs = new String[strs.length];
            for(int i=0; i < strs.length; i++){
                char[] c = strs[i].toCharArray();
                Arrays.sort(c);
                String n = new String(c);

                sortedStrs[i] = n;
            }
            Arrays.sort(sortedStrs);
          Arrays.stream(sortedStrs).forEach((str1) -> {System.out.println(str1);});
        List<List<String>> l = groupAnagrams(strs);
        System.out.println(l);


    }

}
