/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* startPoint(TreeNode* root, int start, unordered_map<TreeNode*, TreeNode*> &childParentMapping){
        TreeNode* result = NULL;
        queue<TreeNode*> q;
        q.push(root);

        childParentMapping[root] = NULL;

        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();

            if(front -> val == start){
                result = front;
            }

            if(front -> left){
                childParentMapping[front -> left] = front;
                q.push(front -> left);
            }

            if(front -> right){
                childParentMapping[front -> right] = front;
                q.push(front -> right);
            }
        }

        return result;
    }

    int t_infected_time(TreeNode* root, unordered_map<TreeNode*, TreeNode*> childParentMapping){
        int minutes = -1;

        unordered_map<TreeNode*, bool> infected;
        queue<TreeNode*> q;

        q.push(root);

        infected[root] = true;

        while(!q.empty()){
            int size = q.size();
            bool flag = true;

            for(int i = 0; i < size; i++){
                
                TreeNode* front = q.front();
                q.pop();

                if(front -> left && !infected[front -> left]){
                    flag = true;
                    q.push(front -> left);
                    infected[front -> left] = true;
                }
                
                if(front -> right && !infected[front -> right]){
                    flag = true;
                    q.push(front -> right);
                    infected[front -> right] = true;
                }

                if(childParentMapping[front] && !infected[childParentMapping[front]]){
                    flag = true;
                    q.push(childParentMapping[front]);
                    infected[childParentMapping[front]] = true;
                }
            }

            if(flag == true) minutes++;
        }

        return minutes;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> childParentMapping;
        TreeNode* startNode = startPoint(root, start, childParentMapping);
        return t_infected_time(startNode, childParentMapping);
    }
};
