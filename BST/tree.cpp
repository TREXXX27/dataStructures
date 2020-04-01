// tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};


void insertNode(node** root, int val);
bool searchTree(node** root, int val);
int minEl(node* root);
int maxEl(node* root);
int height(node* root);

//BFS
void levelOrder(node* root);
//DFS
void preOrder(node* root);
void inOrder(node* root);
void postOrder(node* root);



int main()
{
    node* root;
    root = nullptr;
    insertNode(&root, 25);
    insertNode(&root, 14);
    insertNode(&root, 32);
    insertNode(&root, 1);
    cout << searchTree(&root, 32) << "\n";
    cout << searchTree(&root, 1) << "\n";
    cout << "min " << minEl(root) << "\n";
    cout << "max " << maxEl(root) << "\n";
    cout << "h is " << height(root) << "\n";

    cout << "BFS: \n";
    levelOrder(root);
    cout << "\n";

    cout << "pre: \n";
    preOrder(root);
    cout << "\n";

    cout << "in: \n";
    inOrder(root);
    cout << "\n";

    cout << "post: \n";
    postOrder(root);
    cout << "\n";
}






void insertNode(node** root, int val)
{
    node* ref = *root;

    if (ref == nullptr)
    {
        node* tempNode = new node;
        tempNode->data = val;
        tempNode->left = nullptr;
        tempNode->right = nullptr;

        *root = tempNode;
    }
    else
    {
        if (val <= ref->data)
        {
            insertNode(&(*root)->left, val);
        }
        else
        {
            insertNode(&(*root)->right, val);
        }
    }
}

bool searchTree(node** root, int val)
{
    node* ref = *root;
    if (ref == nullptr)
    {
        return false;
    }
    else
    {
        if (ref->data == val)
        {
            return true;
        }
        else
        {
            if (val < ref->data)
            {
                return searchTree(&(ref->left), val);
            }
            else
            {
                return searchTree(&(ref->right), val);
            }
        }
    }
}

int minEl(node* root)
{
    if (root == nullptr)
        return INT_MIN;

    if (root->left == nullptr)
        return root->data;
    else
        return minEl(root->left);
}

int maxEl(node* root)
{
    if (root == nullptr)
        return INT_MAX;

    if (root->right == nullptr)
        return root->data;
    else
        return maxEl(root->right);
}

int height(node* root)
{
    if (root == nullptr)
        return -1;

    else
    {
        return 1 + max(height(root->left), height(root->right));
    }
}


//BFS
void levelOrder(node* root)
{
    queue<node*> Q;

    Q.push(root);

    while (!Q.empty())
    {
        auto curr = Q.front();
        if (curr != nullptr)
        {
            cout << curr->data<<" ";
            Q.push(curr->left);
            Q.push(curr->right);
        }
        Q.pop();
    }
}

//DFS
void preOrder(node* root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}


void inOrder(node* root)
{
    if (root == nullptr)
        return;

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}


void postOrder(node* root)
{
    if (root == nullptr)
        return;

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}