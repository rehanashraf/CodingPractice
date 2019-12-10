//public class DominionRotation
//{
//        int[] six = new int[7];
//        int[] curVals1 = new int[7];
//        int[] curVals2 = new int[7];
//
//        public int minDominoRotations(int[] A, int[] B)
//        {
//
//            for(int i=0; i < A.length; i++) {
//                if(A[i] == 1){
//                    curVals1[1] = curVals1[1] + 1;
//                }
//                if(A[i] == 2){
//                    curVals1[2] = curVals1[2] + 1;
//                }
//                if(A[i] == 3){
//                    curVals1[3] = curVals1[3] + 1;
//                }
//                if(A[i] == 4){
//                    curVals1[4] = curVals1[4] + 1;
//                }
//                if(A[i] == 5){
//                    curVals1[5] = curVals1[5] + 1;
//                }
//                if(A[i] == 6){
//                    curVals1[6] = curVals1[6] + 1;
//                }
//            }
//
//            for(int i=0; i < B.length; i++) {
//                if(B[i] == 1){
//                    curVals2[1] = curVals2[1] + 1;
//                }
//                if(B[i] == 2){
//                    curVals2[2] = curVals2[2] + 1;
//                }
//                if(B[i] == 3){
//                    curVals2[3] = curVals2[3] + 1;
//                }
//                if(B[i] == 4){
//                    curVals2[4] = curVals2[4] + 1;
//                }
//                if(B[i] == 5){
//                    curVals2[5] = curVals2[5] + 1;
//                }
//                if(B[i] == 6){
//                    curVals2[6] = curVals2[6] + 1;
//                }
//            }
//            for(int i=1 ; i < curVals1.length; i++){
//                int c = 1;
//                 if(curVals2[i] > curVals1[i]){
//                     c = 2;
//                 }
//                six[i] = check(A, B, c, );
//            }
//            int max = Integer.MIN_VALUE;
//
//            for(int i=1 ; i < six.length; i++){
//                if(six[i] > max)
//                {
//                    max = six[i];
//                }
//            }
//            return max;
//
//
//
//
//
//        }
//
//        public int check(int[] arr1, int[] arr2, int a, int val){
//            int len= 0;
//            int total = 0;
//            if(a == 1){
//                len = arr1.length;
//            }
//            else{
//                len = arr2.length;
//            }
//            for(int i=0 ;i < len; )
//
//
//        }
//
//}
