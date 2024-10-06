class Solution {
private:
    ListNode* getMiddle(ListNode* slow, ListNode* fast){
        if(fast == NULL || fast -> next == NULL){
            return slow;
        }

        return getMiddle(slow->next, fast->next->next);
    }
public:
    ListNode* middleNode(ListNode* head) {
       return getMiddle(head, head);
    }
};
