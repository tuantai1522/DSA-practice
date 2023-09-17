import java.util.ArrayList;

public class FindTheDuplicateNumber {
    public static int findDuplicate(int[] nums) {
        int length = nums.length;
        // Tạo một mảng có độ dài length - 1
        int[] array = new int[length - 1];

        for(int i = 0; i < length; ++i){
            if(array[nums[i] - 1] != 2){
                array[nums[i] - 1]++;
            }
            if(array[nums[i] - 1 ] == 2){
                return nums[i];
            }
        }

        for(int i = 0; i < array.length; ++i){
            System.out.println(array[i]);
        }
        return -1;
    }

    public static void main(String[] args) {
        int [] nums = {1,3,4,2,2};

        int res = findDuplicate(nums);

        System.out.println(res);
    }
}
