#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

class Tree {
	string data;
	Tree* left, * right;
public:
	Tree() {
		data = "";
		left = NULL;
		right = NULL;
	}

	void setData(char data) {
		this->data = data;
	}
	void setLeft(Tree* left) {
		this->left = left;
	}
	void setRight(Tree* right) {
		this->right = right;
	}
	void preorder(Tree* root) { //전위
		if (root) {
			cout << root->data;
			preorder(root->left);
			preorder(root->right);
		}
	}
	void inorder(Tree* root) {//중위
		if (root) {
			inorder(root->left);
			cout << root->data;
			inorder(root->right);
		}
	}
	void postorder(Tree* root) {//후위
		if (root) {
			postorder(root->left);
			postorder(root->right);
			cout << root->data;
		}
	}
};

int main() {
	int N;
	cin >> N;
	Tree* tree = new Tree[N];
	for (int i = 0; i < N; i++) {
		char data, left, right;
		cin >> data >> left >> right;
		if (data != '.')
			tree[(int)(data - 'A')].setData(data);
		if (left != '.')
			tree[(int)(data - 'A')].setLeft(&tree[(int)(left - 'A')]);
		else
			tree[(int)(data - 'A')].setLeft(NULL);
		if (right != '.')
			tree[(int)(data - 'A')].setRight(&tree[(int)(right - 'A')]);
		else
			tree[(int)(data - 'A')].setRight(NULL);
	}

	Tree* root = &tree[0];
	tree->preorder(root);
	printf("\n");
	tree->inorder(root);
	printf("\n");
	tree->postorder(root);
	printf("\n");

}