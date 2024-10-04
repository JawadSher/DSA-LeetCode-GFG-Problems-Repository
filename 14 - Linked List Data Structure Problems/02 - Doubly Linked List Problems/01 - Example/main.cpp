#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }

        cout << "Memory Free for node with data : " << value << endl;
    }
};

void insertAtHead(Node* &head, Node* &tail, int d)
{
    Node *temp = head;

    if (temp == NULL)
    {
        Node *node = new Node(d);
        head = node;
        tail = node;

        return;
    }
    else
    {

        Node *node = new Node(d);
        node->next = temp;
        temp->prev = node;

        head = node;
    }
}

void insertAtTail(Node* &head, Node *&tail, int d)
{
    Node *temp = tail;

    if(temp == NULL){
        Node* node = new Node(d);
        head = node;
        tail = node;
    }

    Node *node = new Node(d);
    temp->next = node;
    node->prev = temp;

    tail = node;
}

void insertAtanyPosition(Node *&tail, Node *&head, int position, int d)
{
    Node *temp = head;
    int count = 1;

    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    Node *node = new Node(d);
    node -> next = temp -> next;
    node -> next -> prev = node;
    temp -> next = node;
    node -> prev = temp;
}

void print(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAfter(Node *&tail, Node *&head, int target, int d)
{
    Node *temp = head;

    if (temp == NULL)
    {
        Node* node = new Node(d);
        head = node;
        tail = node;
        return;
    }

    while (temp->data != target)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        insertAtTail(head, tail, d);
        return;
    }

    Node *node = new Node(d);
    node -> next = temp -> next;
    node -> next -> prev = node;
    temp -> next = node;
    node -> prev = temp;
}

void insertBefore(Node *&tail, Node *&head, int target, int d)
{
    Node *temp = head;

    if (temp->data == target)
    {
        insertAtHead(head, tail, d);
        return;
    }

    while (temp->next->data != target)
    {
        temp = temp->next;
    }

    if (temp->next == NULL && temp->data == target)
    {
        insertAtTail(head, tail, d);
        return;
    }

    Node *node = new Node(d);
    node -> next = temp -> next;
    node -> next -> prev = node;
    temp -> next = node;
    node -> prev = temp;
}

void deleteHeadNode(Node *&head)
{
    if (head == NULL)
    {
        return;
    }

    Node *temp = head;

    head = head->next;
    temp -> next = NULL;
    delete temp;
}

void deleteTailNode(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }

    Node* temp = tail;
    tail = tail -> prev;
    tail -> next = NULL;
    delete temp;
}

void deleteNodeAtPosition(Node *&tail, Node *&head, int position)
{   

    if(position == 1){
        deleteHeadNode(head);
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
        deleteTailNode(head, tail);
        return;
    }

    previous -> next = current -> next;
    current -> next -> prev = previous;

    current -> prev = NULL;
    current -> next = NULL;
    delete current;
}

void deleteAllAfter(Node *&head, Node* &tail, int position)
{

    if (head == NULL)
    {
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < position && temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
    {
        return;
    }

    Node *nodeToDelete = temp->next;
    temp->next = NULL;

    while (nodeToDelete != NULL)
    {
        Node *nextNode = nodeToDelete->next;
        delete nodeToDelete;
        nodeToDelete = nextNode;
    }

    tail = temp;
}

void deleteAllNodes(Node *&head)
{

    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        prev = curr;
        curr = curr->next;

        delete prev;
    }

    head = curr;
}

void deleteAllBefore(Node *&head, int position)
{

    if (head == NULL)
    {
        return;
    }

    if (head->next == NULL)
    {
        deleteHeadNode(head);
    }

    int count = 1;
    while (count < position)
    {
        deleteHeadNode(head);
        count++;
    }
}

void totalNodes(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }

    cout << "Total Nodes - Length of list : " << count << endl;
}

void searchNode(Node *head, int target)
{

    if (head->next == NULL)
    {
        return;
    }

    while (head->data != target)
    {
        head = head->next;
    }

    if (head->data == target)
    {
        cout << "Node Found : " << head->data << endl;
    }
    else
    {
        cout << "Node Not Found!" << endl;
    }
}

int main()
{
    Node *dNode = new Node(10);

    Node *head = dNode;
    Node *tail = dNode;

    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    totalNodes(head);
    cout << "--------------------------" << endl;

    insertAtHead(head, tail, 5);
    print(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    totalNodes(head);
    cout << "-------------------------" << endl;

    insertAtTail(head, tail, 15);
    print(head);
    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;
    totalNodes(head);
    cout << "-------------------------" << endl;

    insertAtanyPosition(tail, head, 3, 25);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    insertAfter(tail, head, 25, 13);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

    insertBefore(tail, head, 15, 9);
    print(head);
    cout<< "Head : " << head -> data <<endl;
    cout<< "Tail : " << tail -> data <<endl;
    totalNodes(head);
    cout<< "-------------------------"<<endl;

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

    // deleteNodeAtPosition(tail, head, 3);
    // print(head);
    // cout<< "Head : " << head -> data <<endl;
    // cout<< "Tail : " << tail -> data <<endl;
    // totalNodes(head);
    // cout<< "-------------------------"<<endl;

    // deleteAllAfter(head, tail, 2);
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


    // searchNode(head, 13);
    // cout<<"---------------" <<endl;

    // deleteAllBefore(head, 3);
    // print(head);
    // cout<< "Head : " << head -> data <<endl;
    // cout<< "Tail : " << tail -> data <<endl;
    // totalNodes(head);
    // cout<< "-------------------------"<<endl;

    return 0;
}
