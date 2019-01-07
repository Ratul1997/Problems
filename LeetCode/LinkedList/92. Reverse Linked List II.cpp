//Problem Statement

/*

Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        if(head== NULL || head->next == NULL) return head;
        
        ListNode *current , *prev , *nextNode, *dummy = new ListNode(0);
        dummy->next = head;
        current = NULL;
        prev = dummy;
        nextNode = dummy;
        
        int i = 0;
        for(i=1; i<m; i++){
            nextNode = nextNode->next;
            prev = prev->next;
        }
        for(;i<=n;i++){
            nextNode = nextNode->next;
        }
        for( i = 0 ; i< n-m; i++){
            
            current = prev->next;
            prev->next = current->next;
            current->next = nextNode->next;
            nextNode->next = current;
            
        }
        return dummy->next;
      
    }
};