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

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Node*, vector<Node*>, compare> pq;
        
        for(int i = 0; i < K; i++){
            Node* temp = new Node(arr[i][0], i, 0);
            pq.push(temp);
        }
        
        vector<int> answer;
        
        while(pq.size() > 0){
            Node* temp = pq.top();
            answer.push_back(temp -> data);
            pq.pop();
            
            int i = temp -> row;
            int j = temp -> col;
            
            if(j+1 < arr[i].size()){
                Node* next = new Node(arr[i][j+1], i, j+1);
                pq.push(next);
            }
        }
        
        return answer;
    }
};
