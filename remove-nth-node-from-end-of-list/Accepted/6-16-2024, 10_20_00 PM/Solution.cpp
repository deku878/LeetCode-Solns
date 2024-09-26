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
       ListNode *slow, *fast;
        slow=head;
        fast=head;
        ListNode *prev=new ListNode(0,head);
        ListNode *answer=prev;
        while(n>1){
            fast=fast->next;
            n--;
        }
        while(fast->next){
            fast=fast->next;
            slow=slow->next;
            prev=prev->next;
        }
        prev->next=slow->next;
        return answer->next;
    }
};