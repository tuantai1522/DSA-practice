//https://leetcode.com/problems/two-sum/description/
import java.util.HashMap;

public class TwoSum {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer, Integer> my_map = new HashMap();

        int size = nums.length;
        int [] result = new int[2];
        for(int i = 0; i < size; ++i){
            int count = target - nums[i];
            if(my_map.containsKey(count)){
                result[0] = i;
                result[1] = my_map.get(count);
                break;
            }else{
                my_map.put(count , i);
            }
        }

        return result;
    }
}
