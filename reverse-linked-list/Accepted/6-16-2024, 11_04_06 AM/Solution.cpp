// https://leetcode.com/problems/reverse-linked-list

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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL){
            return head;
        }
        ListNode* i=head;
        vector<int>l;
        while(i!=NULL){
            l.push_back(i->val);
            i=i->next;
        }
        reverse(l.begin(),l.end());
        ListNode* t=new ListNode(l[0]);
        ListNode* u=t;
        int v=1;
        while(v<l.size()){
            ListNode* f=new ListNode(l[v]);
            t->next=f;
            t=t->next;
            v++;
        }

        return u;
    }
};