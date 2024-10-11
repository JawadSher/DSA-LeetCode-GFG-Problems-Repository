// If data over writing is not allowed
class Solution {
  private:
    void insertAtTail(Node* &tail, Node* curr){
        tail -> next = curr;
        tail = curr;
    }
  public:
    // Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node* head) {

      Node* zeroHead = new Node(-1);
      Node* zeroTail = zeroHead;
      
      Node* oneHead = new Node(-1);
      Node* oneTail = oneHead;
      
      Node* twoHead = new Node(-1);
      Node* twoTail = twoHead;
        
      Node* current = head;
      
      while(current != NULL){
          int value = current -> data;
          
          if(value == 0){
              insertAtTail(zeroTail, current);
          }else if(value == 1){
              insertAtTail(oneTail, current);
          }else if(value == 2){
              insertAtTail(twoTail, current);
          }
          
          current = current -> next;
      }
      
      if(oneHead -> next != NULL){
          zeroTail -> next = oneHead -> next;
      }else{
          zeroTail -> next = twoHead -> next;
      }
      
      oneTail -> next = twoHead -> next;
      twoTail -> next = NULL;
      
      head = zeroHead -> next;
      
      delete zeroHead;
      delete oneHead;
      delete twoHead;
      
      return head;
    }
};
