//https://leetcode.com/problems/valid-palindrome/description/
public class ValidPalindrome {
    public boolean isPalindrome(String s) {
        int length = s.length();

        if(length == 0) return  true;
        int left = 0;
        int right = length - 1;
        while(left < right){
            Character a = s.charAt(left);
            Character b = s.charAt(right);

            while(!Character.isLetterOrDigit(a)) ++left;
            while(!Character.isLetterOrDigit(b)) --right;

            if(Character.toLowerCase(s.charAt(left)) != Character.toLowerCase(s.charAt(right))){
                return false;
            }

        }

        return true;
    }
}
