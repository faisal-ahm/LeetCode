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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        auto temp1 = l1;
        auto temp2 = l2;
        ListNode* newHead = NULL;
        ListNode* newTail = newHead;
        while(temp1 && temp2){
            int val = (temp1->val + temp2->val + carry);
            carry = val/10;
            val %= 10;
            if(!newHead){
                newHead = new ListNode(val);
                newTail = newHead;
            }else{
                newTail->next = new ListNode(val);
                newTail = newTail -> next;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while(temp1){
            int val = (temp1->val + carry);
            carry = val/10;
            val %= 10;
            if(!newHead){
                newHead = new ListNode(val);
                newTail = newHead;
            }else{
                newTail->next = new ListNode(val);
                newTail = newTail -> next;
            }
            temp1 = temp1->next;
        }
        while(temp2){
            int val = (temp2->val + carry);
            carry = val/10;
            val %= 10;
            if(!newHead){
                newHead = new ListNode(val);
                newTail = newHead;
            }else{
                newTail->next = new ListNode(val);
                newTail = newTail -> next;
            }
            temp2 = temp2->next;
        }
        if(carry == 1){
            newTail->next = new ListNode(carry);
        }
        return newHead;
    }
};