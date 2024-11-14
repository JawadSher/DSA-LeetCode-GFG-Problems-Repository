class Solution {
  public:
    Node* mergeTwoLists(Node* l1, Node* l2){
        Node* temp = new Node(0);
        Node* current = temp;
        
        while(l1 != NULL && l2 != NULL){
            if(l1 -> data < l2 -> data){
                current -> next = l1;
                l1 = l1 -> next;
            }else{
                current -> next = l2;
                l2 = l2 -> next;
            }
            
            current = current -> next;
        }
        
        if(l1 != NULL) current -> next = l1;
        if(l2 != NULL) current -> next = l2;
        
        return temp -> next;
    };
    
    Node* mergeKListsHelper(vector<Node*>& arr, int left, int right){
        if(left == right) return arr[left];
        
        int mid = left + (right - left) / 2;
        
        Node* leftMerge = mergeKListsHelper(arr, left, mid);
        Node* rightMerge = mergeKListsHelper(arr, mid+1, right);
        
        return mergeTwoLists(leftMerge, rightMerge);
    };
    
    Node* mergeKLists(vector<Node*>& arr) {
        if(arr.empty()) return NULL;
        
        return mergeKListsHelper(arr, 0, arr.size() -1);
    }
};
