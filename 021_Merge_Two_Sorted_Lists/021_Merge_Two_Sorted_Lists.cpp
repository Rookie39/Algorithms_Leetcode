#include <iostream>

using namespace std;

 struct ListNode {
     int val;
	 ListNode *next;
	 ListNode(int x) : val(x), next(NULL) {}
};

 class Solution {
 public:
	 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		 ListNode *result = NULL;

		 if (l1 == NULL)
			 return l2;
		 else if (l2 == NULL)
			 return l1;

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

int main()
{
	ListNode l11(1), l12(3), l13(4);
	ListNode l21(1), l22(3), l23(4);
	l11.next = &l12;
	l12.next = &l13;
	l21.next = &l22;
	l22.next = &l23;
	Solution sol;
	ListNode *result;
	result = sol.mergeTwoLists(&l11, &l21);
	for (size_t i = 0; i < 6; i++)
	{
		cout << result->val << " ";
		result = result->next;
	}
	cout << endl;

	system("pause");
	return 0;
}