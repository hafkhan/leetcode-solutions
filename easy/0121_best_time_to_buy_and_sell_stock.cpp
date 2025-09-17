#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxProfit(vector<int>& prices) {
    int retVal = 0;
    if(prices.empty())
        return 0;
    int minVal = prices[0];
    for(auto val : prices)
    {
        if(val - minVal > retVal)
            retVal = val-minVal;
        if(val < minVal)
            minVal = val;
    }
    return retVal;
}

int main()
{
    vector<int> test = {4,2,4,5,9,7,8,1};
    cout << maxProfit(test) << endl;
    return 0;
}