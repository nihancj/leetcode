#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode *slow = head, *fast = head;
	do  {
		if (fast == NULL || fast->next == NULL) {
			return 0;
		}
		slow = slow->next;
		fast = fast->next->next;
	} while (slow != fast);

	slow = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

typedef struct ListNode node;

int main() {
	node n0, n1, n2, n3;
	n0.val = 3;
	n1.val = 2;
	n2.val = 0;
	n3.val = 4;
	node *p_n1 = &n0;
	n0.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n2;
	node *tf = detectCycle(p_n1);
	printf("%d\n", tf->val);
	return 0;
}
