import java.util.Arrays;
import java.util.Stack;

public class PermutationInString {
    public static boolean checkInclusion(String s1, String s2) {
        int length1 = s1.length();
        int length2 = s2.length();

        if(length1 > length2 || length2 == 0) return false;
        if(length1 == 0) return true;

        int [] characterArray1 = new int[26];
        int [] characterArray2 = new int[26];
        for(int i = 0; i < length1; ++i) {
            ++characterArray1[s1.charAt(i) - 97];
            ++characterArray2[s2.charAt(i) - 97];
        }

        for(int i = length1; i < length2; ++i) {
            if(Arrays.equals(characterArray1, characterArray2)){
                return true;
            }

            --characterArray2[s2.charAt(i - length1) - 97];
            ++characterArray2[s2.charAt(i) - 97];
        }

        //xuất hiện ở cuối cùng
        if(Arrays.equals(characterArray1, characterArray2)){
            return true;
        }
        return false;

    }

    public static void main(String[] args) {
        String s1 = "ab";
        String s2 = "eidbaooo";
        boolean res = checkInclusion(s1, s2);
        System.out.println(res);
    }
}
