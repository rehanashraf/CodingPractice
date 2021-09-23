public class Searcha2DMatrix
{
    public static boolean searchMatrix(int[][] matrix, int target) {
        int start = 0;
        int end = matrix.length-1;
        int mid;
        int lastElment = matrix[0].length-1;

        while(start <= end){
            mid = (start + end)/2;
            if(matrix[mid][lastElment] < target) {
                   start = mid + 1;
            }
            else if (matrix[mid][lastElment] > target){
                    end = mid - 1;
            }
            else {
                   start = start;
                   end = end;
            }
        }

        if(start > end){
            return false;
        }

        // bs in matrix[start] array
        int row = start;
         start = 0;
        end = matrix.length -1;
        int middle;
        while(start <= end){
            middle = (start + end)/2;
            if(matrix[row][middle] < target) {
                start = middle + 1;
            }
            else if (matrix[row][middle] > target){
                end = middle - 1;
            }
            else {
                return true;
            }

        }




        System.out.println(start);
        System.out.println(end);
        return false;

    }

    public static void main(String[] args) {
        int[][] matrix = {
                {1, 3, 5, 6},
                {7, 8, 9, 10},
                {11, 12, 16, 20},
                {23, 30, 34, 50}
        };
        int target = 7;
        System.out.println(searchMatrix(matrix, target));

    }
}
