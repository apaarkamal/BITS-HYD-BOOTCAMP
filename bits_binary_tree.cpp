#include<bits/stdc++.h>

using namespace std;

struct node {
	int data;
	node* left;
	node* right;
	node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

node* buildLevelOrderTree() {
	queue<node*> Q;

	int d;
	cin >> d;
	node* root = new node(d);

	Q.push(root);

	while (!Q.empty()) {
		node* cur = Q.front();
		Q.pop();
		int leftval, rightval;
		cin >> leftval >> rightval;
		if (leftval != -1) {
			cur->left = new node(leftval);
			Q.push(cur->left);
		}
		if (rightval != -1) {
			cur->right = new node(rightval);
			Q.push(cur->right);
		}
	}

	return root;
}

void preorder(node* root) {
	if (root == NULL) return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root) {
	if (root == NULL) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void postorder(node* root) {
	if (root == NULL) return;
	inorder(root->left);
	inorder(root->right);
	cout << root->data << " ";
}

void printLevelOrderTree(node* root) {
	queue<node*> Q;
	Q.push(root);

	while (!Q.empty()) {
		node* cur = Q.front();
		Q.pop();
		cout << cur->data << " ";
		if (cur->left) Q.push(cur->left);
		if (cur->right) Q.push(cur->right);
	}

	return;
}

int countNode(node* root) {
	if (root == NULL) return 0;
	return countNode(root->left) + countNode(root->right) + 1;
}

int heightTree(node* root) {
	if (root == NULL) return 0;
	return max(heightTree(root->left), heightTree(root->right)) + 1;
}

int diameter(node* root) {
	if (root == NULL) return 0;

	int left_height = heightTree(root->left);
	int right_height = heightTree(root->right);

	int left_tree_diameter = diameter(root->left);
	int right_tree_diameter = diameter(root->right);

	return max({left_height + right_height, left_tree_diameter, right_tree_diameter});
}

bool Identical(node* root1, node* root2) {
	if (root1 == NULL && root2 == NULL) return true;
	if (root1 == NULL) return false;
	if (root2 == NULL) return false;
	if (root1->data == root2->data
	        && Identical(root1->left, root2->left)
	        && Identical(root1->right, root2->right)) {
		return true;
	}
	return false;
}

void mirror(node* root) {
	if (root == NULL) return;
	swap(root->left, root->right);
	mirror(root->left);
	mirror(root->right);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	node* root = buildLevelOrderTree();

	// preorder(root);

	// inorder(root);

	// postorder(root);

	// printLevelOrderTree(root);

	// cout << countNode(root);

	// cout << heightTree(root);

	// cout << diameter(root);

	mirror(root);

	printLevelOrderTree(root);


	return 0;
}