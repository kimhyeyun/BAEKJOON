#include<iostream>
#include<stdio.h>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* prev;
	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};

class LinkedDeque {
public:
	Node* head;
	Node* tail;
	int sz;

	LinkedDeque() {
		head = tail = NULL;
		sz = 0;
	}

	void push_front(int data) {
		Node* newN = new Node(data);
		if (head == NULL) {
			head = tail = newN;
		}
		else {
			newN->next = head;
			head->prev = newN;
			head = newN;
		}
		sz++;
	}

	void push_back(int data) {
		Node* newN = new Node(data);
		if (tail == NULL) {
			head = tail = newN;
		}
		else {
			newN->prev = tail;
			tail->next = newN;
			tail = newN;
		}
		sz++;
	}

	int pop_front() {
		if (head == NULL)
			return -1;
		else {
			Node* tmp = head;
			int d = tmp->data;
			if (sz > 1) {
				head = head->next;
				head->prev = NULL;
			}
			else {
				head = tail = NULL;
			}
			sz--;
			delete tmp;
			return d;
		}
	}

	int pop_back() {
		if (tail == NULL)
			return -1;
		else {
			Node* tmp = tail;
			if (sz == 1)
				head = tail = NULL;
			else {
				tail = tail->prev;
				tail->next = NULL;
			}
			int d = tmp->data;
			sz--;
			delete tmp;
			return d;
		}
	}

	int size() {
		return sz;
	}

	bool empty() {
		return (sz == 0);
	}

	int front() {
		if (head == NULL)
			return -1;
		else
			return head->data;
	}

	int back() {
		if (tail == NULL)
			return -1;
		else
			return tail->data;
	}
};

int main() {
	LinkedDeque dq;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (str == "push_front") {
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if (str == "push_back") {
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if (str == "pop_front")
			printf("%d\n", dq.pop_front());
		else if (str == "pop_back")
			printf("%d\n", dq.pop_back());
		else if (str == "size")
			printf("%d\n", dq.size());
		else if (str == "empty")
			printf("%d\n", dq.empty());
		else if (str == "front")
			printf("%d\n", dq.front());
		else if (str == "back")
			printf("%d\n", dq.back());
		else
			i--;
	}
}