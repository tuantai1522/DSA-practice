//https://leetcode.com/problems/valid-palindrome/description/
public class BestTimeToBuyandSellStock {
    public int maxProfit(int[] prices) {
        int size = prices.length;

        int min = Integer.MAX_VALUE;

        int ans = 0;
        for(int price : prices){
            min = Math.min(min, price);

            ans = Math.max(ans, price - min);
        }

        return ans;
    }
}
