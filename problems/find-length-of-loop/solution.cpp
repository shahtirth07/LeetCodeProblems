
class Solution {
  public:
  int countNodesinLoop(Node *head) {
    // Function to find the length of a loop in the linked list.int countNodesinLoop(Node *head) 
        if(head == nullptr || head->next == nullptr) return 0; 
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        if(fast->next == nullptr || fast->next->next == nullptr) return 0;
        
        fast = fast->next;
        int cnt = 1;
        while(slow != fast){
            cnt++;
            fast = fast->next;
        }
        
        return cnt;
    }
};