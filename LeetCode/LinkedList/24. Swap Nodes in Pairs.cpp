//Problem Statement

/*

Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)return head;
        
        ListNode *current, *node2, *node3, *newNode;
        
        newNode = head->next;
        current = head;
        
        while(current!=NULL && current->next!=NULL){
            node2 = current->next;
            node3 = node2->next;
            
            if(!node3 || !node3->next){
                current->next = node3;
            }
            else{
                current->next = node3->next;
            }
            
            node2->next = current;
            
            current = node3;
        }
        return newNode;
        
    }
};
