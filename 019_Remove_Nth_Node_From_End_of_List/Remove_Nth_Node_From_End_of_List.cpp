/**
* Definition for singly-linked list.
*/
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* findNthFromEnd(ListNode* head, int n) {
		if (head == NULL || n < 1)
		{
			return NULL;
		}

		ListNode* pFront = head;
		ListNode* pBack = NULL;

		for (size_t i = 0; i < n - 1; i++)
		{
			if (pFront->next != NULL)
			{
				pFront = pFront->next;
			}
			else
			{
				return NULL;
			}
		}

		pBack = head;
		while (pFront->next != NULL)
		{
			pFront = pFront->next;
			pBack = pBack->next;
		}
		return pBack;
	}

	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* pDeleted = findNthFromEnd(head, n);
		if (pDeleted == NULL)
		{
			return NULL;
		}

		if (head == pDeleted && head->next == NULL)
		{
			delete pDeleted;
			pDeleted = NULL;
			head = NULL;
		}
		else if (pDeleted->next == NULL)
		{
			ListNode* ptr = head;
			while (ptr->next != pDeleted)
			{
				ptr = ptr->next;
			}
			delete pDeleted;
			pDeleted = NULL;
			ptr->next = NULL;
		}
		else
		{
			ListNode* pNext = pDeleted->next;
			pDeleted->val = pNext->val;
			pDeleted->next = pNext->next;
			delete pNext;
			pNext = NULL;
		}
		return head;
	}
};