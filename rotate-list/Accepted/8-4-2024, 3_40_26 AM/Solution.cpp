// https://leetcode.com/problems/rotate-list

#include<bits/stdc++.h>
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
        ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;

        vector<int> ko;
        ListNode* current = head;
        while (current != nullptr) {
            ko.push_back(current->val);
            current = current->next;
        }

        int n = ko.size();
        k = k % n;  // Handle cases where k is greater than the length of the list
        if (k == 0) return head;

        // Rotate the vector
        rotate(ko.begin(), ko.begin() + n - k, ko.end());

        // Rebuild the linked list from the rotated vector
        ListNode* newHead = new ListNode(ko[0]);
        ListNode* temp = newHead;
        for (int i = 1; i < ko.size(); i++) {
            ListNode* newNode = new ListNode(ko[i]);
            temp->next = newNode;
            temp = temp->next;
        }
        
        return newHead;
    }
};