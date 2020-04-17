#include<iostream>
#include<stdio.h>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int a) {
		data = a;
		next = NULL;
	}
};

class LinkedList {
public:
	Node* head;
	Node* tail;

	LinkedList() {
		head = NULL;
		tail = NULL;
	}
	
	int front() {
		return head->data;
	}

	void insert(int n) {
		Node* newN = new Node(n);
		if (head == NULL)
			head = tail = newN;
		else {
			newN->next = head;
			head = newN;
		}
	}

	int del() {
		if (head == NULL)
			return -1;
		else {
			Node* tmp = head;
			head = head->next;
			return tmp->data;
		}
	}

};

class LinkedStack {
public:
	int sz;
	LinkedList* s;

	LinkedStack() {
		this->s = new LinkedList();
		this->sz = 0;
	}

	int size() {
		return sz;
	}

	bool empty() {
		return(sz == 0);
	}

	int top() {
		if (sz== 0)
			return -1;
		return s->front();
	}
	void push(int e) {
		s->insert(e);
		sz++;
	}
	int pop() {
		if (sz != 0) {
			sz--;
			return s->del();
		}
		else
			return -1;
	}
};

int main() {
	LinkedStack s = LinkedStack();
	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		string str;
		int x;
		cin >> str;

		if (str == "push") {
			cin >> x;
			s.push(x);
		}
		else if (str == "top") {
			printf("%d\n", s.top());
		}
		else if (str == "size")
			printf("%d\n", s.size());
		else if (str == "empty")
			printf("%d\n", s.empty());
		else if (str == "pop")
			printf("%d\n", s.pop());
		else
			i--;
	}

}