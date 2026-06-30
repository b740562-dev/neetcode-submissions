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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // see k sorted means q is demanding to use heap
        // take one element from each list and push in pq---min heap will store min at top 
        // point it to dummy->next remove that push it's next !!!
        int k=lists.size();
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> pq;
        // inserted top k minimals !!!
        // lists[0] stores the head of first node
        // in vector<listnode*> each lists[i] stores head of it's own linked list !!
        for(int i=0;i<k;i++){
            if(lists[i]!=nullptr){
                pq.push({lists[i]->val,lists[i]});
            }
        }
        // head is subjected to change----need to use dummy node
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        // to traverse in pq we use !pq.empty()
        while(!pq.empty()){
            temp->next=pq.top().second;
            ListNode* curr=pq.top().second->next;
            pq.pop();
            // whenever accessing a nodes val----check possibility of it being null !!!!
            if(curr != nullptr){
                pq.push({curr->val,curr});
            }
            temp=temp->next;
        }
        return dummy->next;
    }
};
