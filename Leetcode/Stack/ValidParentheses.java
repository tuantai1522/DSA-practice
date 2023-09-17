import java.util.Stack;

public class ValidParentheses {
    public static boolean isValid(String s) {
        Stack<Character> MyStack = new Stack<>();
        int length = s.length();
        for(int i = 0; i < length; ++i){
            Character val = s.charAt(i);

            if(val == '[' || val == '{' || val =='('){
                MyStack.push(val);
            }else{
                if(MyStack.isEmpty()) return false;
                if(MyStack.peek() == '['  && val != ']') return false;
                if(MyStack.peek() == '{'  && val != '}') return false;
                if(MyStack.peek() == '('  && val != ')') return false;

                MyStack.pop();
            }
        }

        return MyStack.isEmpty();
    }

    public static void main(String[] args) {
        String s = "()[]{}";
        boolean result = isValid(s);
        System.out.println(result);
    }
}
