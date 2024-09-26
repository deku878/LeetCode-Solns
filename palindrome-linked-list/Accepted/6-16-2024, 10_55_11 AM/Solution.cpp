// https://leetcode.com/problems/palindrome-linked-list

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
    bool is(vector<int>&p){
        int i=0;
        int j=p.size()-1;
        while(i<j){
            if(p[i]!=p[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        vector<int>x;
        ListNode* h=head;
        while(h!=NULL){
            x.push_back(h->val);
            h=h->next;
        }
        return is(x);
    }
};