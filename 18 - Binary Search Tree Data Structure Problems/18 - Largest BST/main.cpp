class info {
public:
    int mini;
    int maxi;
    bool isBST;
    int size;
};

class Solution {
public:
    info getLargestBSTInfo(Node* root, int &ans) {
        if (root == NULL) return info{INT_MAX, INT_MIN, true, 0};

        info left = getLargestBSTInfo(root->left, ans);
        info right = getLargestBSTInfo(root->right, ans);

        info currNode;
        currNode.size = left.size + right.size + 1;
        currNode.maxi = max(root->data, right.maxi);
        currNode.mini = min(root->data, left.mini);

        if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
            currNode.isBST = true;
        } else {
            currNode.isBST = false;
        }

        if (currNode.isBST) ans = max(ans, currNode.size);

        return currNode;
    }

    int largestBst(Node* root) {
        int maxSize = 0;
        getLargestBSTInfo(root, maxSize);
        return maxSize;
    }
};
