#include "BinarySearchTree.h"

#include <iostream>
#include <stack>
#include <queue>

BST::TreeNode::TreeNode(int value) 
	: m_value(value)
	, m_left(nullptr)
	, m_right(nullptr) {}

BST::TreeNode::~TreeNode() {
	delete m_left;
	delete m_right;
}

BST::BST() 
	: m_root(nullptr) {}

BST::~BST() {
	delete_nodes(m_root);
}

BST::TreeNode* BST::get_root() const {
	return m_root;
}

void BST::insert_node(int value) {
	if (m_root == nullptr) {
		m_root = new TreeNode(value);
		return;
	}
	TreeNode* tmp = m_root;
	while (tmp != nullptr) {
		if (value < tmp->m_value) {
			if (tmp->m_left == nullptr) {
				tmp->m_left = new TreeNode(value);
				return;
			}
			tmp = tmp->m_left;
		}
		else if (value > tmp->m_value) {
			if (tmp->m_right == nullptr) {
				tmp->m_right = new TreeNode(value);
				return;
			}
			tmp = tmp->m_right;
		}
		else {
			std::cout << "The value already exists!" << std::endl;
			return;
		}
	}
}

void BST::delete_node(int value) {
	TreeNode* parent = nullptr;
	TreeNode* current = m_root;
	while (current != nullptr && current->m_value != value) {
		parent = current;
		if (current->m_value < value) {
			current = current->m_right;
		}
		else {
			current = current->m_left;
		}
	}
	if (current == nullptr) {
		return;
	}
	if (current->m_left == nullptr && current->m_right == nullptr) {
		if (parent == nullptr) {
			m_root = nullptr;
		}
		else if (parent->m_left == current) {
			parent->m_left = nullptr;
		}
		else {
			parent->m_right = nullptr;
		}
		delete current;
	}
	else if (current->m_left == nullptr || current->m_right == nullptr) {
		TreeNode* child = nullptr;
		if (current->m_left != nullptr) {
			child = current->m_left;
		}
		else {
			child = current->m_right;
		}
		if (parent == nullptr) {
			m_root = child;
		}
		else if (current == parent->m_left) {
			parent->m_left = child;
		}
		else {
			parent->m_right = child;
		}
		delete current;
	}
	else {
		TreeNode* inorder_successor = current->m_right;
		parent = current;
		while (inorder_successor->m_left != nullptr) {
			parent = inorder_successor;
			inorder_successor = inorder_successor->m_left;
		}
		current->m_value = inorder_successor->m_value;
		if (parent->m_left == inorder_successor) {
			parent->m_left = inorder_successor->m_right;
		}
		else {
			parent->m_right = inorder_successor->m_left;
		}
		delete inorder_successor;
	}

}

BST::TreeNode* BST::find(int value) {
	TreeNode* tmp = m_root;
	while (tmp != nullptr) {
		if (tmp->m_value == value) {
			return tmp;
		}
		else if (tmp->m_value > value) {
			tmp = tmp->m_left;
		}
		else if (tmp->m_value < value) {
			tmp = tmp->m_right;
		}
	}
	return nullptr;
}

int BST::get_value() const {
	return m_root->m_value;
}

void BST::inorder_iter() {
	std::stack<TreeNode*> m_stack;
 	TreeNode* current = m_root;
	while (current != nullptr || !m_stack.empty()) {
		if (current != nullptr) {
			m_stack.push(current);
			current = current->m_left;
		}
		else {
			current = m_stack.top();
			m_stack.pop();
			std::cout << current->m_value << " ";
			current = current->m_right;
		}
	}
	std::cout << std::endl;
}

void BST::postorder_iter() {
	std::stack<TreeNode*> m_stack;
	TreeNode* current = m_root;
	TreeNode* last = nullptr;
	while (current != nullptr || !m_stack.empty()) {
		if (current != nullptr) {
			m_stack.push(current);
			current = current->m_left;
		}
		else {
			TreeNode* top = m_stack.top();
			if (top->m_right != nullptr && top->m_right != last) {
				current = top->m_right;
			}
			else {
				std::cout << top->m_value << " ";
				last = top;
				m_stack.pop();
			}
		}
	}
	std::cout << std::endl;
}

void BST::preorder_iter() {
	if (m_root == nullptr) {
		return;
	}
	TreeNode* current = m_root;
	TreeNode* last = nullptr;
	TreeNode* top = nullptr;
	std::stack<TreeNode*> m_stack;
	while (current != nullptr || !m_stack.empty()) {
		if (current != nullptr) {
			std::cout << current->m_value << " ";
			m_stack.push(current);
			current = current->m_left;
		}
		else {
			top = m_stack.top();
			if (top->m_right != nullptr && top->m_right != last) {
				current = top->m_right;
			}
			else {
				last = m_stack.top();
				m_stack.pop();
			}
		}
	}
	std::cout << std::endl;
}

void BST::levelorder() {
	if (m_root == nullptr) {
		return;
	}
	std::queue<TreeNode*> m_queue;
	m_queue.push(m_root);
	TreeNode* front = m_queue.front();
	while (front != nullptr || !m_queue.empty()) {
		if (front != nullptr) {
			std::cout << front->m_value << " ";
			if (front->m_left != nullptr) {
				m_queue.push(front->m_left);
			}
			if (front->m_right != nullptr) {
				m_queue.push(front->m_right);
			}
			m_queue.pop();
		}
		if (!m_queue.empty()) {
			front = m_queue.front();
		}
		else {
			front = nullptr;
		}
	}
	std::cout << std::endl;
}

int BST::height() {
	if (m_root == nullptr) {
		return -1;
	}
	std::queue<TreeNode*> m_queue;
	m_queue.push(m_root);
	int height{};
	int node_count{};
	TreeNode* node = nullptr;
	while (true) {
		node_count = m_queue.size();
		if (node_count == 0) {
			return height - 1;
		}
		++height;
		while (node_count != 0) {
			node = m_queue.front();
			m_queue.pop();
			if (node->m_left != nullptr) {
				m_queue.push(node->m_left);
			}
			if (node->m_right != nullptr) {
				m_queue.push(node->m_right);
			}
			--node_count;
		}
	}
}

void BST::delete_nodes(TreeNode* node) {
	if (node != nullptr) {
		delete_nodes(node->m_left);
		delete_nodes(node->m_right);
		delete node;
	}
}