/**
 * Created by hduser on 15-12-2.
 * Say you have an array for which the ith element is the price of a given stock on day i.
 * If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
 * design an algorithm to find the maximum profit.
 *
 */
public class BestTimetoBuyandSellStock {
    public int maxProfit(int[] prices) {
        return helper(prices);
    }
    private int helper(int[] prices) {
        if (prices.length <= 0) {
            return 0;
        }
        int maxProfits = Integer.MIN_VALUE;
        int lowestPrice = prices[0];
        int[] dp = new int[prices.length];
        dp[0] = 0;
        for (int i = 1; i < prices.length; i++) {
            if (prices[i] - lowestPrice > maxProfits) {
                maxProfits = prices[i] - lowestPrice;
            }
            if (lowestPrice > prices[i]) {
                lowestPrice = prices[i]; //　更新最低价格
            }
            if (maxProfits < 0) {
                maxProfits = 0;  //　如果是负值的话就没有必要计算了
            }
            dp[i] = maxProfits;
        }
        return dp[prices.length - 1];
    }
}
