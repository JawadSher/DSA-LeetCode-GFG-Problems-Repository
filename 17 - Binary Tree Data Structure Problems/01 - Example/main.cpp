#include <iostream>
using namespace std;
#include <queue>
#include <stack>

class Node{
    public:
        int data;
        Node* left;
        Node* right;
        
    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildTree(Node* root){
    cout << "Enter the data : " << endl;
    int data;
    cin >> data;
    root = new Node(data);
    
    if(data == -1) return NULL;
    
    cout << "Enter data for inserting in the left of " << data << endl;
    root->left = buildTree(root->left);
    
    cout << "Enter data for inserting in the right of "<< data << endl;
    root->right = buildTree(root->right);
    
    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL); // Separator
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            // previous level completed
            cout << endl;
            if(!q.empty()){
                // Queue has still some child nodes
                q.push(NULL);
            }
        }else{
            cout << temp -> data << " ";
            if(temp -> left) q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);
        }
    }
}

void reverseLevelOrderTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    stack<Node*> st;

    // Push the root to the queue and a NULL to mark the end of the level
    q.push(root);
    q.push(NULL); // NULL acts as a level separator

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp == NULL) {
            // End of current level
            st.push(NULL); // Push NULL to the stack to mark level boundary

            if (!q.empty()) {
                q.push(NULL); // Add separator for the next level
            }
        } else {
            // Push the node data into the stack
            st.push(temp);

            // Enqueue right child first, then left child to maintain reverse level order
            if (temp->right) q.push(temp->right);
            if (temp->left) q.push(temp->left);
        }
    }

    // Print nodes from the stack in reverse level order with levels separated
    while (!st.empty()) {
        Node* node = st.top();
        st.pop();

        if (node == NULL) {
            cout << endl; // Newline after each level
        } else {
            cout << node->data << " ";
        }
    }
    cout << endl;
}

void inOrderTraversal(Node* root){
    if(root == NULL) return;
    
    inOrderTraversal(root->left);
    cout<< root -> data << " ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root){
    if(root == NULL) return;
    
    cout<< root -> data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root){
    if(root == NULL) return;
    
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root -> data << " ";
}

void buildFromLevelOrder(Node* &root){
    queue<Node *> q;
    cout << "Enter data for root " << endl;
    int data;
    cin >> data ;
    root = new Node(data);
    q.push(root);
    
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        
        cout << "Enter left Node for : " << temp -> data <<endl;
        int leftData;
        cin>> leftData;
        
        if(leftData != -1){
            temp -> left = new Node(leftData);
            q.push(temp->left);
        }
        
        cout << "Enter right Node for : " << root -> data <<endl;
        int rightData;
        cin>> rightData;
        
        if(rightData != -1){
            temp -> right = new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main() {
    Node* root = NULL;
    
    // Creating buildTree
    root = buildTree(root);
    
    // // data : 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    
    // // level order Traversal
    // cout << "Printing the level order traversal output " <<endl;
    // levelOrderTraversal(root);
    
    // Reverse Level Order Traversal
    cout << "Printing the reverse order traversal output " << endl;
    reverseLevelOrderTraversal(root);
    
    // cout << "Inorder Taversal is : ";
    // inOrderTraversal(root);
    
    // cout << endl;
    
    // cout << "Preorder Traversal is : ";
    // preOrderTraversal(root);
    
    // cout << endl;
    
    // cout << "Postorder Traversal is : ";
    // postOrderTraversal(root);
    
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    // Create from level order
    // buildFromLevelOrder(root);
    
    // // // level order
    // cout << "Printing the level order traversal output " <<endl;
    // levelOrderTraversal(root);

    return 0;
}
