#include <iostream>

using namespace std;
struct Node {
	int data;
	Node* next;
};

//push back a new node
/*void push(Node*& list, int value) {
	Node* newNode = new Node();
	newNode->data = value;
	newNode->next = NULL;

	if(list == NULL){
		list = newNode;
	}
	else{
		Node* head = list;
		while(head->next != NULL) {
			head = head->next;
		}
		head->next = newNode;
	}
}*/

Node* push(Node*& tail, int value) {
	Node* newNode = new Node();
	newNode->data = value;
	newNode->next = NULL;

	if(tail == NULL){
		tail = newNode;
	}
	else{
		tail->next = newNode;
	}
}

//get to a node after moving forward certain steps
Node* stepForward(Node* node, int step) {
	int i = 0;
	while(i < step - 1) {
		node = node->next;
		i++;
	}
	return node;
}

//interleave node in recursive manner
Node* interleave(Node* p, Node* q, int step) {
    if(!q) return p;
	Node* temp = stepForward(p, step);
	q->next = interleave(temp->next, q->next, step);
    temp->next = q;
    return p;
}


//print out element in the list
void printList(Node*& list) {
	Node* curr = list;
	while(curr != NULL) {
		cout << curr->data << " ";
		curr = curr->next;
	}
}


int main() {
    ios_base::sync_with_stdio(false);
	Node* list1 = NULL;
	int initialNum = 0;
	cin >> initialNum;

	//push each the value to the end of a linked list to create the initial list
	int value;
	int headValue;
    cin >> headValue;
	Node* tail = push(list1, headValue);
	for(int i = 1; i < initialNum; i++) {
		cin >> value;
		tail = push(tail, value);
	}
	int additionalList = 0;
	int nodeNum = 0;
	cin >> additionalList;
	int step = 0;

	//interleave two lists with certain step in each iteration
	for(int i = 0; i < additionalList; i++) {
        Node* list2 = NULL;
		cin >> step;
		cin >> nodeNum;

		//create additional list
        cin >> headValue;
        Node* tail2 = push(list2, headValue);
		for(int i = 1; i < nodeNum; i++) {
			cin >> value;
			tail2 = push(tail2, value);
		}
		interleave(list1, list2, step);
	}

	//print out the resulted list
	printList(list1);
	return 0;
}
