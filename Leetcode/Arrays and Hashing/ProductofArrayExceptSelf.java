public class ProductofArrayExceptSelf {
    public static int[] productExceptSelf(int[] nums) {
        int length = nums.length;
        int [] arrayLeft = new int[length];
        int [] arrayRight = new int[length];
        int [] arrayResult = new int[length];

        for(int i = 0; i < length; ++i){
            arrayLeft[i] = arrayRight[i] = 1;
        }

        for(int i = 1; i < length; ++i){
            arrayLeft[i] = nums[i - 1] * arrayLeft[i - 1];
        }

        for(int i = length - 2; i >= 0; --i){
            arrayRight[i] = nums[i + 1] * arrayRight[i + 1];
        }

        for(int i = 0; i < length; ++i){
            arrayResult[i] = arrayRight[i] * arrayLeft[i];
        }
        return arrayResult;
    }

    public static void main(String[] args) {
        int [] nums = {1,2,3,4};
        int [] result = productExceptSelf(nums);
        for(int i = 0; i < result.length; ++i){
            System.out.println(result[i]);
        }
    }
}
