class Solution {
  private:
    Node* mergeTwoLists(Node* a, Node* b){
        if(a == NULL) return b;
        if(b == NULL) return a;
        
        Node* result;
        
        if(a -> data < b -> data){
            result = a;
            result -> bottom = mergeTwoLists(a->bottom, b);
        }else{
            result = b;
            result -> bottom = mergeTwoLists(a, b->bottom);
        }
        
        return result;
    }
  public:
    // Function which returns the  root of the flattened linked list.
    Node *flatten(Node *root) {
        if(root == NULL || root -> next == NULL) return root;
        
        return mergeTwoLists(root, flatten(root->next));
        
    }
};
