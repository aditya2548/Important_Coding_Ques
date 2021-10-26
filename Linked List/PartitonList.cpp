/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
void swap(ListNode* a,ListNode* b)
{
    int temp=a->val;
    a->val=b->val;
    b->val=temp;
}
ListNode* Solution::partition(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode* i=NULL;
    ListNode* j=NULL;
    ListNode* k=NULL;
    ListNode* temp=A;
    int count=0;
    ListNode* b1=NULL;
    ListNode* b2=NULL;
    ListNode* b3=NULL;
    while(temp!=NULL)
    {
        if(temp->val<B)
        {
            if(b1==NULL)
            {
                b1=temp;
                i=b1;
            }
            else
            {
                i->next=temp;
                i=i->next;
            }
        }
        else
        {
            if(b3==NULL)
            {
                b3=temp;
                k=b3;
            }
            else
            {
                k->next=temp;
                k=k->next;
            }
        }
        temp=temp->next;
    }
    
    if(b1==NULL)
    {
        A=b3;
        if(k!=NULL)
            k=k->next;
    }
    else
    {
        A=b1;
        i->next=b3;
        if(k!=NULL)
            k->next=NULL;
    }
    return A;
}

