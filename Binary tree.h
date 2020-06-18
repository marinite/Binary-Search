#ifndef _Binary tree_H
#define _Binary tree_H
#include <iostream>
using namespace std;

struct Tree_el
{
	int number;            //���� ������
	Tree_el* left = NULL;  //����� �������
	Tree_el* right = NULL; //������ �������
};

struct Tree
{
	Tree_el* root = NULL;
};

void Menu(Tree* tree, Tree_el* tree_node);
void printtree(Tree_el* tree_node); //����� ������ ������ ���� (� ������ �������)
void add_tree(Tree* tree, int x); //�������� �����
void add(Tree_el* tree, int x); //�������� ����� � ������
void deletetree(Tree_el* tree_root); //�������� ���������
bool find_tree(Tree* tree, int x);
bool find(Tree* tree_root, Tree_el* tree, Tree_el* tree_par, int x);
void deletenode(Tree* tree_root);
void addnode(Tree* tree); //�������� ������
void deleteNode(Tree* tree_root, Tree_el* tree, Tree_el* tree_par);
#endif