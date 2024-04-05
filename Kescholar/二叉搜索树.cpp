struct Node {
	int data;
	Node* left;
	Node* right;

	Node* newNode(int v) {
		Node* node = new Node;
		node->data = v;
		node->right = node->left = NULL;
		return node;
	}

	void insert(Node* &root, int x) {
		if (root == NULL) {
			root = newNode(x);
			return ;
		}
		if (root->data > x)
			insert(root->left, x);
		else
			insert(root->right, x);
	}

	Node* Create(vector<int> tree) {
		Node* root = NULL;
		for (auto i : tree) {
			insert(root, i);
		}
		return root;
	}
};