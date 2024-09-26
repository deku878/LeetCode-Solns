// https://leetcode.com/problems/linked-list-cycle-ii

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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*,ListNode*>mp;
        ListNode* temp=head;
        while(temp!=NULL){
            
            if(mp.count(temp)==0){
                mp[temp]=temp;
            }
            else{
                return mp[temp];
            }
            temp=temp->next;
        }
        return NULL;
    }
};