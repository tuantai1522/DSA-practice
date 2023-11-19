import java.util.HashMap;

public class LongestRepeatingCharacterReplacement {
    public static int characterReplacement(String s, int k) {
        int length = s.length();
        int pointer_left = 0;
        int pointer_right = 0;
        int [] characterArray = new int[26];
        int res = 0;
        boolean check = true;
        int max_value = 0;

        while(pointer_left <= pointer_right && pointer_right < length){
            //chỉ cập nhật array khi thoải đk: distance - max_value <= k
            if(check == true){
                ++characterArray[s.charAt(pointer_right) - 65];
            }

            // Tìm giá trị lớn nhất trong characterArray
            max_value = Math.max(max_value, characterArray[s.charAt(pointer_right) - 65]);


            int distance = pointer_right - pointer_left + 1;
            if(distance - max_value <= k){
                pointer_right++;
                res = Math.max(res, distance);
                check = true;
            }else {
                --characterArray[s.charAt(pointer_left) - 65];
                pointer_left++;
                check = false;
            }
        }

        return res;
    }

    public static void main(String[] args) {
        String s = "AABABBA";
        int k = 1;
        int res = characterReplacement(s, k);
        System.out.println(res);
    }

}
