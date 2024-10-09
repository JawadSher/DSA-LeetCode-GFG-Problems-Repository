class Solution {
  private:
   Node* removeDuplicatesHelper(Node* head){
       if(!head) return head;
       
       Node* current = head;
       
       map<int, bool> seen;
       
       seen[current->data] = true;
       
       while(current->next != NULL){
           
           if(seen[current->next->data]){
               Node* temp = current -> next;
               current -> next = current -> next -> next;
               delete temp;
           }else{
               seen[current->next->data] = true;
                current = current -> next;
           }
           
       }
       
       return head;
   }
  public:
    Node *removeDuplicates(Node *head) {
        if(!head || !head -> next) return head;
        
       
        return removeDuplicatesHelper(head);

    }
};
