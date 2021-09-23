import java.util.Stack;

public class EvaluateReversePolishNotation
{
    public static int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();

        for(String value :tokens){
            char[] arr = value.toCharArray();
            if(arr.length == 1){
                char ch = value.charAt(0);

                if(Character.isDigit(ch)){
                    stack.push(Integer.parseInt(value));
                }
                else{
                    int v1 = stack.pop();
                    int v2 = stack.pop();
                    int res = doOperation(ch, v2, v1);
                    stack.push(res);
                }
            }
            else{
                stack.push(Integer.parseInt(value));
            }

        }
        return stack.pop();

    }

    public static int doOperation(Character op, int v1, int v2){
        switch (op) {
            case '/':
                return v1/v2;
            case '*':
                return v1*v2;
            case '+':
                return v1+v2;
            case '-':
                return v1-v2;

        }

        return -1;
    }

    public static void main(String[] args) {
        String[] arr = {"4", "13", "5", "/", "+"};
        System.out.println(evalRPN(arr));
    }


}
