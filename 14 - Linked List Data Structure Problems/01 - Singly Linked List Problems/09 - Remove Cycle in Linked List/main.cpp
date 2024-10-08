#include <iostream>
using namespace std;

class ListNode {
    public:
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createCyclicLinkedList() {
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    node5->next = node3;

    return head; 
}


void removeCyclic(ListNode* head){
    if (head == NULL || head->next == NULL) {
        cout << "Empty or No Loop in the linked list" << endl;
        return;
    }

  ListNode* slow = head;
  ListNode* fast = head;

  while(fast != NULL && fast -> next != NULL){
    fast = fast -> next -> next;
    slow = slow -> next;

    if(slow == fast){
      ListNode* intersectionPoint = fast;
      slow = head;

      while(slow != intersectionPoint){
        slow = slow -> next;
        intersectionPoint = intersectionPoint -> next;
      }

      ListNode* temp = intersectionPoint;
      while(temp -> next != intersectionPoint){
        temp = temp -> next;
      }

      temp -> next = NULL;
      cout<< "Cycle removed successfully" <<endl;
      return;
    }
  }

  cout << "No cycle detected" <<endl;
}

void printList(ListNode* head, int limit = 10) {
    ListNode* temp = head;
    while (limit-- > 0 && temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main() {
    ListNode* cyclicList = createCyclicLinkedList();

    cout<< "Cyclic Linked list : ";
    printList(cyclicList);
    
    cout<<endl;
    removeCyclic(cyclicList);

    cout << "\nRemove Cyclic Linked list : ";
    printList(cyclicList);
}
