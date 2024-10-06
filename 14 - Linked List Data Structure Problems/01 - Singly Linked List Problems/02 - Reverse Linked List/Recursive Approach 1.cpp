class Solution {
private:
    void reverse(ListNode* &head, ListNode* current, ListNode* previous ){
        
        // base case
        if(current == NULL){
            head = previous;
            return;
        }

        ListNode* forward = current -> next;
        reverse(head, forward, current);
        current -> next = previous;
    }
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* current = head;
        ListNode* previous = NULL;
        reverse(head, current, previous);
        return head;
    }
};
