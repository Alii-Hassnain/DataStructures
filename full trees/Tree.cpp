#include <iostream>
using namespace std;


struct Node{
    int data;
    Node *left;
    Node *right;
};
Node *createNode(int data){
    Node *newnode = new Node();
    newnode->data = data;
    newnode->left = newnode->right = nullptr;
    return newnode;
}

int main(){
    Node* root = new Node;
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root ->right->right = createNode(5);
    root ->right->left = createNode(6);
    root ->right->right = createNode(7);

    root->left->right->left = createNode(9);
    root ->right->right->right = createNode(15);

}