#include"BinaryTree.h"
#include<iostream>
#include<cstdlib>
#include<time.h>

unsigned int counter = -1;
extern TreeNode* prev;
extern TreeNode* currNode;
extern unsigned int keys;

TreeNode* newBranch()
{
    TreeNode* newbranch = new TreeNode;
    newbranch->key = keys;
    keys++;
    newbranch->leftEl = NULL;
    newbranch->rightEl = NULL;
    newbranch->passportNum = rand() % 10000000;

    return (newbranch);
}

void preorderPrint(struct TreeNode* Root)
{
    if (Root == NULL) return;

    preorderPrint(Root->leftEl);
    std::cout << Root->key << ": " << Root->passportNum << std::endl;
    preorderPrint(Root->rightEl);
}

TreeNode* insertLeft(struct TreeNode* Node)
{
    prev = Node;
    Node->leftEl = newBranch();
    currNode = Node->leftEl;
    return Node->leftEl;
}

TreeNode* insertRight(struct TreeNode* Node) 
{
    prev = Node;
    Node->rightEl = newBranch();
    currNode = Node->rightEl;
    return Node->rightEl;
}

TreeNode* deleteANode(TreeNode* root, unsigned int searchedKey)
{
    TreeNode* deletable, *deletablePrev, *replaceable, *replaceablePrev;
    deletable = root;
    deletablePrev = NULL;

    while (deletable != NULL && deletable->key != searchedKey)
    {
        deletablePrev = deletable;
        if (deletable->key > searchedKey)
            deletable = deletable->leftEl;
        else
            deletable = deletable->rightEl;
    }
    if (deletable == NULL)
    {
        std::cout << "Элемент с таким ключом не существует";
        return root;
    }

    if (deletable->rightEl == NULL)
        replaceable = deletable->leftEl;
    else
        if (deletable->leftEl == NULL) replaceable = deletable->rightEl;
        else
        {
            replaceablePrev = deletable;
            replaceable = deletable->leftEl;
            while (replaceable->rightEl != NULL) 
            {
                replaceablePrev = replaceable; 
                replaceable= replaceable->rightEl;
            }
            if (replaceablePrev == deletable) 
                replaceable->rightEl = deletable->rightEl;
            else {
                replaceable->rightEl = deletable->rightEl; 
                replaceablePrev->rightEl = replaceable->leftEl; 
                replaceable->leftEl = replaceablePrev; 
            }
        }
    if (deletable == root) root = replaceable; 
    else
    if (deletable->key < deletablePrev->key) 
        deletablePrev->leftEl = replaceable; 
    else deletablePrev->rightEl = replaceable; 
    std::cout<<"Элемент под номером "<<deletable->key<<" удален"<<std::endl;

    delete deletable; 
    return root;
}

TreeNode* findANode(TreeNode* root,unsigned int searchedKey)
{
    TreeNode* finder, * finderPrev;
    finder = root;
    finderPrev = NULL;

    while (finder != NULL && finder->key != searchedKey)
    {
        finderPrev = finder;
        if (finder->key > searchedKey)
            finder = finder->leftEl;
        else
            finder = finder->rightEl;
    }
    if (finder == NULL)
    {
        std::cout << "Элемент с таким ключом не существует";
        return root;
    }
    std::cout << "Найден элемент с ключом " << finder->key << ": " << finder->passportNum<<std::endl;
    return root;
}

unsigned int rightSub(TreeNode* Root)
{
    if (Root == NULL)
    {
        return counter;
        
    }
    rightSub(Root->rightEl);
    counter++;

}

void deleteAll(TreeNode* root)
{
    if (root != NULL)
    {
        deleteAll(root->rightEl);
        deleteAll(root->leftEl);
        free(root);
    }
}
