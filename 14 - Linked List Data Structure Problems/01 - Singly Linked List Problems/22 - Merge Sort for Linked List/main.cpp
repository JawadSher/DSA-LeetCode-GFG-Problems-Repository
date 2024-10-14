class Solution {
  private:
    Node* getMiddle(Node* head){
        if(head == NULL && head -> next == NULL) return head;
        
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        return slow;
    }
    
    Node* merge(Node* left, Node* right){
        if(left == NULL) return right;
        if(right == NULL) return left;
        
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        while(left != NULL && right != NULL){
            if(left -> data < right -> data){
                temp -> next = left;
                temp = left;
                left = left -> next;
            }else{
                temp -> next = right;
                temp = right;
                right = right -> next;
            }
        }
        
        if(left != NULL) temp -> next = left;
        if(right != NULL) temp -> next = right;
        
        return ans -> next;
    }
  public:
    Node* mergeSort(Node* head) {
        // base case
        if(head == NULL || head -> next == NULL){
            return head;
        }
        
        Node* middle = getMiddle(head);
        
        Node* right = middle -> next;
        middle -> next = NULL;
        
        Node* left = mergeSort(head);
        right = mergeSort(right);
        
        return merge(left, right);
    }
};
