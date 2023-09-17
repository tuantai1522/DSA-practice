//https://leetcode.com/problems/contains-duplicate/


import java.util.HashSet;
public class ContainsDuplicate {
    public static boolean containsDuplicate(int[] nums) {
        int length = nums.length;

        HashSet<Integer> MyHashMap = new HashSet<Integer>();
        for(int i = 0; i < length; ++i){
            if(MyHashMap.contains(nums[i])){
                return true;
            }else{
                MyHashMap.add(nums[i]);
            }
        }
        return false;
    }

    public static void main(String[] args) {
        int [] arr = {1,2,3,4};
        boolean result = containsDuplicate(arr);
        System.out.println(result);
    }
}
