import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class LongestConsecutiveSequence {
    public static int longestConsecutive(int[] nums) {
        int length = nums.length;
        if(length == 0) return 0;
        HashSet<Integer> MyHashSet = new HashSet<Integer>();

        for(int i = 0; i < length; ++i){
            MyHashSet.add(nums[i]);
        }
        int result = 1;
        for(int i = 0; i < length; ++i){
            //if this element is the first value of sequence
            if(!MyHashSet.contains(nums[i] - 1)){
                int count = 1;
                while(MyHashSet.contains(nums[i] + 1)){
                    ++count;
                    ++nums[i];
                }
                result = Math.max(result, count);
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int [] nums = {100,4,200,1,3,2};
        int result = longestConsecutive(nums);
        System.out.println(result);
    }
}
