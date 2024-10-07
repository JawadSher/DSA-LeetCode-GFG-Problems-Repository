class Solution {
  public:
    bool isCircular(Node *head) {
        if(head == NULL) return true;
        
        Node* temp = head -> next;
        
        while(temp != NULL){
            if(temp == head) return true;
            
            temp = temp -> next;
        }
        return false;
    }
};
