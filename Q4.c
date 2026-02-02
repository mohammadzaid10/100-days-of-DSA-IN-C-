/**You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
Example 2:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.**/ 
#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    if (pricesSize == 0) return 0;

    int min_price = prices[0]; // Assume the first day is the cheapest initially
    int max_profit = 0;        // Start with zero profit

    for (int i = 1; i < pricesSize; i++) {
        // If we find a lower price, update the buying point
        if (prices[i] < min_price) {
            min_price = prices[i];
        } 
        // Otherwise, check if selling today gives us a better profit
        else {
            int current_profit = prices[i] - min_price;
            if (current_profit > max_profit) {
                max_profit = current_profit;
            }
        }
    }

    return max_profit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int n = sizeof(prices) / sizeof(prices[0]);
    
    int result = maxProfit(prices, n);
    printf("Maximum Profit: %d\n", result);   

    return 0;
}