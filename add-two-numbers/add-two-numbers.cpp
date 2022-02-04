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
        //Declare variables
        int num1, num2, sum, carry;
        std::queue<int> q1, q2;
        
        //Get queue of numbers from both linked-lists
        while (l1 != nullptr) {
            q1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) {
            q2.push(l2->val);
            l2 = l2->next;
        }
        
        //Generate output linked-list
        sum = q1.front() + q2.front();
        q1.pop();
        q2.pop();
        ListNode* solution = new ListNode(sum % 10, nullptr);
        carry = sum / 10;
        ListNode* t = solution;
        while ((!q1.empty() || !q2.empty()) || carry == 1) {
            //Case 1: Both queues are empty, but carry is 1
            if (q1.empty() && q2.empty()) {
                sum = carry;
            }
            
            //Case 2: Queue 1 is empty, but queue 2 is not
            else if (q1.empty()) {
                sum = q2.front() + carry;
                q2.pop();
            }
            
            //Case 3: Queue 2 is empty, but not queue 1
            else if (q2.empty()) {
                sum = q1.front() + carry;
                q1.pop();
            }
            
            //General Case: Both queues have elements
            else {
                sum = q1.front() + q2.front() + carry;
                q1.pop();
                q2.pop();
            }
            
            ListNode* next = new ListNode(sum % 10, nullptr);
            t->next = next;
            t = next;
            carry = sum / 10;
        }
        return solution;
    }
};
