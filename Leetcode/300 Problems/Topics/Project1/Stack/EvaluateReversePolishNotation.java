import java.util.Stack;

public class EvaluateReversePolishNotation {
    public static int evalRPN(String[] tokens) {
        int length = tokens.length;
        if(length == 1) return Integer.parseInt(tokens[0]);
        int res = 0;
        Stack<String> MyStack = new Stack<>();

        for(int i = 0; i < length; ++i){
            if(tokens[i].equals("+") || tokens[i].equals("-") || tokens[i].equals("*") || tokens[i].equals("/")){
                int secondNumber = Integer.parseInt(MyStack.pop());
                int firstNumber = Integer.parseInt(MyStack.pop());
                if(tokens[i].equals("+")) {
                    res = firstNumber + secondNumber;
                }else if(tokens[i].equals("-")){
                    res = firstNumber - secondNumber;
                }
                else if(tokens[i].equals("*")) {
                    res = firstNumber * secondNumber;
                }else {
                    res = firstNumber / secondNumber;
                }
                MyStack.push(Integer.toString(res));
                System.out.println(res);
            }else{
                MyStack.push(tokens[i]);
            }

        }
        return res;
    }

    public static void main(String[] args) {
        String [] tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};

        int res = evalRPN(tokens);

        System.out.println(res);
    }
}
