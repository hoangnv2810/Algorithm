#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

void addNode(int u, int v, char x, Node** root){
	if((*root) != NULL && (*root)->data == u){
		if(x == 'R'){
			(*root)->right = new Node(v);
		} else {
			(*root)->left = new Node(v);
		}
	} else {
		if((*root)->right != NULL){
			addNode(u, v, x, &(*root)->right);
		} 
		if((*root)->left != NULL){
			addNode(u, v, x, &(*root)->left);
		}
	}
}

bool check(int level, int* leafLevel, Node* root){
	if(root == NULL) return true;
	if(root->left == NULL && root->right == NULL){
		if(*leafLevel == 0){
			*leafLevel = level;
			return true;
		}
		return (level == *leafLevel);
	}
	return check(level+1, leafLevel, root->left) && check(level+1, leafLevel, root->right);
}

int main(){
	int t;
	cin >> t;
	while(t--){
		int n, u, v;
		char x;
		cin >> n >> u >> v >> x;
		Node* root = new Node(u);
		addNode(u, v, x, &root);
		for(int i = 1; i < n; i++){
			cin >> u >> v >> x;
			addNode(u, v, x, &root);
		}
		int level = 0, leafLevel = 0;
		if(check(level, &leafLevel, root)){
			cout << 1 << endl;
		} else {
			cout << 0 << endl;
		}
	}
}

