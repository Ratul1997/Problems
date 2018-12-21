//Problem Statement

/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5
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
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode *dummy = new ListNode(0), *current;
        
        dummy->next = head;
        
        current = dummy;
        
        while(current->next != NULL){
            (current->next->val == val)? current->next =  current->next->next : current = current->next; 
        }
        
        return dummy->next;
    }
};