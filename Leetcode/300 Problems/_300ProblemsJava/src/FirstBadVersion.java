//https://leetcode.com/problems/first-bad-version/description/

public class FirstBadVersion {
    public static boolean isBadVersion(int version){
        return true;
    }
    public int firstBadVersion(int n) {
        int left = 1;
        int right = n;

        int result = n;

        while(left < right){
            int mid = left + (right - left) / 2; //(left + right) / 2 will TLE
            if(isBadVersion(mid)){
                result = mid;
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return result;
    }
}
