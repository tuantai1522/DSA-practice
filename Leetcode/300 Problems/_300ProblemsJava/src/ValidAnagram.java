import java.util.HashMap;
//https://leetcode.com/problems/valid-anagram/description/
public class ValidAnagram {
    public boolean isAnagram(String s, String t) {
        int length_s = s.length();
        int length_t = t.length();

        if(length_s != length_t) return false;

        HashMap<Character, Integer> my_hash_Map = new HashMap<>();

        for(int i = 0; i < length_s; ++i){
            Character a = s.charAt(i);
            if(!my_hash_Map.containsKey(a)){
                my_hash_Map.put(a, 1);
            }else{
                my_hash_Map.put(a, my_hash_Map.get(a) + 1);
            }
        }

        for(int i = 0; i < length_s; ++i) {
            Character a = t.charAt(i);
            if(!my_hash_Map.containsKey(a) || my_hash_Map.get(a) == 0){
                return false;
            }

            my_hash_Map.put(a, my_hash_Map.get(a) - 1);
        }
        return true;
    }
}
