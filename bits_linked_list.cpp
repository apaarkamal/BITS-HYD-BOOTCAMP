#include<bits/stdc++.h>

using namespace std;

struct node {
	int data;
	node* next;
	node(int data) {
		this->data = data;
		next = NULL;
	}
};

node* constructLinkedList() {
	node *head = NULL;
	node *tail = NULL;

	while (1) {
		int x;
		cin >> x;
		if (x == -1) break;

		node *curnode = new node(x);

		if (head == NULL) {
			head = curnode;
			tail = curnode;
		}
		else {
			tail->next = curnode;
			tail = tail->next;
		}
	}

	return head;
}

void printLinkedList(node* head) {
	node *cur = head;
	while (cur != NULL) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << '\n';
}

node* insertAtHead(node* head, int x) {
	node *curnode = new node(x);
	if (head == NULL) {
		head = curnode;
	}
	else {
		curnode->next = head;
		head = curnode;
	}
	return head;
}

node* insertAtTail(node* head, int x) {
	if (head == NULL) {
		return insertAtHead(head, x);
	}
	node* cur = head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	node *newnode = new node(x);
	cur->next = newnode;
	return head;
}

int LengthOfLinkedList(node* head) {
	node* cur = head;
	int cnt = 0;
	while (cur) {
		cur = cur->next;
		cnt++;
	}
	return cnt;
}

node* insertAtK(node* head, int k, int x) {
	if (head == NULL || k == 1) {
		return insertAtHead(head, x);
	}
	if (k > LengthOfLinkedList(head)) {
		return insertAtTail(head, x);
	}

	node* cur = head;
	k -= 2;
	while (k--) {
		cur = cur->next;
	}

	node *newnode = new node(x);
	newnode->next = cur->next;
	cur->next = newnode;

	return head;
}

node* leftShiftLinkedList(node* head, int k) {
	if (head == NULL) return NULL;
	int n = LengthOfLinkedList(head);
	k = ((k % n) + n) % n ;

	node* cur = head;
	k -= 1;
	while (k--) {
		cur = cur->next;
	}
	node* new_head = cur->next;
	cur->next = NULL;

	cur = new_head;
	while (cur->next != NULL) {
		cur = cur->next;
	}
	cur->next = head;

	return new_head;
}

node* rightShiftLinkedList(node* head, int k) {
	return leftShiftLinkedList(head, LengthOfLinkedList(head) - k);
}

node* deleteLinkedListnode(node* head, int k) {
	if (head == NULL || k == 1) return NULL;

	node* cur = head;
	k -= 2;
	while (k--) {
		cur = cur->next;
	}

	node* to_be_deleted = cur->next;
	cur->next = cur->next->next;
	delete to_be_deleted;
	return head;
}

node* reverseLinkedList(node* head) {
	node* cur = head;
	node* prev = NULL;
	while (cur) {
		node* ahead = cur->next;
		cur->next = prev;
		prev = cur;
		cur = ahead;
	}
	return prev;
}

node* merge(node* head1, node* head2) {
	if (head1 == NULL && head2 == NULL) return NULL;
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;

	if (head1->data < head2->data) {
		head1->next = merge(head1->next, head2);
		return head1;
	}
	else {
		head2->next = merge(head1, head2->next);
		return head2;
	}
}

node* midPoint(node* head) {
	node* slow = head;
	node* fast = head;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

node* mergesortLinkedList(node* head) {
	if (head == NULL || head->next == NULL) return head;
	node* midNode = midPoint(head);
	node* head1 = midNode->next;
	midNode->next = NULL;

	head = mergesortLinkedList(head);
	head1 = mergesortLinkedList(head1);
	node* new_list = merge(head, head1);

	return new_list;
}

bool isCycle(node* head) {
	node* slow = head;
	node* fast = head;

	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) return true;
	}
	return false;
}

node* detectCyclicNode(node* head) {
	if (!isCycle(head)) return NULL;

	node* slow = head;
	node* fast = head;

	while (1) {
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) break;
	}

	slow = head;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	// node* head = new node(5);
	// cout << head->data;

	// node* head = constructLinkedList();

	// head = insertAtHead(head, 10);
	// head = insertAtTail(head, 20);

	// // insert at kth position
	// head = insertAtK(head, 3, 30);

	// head = leftShiftLinkedList(head, 3);


	// head = deleteLinkedListnode(head, 3);

	// head = reverseLinkedList(head);

	// printLinkedList(head);

	// head = mergesortLinkedList(head);

	// printLinkedList(head);

	// node* head = constructLinkedList();
	// head->next->next->next->next->next->next->next = head->next->next->next;

	// cout << isCycle(head) << '\n';

	// node* cyclic_node = detectCyclicNode(head);
	// cout << cyclic_node->data;










	return 0;
}