#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) 
{
    vector l2r(nums.size(), 1);
    vector r2l(nums.size(), 1);
    vector res(nums.size(), 0);
    int mulVal = 1;
    for(int i = 1; i < (int)nums.size(); i++)
    {
        l2r[i] = nums[i-1] * mulVal;
        mulVal = l2r[i];
    }
    mulVal = 1;
    for(int i = nums.size() - 2; i >= 0; i--)
    {
        r2l[i] = nums[i + 1] * mulVal;
        mulVal = r2l[i];
    }
    // inp = [ 1, 2,3,4]
    // l2r = [ 1, 1,2,6]
    // r2l = [24,12,4,1]

    for(int i = 0; i < nums.size(); i++)
    {
        res[i] = l2r[i] * r2l[i];
    }
    return res;
}

int main()
{
    vector<int> nums = {-1,-90981};
    auto res = productExceptSelf(nums);
    for(auto val : res)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}