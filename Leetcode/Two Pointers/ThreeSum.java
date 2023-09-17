import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThreeSum {
    public static List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new ArrayList<>();

        for (int i = 0; i < nums.length - 2; i++) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int left = i + 1;
                int right = nums.length - 1;

                int target = nums[left] + nums[right] + nums[i];

                while (left < right) {
                    if (target == 0) {
                        ArrayList<Integer> miniSol = new ArrayList<>();

                        miniSol.add(nums[i]);
                        miniSol.add(nums[left]);
                        miniSol.add(nums[right]);

                        result.add(miniSol);
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1]) {
                            right--;
                        }
                        left++;
                        right--;
                    } else if (target > 0) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int [] nums = {0,0,0};
        List<List<Integer>> result = threeSum(nums);
        for(int i = 0; i < result.size(); ++i){
            System.out.println(result.get(i));
        }
    }
}
