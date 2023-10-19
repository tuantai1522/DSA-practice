import java.util.Stack;

//https://leetcode.com/problems/valid-parentheses/description/
public class ValidParentheses {
    public boolean isValid(String s) {
        int length = s.length();
        Stack<Character> my_stack = new Stack<>();
        for (int i = 0; i < length; ++i) {
            if (s.charAt(i) == '('
                    || s.charAt(i) == '{'
                    || s.charAt(i) == '[') {
                my_stack.push(s.charAt(i));
            } else {
                if (my_stack.isEmpty()) {
                    return false;
                }else if (my_stack.peek() == '(' && s.charAt(i) == ')') {
                    my_stack.pop();
                } else if (my_stack.peek() == '{' && s.charAt(i) == '}') {
                    my_stack.pop();
                } else if (my_stack.peek() == '[' && s.charAt(i) == ']') {
                    my_stack.pop();
                }else{ // other circumstances
                    return false;
                }
            }
        }
        return my_stack.isEmpty();
    }
}
