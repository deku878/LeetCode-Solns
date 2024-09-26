// https://leetcode.com/problems/add-two-numbers

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int>res1;
        while(l1!=NULL){
            res1.push_back(l1->val);
            l1=l1->next;
        }
        vector<int>res2;
        while(l2!=NULL){
            res2.push_back(l2->val);
            l2=l2->next;
        }
        int mul=1;
        int ans=0;
        for(int i=0;i<res1.size();i++){
            ans+=res1[i]*mul;
            mul*=10;
        }
        int mul1=1;
        int ans1=0;
         for(int i=0;i<res2.size();i++){
            ans1+=res2[i]*mul1;
            mul1*=10;
        }
        int gh=ans1+ans;
        cout<<gh<<endl;
        string h=to_string(gh);
        vector<int>ko;
        cout<<h<<endl;
        for(int i=0;i<h.size();i++){
            ko.push_back(h[i]-'0');
        }
        reverse(ko.begin(),ko.end());
        ListNode* h1=new ListNode(ko[0]);
        ListNode* tem=h1;
        for(int i=1;i<ko.size();i++){
            ListNode* temp=new ListNode(ko[i]);
            tem->next=temp;
            tem=tem->next;
        }
        return h1;
    }
};