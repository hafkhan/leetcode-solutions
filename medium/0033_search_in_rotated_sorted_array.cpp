#include <iostream>
#include <vector>
#include <string>

using namespace std;
int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;
    int index = -1;
    while(l <= r)
    {
        int mid = l + (r - l) / 2;
        if(nums[mid] == target)
        {
            index = mid;
            break;
        }
        if(nums[l] <= nums[mid])
        {
            //left half is sorted
            if(nums[l] <= target && target < nums[mid])
            {
                r =  mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            if(nums[mid] < target && target <= nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
    }
    return index;
}

int main()
{
    vector<int> nums = {4,,5,6,7,0,1,2};
    int target = 0;
    cout << search(nums,target) << endl;
    return 0;
}