#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

_Bool hasCycle(struct ListNode *head) {
	struct ListNode *slow = head, *fast = head;
	do  {
		if (fast == NULL || fast->next == NULL) {
			return 0;
		}
		slow = slow->next;
		fast = fast->next->next;
	} while (slow != fast);
	return 1;
}

typedef struct ListNode node;

int main() {
	node n1, n2, n3;
	n1.val = 1;
	n2.val = 2;
	n3.val = 3;
	node *p_n1 = NULL;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n1;
	int tf = hasCycle(p_n1);
	printf("%d\n", tf);
	return 0;
}
