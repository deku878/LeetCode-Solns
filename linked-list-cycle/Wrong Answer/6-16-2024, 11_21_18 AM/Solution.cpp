// https://leetcode.com/problems/linked-list-cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<int,int>mp;
        ListNode* t=head;
        while(t!=NULL){
            if(mp[t->val]>0){
                return true;
            }
            else{
                mp[t->val]++;
            }
            t=t->next;
        }
        return false;
    }
};