#include <iostream>
#include <vector>
#include <string>

using namespace std;

int maxSubArray(vector<int>& nums) 
{
    int bestNow = nums[0];
    int bestAlltime = nums[0];
    for(int i = 1; i < (int)nums.size(); i++)
    {
        bestNow = max(bestNow + nums[i], nums[i]);
        bestAlltime = max(bestNow, bestAlltime);
    }
    return bestAlltime;
}

int main()
{
    vector<int> vals = {-2,1,-3,4,-1,2,1,-5,4};
    cout << maxSubArray(vals) << endl;
    return 0;
}