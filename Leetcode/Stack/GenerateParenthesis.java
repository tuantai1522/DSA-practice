import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Stack;

public class GenerateParenthesis {
    public static void backpack(List<String> res, String current_string, int n, int open, int close){
        if(current_string.length() == n * 2){

            res.add(current_string);
            return;
        }

        if(open < n) {
            backpack(res, current_string + "(", n, open + 1, close);

        }
        if(open > close) {
            backpack(res, current_string + ")", n, open, close + 1);
        }
    }
    public static List<String> generateParenthesis(int n) {
        List<String> res = new ArrayList<>();

        backpack(res, "", n, 0, 0);

        return res;

    }

    public static void main(String[] args) {
        generateParenthesis(2);
    }
}
