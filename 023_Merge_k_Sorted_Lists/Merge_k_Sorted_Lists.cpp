#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        ListNode *result = NULL;

        /** 错误情况处理和递归终止条件 */
        if (l1 == NULL)
            return l2;
        else if (l2 == NULL)
            return l1;

        /** 选出较小的值进行递归合并 */
        if (l1->val < l2->val)
        {
            result = l1;
            result->next = mergeTwoLists(l1->next, l2);
        }
        else
        {
            result = l2;
            result->next = mergeTwoLists(l1, l2->next);
        }
        return result;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        if(lists.size() == 1)
            return lists.front();

        ListNode *l1 = NULL;
        ListNode *l2 = NULL;
        vector<ListNode*> lists1, lists2;
        lists1.insert(lists1.begin(), lists.begin(), lists.begin()+lists.size()/2);
        lists2.insert(lists2.begin(), lists.begin()+lists.size()/2, lists.end());

        l1 = mergeKLists(lists1);
        l2 = mergeKLists(lists2);

        return mergeTwoLists(l1, l2);
    }
};

int main()
{
    Solution sol;
    vector<ListNode*> lists;
    ListNode l1(1);
    ListNode l2(4);
    ListNode l3(5);
    ListNode l4(1);
    ListNode l5(3);
    ListNode l6(4);
    ListNode l7(2);
    ListNode l8(6);
    l1.next = &l2;
    l2.next = &l3;
    l4.next = &l5;
    l5.next = &l6;
    l7.next = &l8;
    lists.push_back(&l1);
    lists.push_back(&l4);
    lists.push_back(&l7);
    ListNode *result = sol.mergeKLists(lists);

    while(result)
    {
        cout << result->val << ' ';
        result = result->next;
    }
    cout << endl;

    return 0;
}
