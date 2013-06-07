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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head) return NULL;
        else if(head->next == NULL){
            return head;
        }
        ListNode *lt = NULL;
        ListNode *ge = NULL;
        ListNode *lt_root = NULL;
        ListNode *ge_root = NULL;
        
        while(head){
            if(head->val < x){
                if(!lt){
                    lt = new ListNode(head->val);
                    lt_root = lt;
                }
                else{
                    lt->next = new ListNode(head->val);
                    lt = lt->next;
                }
            }
            else{
                if(!ge){
                    ge = new ListNode(head->val);
                    ge_root = ge;
                }
                else{
                    ge->next = new ListNode(head->val);
                    ge = ge->next;
                }
            }
            head  = head->next;
        }
        
        ge = NULL;
        if(lt_root != NULL){
            lt->next = ge_root;
            return lt_root;
        }
        else{
            return ge_root;
        }
        
    }
};