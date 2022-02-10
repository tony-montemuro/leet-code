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
        // Trivial Case: If list is length 1, simply return nullptr
        if (head->next == nullptr) return nullptr;
        
        // Set up runner nodes: the main runner, one that lags n-nodes behind, and
        // one that is one behind the lagger (since we want to delete the lag runner)
        ListNode* r = head;
        ListNode* lag = head;
        ListNode* prev = head;
        
        // Get runner node n-nodes ahead of lag
        for (int i = 0; i < n; i++) {
            r = r->next;
        }
      
        // Now, increment all nodes until runner reaches end of list
        while (r != nullptr) {
            r = r->next;
            prev = lag;
            lag = lag->next;
        }
        
        // Special case: If neither lagging runner has moved, this implies the n-th node
        // from end is first node: so increment header node by one
        if (prev == lag) head = head->next;
        
        //Otherwise, set next pointer of previous node to that of the lag node, & return head
        prev->next = lag->next;
        delete lag;
        return head;
    }
};
