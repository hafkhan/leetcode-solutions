#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    ListNode* newListHead = nullptr;
    ListNode* newListTail = nullptr;
    while(list1 != nullptr && list2 != nullptr)
    {
        if(list1->val <= list2->val)
        {
            if(newListHead == nullptr)
            {
                newListHead = list1;
                newListTail = list1;
            }
            else
            {
                newListTail->next = list1;
                newListTail = newListTail->next;
            }
            list1 = list1->next;
        }
        else
        {
            if(newListHead == nullptr)
            {
                newListHead = list2;
                newListTail = list2;
            }
            else
            {
                newListTail->next = list2;
                newListTail = newListTail->next;
            }
            list2 = list2->next;
        }
    }
    if(newListHead == nullptr)
    {
        if(list1 == nullptr)
        {
            newListHead = list2;
        }
        else
        {
            newListHead = list1;
        }
    }
    else
    {
        if(list1 == nullptr)
        {
            newListTail->next = list2;
        }
        else
        {
            newListTail->next = list1;
        }
    }
    return newListHead;
}


ListNode* build_list(const vector<int>& v) 
{
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int x : v) {
        tail->next = new ListNode(x);
        tail = tail->next;
    }
    return dummy.next;
}
vector<int> to_vec(ListNode* h) 
{
    vector<int> out; 
    for (auto* p=h; p; p=p->next) 
        out.push_back(p->val); 
    return out;
}
void free_list(ListNode* h) 
{ 
    while (h)
    {
        auto* n=h->next; delete h; h=n;
    }
}

int main() {
    vector<tuple<vector<int>,vector<int>,vector<int>,string>> tests = {
        {{1,2,4}, {1,3,4}, {1,1,2,3,4,4}, "interleaved"},
        {{}, {}, {}, "both empty"},
        {{}, {0}, {0}, "left empty"},
        {{5}, {1,2,3}, {1,2,3,5}, "single + list"},
        {{1,3,5}, {2,4,6}, {1,2,3,4,5,6}, "alternating"},
        {{1,1,1}, {1,1}, {1,1,1,1,1}, "duplicates"},
        {{-10,-3,0,2}, {-5,-4,3}, {-10,-5,-4,-3,0,2,3}, "negatives+positives"},
        {{1,2,2,3}, {2,2,4}, {1,2,2,2,2,3,4}, "runs of equals"}
    };

    int pass = 0, tc = (int)tests.size();
    for (int i = 0; i < tc; ++i) 
    {
        auto [a,b,exp,name] = tests[i];
        ListNode* l1 = build_list(a);
        ListNode* l2 = build_list(b);
        ListNode* merged = mergeTwoLists(l1, l2);
        auto got = to_vec(merged);

        bool ok = (got == exp);
        cout << "Test " << (i+1) << " [" << name << "]: " << (ok ? "PASS" : "FAIL") << "\n";
        if (!ok) 
        {
            cout << "  expected: "; for (int x:exp) cout << x << " "; cout << "\n";
            cout << "  got:      "; for (int x:got) cout << x << " "; cout << "\n";
        }
        free_list(merged);
        pass += ok;
    }
    cout << "\nSummary: " << pass << "/" << tc << " passed.\n";
    return 0;
}