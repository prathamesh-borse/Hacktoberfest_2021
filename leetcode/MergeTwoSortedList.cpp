/* Author - Ashish Tyagi */

/* Problem Statement
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.
*/

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
    
    #define ln ListNode
    
    ListNode* mergeTwoLists(ListNode* start1, ListNode* start2) {
        ln *merge=new ln(-1),*head = merge;
        
        while(start1!=NULL and start2!=NULL){
            if((start1->val)<=(start2->val)){
                merge->next = start1;
                start1 = start1->next;
                merge = merge->next;
            }
            else{
                merge->next = start2;
                start2 = start2->next;
                merge = merge->next;
            }
        }
        
        while(start1!=NULL){
                merge->next = start1;
                start1 = start1->next;
                merge = merge->next;
        }
        
        while(start2!=NULL)
        {
                merge->next = start2;
                start2 = start2->next;
                merge = merge->next;
        }
        
        return head->next;
    }
};
