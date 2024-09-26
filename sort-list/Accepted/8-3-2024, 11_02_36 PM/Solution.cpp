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
        if(head==NULL){
            return head;
        }
        vector<int>res;
        while(head!=NULL){
            res.push_back(head->val);
            head=head->next;
        }
        sort(res.begin(),res.end());
        ListNode* ui=new ListNode(res[0]);
        ListNode* yt=ui;
        for(int i=1;i<res.size();i++){
            ListNode* yu=new ListNode(res[i]);
            ui->next=yu;
            ui=ui->next;
        }
        return yt;
    }
};