#include <iostream>
#include<queue>
#include<vector>

/*
first hard solved without help :D
 */
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        using P = priority_queue<int, vector<int>, greater<int>>;

        int vectorSize = lists.size();
        vector<P> myLists(lists.size());
        int allItemCount = 0;
        int listCount = 0;
        for(auto val : lists)
        {
            while(val != nullptr)
            {
                myLists[0].push(val->val);
                allItemCount++;
                val = val->next;
            }
            listCount++;
        }
        vector<int> finalResult(allItemCount);
        for(int k = 0; k < allItemCount; k++)
        {
            int minIdx = 0;
            int val = 0;
            for(int j = 0; j < vectorSize; j++)
            {
                if(myLists[j].size() >= 1)
                {
                    minIdx = j;
                    val = myLists[j].top();
                    break;
                }
            }
            for(int i = minIdx; i < vectorSize; i++)
            {
                if(myLists[i].size() >= 1)
                {
                    if(myLists[i].top() < val)
                    {
                        minIdx = i;
                        val = myLists[i].top();
                    }
                }
            }
            finalResult[k] = val;
            myLists[minIdx].pop();
        }
        if(allItemCount >=1)
        {
            ListNode *result = new ListNode();
            ListNode *head = result;
            result->val = finalResult[0];
            for(int i = 1; i < allItemCount; i++)
            {
                ListNode *newVal = new ListNode(finalResult[i]);
                head->next = newVal;
                head = head->next;
            }
            return result;
        }
        else
        {
            return nullptr;
        }
    }
};


int main()
{    
    return 0;
}