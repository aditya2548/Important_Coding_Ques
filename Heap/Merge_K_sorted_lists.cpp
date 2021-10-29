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
    struct cmp
    {
        bool operator()(ListNode*a,ListNode*b)
        {
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* newNode=new ListNode();
        ListNode* temp=newNode;
        priority_queue<ListNode*,vector<ListNode*>,cmp>minHeap;
        for(int i=0;i<lists.size();i++)
            if(lists[i])
                minHeap.push(lists[i]);
        while(!minHeap.empty())
        {
            ListNode*p=minHeap.top();
            temp->next=p;
            temp=temp->next;
            minHeap.pop();
            if(p->next)
                minHeap.push(p->next);
        }
        return newNode->next;
        
    }
};