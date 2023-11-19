public class ValidPalindrome {
    public boolean isPalindrome_MySolution(String s) {
        int length = s.length();
        if(length == 0 || length == 1) return true;

        s = s.toLowerCase().replaceAll("[^a-z0-9]","");

        int begin = 0;
        int end = s.length() - 1;
        while(begin < end){
            if(s.charAt(begin) != s.charAt(end)) return false;
            ++begin;
            --end;
        }
        return true;
    }


    public static boolean isPalindrome(String s) {
        int length = s.length();
        if(length == 0 || length == 1) return true;

        int i = 0;
        int j = length - 1;
        while(i < j){
            Character begin = s.charAt(i);
            Character end = s.charAt(j);

            //to check whether that element at index i is character (a -> z, A -> Z) or not
            if(!Character.isLetterOrDigit(begin)){
                ++i;
                continue;
            }

            //to check whether that element at index i is character (a -> z, A -> Z) or not
            if(!Character.isLetterOrDigit(end)){
                --j;
                continue;
            }
            if(Character.toLowerCase(begin) != Character.toLowerCase(end)) return false;

            ++i;
            --j;
        }
        return true;
    }

    public static void main(String[] args) {
        String s = "race a car";
        boolean result = isPalindrome(s);
        System.out.println(result);
    }
}
