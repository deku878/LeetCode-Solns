// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list

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
    ListNode* deleteMiddle(ListNode* head) {
       if(head->next==NULL){
        return NULL;
      }
      ListNode* res=head;
      ListNode* res1=head;
      int n=0;
      while(res1!=NULL){
        res1=res1->next;
        n++;
      }
      long long int cnt=1;
      while(cnt<n/2){
        res=res->next;
        cnt++;
      }
      ListNode* p=res->next->next;
      res->next=p;
      return head;
    }
};