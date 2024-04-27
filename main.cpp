#include <iostream>
#include <queue>
using namespace std;

class Node{
public:
  int data;
  Node* left;
  Node* right;

public:
  Node(int d){
    this->data = d;
    this->right = NULL;
    this->left = NULL;
  }
};

void inOrder(Node* root){
  // base case
  if(root == NULL){
    return;
  }

  // L, N, R
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}

void levelOrderTraversal(Node* root){
  queue<Node*> q;
  q.push(root);
  q.push(NULL);

  while(!q.empty()){
    Node* temp = q.front();

    q.pop();
    if(temp == NULL){
      cout<<endl; // level kahatam
      if(!q.empty()){  // queue mein bhi kuch hai
        q.push(NULL);
      }
    }
    else{
      cout<<temp->data<<" ";
      if(temp->left){
        q.push(temp->left);
      }
      if(temp->right){
        q.push(temp->right);
      }
    }
  }
}

Node* InsertIntoBts(Node* &root, int d){
  if(root == NULL){
    root = new Node(d);
    return root;
  }
  if(d > root->data){
    root->right = InsertIntoBts(root->right, d);
  }
  else{
    root->left = InsertIntoBts(root->left, d);
  }
  return root;
}

void takeInput(Node* &root){
  int data;
  cin>>data;
  while(data != -1){
    root = InsertIntoBts(root, data);
    cin>>data;
  }
}

Node* getMin(Node* root){
  Node* temp = root;
  while(temp->left != NULL)
    temp = temp->left;

  return temp;
}

Node* getMax(Node* root){
  Node* temp = root;
  while(temp->right != NULL)
    temp = temp->right;

  return temp;
}

Node* deleteNode(Node* root, int val){
  // base case
  if(root == NULL){
    return root;
  }
  if(root->data == val){
    //0 child
    if(root->left == NULL && root->right == NULL){
      delete root;
      return NULL;
    }

    //1 child

    // left child present
    if(root->left != NULL && root->right == NULL){
      Node* temp = root->left;
      delete root;
      return temp;
    }

    // right child present
    if(root->left == NULL && root->right != NULL){
      Node* temp = root->right;
      delete root;
      return temp;
    }

    //2 child
    if(root->left != NULL && root->right != NULL){    // mtd 1 left max
      int maxi = getMax(root->left)->data;
      root->data = maxi;
      root->left = deleteNode(root->left, maxi);
      return root;
    }
  }
  // left maei jaa
  else if(root->data > val){
    root->left = deleteNode(root->left, val);
    return root;
  }
    // right mai jaa
  else{
    root->right = deleteNode(root->right, val);
    return root;
  }
}

int main() {
  Node* root = NULL;
  cout<<"Enter data to make tree"<<endl;
  takeInput(root);

  cout<<"Printing the tree"<<endl;
  levelOrderTraversal(root);

  cout<<endl<<"Printing the inorder traversal"<<endl;
  inOrder(root);
  cout<<endl<<"inorder print BST in sorted order"<<endl;

  cout<<"the minimum ele is "<<getMin(root)->data<<endl;
  cout<<"the maximum ele is "<<getMax(root)->data<<endl;


  // delition in BTS
  

  
}