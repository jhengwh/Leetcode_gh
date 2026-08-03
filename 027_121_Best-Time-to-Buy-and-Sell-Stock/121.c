int maxProfit(int* prices, int pricesSize) {
    int buy_price = prices[0];
    int profit = 0;

    for (int i = 1; i < pricesSize; i++)
    {
        if (prices[i-1] < buy_price)
        {
            buy_price = prices[i-1];
        }

        if ((prices[i] - buy_price) > profit)
        {
            profit = prices[i] - buy_price;
        }
    }

    return profit;
}