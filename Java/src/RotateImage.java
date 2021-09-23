public class RotateImage
{
    public static void rotate(int[][] matrix){
        rotateHelper(matrix, matrix.length, 0);

    }

    public static void rotateHelper(int[][] m, int N, int start){
        if(N == 0){
            return;
        }
        int n = N-1;
        for(int i=1; i < n; i++){
            int temp1 = m[i][n];
            m[i][n] = m[0+start][i];
            int temp2 = m[n][n-i];
            m[n][n-i] = temp1;
            int temp3 = m[n-i][0+start];
            m[n-i][0+start] = temp2;
            m[0+start][i] = temp3;
         }
        rotateHelper(m, N-1, start+1);

    }

    public static void main(String[] args) {
        int[][] matrix = {
                {5, 1, 9, 11},
                {2, 4, 8, 10},
                {13, 3, 6, 7},
                {15,14,12,16}
        };
        rotate(matrix);
        System.out.println(matrix.toString());
    }
}
