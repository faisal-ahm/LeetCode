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
    int getLen(ListNode* head){
        int size = 0;
        auto temp = head;
        while(temp){
            temp = temp->next; 
            size++;
        } 
        return size;
    }
    ListNode* getTail(ListNode* head){
        auto temp = head;
        while(temp->next) temp = temp->next;
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int n = getLen(head);
        if(!n) return head;
        k %= n;
        if(!k) return head;
        auto tail = getTail(head);
        int pos = 1;
        auto temp = head;
        ListNode* newHead;
        while(pos != n-k){
            temp = temp->next;
            pos++;
        }
        newHead = temp->next;
        temp->next = NULL;
        tail->next = head;
        return newHead;
        
    }
};