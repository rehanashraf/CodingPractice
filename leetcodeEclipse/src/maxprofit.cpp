//
//  maxprofit.cpp
//  leetcodeXcode
//
//  Created by Rehan Ashraf on 7/3/20.
//  Copyright © 2020 Rehan Ashraf. All rights reserved.
//

/*
Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

#include <stdio.h>
#include <iostream>
#include <vector>
bool runMaxProfit();
int maxProfit(std::vector<int>& prices);

int maxProfit(std::vector<int>& prices) {
    int rv, buyingprice, sellingprice, profit;
    rv = buyingprice = sellingprice = profit = 0;
    
    if (prices.size() == 0 || prices.size() == 1)
        return rv;
    buyingprice = prices[0];
    for(int i = 1; i < prices.size(); i++)
    {
        sellingprice = prices[i];
        if (sellingprice > buyingprice)
        {
            profit += sellingprice - buyingprice;
        }
        buyingprice = sellingprice;
    }
    rv = profit;
    return rv;
}

bool runMaxProfit() {
    bool rv = true;
    int maxprofit = 0;
    std::vector<int> list1, list2, list3;
    
    list1.push_back(7);
    list1.push_back(1);
    list1.push_back(5);
    list1.push_back(3);
    list1.push_back(6);
    list1.push_back(4);
    
    list2.push_back(1);
    list2.push_back(2);
    list2.push_back(3);
    list2.push_back(4);
    list2.push_back(5);
    list2.push_back(6);
    
    list3.push_back(3);
    list3.push_back(2);
    list3.push_back(6);
    list3.push_back(5);
    list3.push_back(0);
    list3.push_back(3);
    
    maxProfit(list1);
    maxProfit(list2);
    maxProfit(list3);
    
    return rv;
}
