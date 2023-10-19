//https://leetcode.com/problems/ransom-note/
public class RansomNote {
    public boolean canConstruct(String ransomNote, String magazine) {
        int [] characterArray = new int[26];

        int length1 = ransomNote.length();
        int length2 = magazine.length();

        for(int i = 0; i < length2; ++i){
            ++characterArray[magazine.charAt(i) - 97];
        }

        for(int i = 0; i < length1; ++i){
            if(characterArray[ransomNote.charAt(i) - 97] == 0) return false;

            characterArray[ransomNote.charAt(i) - 97]--;
        }

        return true;
    }
}
