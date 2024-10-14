#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        
        Node(int v){
            this -> data = v;
            this -> next = NULL;
        }
};

class Stack{
    public:
        Node* head;

        
        Stack(){
            head = NULL;

        }
        
        void push(int d){
            Node* newNode = new Node(d);
            newNode -> next = head;
            head = newNode;
        }
        
        void pushRange(int *arr, int size){
            
            for(int i = 0; i < size; i++){
                Node* newNode = new Node(arr[i]);
                newNode -> next = head;
                head = newNode;
            }
        }
        
        int pop(){
            if(isEmpty()){
                cout << "Stack is Empty" <<endl;
                return -1;
            }
            int value = head -> data;
            Node* temp = head;
            head = head -> next;
            delete temp;
            return value;
        }
        
        int peek(){
            if(isEmpty()){
                cout << "Stack is Empty" <<endl;
                return -1;
            }
            return head -> data;
        }
        
        bool isEmpty(){
            return head == NULL; 
        }
        
        void allElements(){
            Node* temp = head;
            while(temp != NULL){
                cout << temp -> data << ' ';
                temp = temp -> next;
            }
        }
};

int main(){
    Stack st;
    
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    
    int arr[5] = {50, 60, 70, 80, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    st.pushRange(arr, size);
    
    cout << "head element : " << st.peek() << endl;
    
    int value = st.pop();
    cout << "Poped Element : " << value <<endl;
    
    cout << "After poped - head element : " << st.peek() << endl;
    
    cout << "All Stack Elements : ";
    st.allElements();
    
    return 0;
}
