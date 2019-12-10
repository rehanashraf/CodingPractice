public class WordValid {

    public static boolean isValid(String S) {
        if(S.startsWith("c") || S.startsWith("b")) {
            return false;
        }
        String s_new = removeABC(S);
        if(s_new.length() == 0){
            return true;
        }
        if(s_new.length() > 0 && !s_new.contains("abc")) {
            return false;
        }
        else {
            return isValid(s_new);
        }



    }

    public static String removeABC(String S){
        // char[] list = S.toCharArray();
        String res = "";
        if(S.length() <= 3)
        {
            if(S.equalsIgnoreCase("abc")){
                return "";
            }
            else{
                return S;
            }
        }
        for(int i=0; i<S.length(); i++){
            if(S.charAt(i) == 'a' && i+3 < S.length()){
                if( S.charAt(i+1) == 'b' && S.charAt(i+2) =='c'){
                    return S.substring(0,i) + S.substring(i+3);
                }
            }

        }
        return S;
    }

    public static void main(String[] args) {
        System.out.println(isValid("cababc"));
    }
}