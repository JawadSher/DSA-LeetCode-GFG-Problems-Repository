class Solution {
private:
    ListNode* reverse1(ListNode* head){
        // basecase
        if(head == NULL || head -> next == NULL){
            return head;
        }

        ListNode* newHead = reverse1(head -> next);
        head -> next -> next = head;
        head -> next = NULL;

        return newHead;
    }
public:
    ListNode* reverseList(ListNode* head) {
        return reverse1(head);
    }
};
