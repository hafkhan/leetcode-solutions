#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    vector<int> result;
    deque<int> myDeque;
    for(int i = 0; i < nums.size(); i++)
    {
        while(!myDeque.empty() &&
                nums[myDeque.back()] <= nums[i])
        {
            myDeque.pop_back();
        }
        myDeque.push_back(i);
        
        if(i - k >= myDeque.front())
        {
            myDeque.pop_front();
        }
        
        if(i - k + 1 >= 0)
        {
            result.push_back(nums[myDeque.front()]);
        }
    }
    return result;

}
int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    auto res = maxSlidingWindow(nums, k);
    for(auto val:res)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}