//Problem Statement

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(head == NULL)return head;
        
        ListNode *current,*nextNode;
        current = head;
        while(current->next){
            nextNode = current->next;
            
            (current->val == nextNode->val)? current->next = nextNode->next : current = nextNode;
        }
        
        return head;
    }
};