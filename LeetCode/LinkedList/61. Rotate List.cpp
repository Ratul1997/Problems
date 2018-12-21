//Problem Statement

/*

Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL )return NULL;
        if(head->next == NULL)return head;
        int size=1;
        
        ListNode *temp= head;
        
        while(temp->next!=NULL){
            temp= temp->next;
            size++;
        }
        
        temp->next = head;
        
        int t= k%size;
        
        for(int i= 0 ; i<size-t ;i++){
            temp = temp->next;
        }
        head = temp->next;
        
        temp->next = NULL;
        return head;
        
    }
};