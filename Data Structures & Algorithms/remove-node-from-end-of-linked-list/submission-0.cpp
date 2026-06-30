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

        //  this problem requires us to use sliding window and solve in one pass 
        ListNode* dummy=new ListNode(-1,head);

        ListNode* temp=dummy;
        for(int i=0;i<=n;i++){
            temp=temp->next;
        }

        ListNode* temp2=dummy;

        while(temp!=nullptr){
            temp=temp->next;
            temp2=temp2->next;
        }

        ListNode* temp3=temp2->next;
        temp2->next=temp2->next->next;
        delete temp3;

        return dummy->next;
    }
};
