//https://leetcode.com/problems/two-sum/

import java.util.HashMap;

public class TwoSum {
    public static int[] twoSum(int[] nums, int target) {
        int [] result = new int[2];
        int length = nums.length;
        HashMap<Integer, Integer> MyHashMap = new HashMap<Integer, Integer>();
        for(int i = 0; i < length; ++i){
            int number = target - nums[i];
            if(MyHashMap.containsKey(number)){
                result[0] = MyHashMap.get(number);
                result[1] = i;
                break;
            }else{
                MyHashMap.put(nums[i], i);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int [] arr = {2,7,11,15};
        int [] result = twoSum(arr, 9);
        System.out.println(result[0]);
        System.out.println(result[1]);
    }
}
