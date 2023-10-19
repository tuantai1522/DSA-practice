//https://leetcode.com/problems/longest-palindrome/
public class LongestPalindrome {
    public int longestPalindrome(String s) {
        int length = s.length();
        int [] characterArray = new int[128];

        for(int i = 0; i < length; ++i){
            ++characterArray[s.charAt(i)];
        }

        int ans = 0;
        int check = 1; // check whether there is any unique element or not
        for(int count : characterArray){
            ans += (count / 2 * 2);
            if(count % 2 == 1){
                check = 0; //there is any unique element
            }
        }

        return check == 1 ? ans : ans + 1; //if there is any unique element => plus 1
    }
}
