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
    bool hasCycle(ListNode* head) {
        // if fast and slow meet then cycle present otherwise not !!!!
        ListNode* fast=head;
        ListNode* slow=head;
        
        if(head==nullptr || head->next==nullptr){
            return 0;
        }
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                return 1;
            }
        }
        return 0;
    }
};
