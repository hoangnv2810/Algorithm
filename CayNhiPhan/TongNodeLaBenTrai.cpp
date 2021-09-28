#include<iostream>
#include<stack>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

void addNode(int u, int v, char x, Node** root) {
	if ((*root) != NULL && (*root)->data == u) {
		if (x == 'L') {
			(*root)->left = new Node(v);
		}
		else {
			(*root)->right = new Node(v);
		}
	}
	else {
		if ((*root)->right != NULL) {
			addNode(u, v, x, &(*root)->right);
		}
		if ((*root)->left != NULL) {
			addNode(u, v, x, &(*root)->left);
		}
	}
}

int sumLeftNode(Node* root) {
	stack<Node*> st;
	st.push(root);
	int sum = 0;
	while (!st.empty()) {
		Node* node = st.top();
		st.pop();
		if (node->left != NULL) {
			st.push(node->left);
			if (node->left->left == NULL && node->left->right == NULL) {
				sum += node->left->data;
			}
		}
		if (node->right != NULL) {
			st.push(node->right);
		}
	}
	return sum;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int u, v;
		char x;
		cin >> u >> v >> x;
		Node* root = new Node(u);
		addNode(u, v, x, &root);
		for (int i = 1; i < n; i++) {
			cin >> u >> v >> x;
			addNode(u, v, x, &root);
		}
		cout << sumLeftNode(root) << endl;
	}
}
