class Solution {
private:
    bool pallindrome(ListNode* head){
        vector<int> list_arr(0);

        while(head != NULL){
            list_arr.push_back(head->val);
            head = head -> next;
        }

        int s = 0; 
        int e = list_arr.size() -1;

        while(s < e){
            if(list_arr[s] != list_arr[e]){
                return false;
            }
            s++;
            e--;
        }

        return true;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(pallindrome(head)){
            return true;
        }

        return false;
    }
};
