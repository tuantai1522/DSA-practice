import java.util.*;

public class TopKFrequentElements {
    public static int[] topKFrequent_MySolution(int[] nums, int k) {
        HashMap<Integer, Integer> MyHashMap = new HashMap<Integer, Integer>();
        HashSet<Integer> MyHashSet = new HashSet<Integer>();

        int length = nums.length;
        for(int i = 0; i < length; ++i){
            if(MyHashMap.containsKey(nums[i])){
                int occurence = MyHashMap.get(nums[i]) + 1;
                MyHashMap.put(nums[i], occurence);
            }else{
                MyHashMap.put(nums[i], 1);
            }
        }
        while(k > 0){
            int max = Integer.MIN_VALUE;
            int key = -1;
            for (HashMap.Entry<Integer, Integer> set : MyHashMap.entrySet()) {
                if(max < set.getValue()){
                    max = set.getValue();
                    key = set.getKey();
                }
            }
            MyHashSet.add(key);
            MyHashMap.remove(key);
            --k;
        }

        int arr[] = new int[MyHashSet.size()];
        int i = 0;
        for(int ele : MyHashSet){
            arr[i++] = ele;
        }

        return arr;
    }

    public static int[] topKFrequent(int[] nums, int k) {
        HashMap<Integer, Integer> MyHashMap = new HashMap<Integer, Integer>();

        int length = nums.length;

        if (length == 1) {
            return new int[]{1};
        }
        for(int i = 0; i < length; ++i){
            MyHashMap.put(nums[i], MyHashMap.getOrDefault(nums[i], 0) + 1);
        }

        ArrayList<ArrayList<Integer>> MyArrayList = new ArrayList<>();
        for (int i = 0; i <= length; i++) {
            MyArrayList.add(new ArrayList<>());
        }


        //to restore the k frequent elements of all elements in array
        for (HashMap.Entry<Integer, Integer> set : MyHashMap.entrySet()) {

            //at index of the frequent occurence of that element
            MyArrayList.get(set.getValue()).add(set.getKey());
        }

        for (int i = 0; i <= length; i++) {
            System.out.println(MyArrayList.get(i));
        }

        List<Integer> result = new ArrayList<>();

        for (int i = length; i >= 0; --i) {
            if(result.size() >= k){
                break;
            }

            if(!MyArrayList.get(i).isEmpty()) result.addAll(MyArrayList.get(i));
        }

        // Convert List<Integer> to int[]
        int[] resultArray = new int[result.size()];
        for (int i = 0; i < result.size(); i++) {
            resultArray[i] = result.get(i);
        }

        return resultArray;
    }

    public static void main(String[] args) {
        int [] nums = {1, 10, 2, 3, 10, 1, 2, 1, 10, 1, 10};
        int k = 2;
        int [] result = topKFrequent(nums, k);
        for(int i = 0; i < result.length; ++i){
            System.out.println(result[i]);
        }
    }
}
