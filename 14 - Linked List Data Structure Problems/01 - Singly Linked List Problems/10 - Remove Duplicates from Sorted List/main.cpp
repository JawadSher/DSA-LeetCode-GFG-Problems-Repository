class Solution {
private:
    void rDuplicates(ListNode* current){

        if(current == nullptr || current -> next == nullptr){
            return;
        }

        if(current->val == current -> next -> val){
            ListNode* nodeToDelete = current -> next;
            current -> next = current -> next -> next;
            delete nodeToDelete;
            rDuplicates(current);
        }else{
            rDuplicates(current->next);
        }
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) return head;
        rDuplicates(head);

        return head;
    }
};
