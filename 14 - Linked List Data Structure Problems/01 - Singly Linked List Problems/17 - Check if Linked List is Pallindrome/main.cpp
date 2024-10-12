class Solution {
  private:
    Node* getMid(Node* head){
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* reverse(Node* head){
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
  public:
    bool isPalindrome(Node *head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        
        // Step 1: Get the middle of the linked list
        Node* middle = getMid(head);
        
        // Step 2: Reverse the second half of the list starting from the middle
        Node* secondHalf = reverse(middle);
        
        // Step 3: Compare the first and second halves
        Node* firstHalf = head;
        Node* secondHalfCopy = secondHalf;

        while (secondHalf != NULL) {
            if (firstHalf->data != secondHalf->data) {
                // Step 4: Restore the list before returning false
                reverse(secondHalfCopy); 
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }

        // Step 5: Restore the list before returning true
        reverse(secondHalfCopy);

        return true;
    }
};
