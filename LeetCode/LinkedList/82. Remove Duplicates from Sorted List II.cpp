//Problem Statement

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
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
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = head, *previous = dummy, *nextNode;
        
        while(current!=NULL){
             nextNode = current->next;  
                if(nextNode == NULL) break;
              if(nextNode->val == current->val){
                  while(nextNode!=NULL  && current->val == nextNode->val){
                       nextNode = nextNode ->next;
                  }
                  previous->next =  nextNode;
                  current = nextNode;
              }
            else{
                previous = current;
                current =  nextNode;
            }
            
            
        }
        
        return dummy->next;
    }
        
};