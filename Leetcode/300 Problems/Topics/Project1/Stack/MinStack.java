import java.util.Stack;

public class MinStack {
    private Stack<Integer> minStack;
    private Stack<Integer> stack;
    public MinStack() {
        stack = new Stack<>();
        minStack = new Stack<>(); // only push value which is lower than the top value
    }

    public void push(int val) {
        stack.push(val);
        minStack.push(Math.min(val, minStack.isEmpty() ? val : minStack.peek()));

    }

    public void pop() {
        minStack.pop();
        stack.pop();
    }

    public int top() {
        return stack.peek();
    }

    public int getMin() {
        return minStack.peek();
    }

    public static void main(String[] args) {
        MinStack minStack = new MinStack();
        minStack.push(-2);
        minStack.push(0);
        minStack.push(-3);
        minStack.getMin(); // return -3
        minStack.pop();
        minStack.top();    // return 0
        minStack.getMin(); // return -2
    }
}
