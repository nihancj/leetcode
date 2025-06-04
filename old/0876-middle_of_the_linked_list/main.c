#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* middleNode(struct ListNode* head){
	struct ListNode *slow = head, *fast = head;
	while (fast != NULL && fast->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

typedef struct ListNode node;

int main() {
	node n1, n2, n3, n4, n5;
	n1.val = 1;
	n2.val = 2;
	n3.val = 3;
	n4.val = 4;
	n5.val = 5;
	node *p_n1 = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = NULL;
	struct ListNode* middle;
	middle = middleNode(p_n1);
	printf("%d", middle->val);
	return 0;
}
