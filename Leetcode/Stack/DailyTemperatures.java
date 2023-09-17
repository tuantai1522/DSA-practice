import java.util.Stack;

public class DailyTemperatures {
    public static int[] dailyTemperatures(int[] temperatures) {
        Stack<Integer> MyStack = new Stack<>();
        int length = temperatures.length;
        int [] res = new int[length];

        for(int curDay = 0; curDay < length; ++curDay){
            while(!MyStack.isEmpty() && temperatures[curDay] > temperatures[MyStack.peek()]){
                int prevDay = MyStack.pop();
                res[prevDay] = curDay - prevDay;
            }
            MyStack.add(curDay);
        }
        return res;
    }

    public static void main(String[] args) {
        int [] arr = {73,74,75,71,69,72,76,73};
        int [] res = dailyTemperatures(arr);

        for(int i = 0; i < res.length; ++i){
            System.out.print(res[i] + " ");
        }
    }
}
