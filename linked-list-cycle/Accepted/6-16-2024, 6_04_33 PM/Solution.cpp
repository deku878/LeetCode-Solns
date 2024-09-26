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
        map<ListNode*,int>mp;
        ListNode* t=head;
        while(t!=NULL){
            if(mp[t]>0){
                return true;
            }
            else{
                mp[t]++;
            }
            t=t->next;
        }
        return false;
    }
};