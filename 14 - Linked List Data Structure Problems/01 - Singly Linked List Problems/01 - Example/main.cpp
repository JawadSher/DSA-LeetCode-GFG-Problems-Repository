#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int d){
            this -> data = d;
            this -> next = NULL; 
        }

        ~Node(){
            int value = this -> data;
            if(this -> next != NULL){
                delete next;
                this -> next = NULL;
            }

            cout << "Memory Free for node with data : "<< value << endl;
        }
};

void insertAtHead(Node* &head, int d){
    Node* temp = head;

    Node* node = new Node(d);
    node -> next = temp;
    head = node;
}

void insertAtTail(Node* &tail, int d){
    Node* temp = tail;

    Node* node = new Node(d);
    temp -> next = node;
    tail = node;
}

void insertAtanyPosition(Node* &tail, Node* &head, int position, int d){
    Node* temp = head;
    int count = 1;

    if(position == 1){
        insertAtHead(head, d);
        return;
    } 
    

    while(count < position-1){
        temp = temp -> next;
        count++;
    }

    if(temp -> next == NULL){
        insertAtTail(tail, d);
        return;
    }

    Node* node = new Node(d);
    node -> next = temp -> next;
    temp -> next = node;
}

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }cout << endl;
}

void insertAfter(Node* &tail, Node* &head, int target, int d){
    Node* temp = head;

    if(temp -> next == NULL && temp -> data != target){
        cout << "Element Not Exist" << endl;
    }

    while(temp->data != target){
        temp = temp -> next;
    }

    if(temp->next == NULL){
        insertAtTail(tail, d);
        return;
    }

    Node* node = new Node(d);
    node -> next = temp -> next;
    temp -> next = node;
}

void insertBefore(Node* &tail, Node* &head, int target, int d){
    Node* temp = head;

    if(temp -> data == target){
        insertAtHead(head, d);
        return;
    }

    while(temp -> next -> data != target){
        temp = temp -> next;
    }

    if(temp -> next == NULL && temp -> data == target){
        insertAtTail(tail, d);
        return;
    }

    Node* node = new Node(d);
    node -> next = temp -> next;
    temp -> next = node;
}

void deleteNodeAtPosition(Node* &tail, Node* &head, int position){
    
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        if(head == NULL){
            tail = NULL;
        }

        temp -> next = NULL;
        delete temp;
        return;
    }
    
    Node* current = head;
    Node* previous = NULL;

    int count = 1;
    while(count < position){
        previous = current;
        current = current -> next;
        count++;
    }

    if(current -> next == NULL){
        tail = previous;
    }

    previous -> next = current -> next;
    current -> next = NULL;
    delete current;
}

void deleteAllAfter(Node* &head, int position){

    if(head == NULL){
        return;
    }
    
    Node* temp = head;
    int count = 1;

    while(count < position && temp != NULL){
        count++;
        temp = temp -> next;
    }

    if(temp == NULL || temp -> next == NULL){
        return;
    }

    Node* nodeToDelete = temp -> next;
    temp -> next = NULL;

    while(nodeToDelete != NULL){
        Node* nextNode = nodeToDelete -> next;
        delete nodeToDelete;
        nodeToDelete = nextNode;
    }

}

void deleteAllNodes(Node* &head){

    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){
        prev = curr;
        curr = curr -> next;

        delete prev;
    }

    head = curr;

}

void deleteHeadNode(Node* &head){
    if(head == NULL){
        return;
    }

    Node* temp = head;

    head = head -> next;
    temp -> next = NULL;
    delete temp;
}

void deleteTailNode(Node* &head, Node* &tail){
    if(head == NULL){
        return;
    }

    if(head -> next == NULL){
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;
    while(temp->next->next != NULL){
        temp = temp -> next;
    }
    tail = temp;
    Node* tailNode = temp->next;
    temp->next = NULL;
    delete tailNode;
}

void deleteAllBefore(Node* &head, int position){

    if(head == NULL){
        return;
    }

    if(head->next == NULL){
        deleteHeadNode(head);
    }

    int count = 1;
    while(count < position){
        deleteHeadNode(head);
        count++;
    }
}
void totalNodes(Node* head){
    int count = 0;
    while(head != NULL){
        count++;
        head = head -> next;
    }

    cout << "Total Nodes - Length of list : " << count <<endl;
}

int main(){
    Node* sNode = new Node(10);
    
    Node* head = sNode;
    Node* tail = sNode;

    cout<< "Head : " << head -> data <<endl;
    totalNodes(head);

    insertAtHead(head, 5);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    
    insertAtTail(tail, 15);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    insertAtanyPosition(tail, head, 2, 25);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    insertAfter(tail, head, 10, 13);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    insertBefore(tail, head, 5, 9);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    deleteNodeAtPosition(tail, head, 1);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    // deleteAllAfter(head, 1);
    // print(head);
    // cout<< "Head : " << head -> data <<endl;
    // cout<< "Tail : " << tail -> data <<endl;
    // totalNodes(head);
    // cout<< "-------------------------"<<endl;

    // deleteAllNodes(head);
    // print(head);
    // cout<< "Head : " << head -> data <<endl;
    // cout<< "Tail : " << tail -> data <<endl;
    // totalNodes(head);
    // cout<< "-------------------------"<<endl;

    // deleteHeadNode(head);
    // print(head);
    // cout<< "Head : " << head -> data <<endl;
    // cout<< "Tail : " << tail -> data <<endl;
    // totalNodes(head);
    // cout<< "-------------------------"<<endl;

    // deleteTailNode(head, tail);
    // print(head);
    // cout<< "Head : " << head -> data <<endl;
    // cout<< "Tail : " << tail -> data <<endl;
    // totalNodes(head);
    // cout<< "-------------------------"<<endl;

    deleteAllBefore(head, 3);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    return 0;
}
