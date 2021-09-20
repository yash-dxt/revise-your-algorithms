#include<algorithm>
#include<iostream> 

using namespace std

class Node{
	int data; 
	Node* left; 
	Node* right; 
}

bool search(Node* root, int data){
	if(root==NULL) return false; 
	if(root->data == data) return true; 
	if(data > root->data) search(root->right, data); 
	if(data < root->data) search(root->left, data);
}
