/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <stdio.h>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#if 0
/* added to list 1 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *t1 = l1, *t2 = l2;

		while (1) {
			if (t2) {
				t1->val += t2->val;
			}
			if (t1->val >= 10) {
				if (t1->next) {
					t1->next->val += t1->val / 10;
				} else {
					t1->next = new ListNode(t1->val / 10);
				}
				t1->val %= 10;
			}
			if (!t1->next && (!t2 || !t2->next)) {
				break;
			}
			if (!t1->next) {
				t1->next = new ListNode(0);
			}
			t1 = t1->next;
			if (t2) {
				t2 = t2->next;			
			}
		}
		return l1;
    }
};
#endif

/* make a new list */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode *t1 = l1, *t2 = l2, *last = NULL, *n = NULL, *first = NULL;
		int base = 0;

		do {			
			n = new ListNode(base);
			if (last) {
				last->next = n;	
			} else {
				first = n;
			}
			if (t1) {
				n->val += t1->val;
				t1 = t1->next;
			}
			if (t2) {
				n->val += t2->val;
				t2 = t2->next;
			}
			if (n->val >= 10) {
				base = n->val / 10;
				n->val %= 10;
			} else {
				base = 0;
			}	
			last = n;
		} while (t1 != NULL || t2 != NULL || base != 0);

		return first;
    }
};

void printList(ListNode *l)
{
	for (ListNode *t = l; t; t=t->next)
		printf("%d %s", t->val, t->next ? "-> " : "\n");
}

ListNode *makeList(int *v, int n)
{
	ListNode *l, *last, *first;

	last = NULL;
	for (int i = 0; i < n; i++) {
		l = new ListNode(v[i]);
		if (last) {
			last->next = l;
		}
		if (i == 0) {
			first = l;
		}
		last = l;
	}
	return first;
}

int main()
{
	int v1[] = {9, 9, 9};
	int v2[] = {1};
	int v3[] = {0};
	int v4[] = {5};
	Solution *s = new Solution();

	ListNode *l1 = makeList(v1, 3);
	ListNode *l2 = makeList(v2, 1);
	ListNode *l = s->addTwoNumbers(l1, l2);
	printList(l);

	l1 = makeList(v3, 1);
	l2 = makeList(v3, 1);
	l = s->addTwoNumbers(l1, l2);
	printList(l);

	l1 = makeList(v4, 1);
	l2 = makeList(v4, 1);
	l = s->addTwoNumbers(l1, l2);
	printList(l);

	return 0;
}