#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <iostream>
#include <stack>
#include <queue>

template <typename T>
class BST {
private:
	struct TreeNode {
		TreeNode* m_left;
		TreeNode* m_right;
		T m_value;

		TreeNode(T);
		~TreeNode();
	};

public:
	BST();
	~BST();

	void insert_node(T);
	TreeNode* get_root() const;
	void delete_node(T);
	TreeNode* find(T);
	T get_value() const;
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

#include "BinarySearchTree.tpp"

#endif //BINARY_SEARCH_TREE_H