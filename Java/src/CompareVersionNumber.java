//import com.sun.tools.javac.util.StringUtils;
//
//public class CompareVersionNumber {
//
//        public  static int compareVersion(String version1, String version2) {
//            if(version1 == null || version2 == null){
//                return -1;
//            }
//            String c1 = version1.substring(0, version1.indexOf("."));
//            c1 = c1.replaceAll("0", "");
//            char ch1 = c1.charAt(0);
//
//            String c2 = version2.substring(0, version2.indexOf("."));
//            c2 = c2.replaceAll("0", "");
//         //   char ch2 = Character.isDigit(c2);
////            if(ch1 > ch2){
////                return 1;
////            }
////            else if(ch1 < ch2){
////                return -1;
////            }
////            else{
////                return compareVersion(version1.substring(1), version2.substring(1));
////            }
//
////            return
//        }
//
//    public static void main(String[] args)
//    {
//        String version1 = "0.1";
//        String version2 = "1.1";
//        int a = version1.indexOf(".");
//        String c1 = version1.substring(0, a);
//        c1 = c1.replace("0", "");
//        //.charAt(0);
//       // System.out.println(version1.indexOf("."));
//
//        int i = compareVersion(version1, version2);
//        System.out.println(i);
//
//
//
//    }
//}
