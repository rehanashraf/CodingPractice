import javax.lang.model.type.ArrayType;
import java.util.ArrayList;
import java.util.List;

public class ZigZagConversion {
    public static String convert(String s, int numRows)
    {
        int midRows = numRows - 2;
        char[] chars = s.toCharArray();
        List<List<Character>> lists = new ArrayList<>();
        for(int i=0; i < chars.length; i++){

        }

        int columns = calColumns(numRows, s.length());
        char[][] matrix = new char[numRows][columns];
        int count = 0;
        int index = 0;
        int x = matrix.length;
        for(int i =0; i < matrix[0].length; i++){
            if(count == 0) {
                for (int j = 0; j < matrix.length; j++) {
                    matrix[j][i] = chars[j];
                    index++;

                }
                count = midRows;
            }
            else {

                matrix[x-1][i] = chars[index];
                index++;
                x = x -1;
                count--;
            }

        }
        String f = "";
        for(int i =0; i < matrix.length; i++) {

            for (int j = 0; j < matrix[0].length; j++) {

                f += matrix[i][j];

            }
        }

        return f;



    }

    public static int calColumns(int r, int len){
            int x = r + (r-2);
            int col = len/x + len%x;
            return col;
    }


    public static void main(String[] args) {
        String res = convert("PAYPALISHIRING", 3);
        System.out.println(res);
    }
}
