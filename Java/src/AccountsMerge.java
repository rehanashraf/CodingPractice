import java.util.*;

public class AccountsMerge {
    public static class Data{
        int index;
        String name;
        public Data(int i, String n){
            this.index = i;
            this.name = n;
        }
    }

    public static  List<List<String>> accountsMerge(List<List<String>> accounts) {

        // hashset for emails
        HashSet emails = new HashSet<String>();
        HashMap<Integer, String> mapForName = new HashMap<>();
        int indexForName = 0;


        for(List list: accounts){
           // mapForName.put(indexForName++, list.get(0).toString());
            if(list.size() > 1) {
                for (int i = 1; i < list.size(); i++) {
                    emails.add(list.get(i).toString()+ "_" + list.get(0));
                }
            }
        }
        // HashMap for email to number for union find
        HashMap<String, Integer> map = new HashMap<>();
        Iterator setIter = emails.iterator();
        int index = 0;
        while(setIter.hasNext()){
            map.put(setIter.next().toString(), index++);
        }


        // HashMap for email to number for union find
        HashMap<Integer, String> map2 = new HashMap<>();
        Iterator setIter2 = emails.iterator();
        int index2 = 0;
        while(setIter2.hasNext()){
            map2.put(index2++, setIter2.next().toString());
        }


        int[] UnionFind = new int[map.size()];
        for(int i =0; i < map.size(); i++){
            UnionFind[i] = -1;
        }

        for(List list: accounts){
            if(list.size() <= 2){
                continue;
            }
            String firstEmail = (String) list.get(1) + "_";
            for(int i=2;i < list.size(); i++){
                String email = (String) list.get(i);
                union(firstEmail, email, map, UnionFind);

            }
        }


        // [-1,1,0,2,-1]
        int[] nUnionFind = new int[UnionFind.length];
        for(int i=0; i< UnionFind.length; i++) {
            int x = find(UnionFind, i);
            nUnionFind[i] = x;
        }
        HashMap<Integer, List<String>> result = new HashMap<>();

        for(int i=0; i < nUnionFind.length; i++){
            if(result.containsKey(nUnionFind[i])){
                result.get(nUnionFind[i]).add(map2.get(i));
            }
            else
            {

                String toAdd[] = map2.get(i).split("_");

                ArrayList<String> t  = new ArrayList<>();
                t.add(toAdd[0]);
                t.add(toAdd[1]);
                result.put(i,t);
            }
        }


        List<List<String>> res = new ArrayList<>();
        for(List<String> l: result.values()){
            res.add(l);
        }

        return res;

    }



    public static int find(int[] parent, int index){
        if(parent[index] == -1){
            return index;
        }
        return find(parent, parent[index]);
    }


    public static void union(String fE, String sE, HashMap<String, Integer> map, int[] parent){
        int p = map.get(fE).intValue();
        int q = map.get(sE).intValue();

        int pSet = find(parent, p);
        int qSet = find(parent, q);
        if(pSet != qSet){
            parent[qSet] = pSet;
        }


    }

    public static void main(String[] args) {


        List<List<String>> accounts = new ArrayList<>();
        accounts.add(new ArrayList<String>(Arrays.asList(new String[]{"John", "johnsmith@mail.com", "john00@mail.com"})));
        accounts.add(new ArrayList<String>(Arrays.asList(new String[]{"John", "johnnybravo@mail.com"})));
        accounts.add(new ArrayList<String>(Arrays.asList(new String[]{"John", "johnsmith@mail.com", "john_newyork@mail.com"})));
        accounts.add(new ArrayList<String>(Arrays.asList(new String[]{"Mary", "mary@mail.com"})));

        List<List<String>> r = accountsMerge(accounts);
        System.out.println(r.toString());

    }
}
