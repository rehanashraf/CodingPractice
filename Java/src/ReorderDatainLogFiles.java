import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class ReorderDatainLogFiles {
    public static  String[] reorderLogFiles(String[] logs) {
        ArrayList<String> digitLogs = new ArrayList<>();
        ArrayList<String> letterLogs = new ArrayList<>();

        for(String log: logs){
            if(digLog(log)){
                digitLogs.add(log);
            }
            else{
                letterLogs.add(log);
                Collections.sort(letterLogs, new Comparator<String>() {
                    @Override
                    public int compare(String o1, String o2) {
                        String a = o1.substring(o1.indexOf(" "));
                        String b = o2.substring(o2.indexOf(" "));
                        if(a.compareTo(b) == 0){
                             a = o1.substring(0, o1.indexOf(" "));
                             b = o2.substring(0, o2.indexOf(" "));
                             return a.compareTo(b);
                        }
                        return a.compareTo(b);
                    }
                });
            }
        }

        letterLogs.addAll(digitLogs);
        return (String[]) letterLogs.toArray(new String[0]);


    }

    public static boolean digLog(String log){
        if(Character.isDigit(log.split(" ")[1].charAt(0))){
            return true;
        }
        return false;

    }

    public static void main(String[] args) {
        String[] logs = {"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"};
        System.out.println(reorderLogFiles(logs).toString());

    }


}
