// https://leetcode.com/problems/remove-nth-node-from-end-of-list

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL){
            return NULL;
        }
        ListNode*x=head;
        ListNode *res=head;
        int cnt=0;
        while(x!=NULL){
            cnt++;
            x=x->next;
        }
        cnt-=n;
        cnt-=1;
        while(cnt!=0){
            res=res->next;
            cnt--;
        }
        ListNode* ui=res->next->next;
        res->next=ui;
        return head;
    }
};