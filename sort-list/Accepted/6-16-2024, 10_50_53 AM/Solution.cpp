// https://leetcode.com/problems/sort-list

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
    ListNode* sortList(ListNode* head) {
        vector<int>x;
        ListNode* h=head;
        while(h!=NULL){
            x.push_back(h->val);
            h=h->next;
        }
        sort(x.begin(),x.end());
        ListNode* kl=new ListNode(0);
        ListNode* b=kl;
        long long int i=0;
        while(i<x.size()){
            ListNode* o=new ListNode(x[i]);
            b->next=o;
            b=b->next;
            i++;
        }
        return kl->next;
    }
};