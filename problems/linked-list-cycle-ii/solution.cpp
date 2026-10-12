/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow != nullptr || fast != nullptr) {
            if (fast-> next == nullptr || fast->next->next == nullptr) {
                return nullptr;
            }
            slow = slow->next;
            fast = fast->next->next;
             if (slow == fast) {
            // Move slow to head, and move both slow and fast one step at a time
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;  // Start of the cycle
        }
             
        }
        return nullptr;
    }
};