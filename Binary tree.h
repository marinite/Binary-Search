#ifndef _Binary tree_H
#define _Binary tree_H
#include <iostream>
using namespace std;

struct Tree_el
{
	int number;            //поле данных
	Tree_el* left = NULL;  //левый потомок
	Tree_el* right = NULL; //правый потомок
};

struct Tree
{
	Tree_el* root = NULL;
};

void Menu(Tree* tree, Tree_el* tree_node);
void printtree(Tree_el* tree_node); //обход дерева сверху вниз (в прямом порядке)
void add_tree(Tree* tree, int x); //создание корня
void add(Tree_el* tree, int x); //создание узлов в дереве
void deletetree(Tree_el* tree_root); //удаление поддерева
bool find_tree(Tree* tree, int x);
bool find(Tree* tree_root, Tree_el* tree, Tree_el* tree_par, int x);
void deletenode(Tree* tree_root);
void addnode(Tree* tree); //создание дерева
void deleteNode(Tree* tree_root, Tree_el* tree, Tree_el* tree_par);
#endif