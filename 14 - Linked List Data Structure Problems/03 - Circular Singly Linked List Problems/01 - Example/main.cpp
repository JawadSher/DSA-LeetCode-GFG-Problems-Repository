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
        if(this -> next == NULL){
            delete next;
            next = NULL;
        }

        cout << "Memory free for node with data : " << value << endl;
    }
};

void insertNode(Node* &tail, int target, int d){
    if(tail == NULL){
        Node* node = new Node(d);
        tail = node;
        node -> next = node;
        return;
    }

    Node* current = tail;
    do {
        if (current->data == target) {
            break;  // Target found
        }
        current = current->next;
    } while (current != tail);

    Node* node = new Node(d);
    node -> next = current -> next;
    current -> next = node;

    if(current == tail){
        tail = node;
    }
}

void print(Node* tail){
    Node* temp = tail;

    if(tail == NULL){
        cout << "List is empyt" <<endl;
        return;
    }

    do{
        cout << tail -> data <<" ";
        tail = tail -> next;
    }while(tail != temp);
    cout << endl;
}

void deleteNode(Node* &tail, int target){
    if(tail == NULL){
        cout << "Empty List" <<endl;
        return;
    }

    Node* previous = tail;
    Node* current = previous -> next;
    
    while(current -> data != target){
        previous = current;
        current = current -> next;
    }

    previous -> next = current -> next;
    if(current == previous){
        tail = previous;
    }else if(tail == current){
        tail = previous;
    }

    current -> next = NULL;
    delete current;
}

int main(){
    Node* tail = NULL;

    insertNode(tail, 1, 10);
    print(tail);

    insertNode(tail, 2, 20);
    print(tail);

    insertNode(tail, 3, 30);
    print(tail);

    deleteNode(tail, 10);
    print(tail);


    return 0;
}
