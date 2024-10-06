class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head == NULL || head -> next == NULL) return head;

        ListNode* previous = NULL;
        ListNode* current = head;

        while(current != NULL){
            ListNode* forward = current -> next;
            current -> next = previous;

            previous = current;
            current = forward;
        }

        return previous;
    }
};
