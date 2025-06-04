#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node *next;
    struct Node *random;
};
typedef struct Node node ;

void insertCopy(node *nd) {
	node *new = (node *) malloc(sizeof(node));
	new->val = nd->val;
	new->next = nd->next;
	nd->next = new;
}

void fixCopyRandom(node *head) {
	while (head != NULL) {
		if (head->random == NULL) {
			head->next->random = NULL;
		} else {
			head->next->random = head->random->next;
		}
		head = head->next->next;
	}
}

void deleteOldList(node *new_head) {
	while (new_head->next != NULL) {
		new_head->next = new_head->next->next;
		new_head = new_head->next;
	}
}

struct Node* copyRandomList(struct Node* head) {
	if (head == NULL) {
		return 0;
	}
	for (node *tmp = head; tmp != NULL; tmp = tmp->next->next) {
		insertCopy(tmp);
	}
	fixCopyRandom(head);
	deleteOldList(head->next);

	return head->next;
}

int main() {
	node n0, n1, n2, n3, n4;
	n0.val = 7;
	n1.val = 13;
	n2.val = 11;
	n3.val = 10;
	n4.val = 1;
	node *p_n1 = &n0;
	n0.next = &n1;
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = NULL;
	n0.random = NULL;
	n1.random = &n0;
	n2.random = &n4;
	n3.random = &n2;
	n4.random = &n0;
	node *new = copyRandomList(p_n1);

	return 0;
}
