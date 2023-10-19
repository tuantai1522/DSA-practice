//https://leetcode.com/problems/add-binary/
public class AddBinary {
    public static String addBinary(String a, String b) {
        StringBuilder result = new StringBuilder();

        int length_a = a.length();
        int length_b = b.length();

        int index_1 = length_a - 1;
        int index_2 = length_b - 1;

        int carry = 0;

        while(index_1 >= 0 || index_2 >= 0){
            int number_1 = index_1 >= 0 ? a.charAt(index_1--) - '0' : 0;
            int number_2 = index_2 >= 0 ? b.charAt(index_2--) - '0' : 0;

            int sum = number_1 + number_2 + carry;

            int number = sum % 2;
            carry = sum > 1 ? 1 : 0;

            result.append(number);

        }
        if(carry != 0){
            result.append(carry);
        }
        return String.valueOf(result.reverse());
    }

    public static void main(String[] args) {
        addBinary("11", "11");
    }
}
