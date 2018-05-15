/*
 *Author: Rookie118
 *Title: Add Two Numbers
 *Completion time: 2018-03-03
*/

//The first version
//Time complexity: O(max(m,n))
//Space complexity: O(max(m,n))
//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        ListNode l(0);  //新建一个头结点
        ListNode *ptr = &l;  //声明一个指针指向这个头节点
        int carry_digit = 0;  //进位数
        int sum = 0;
        while(l1 != NULL || l2 != NULL || carry_digit)  //循环直到l1和l2链表末尾且没有进位时结束
        {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry_digit;  //判断l1此时是否为NULL,是则返回0;l2同理
            carry_digit = sum / 10;  //整除取进位数

            ptr->next = new ListNode(sum % 10);  //新建结点存储余数
            ptr = ptr->next;

            if(l1 != NULL)  //防止l2比l1长导致l1越界
                l1 = l1->next;  //l1指向链表下一个地址
            if(l2 != NULL)  //防止l1比l2长导致l1越界
                l2 = l2->next; //l2指向链表下一个地址
        }
        return l.next;  //返回第一个存储数字的地址
    }
};
