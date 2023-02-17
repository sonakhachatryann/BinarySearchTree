#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

class BST {
private:
	struct TreeNode {
		TreeNode* m_left;
		TreeNode* m_right;
		int m_value;

		TreeNode(int);
		~TreeNode();
	};

public:
	BST();
	~BST();

	void insert_node(int);
	TreeNode* get_root() const;
	void delete_node(int);
	TreeNode* find(int);
	int get_value() const;
	void inorder_iter();
	void postorder_iter();
	void preorder_iter();
	void levelorder();
	int height();

private:
	void delete_nodes(TreeNode*);

private:
	TreeNode* m_root;
};

#endif //BINARY_SEARCH_TREE_H