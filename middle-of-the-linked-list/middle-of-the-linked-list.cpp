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
        ListNode* r = head;
        std::vector<ListNode*> nodes;
        while (r != nullptr) {
            nodes.push_back(r);
            r = r->next;
        }
        return nodes[nodes.size()/2];
    }
};
