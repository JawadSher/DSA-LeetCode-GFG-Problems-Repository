class Solution
{
    public:
    queue<int> rev(queue<int> q)
    {
        if(q.empty()) return q;
        
        int element = q.front();
        q.pop();
        
        q = rev(q);
        
        q.push(element);
        
        return q;
    }
};
