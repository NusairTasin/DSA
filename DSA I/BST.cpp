/*
    Binary Search Tree :
        Traversal:
            *Inorder
            *Preorder
            *Postorder
        Insertion
        Deletion
*/

#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) :data(value), left(NULL), right(NULL) {}
};
Node* root = NULL;

void inOrder(Node* root) {  //Left->Root->Right
    if(root == NULL) return;
    inOrder(root->left); 
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(Node* root) { //Root->left->Right
    if(root == NULL) return;
    cout<<root->data<<" "; 
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root) { //Left->Right->Root
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}
// Insert Node
Node* insertion(Node* root, int value) {
    if(root == NULL) return new Node(value);
    if(value < root->data) root->left = insertion(root->left, value);
    else root->right = insertion(root->right, value);
    return root;
}

void insert(int value) {
    root = insertion(root, value);
}
// Delete Node
void deletion(Node* root) {
    if(!root) return;
    deletion(root->left);
    deletion(root->right);
    delete root;
}

void deleteNode(Node* root, int value) {
    if(root == NULL) return;
    if(root->data == value) {
        if(root->left == NULL && root->right == NULL) {
            delete root;
            root = nullptr;
        }
        else if(root->left == NULL) {
            Node* temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL) {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else {
            Node* temp = root->right;
            while(temp->left) {
                temp = temp->left;
            }
            root->data = temp->data;
            deleteNode(root->right, temp->data);
        }
    }
    else if(value > root->data) {
        deleteNode(root->right, value);
    }
    else deleteNode(root->left, value);
}

//Search Node
Node* searchRecursive(Node* root, int data) {
    if (root == NULL || root->data == data) return root;
    if (root->data > data) return searchRecursive(root->left, data);
    else return searchRecursive(root->right, data);
}
void search(int data) {
    Node* result = searchRecursive(root, data);
    if (result != NULL) cout << "Found!" << endl;
    else cout << "Not found!" << endl;

}

int main() {
    // root = new Node(50);
    // root->left = new Node(20);
    // root->right = new Node(60);
    // root->left->left = new Node(10);
    // root->left->right = new Node(25);
    // root->right->left = new Node(55);

    insert(50); insert(20); insert(60); insert(10); insert(25); insert(55);

    inOrder(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    postOrder(root);
    deleteNode(root, 20);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    search(50);
}