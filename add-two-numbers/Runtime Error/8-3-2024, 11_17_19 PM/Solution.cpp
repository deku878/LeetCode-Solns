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
        vector<int> res1;
        vector<int> res2;

        // Collect digits from the first list
        while (l1 != nullptr) {
            res1.push_back(l1->val);
            l1 = l1->next;
        }

        // Collect digits from the second list
        while (l2 != nullptr) {
            res2.push_back(l2->val);
            l2 = l2->next;
        }

        // Convert the vectors to integers
        int num1 = 0, num2 = 0;
        int multiplier = 1;
        for (int digit : res1) {
            num1 += digit * multiplier;
            multiplier *= 10;
        }

        multiplier = 1;
        for (int digit : res2) {
            num2 += digit * multiplier;
            multiplier *= 10;
        }

        // Add the two numbers
        int sum = num1 + num2;

        // Edge case: if the sum is 0, return a single node with value 0
        if (sum == 0) {
            return new ListNode(0);
        }

        // Convert the sum back to a linked list
        ListNode* dummyHead = new ListNode(0); // Dummy head to simplify list construction
        ListNode* current = dummyHead;

        while (sum > 0) {
            int digit = sum % 10;
            current->next = new ListNode(digit);
            current = current->next;
            sum /= 10;
        }

        // Return the next node of dummy head, which is the actual head of the result list
        return dummyHead->next;
    }
};
