import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;


public class LongestSubStringWithoutRepeatingCharacters {
    public static int lengthOfLongestSubstring(String s) {
        int length = s.length();
        int a_pointer = 0;
        int b_pointer = 0;

        int res = 0;
        HashSet<Character> MyHashSet = new HashSet<Character>();

        while(b_pointer < length){
            if(!MyHashSet.contains(s.charAt(b_pointer))){
                MyHashSet.add(s.charAt(b_pointer));
                ++b_pointer;
                res = Math.max(res, MyHashSet.size());
            }else{
                MyHashSet.remove(s.charAt(a_pointer));
                ++a_pointer;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        String s = "dvdf";
        int res = lengthOfLongestSubstring(s);
        System.out.println(res);
    }

}
