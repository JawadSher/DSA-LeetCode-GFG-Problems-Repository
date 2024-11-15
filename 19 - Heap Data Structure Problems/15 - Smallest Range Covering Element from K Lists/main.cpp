class Node {
    public:
        int data;
        int row;
        int col;

        Node(int data, int row, int col) { 
            this->data = data;
            this->row = row;
            this->col = col;
        }
};

class compare{
    public:
        bool operator()(Node* a, Node* b){
            return a -> data > b -> data;
        }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        priority_queue<Node*, vector<Node*>, compare> pq;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i = 0; i < k; i++){
            int element = nums[i][0];

            maxi = max(maxi, element);
            mini = min(mini, element);

            pq.push(new Node(element, i, 0));
        }

        int start = mini;
        int end = maxi;

        while(!pq.empty()){
            Node* temp = pq.top();
            pq.pop();

            mini = temp -> data;

            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }

            if(temp -> col + 1 < nums[temp -> row].size()){
                int nextElement = nums[temp -> row][temp -> col + 1];

                maxi = max(nextElement, maxi);
                pq.push(new Node(nextElement, temp -> row, temp -> col + 1));
            }else{
                break;
            }
        }

        return {start, end};
    }
};
