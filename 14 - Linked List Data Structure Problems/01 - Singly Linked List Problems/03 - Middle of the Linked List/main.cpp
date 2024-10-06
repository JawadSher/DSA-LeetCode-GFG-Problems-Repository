class Solution {
private:
    int getlength(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head -> next;
        }

        return len;
    }
public:
    ListNode* middleNode(ListNode* head) {
        int len = getlength(head);
        int ans = (len/2);

        while(ans != 0){
            head = head -> next;
            ans--;
        }

        return head;
    }
};
