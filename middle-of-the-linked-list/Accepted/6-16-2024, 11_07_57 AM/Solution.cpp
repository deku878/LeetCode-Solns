// https://leetcode.com/problems/middle-of-the-linked-list

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<int>x;
        ListNode* t=head;
        ListNode* y=head;
        while(t!=NULL){
            x.push_back(t->val);
            t=t->next;
        }
        int pos=x.size()/2;
        while(pos--){
            y=y->next;
        }
        return y;
    }
};