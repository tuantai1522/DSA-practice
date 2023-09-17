public class TwoSum {
    public static int[] twoSum(int[] numbers, int target) {
        int i = 0;
        int j = numbers.length - 1;
        int [] result = new int[2];
        while(i < j){
            int count = numbers[i] + numbers[j];

            if(count < target) ++i;
            else if(count > target) --j;
            else {
                result[0] = i + 1;
                result[1] = j + 1;
                break;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int [] numbers = {2,7,11,15};
        int target = 9;
        int [] result = twoSum(numbers, target);

        System.out.println(result[0]);
        System.out.println(result[1]);
    }
}
