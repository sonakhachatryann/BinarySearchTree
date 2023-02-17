#include <iostream>
#include "BinarySearchTree.h"

int main() {

	BST* t = new BST();
	t->insert_node(10);
	t->insert_node(8);
	t->insert_node(16);
	t->insert_node(4);
	t->insert_node(11);
	t->insert_node(17);
	t->insert_node(18);
	t->inorder_iter();
	std::cout << (*(t->find(4))).m_value << std::endl;
	t->delete_node(4);
	t->preorder_iter();
	t->postorder_iter();
	t->levelorder();
	std::cout << t->height() << std::endl;

	return 0;
}