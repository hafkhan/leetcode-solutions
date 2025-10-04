#include <vector>
#include <iostream>

using namespace std;

bool is_ok(vector<int>& nums, int val, int k)
{
    int parts = 1; 
    int sum = 0;
    for(auto x : nums)
    {
        if(sum + x > val)
        {
            if(parts == k)
            {
                return false;
            }
            parts++;
            sum = x; 
        }
        else
        {
            sum += x;
        }
    }
    return true;
}
int splitArray(vector<int>& nums, int k) {
    int low = 0;
    int high = 0;
    for(int x : nums)
    {
        high += x;
        low = max(low,x);
    }
    int found = high;
    while(low < high)
    {
        int med = low + (high - low) / 2;
        if(is_ok(nums, med, k))
        {
            found = med;
            high = med;
        }
        else
        {
            low = med + 1;
        }
    }
    return found;
}

int main()
{
    vector<int> nums = {1,2,3,4,5};
    int k = 2;
    cout << splitArray(nums,2) << endl;
    return 0;
}