#include <bits/stdc++.h>

using namespace std;

struct Node {
	int data;
	struct Node* next;
};

void printLinkedList(Node *node) {
    while(1) {
        cout << (node -> data);
        if((node -> next) == NULL) break;
        node = (node -> next);
    }
}

Node* createLinkedList(Node **node, int n) {
	if( n > 0 &&  (*node) == NULL) {
		(*node) = new Node;
		int temp;
		cin >> temp;
		(*node) -> data = temp;
		(*node) -> next = createLinkedList( &((*node)->next), n-1);
	}
	return (*node);
}

int length(Node *node) {
    if(node == NULL) return 0;
    return 1+length((node->next));
}

int findElem(Node *node, int query) {
    if((node->data) == query) return query;
    if((node->next) == NULL) return -1;

    return findElem((node->next), query);
}

int middleElem(Node *node) {
    Node *slow = node;
    Node *fast = node;
    while(1) {
        if(fast == NULL || (fast->next) == NULL ) return (slow->data);
        if( (fast->next->next) == NULL) return (slow -> next -> data);
        slow = (slow ->next);
        fast = (fast -> next -> next);
    }
}

int main() {
	Node *head = NULL;
	int n;
	cin >> n;
	createLinkedList(&head, n);
	printLinkedList(head);
	cout << "The lenth of the linked list is " << length(head);

	cout << endl << (findElem(head, 9) != -1 ? "Found the element " : "Element Not Found");

	cout << endl << "Mid Elem " << middleElem(head);
	return 0;
}
