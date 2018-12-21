// Problem Statement

/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.
*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
    int s;
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* current = head;
        int size = 0;
        while(current!=NULL){
            size++;
            current=current->next;
        }
        if(size == n&& n==1){
            head = NULL;
        }
        else if(size == n){
            head = head->next; 
        }
        else{
            size = size - n;
            current = head;
            
            while(size>1){
                current = current->next;
                size--;
            }
            
            ListNode *temp = current->next;
            current->next= current->next->next;
            
            delete temp;
        }
         return head;

        
    }
};