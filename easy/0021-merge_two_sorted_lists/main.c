#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode* newNode() {
	struct ListNode *node = malloc(sizeof(struct ListNode));
	node->next = NULL;
	return node;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
	if (list1 == NULL) return list2;
	if (list2 == NULL) return list1;
	struct ListNode *merged = newNode();
	struct ListNode *temp, *tail = merged;

	while (list1 != NULL && list2 != NULL) {
		temp = newNode();
		if (list1->val <= list2->val) {
			temp->val = list1->val;
			list1 = list1->next;
		} else {
			temp->val = list2->val;
			list2 = list2->next;
		}
		tail->next = temp;
		tail = temp;
	}

	while (list1 != NULL) {
		temp = newNode();
		temp->val = list1->val;
		list1 = list1->next;
		tail->next = temp;
		tail = temp;
	}
	while (list2 != NULL) {
		temp = newNode();
		temp->val = list2->val;
		list2 = list2->next;
		tail->next = temp;
		tail = temp;
	}

	return merged->next;
}

void freeAllNodes(struct ListNode* head) {
	if (head->next == NULL) {
		return;
	}
	freeAllNodes(head->next);
	free(head->next);
}

int main(int argc, char *argv[]) {
	struct ListNode *first = newNode();
	struct ListNode *second = newNode();
	first->val = 8;
	first->next = NULL;
	second->val = 4;
	second->next = newNode();
	second->next->val = 5;
	second->next->next = NULL;

	struct ListNode *merged = mergeTwoLists(first, second);
	while (merged->next != NULL) {
		printf("%d\t", merged->val);
		merged = merged->next;
	}
	printf("%d\n", merged->val);

	freeAllNodes(merged);
	freeAllNodes(first);
	freeAllNodes(second);

	return 0;
}
