class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL && count < k){
            temp = temp -> next;
            count++;
        }

        if(count < k){
            return head;
        }

        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        count = 0;

        while(curr != NULL && count < k){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(next != NULL){
            head -> next = reverseKGroup(next, k);
        }

        return prev;
    }
};
