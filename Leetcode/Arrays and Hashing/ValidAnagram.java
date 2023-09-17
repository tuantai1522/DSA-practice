//https://leetcode.com/problems/valid-anagram/

import java.util.HashMap;
import java.util.HashSet;

public class ValidAnagram {
    public static boolean isAnagram_MySolution(String s, String t) {
        int length1 = s.length();
        int length2 = t.length();
        if(length1 != length2) return false;

        HashMap<Character, Integer> firstHashMap = new HashMap<Character, Integer>();
        HashMap<Character, Integer> secondHashMap = new HashMap<Character, Integer>();

        //only iterate one String
        for(int i = 0; i < length1; ++i){
            //String s
            if(firstHashMap.containsKey(s.charAt(i))){
                int occurence = firstHashMap.get(s.charAt(i)) + 1;
                firstHashMap.put(s.charAt(i), occurence);
            }else{
                firstHashMap.put(s.charAt(i), 1);
            }

            //String t
            if(secondHashMap.containsKey(t.charAt(i))){
                int occurence = secondHashMap.get(t.charAt(i)) + 1;
                secondHashMap.put(t.charAt(i), occurence);
            }else{
                secondHashMap.put(t.charAt(i), 1);
            }
        }

        for (HashMap.Entry<Character, Integer> set : firstHashMap.entrySet()) {
            if(secondHashMap.containsKey(set.getKey())){
                int second  = secondHashMap.get(set.getKey());
                int first = set.getValue();
                if(first != second) return false;
            }else{
                return false;
            }
        }
        return true;
    }

    public static boolean isAnagram(String s, String t) {
        int []characterArray = new int[26];
        int length1 = s.length();
        int length2 = t.length();
        if(length1 != length2) return false;

        for(int i = 0; i < length1; ++i){
            ++characterArray[s.charAt(i) - 97];

        }

        for(int i = 0; i < length2; ++i){
            --characterArray[t.charAt(i) - 97];


        }

        for(int i = 0; i < 26; ++i){
            if(characterArray[i] != 0) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        String s = "anagram";
        String t = "nagaram";
        boolean result = isAnagram(s, t);
        System.out.println(result);
    }
}
