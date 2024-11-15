class Node{
    public:
        int data;
        int row;
        int col;
        
        Node(int data, int row, int col){
            this -> data = data;
            this -> row = row;
            this -> col = col;
        }
};

class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a -> data > b -> data;
        }
};
class Solution{
    public:
    pair<int,int> findSmallestRange(int arr[][N], int n, int k)
    {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        priority_queue<Node*, vector<Node*>, compare> minHeap;
        
        for(int i = 0; i < k; i++){
            int element = arr[i][0];  
            
            mini = min(mini, element);
            maxi = max(maxi, element);
            
            minHeap.push(new Node(element, i, 0));
        }
        
        
        int start = mini, end = maxi;
        
        while(!minHeap.empty()){
            Node* temp = minHeap.top();
            minHeap.pop();
            
            mini = temp -> data;
            
            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }
            
            if(temp -> col + 1 < n){
                maxi = max(maxi, arr[temp->row][temp->col + 1]);
                minHeap.push(new Node(arr[temp->row][temp->col + 1], temp -> row, temp -> col + 1));
            }else break;
            
        }
        
        return {start, end};
        
    }
};
