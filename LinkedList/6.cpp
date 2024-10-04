#include <stack>
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
    bool isPalindrome(ListNode* head) {
        ListNode* current = head;
        stack<int> s1;
        while(current != nullptr) {
            s1.push(current->val);
            current = current->next;
        }

        while (head != nullptr) {
            int c = s1.top();
            s1.pop();
            if (head->val != c) {
                return false;
            }
            head = head->next;
        }
    return true;
    }
};