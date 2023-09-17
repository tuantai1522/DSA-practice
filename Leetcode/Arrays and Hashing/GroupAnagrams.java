import java.util.ArrayList;
import java.util.List;
import java.util.HashMap;

public class GroupAnagrams {
    public static List<List<String>> groupAnagrams(String[] strs) {
        int length = strs.length;
        List<List<String>> result = new ArrayList<>();


        HashMap<String, List<String>> MyHashMap = new HashMap<>();
        for(int i = 0; i < length; ++i){
            int [] characterArray = new int[26];
            List<String> MyList;
            for(int j = 0; j < strs[i].length(); ++j){
                ++characterArray[strs[i].charAt(j) - 97];
            }

            String key = characterArray.toString();
            if(MyHashMap.containsKey(key)){
                MyList = MyHashMap.get(key);
            }else{
                MyList = new ArrayList<String>();
            }
            MyList.add(strs[i]);
            MyHashMap.put(key, MyList);
        }
        result.addAll(MyHashMap.values());

        return result;
    }
    public static void main(String[] args) {

    }
}
