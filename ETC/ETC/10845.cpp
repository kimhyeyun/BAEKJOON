#include<iostream>
#include<stdio.h>
using namespace std;

struct Node {
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class linkedList {
public:
	Node* head;
	Node* tail;

	linkedList() {
		head = NULL;
		tail = NULL;
	}

	void insert(int data) {
		Node* newN = new Node(data);
		if (head == NULL) {
			head = newN;
			tail = head;
		}
		else {
			tail->next = newN;
			tail = newN;
		}
	}

	int del() {
		Node* tmp = head;
		head = head->next;
		return tmp->data;
	}

	int front() {
		return head->data;
	}

	int back() {
		return tail->data;
	}
};

class LinkedQueue {
public:
	linkedList* l;
	int sz = 0;

	LinkedQueue() {
		this->l = new linkedList();
		sz = 0;
	}

	void push(int data) {
		sz++;
		l->insert(data);
	}

	int pop() {
		if (l->head == NULL)
			return -1;
		else {
			sz--;
			return l->del();
		}
	}

	int size() {
		return sz;
	}

	bool empty() {
		return (sz == 0);
	}

	int front() {
		return l->front();
	}
	
	int back() {
		return l->back();
	}
};

int main() {
	LinkedQueue queue;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == "push") {
			int x;
			cin >> x;
			queue.push(x);
		}
		else if (str == "pop")
			printf("%d\n", queue.pop());
		else if (str == "size")
			printf("%d\n", queue.size());
		else if (str == "empty")
			printf("%d\n", queue.empty());
		else if (str == "front")
			printf("%d\n", queue.front());
		else if (str == "back")
			printf("%d\n", queue.back());
		else
			i--;
	}
}