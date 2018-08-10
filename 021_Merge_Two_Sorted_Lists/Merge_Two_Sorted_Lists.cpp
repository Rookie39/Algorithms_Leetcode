/*
 * Author: Rookie39
 * Title: Merge Two Sorted Lists
 * Completion time: 2018-08-07
*/

//The first version
//Time complexity: O(n)
//Space complexity: O(max(l1,l2))
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
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
};
