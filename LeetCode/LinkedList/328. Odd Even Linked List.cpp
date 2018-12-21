//problem Statement

/*

Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head == NULL || head->next==NULL)return head;
        ListNode *dummy = head;
        ListNode *current = dummy,  *temp = head->next,*nextNode = temp;
        
        while(nextNode){
            current->next =  nextNode->next;
            if(current->next){
                nextNode->next = current->next->next;
                current = current->next;
            }
            nextNode = nextNode->next;
        }
        current->next = temp;
        
        return dummy;
    }
};