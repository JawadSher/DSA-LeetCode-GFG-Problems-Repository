// This return only sorted output
class Solution {
  private:
    Node* merge(Node* left, Node* right){
        if(!left) return right;
        if(!right) return left;
        
        
        Node* result = nullptr;
        
        if(left -> data <= right -> data){
            result = left;
            result->next = merge(left->next, right);
        }else{
            result = right;
            result->next = merge(left, right->next);
        }
        
        return result;
    }
    Node* getMiddle(Node* head){
        if(!head || head -> next) return head;
        
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        
        return slow;
    }
    Node* mergeSort(Node* head){
        if(!head || !head -> next) return head;
        
        Node* middleNode = getMiddle(head);
        Node* middleNext = middleNode -> next;
        
        middleNode -> next = nullptr;
        
        Node* left = mergeSort(head);
        Node* right = mergeSort(middleNext);
        
        return merge(left, right);
    }
    Node* removeDuplicatesSorted(Node* head) {
        if (!head || !head->next) return head; 
        
        Node* current = head; 
        
        while (current -> next != nullptr) {

            if (current->data == current->next->data) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp; 
            } else {
                current = current->next;  
            }

        }
        
        return head; 
    }
  public:
    Node *removeDuplicates(Node *head) {
        if(!head || !head -> next) return head;
        
        head = mergeSort(head);
        
        head = removeDuplicatesSorted(head);
        
        
        return head;
    }
};
