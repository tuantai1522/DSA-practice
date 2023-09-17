import java.util.Arrays;
import java.util.Stack;

public class CarFleet {
    public static int carFleet(int target, int[] position, int[] speed) {
        int length1 = position.length;
        int length2 = speed.length;

        if(length1 == length2 && length1 == 1) return 1;

        Stack<Double> MyStack = new Stack<>();
        Arrays.sort(position);

        for(int i = length1 - 1; i >= 0; --i){
            double time = (double)(target - position[i]) / speed[i];
            System.out.println(time);
            if(MyStack.isEmpty()){
                MyStack.push(time);
            }else{
                if(time <= MyStack.peek()){
                    continue;
                }
            }
        }
        return MyStack.size();
    }

    public static void main(String[] args) {
        int [] position = {10,8,0,5,3};
        int [] speed = {2,4,1,1,3};
        int target = 12;
        int res = carFleet(target, position, speed);
        System.out.println(res);
    }
}
