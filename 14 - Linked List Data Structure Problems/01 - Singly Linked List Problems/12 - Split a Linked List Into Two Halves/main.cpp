class Solution {
public:
    pair<Node *, Node *> splitList(struct Node *head) {
        if (!head) return {nullptr, nullptr}; 
        if (head->next == head) return {head, head}; 

        Node* slow = head;
        Node* fast = head;

        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;      
            fast = fast->next->next; 
        }

        Node* head1 = head;
        Node* head2 = slow->next;
 
        slow->next = head1; 

        Node* last = head2;
        while (last->next != head1 && last->next != head2) {
            last = last->next;
        }
        last->next = head2; 

        return {head1, head2};
    }
};
