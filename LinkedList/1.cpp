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
    ListNode* middleNode(ListNode* head) {
        ListNode* current = head;
        int count = 0;
        while (current != nullptr) {
            current = current->next;
            count += 1;
        }
        if (count%2 == 0) {
            ListNode *print = head;
            for (int i = 0; i <= count/2-1; i++) {
                print = print->next;
            } 
            return print;
        } else {
            ListNode *print = head;
            for (int i = 0; i <= count/2-1; i++) {
                print = print->next;
            } 
            return print;
        }
    }
};