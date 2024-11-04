#include <iostream>
#include <queue>
using namespace std;

class Node{
  public:
    int data;
    Node* right;
    Node* left;

    Node(int data){
      this -> data = data;
      this -> left = NULL;
      this -> right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data){
  // base case
  if(root == NULL){
    root = new Node(data);
    return root;
  }

  if(data > root -> data){
    // right part insertion
    root -> right = insertIntoBST(root -> right, data);
  }else{
    // left part insertion
    root -> left = insertIntoBST(root -> left, data);
  }

  return root;
}

void takeInput(Node* &root){
  int data;
  cin >> data;

  while (data != -1){
    root = insertIntoBST(root, data);
    cin >> data;
  }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << temp -> data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }
            if(temp -> right){
                q.push(temp -> right);
            }
        }
    }
}

void inOrderTraversal(Node* root){
    if(root == NULL) return;
    
    inOrderTraversal(root -> left);
    cout << root -> data << " ";
    inOrderTraversal(root -> right);
}

void preOrderTraversal(Node* root){
    if(root == NULL) return;
    
    cout << root -> data << " ";
    preOrderTraversal(root -> left);
    preOrderTraversal(root -> right);
}

void postOrderTraversal(Node* root){
    if(root == NULL) return;
    
    postOrderTraversal(root -> left);
    postOrderTraversal(root -> right);
    cout << root -> data << " ";
}

void SearchBST(Node* root, int value){
    if(root == NULL) {
        cout << "Value not Present" << endl;
        return;
    }
    
    if(root -> data == value) {
        cout << "Value is Present" << endl;
        return;
    }
    
    if(root -> data < value) return SearchBST(root -> right, value);
    else return SearchBST(root -> left, value);
}

Node* minValue(Node* root){
    if(root == NULL) {
        cout << "Tree is Empty" << endl;
        return NULL;
    }
    while(root -> left != NULL){
        root = root -> left;
    }
    
    cout << "Minimum Value is : " << root -> data << endl;
    return root;
}

Node* maxValue(Node* root){
    if(root == NULL){
        cout << "Tree is Empty" << endl;
        return NULL;
    }
    
    while(root -> right != NULL){
        root = root -> right;
    }
    
    cout << "Maximum value is : "<< root -> data << endl;
    return root;
}

Node* inOrderPredecessor(Node* root, Node* target){
    Node* predecessor = NULL;
    
    while(root != NULL){
        if(target -> data > root -> data){
            predecessor = root;
            root = root -> right;
        }else{
            root = root -> left;
        }   
    }
    
    return predecessor;
}

Node* inOrderSuccessor(Node* root, Node* target){
   if(target->right != NULL) {
        Node* current = target->right;
        while(current->left != NULL) {
            current = current->left;
        }
        return current;
    } else {
        Node* successor = NULL;
        Node* ancestor = root;

        while(ancestor != target) {
            if(target->data < ancestor->data) {
                successor = ancestor;
                ancestor = ancestor->left;
            } else {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

Node* deleteFromBST(Node* root, int value) {
    // Base case: If the root is NULL, return NULL
    if (root == NULL) return root;
    
    // If the node to be deleted is found
    if (root->data == value) {
        // Case 1: Node with 0 children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        
        // Case 2: Node with 1 child
        if (root->left != NULL && root->right == NULL) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        if (root->left == NULL && root->right != NULL) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        // Case 3: Node with 2 children
        if (root->left != NULL && root->right != NULL) {
            // Find the minimum value in the right subtree
            int mini = minValue(root->right)->data;
            // Replace root's data with the minimum value
            root->data = mini;
            // Recursively delete the minimum node in the right subtree
            root->right = deleteFromBST(root->right, mini);
        }
    } 
    // If the value is less than root's data, go to the left subtree
    else if (root->data > value) {
        root->left = deleteFromBST(root->left, value);
    } 
    // If the value is greater than root's data, go to the right subtree
    else {
        root->right = deleteFromBST(root->right, value);
    }
    
    return root;
}


int main() {
  Node* root = NULL;
  
  cout << endl << "Enter data to create BST" <<endl;
  takeInput(root);
  
  cout << endl << "Printing the BST" << endl;
  levelOrderTraversal(root);
  
  cout << endl << "Printing In-Order Traversal" << endl;
  inOrderTraversal(root);
  
  cout << endl << "Printing Pre-Order Traversal" << endl;
  preOrderTraversal(root);
  
  cout << endl << "Printing Post-Order Traversal" << endl;
  postOrderTraversal(root);
 
  cout << endl << "Searching in BST" << endl;
  SearchBST(root, 2);
  SearchBST(root, 50);
  
  cout << endl << "Searching minimum value" << endl;
  minValue(root);
  
  cout << endl << "Searching maximum value" << endl;
  maxValue(root);
  
  cout << endl << "Searching the Predecessor" << endl;
    int targetValue = 5;
    Node* targetNode = root;
    
    // Find the target node in the BST
    while (targetNode != NULL && targetNode->data != targetValue) {
        if (targetValue < targetNode->data) {
            targetNode = targetNode->left;
        } else {
            targetNode = targetNode->right;
        }
    }
  
    if (targetNode != NULL) {
        Node* predecessor = inOrderPredecessor(root, targetNode);
        if (predecessor != NULL) {
            cout << "Predecessor of " << targetValue << " is : " << predecessor->data << endl;
        } else {
            cout << "No predecessor found for " << targetValue << endl;
        }
    } else {
        cout << "Target node not found in the tree." << endl;
    }
    
    cout << endl << "Searching the Successor" << endl;
    int value = 5;
    Node* target = root;

    // Find the target node in the BST
    while(target != NULL && target->data != value) {
        if(value < target->data) {
            target = target->left;
        } else {
            target = target->right;
        }
    }

    if(target != NULL) {
        Node* successor = inOrderSuccessor(root, target);
        if(successor != NULL) {
            cout << "Successor of " << value << " is : " << successor->data << endl;
        } else {
            cout << "No Successor found for " << value << endl;
        }
    } else {
        cout << "Target node not found in the tree." << endl;
    }
    
    root = deleteFromBST(root, 90);
    
    cout << endl << "Printing the BST" << endl;
    levelOrderTraversal(root);
    
  return 0;
}
