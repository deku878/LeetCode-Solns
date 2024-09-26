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
        ListNode* ans = new ListNode(-1);
        ans->next = head;
        ListNode *slow, *fast;
        slow = ans;
        fast = ans;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // now point slow pointer to nth position
        //  i can get it through fast pointer

        while (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }

        // now delete the node
        slow->next = slow->next->next;
        // this is beacause ans is pointing to -1 at the beginnig so move ponter
        // from -1 to actual content
        return ans->next;
    }
};