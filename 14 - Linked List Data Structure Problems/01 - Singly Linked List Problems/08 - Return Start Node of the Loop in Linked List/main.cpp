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

ListNode* startNode(ListNode* head){
  if(head == NULL || head -> next == NULL){
    cout<< "List List is Empty" <<endl;
    return NULL;
  }

  ListNode* slow = head;
  ListNode* fast = head;

  while(fast != NULL && fast -> next != NULL){
    slow = slow -> next;
    fast = fast -> next -> next;

    if(slow == fast){
      slow = head;

      while(slow != fast){
        slow = slow -> next;
        fast = fast -> next;
      }

      return slow;
    }
  }

  return NULL;
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

    printList(cyclicList);

    ListNode* sNode = startNode(cyclicList);

   if(sNode != NULL){
     cout << "\nStart Node of the loop is " << sNode -> val <<endl;  
   }else{
    cout << "No cycle dected" << endl;
   }

}
