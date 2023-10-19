import java.util.HashMap;

//https://leetcode.com/problems/roman-to-integer/description/
public class RomantoInteger {
    public int romanToInt(String s) {
        int result = 0;
        int length = s.length();
        int i = 0;
        HashMap<Character, Integer> my_hash_map = new HashMap<>();
        my_hash_map.put('I', 1);
        my_hash_map.put('V', 5);
        my_hash_map.put('X', 10);
        my_hash_map.put('L', 50);
        my_hash_map.put('C', 100);
        my_hash_map.put('D', 500);
        my_hash_map.put('M', 1000);

        while(i < length){
            int current = my_hash_map.get(s.charAt(i));
            result += current;
            if(i > 0){
                int prev = my_hash_map.get(s.charAt(i - 1));
                if(current > prev){
                    result -= (prev * 2);
                }
            }

            ++i;
        }
        return result;
    }
}
