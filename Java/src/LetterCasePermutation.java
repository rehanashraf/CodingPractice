import java.util.ArrayList;
import java.util.List;

public class LetterCasePermutation {

//    public List<String> letterCasePermutation(String S) {
//        for(int i=0; i < S.length(); i++){
//            char c = S.charAt(i);
//            if(!Character.isDigit(c)){
//                String start = S.substring(0,i);
//                String end =  S.substring(i+1);
//                List<String> st = letterCasePermutation(start);
//                List<String> ed = letterCasePermutation(end);
//
//            }
//
//        }
//
//    }

    static List<String> list = new ArrayList<String>();
    static int len = -1;

    public static void letterCasePermutation(String S) {

        len = S.length();
        letterCasePermutationHelper("", S);


    }


    private static void letterCasePermutationHelper(String soFar, String rest)
    {
        if(rest.equalsIgnoreCase("") && soFar.length() == len){
            list.add(soFar);
            System.out.println(soFar);
        }
        else{
            for(int i =0; i < rest.length(); i++)
            {
                char current = rest.charAt(i);
                String next = null;
                String remaining = rest.substring(i+1);
                if(Character.isAlphabetic(current)) {
                    next = soFar + Character.toUpperCase(current);

                letterCasePermutationHelper(next, remaining);
                    next = soFar + Character.toLowerCase(current);
                letterCasePermutationHelper(next, remaining);
            }
                else {
                    next = soFar + current;
                    letterCasePermutationHelper(next, remaining);

            }


             }
        }

    }

    public static void main(String[] args) {

        letterCasePermutation("a1b2");
    }

}
