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

        ListNode* temp=head;
        ListNode* prev=nullptr;

        while(temp!=nullptr){
            ListNode* nex=temp->next;
            temp->next=prev;
            prev=temp;
            temp=nex;
        }
        return prev;

    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* temp=head;

        // add prevtail
        ListNode* prevtail=dummy;

        while(temp!=nullptr){
            // currently kon sa node head hai !!!
            ListNode* currhead=temp;

            for(int i=0;i<k-1;i++){
                if(temp!=nullptr){
                    temp=temp->next;
                }
            } 
            

            if(temp==nullptr){
                // before breaking we have to make sure prevtail->next is connected to currhead !!
                prevtail->next=currhead;
                break;
            }

            ListNode* nexthead=temp->next;
            temp->next=nullptr;
            ListNode* newhead=reverse(currhead);

            // immediately after reversing connect prev part !!
            prevtail->next=newhead;
            currhead->next=nexthead;
            
            prevtail=currhead;
            temp=nexthead;

        }
        return dummy->next;
    }
};
