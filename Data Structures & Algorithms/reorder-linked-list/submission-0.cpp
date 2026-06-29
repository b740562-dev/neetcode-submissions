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
private:
    ListNode* reverse(ListNode* head){
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp!=nullptr){
            ListNode* next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        // go to middle node and break the linked list 
        // now we have two linked list----reverse second one
        // we can make joins much simpler then what we made in merging two ll !!!
        if(head->next==nullptr || head->next->next==nullptr){
            return ;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* head2=slow->next;
        slow->next=nullptr;
        head2=reverse(head2);

        ListNode*temp=head;
        ListNode*temp1=head;
        ListNode*temp2=head2;
        int cnt=0;
        // alternating karne ka best simpler approach !
        while(temp2!=nullptr){
            ListNode* next1=temp1->next;
            ListNode* next2=temp2->next;
            temp1->next=temp2;
            temp2->next=next1;
            temp1=next1;
            temp2=next2;
        }
    }
};
