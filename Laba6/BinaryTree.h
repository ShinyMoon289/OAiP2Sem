#pragma once
#include<string>

struct TreeNode
{
	unsigned int key;
	TreeNode* leftEl;
	TreeNode* rightEl;
	unsigned int passportNum;
};

TreeNode* newBranch();
TreeNode* deleteANode(TreeNode* root, unsigned int searchedKey);
TreeNode* findANode(TreeNode* root,unsigned int searchedKey);
TreeNode* insertLeft(struct TreeNode*);
TreeNode* insertRight(struct TreeNode*);
void preorderPrint(struct TreeNode* root);
void deleteAll(TreeNode*);
unsigned int rightSub(TreeNode* root);

extern TreeNode* prev;
extern TreeNode* currNode;
extern unsigned int keys;

