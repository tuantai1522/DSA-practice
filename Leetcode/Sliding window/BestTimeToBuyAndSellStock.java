public class BestTimeToBuyAndSellStock {
    public static int maxProfit(int[] prices) {
        int length = prices.length;
        int left = 0;
        int right = 1;
        int res = 0;
        while(right < length){
            if(prices[left] < prices[right]){
                res = Math.max(res, prices[right] - prices[left]);
                ++right;
            }else{
                left = right;
                ++right;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int [] prices = {2,1,2,0,1};
        int res = maxProfit(prices);
        System.out.println(res);
    }
}
