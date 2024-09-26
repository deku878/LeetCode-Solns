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
        if (head == nullptr) return nullptr;

        vector<int> res;
        ListNode* current = head;
        while (current != nullptr) {
            res.push_back(current->val);
            current = current->next;
        }

        reverse(res.begin(), res.end());

        ListNode* newHead = new ListNode(res[0]);
        ListNode* temp = newHead;
        for (int i = 1; i < res.size(); i++) {
            temp->next = new ListNode(res[i]);
            temp = temp->next;
        }
        
        return newHead;
    }
};
