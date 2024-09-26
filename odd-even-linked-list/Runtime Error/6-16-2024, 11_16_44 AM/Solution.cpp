// https://leetcode.com/problems/odd-even-linked-list

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
    ListNode* oddEvenList(ListNode* head) {
        vector<int>x;
        ListNode* t=head;
        while(t!=NULL){
            x.push_back(t->val);
            t=t->next;
        }
        ListNode* y=new ListNode(x[0]);
        ListNode* ui=y;
        for(int i=2;i<x.size();i+=2){
            ListNode* f=new ListNode(x[i]);
            y->next=f;
            y=y->next;
        }
        for(int i=1;i<x.size();i+=2){
            ListNode* f=new ListNode(x[i]);
            y->next=f;
            y=y->next;
        }
        return ui;
    }
};