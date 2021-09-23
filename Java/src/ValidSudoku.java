import java.util.*;

public class ValidSudoku
{

    static HashMap<Integer, HashMap<Character, Integer>>  verticalMap = new HashMap<>();
    static HashMap<Integer, HashMap<Character, Integer>>  horizontalMap = new HashMap<>();
    static HashMap<Integer, HashMap<Character, Integer>>  gridMap = new HashMap<>();

    public static boolean isValidSudoku(char[][] board) {
        // three types of hashmap

        for(int i=0; i < board.length; i++) {
            for(int j = 0; j < board.length; j++)
            {
                if(board[i][j] == '.'){
                    continue;
                }
                if(verticalMap.containsKey(j)){
                    HashMap<Character, Integer> m = verticalMap.get(j);
                    if(m.containsKey(board[i][j])){
                        System.out.println();
                        return false;
                    }
                    else{
                        m.put(board[i][j], 1);
                    }
                }
                else{
                    HashMap<Character, Integer> map = new HashMap<>();
                    map.put(board[i][j], 1);
                    verticalMap.put(j, map);

                }

                if(horizontalMap.containsKey(i)){
                    HashMap<Character, Integer> m = horizontalMap.get(i);

                    if(m.containsKey(board[i][j])){
                        System.out.println();
                        return false;
                    }
                    else{
                        m.put(board[i][j], 1);
                    }


                   // horizontalMap.get(i).add(board[i][j]);
                }
                else{
                    HashMap<Character, Integer> map = new HashMap<>();
                    map.put(board[i][j], 1);
                    horizontalMap.put(i, map);
                        // horizontalMap.put(i, new ArrayList<>(board[i][j]));
                }

                if(gridMap.containsKey(findMapKey(i,j)))
                {
                    HashMap<Character, Integer> m = gridMap.get(findMapKey(i,j));
                    if(m.containsKey(board[i][j])){
                        System.out.println();
                        return false;
                    }
                    else{
                        m.put(board[i][j], 1);
                    }
                       // gridMap.get(findMapKey(i,j)).add(board[i][j]);
                }

                else{
                    HashMap<Character, Integer> map = new HashMap<>();
                    map.put(board[i][j], 1);
                    gridMap.put(findMapKey(i,j), map);
                    //gridMap.put(gridMap.get(findMapKey(i,j)), new ArrayList<>(board[i][j]);
                }



            }
        }
//        Set<Integer> set = verticalMap.keySet();
//        for(int i: set){
//            List<Character> l = verticalMap.get(i);
//            for(int x = 0; x < l.size(); x++){
//                int ch= Integer.parseInt(String.valueOf(l.get(i)));
//                if(!(ch >= 1 &&ch <= 9)){
//                    return false;
//                }
//
//            }
//        }


return true;
    }

    public static int findMapKey(int i, int j){
        if(i >= 0 && i <= 2 && j >= 0 && j <= 2){
            return 0;
        }
        if(i >= 0 && i <= 2 && j >= 3 && j <= 5){
            return 1;
        }
        if(i >= 0 && i <= 2 && j >= 6 && j <= 8){
            return 2;
        }
        if(i >= 3 && i <= 5 && j >= 0 && j <= 2){
            return 3;
        }
        if(i >= 3 && i <= 5 && j >= 3 && j <= 5){
            return 4;
        }
        if(i >= 3 && i <= 5 && j >= 6 && j <= 8){
            return 5;
        }
        if(i >= 6 && i <= 8 && j >= 0 && j <= 2){
            return 6;
        }
        if(i >= 6 && i <= 8 && j >= 3 && j <= 5){
            return 7;
        }
        if(i >= 6 && i <= 8 && j >= 6 && j <= 8){
            return 8;
        }
        return -1;
    }

    public static void main(String[] args) {
        char[][] chars = {

                {'.','8','7','6','5','4','3','2','1'},
                {'2','.','.','.','.','.','.','.','.'},
                {'3','.','.','.','.','.','.','.','.'},
                {'4','.','.','.','.','.','.','.','.'},
                {'5','.','.','.','.','.','.','.','.'},
                {'6','.','.','.','.','.','.','.','.'},
                {'7','.','.','.','.','.','.','.','.'},
                {'8','.','.','.','.','.','.','.','.'},
                {'9','.','.','.','.','.','.','.','.'}
    };
        boolean t = isValidSudoku(chars);
        System.out.println(t);
    }
}
