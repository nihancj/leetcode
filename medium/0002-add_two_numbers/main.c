#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* newNode(int x) {
	struct ListNode *node = malloc(sizeof(struct ListNode));
	node->val = x;
	node->next = NULL;
	return node;
}

void addCarryToList(int carry, struct ListNode *tail) {
	while(carry) {
		if (tail->next == NULL) {
			tail->next = newNode(carry);
			return;
		}
		tail = tail->next;
		tail->val += carry;
		carry = tail->val/10;
		tail->val %= 10;
	}
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *l3, *tail;
	int sum = l1->val+l2->val;
	int carry = sum/10;
	l3 = newNode(sum%10);
	tail = l3;

	while (l1->next != NULL && l2->next != NULL) {
		l1 = l1->next;
		l2 = l2->next;
		sum = l2->val + l1->val;
		tail->next = newNode((sum+carry) % 10);
		tail = tail->next;
		carry = (sum+carry)/10;
	}

	if (l1->next != NULL) {
		tail->next = l1->next;
		addCarryToList(carry, tail);
		return l3;
	}
	if (l2->next != NULL) {
		tail->next = l2->next;
		addCarryToList(carry, tail);
		return l3;
	}

	addCarryToList(carry, tail);

	return l3;
}
