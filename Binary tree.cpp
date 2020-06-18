#include "Binary tree.h"

void Menu(Tree* tree_root, Tree_el* tree)
{
	int count = 0;

	do
	{
		cout << "0.Exit" << endl << "1.Input" << endl << "2.Delete node" << endl << "3.Output" << endl << "Select an action: ";
		cin >> count;
		if (count == 1)
			addnode(tree_root);
		else if (count == 2)
		{
			deletenode(tree_root);
		}
		else if (count == 3)
			printtree(tree_root->root);
		else
			deletetree(tree_root->root);
	} while (count != 0);
}

void printtree(Tree_el* tree_node)
{
	if (tree_node != NULL)
	{
		cout << tree_node->number<<endl;
		printtree(tree_node->left);
		printtree(tree_node->right);
	}
}

void add_tree(Tree* tree, int x)
{
	if (tree->root == NULL)
	{
		Tree_el* r = new Tree_el;
		tree->root = r;
		tree->root->number = x;
	}
	else add(tree->root, x);
}

void add(Tree_el* tree, int x)
{
	if (tree->number > x)
	{
		if (tree->left == NULL)
		{
			Tree_el* e = new Tree_el;
			e->number = x;
			tree->left = e;
		}
		else add(tree->left, x);
	}
	else if (tree->number < x)
	{
		if (tree->right == NULL)
		{
			Tree_el* e = new Tree_el;
			e->number = x;
			tree->right = e;
		}
		else add(tree->right, x);
	}
}

void deletetree(Tree_el* tree_root)
{
	if (tree_root != NULL)
	{
		deletetree(tree_root->left);
		deletetree(tree_root->right);
		delete tree_root;
	}
}

void addnode(Tree* tree)
{
	int n, x;

	cout << "Enter the number of numbers: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ": ";
		cin >> x;
		add_tree(tree, x);
	}
}

bool find_tree(Tree* tree, int x)
{
	if (tree->root != NULL)
	{
		Tree_el* tree_par=tree->root;
		return find(tree, tree->root, tree_par, x);
	}
	else return false;
}

bool find(Tree* tree_root, Tree_el* tree, Tree_el* tree_par, int x)
{
	if (tree->number == x)
	{
		deleteNode(tree_root, tree, tree_par);
		return true;
	}
	if (tree->number > x)
	{
		if (tree->left == NULL) return false;
		else
		{
			tree_par = tree;
			return find(tree_root, tree->left, tree_par, x);
		}
	}
	else
	{
		if (tree->right == NULL) return false;
		else
		{
			tree_par = tree;
			return find(tree_root, tree->right, tree_par, x);
		}
	}
}

void deletenode(Tree* tree_root) //функция удаления узла
{
	int x;
	cout << "Enter the number you want to delete: ";
	cin >> x;
	bool choice = 0;
	choice = find_tree(tree_root, x); //есть ли у нас вообще это число

	if (choice==0) 
		cout << "This number is not";
}

void deleteNode(Tree* tree_root, Tree_el* tree, Tree_el* tree_par)
{
	Tree_el* tree_cur; //узел которым ходим

	//если мы удаляем корень, у него нет родителя
	if (tree_par != tree_root->root)
	{
		if (tree_par->left == tree)
		{

			if (tree->right != NULL)
			{
				tree_cur = tree->right;
				while (tree_cur->left != NULL)
				{
					tree_cur = tree_cur->left;
				}
				tree_cur->left = tree->left;
				tree_par->left = tree->right;
			}
			else if (tree->right == NULL)
			{
				tree_par->left = tree->left;
			}
		}
		else if (tree_par->right == tree)
		{
			if (tree->left != NULL)
			{
				tree_cur = tree->left;
				while (tree_cur->right != NULL)
				{
					tree_cur = tree_cur->right;
				}
				tree_cur->right = tree->right;
				tree_par->right = tree->left;
			}
			else if (tree->left == NULL)
			{
				tree_par->right = tree->right;
			}
		}
		delete tree;
	}
	else
	{
		if (tree->left != NULL)
		{
			if (tree->right != NULL)
			{
				tree_cur = tree->right;
				while (tree_cur->left != NULL)
				{
					tree_cur = tree_cur->left;
				}
				tree_cur->left = tree->left;
				//delete tree_root->root;
				tree_root->root = tree->right;
			}
			else
			{
				//delete tree_root->root;
				tree_root->root = tree->left;
			}
		}
		else if (tree->right != NULL)
		{
				//delete tree_root->root;
				tree_root->root = tree->right;
		}
		else cout << "TREE DELETED";
	}
}