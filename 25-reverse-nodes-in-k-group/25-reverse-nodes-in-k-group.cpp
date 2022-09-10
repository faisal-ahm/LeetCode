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
    int getn(ListNode* head){
        int ans = 0;
        while(head){
            head = head->next;
            ans++;
        }
        return ans;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = getn(head);
        ListNode* newHead = NULL; 
        ListNode* prevSegTail = NULL;
        ListNode* tempHead = head;
        
        while(n >= k){
            int K = k-1;
            auto currTail = tempHead;
            while(K--) currTail = currTail->next;
            auto nextSeg = currTail->next;
            currTail->next = NULL;
            
            ListNode* curr = tempHead;
            ListNode* prev = NULL;
            ListNode* next;
            
            while(curr){
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            
            if(!newHead){
                newHead = prev;
            }else{
                prevSegTail->next = prev;
            }
            
            tempHead->next = nextSeg;
            prevSegTail = tempHead;
            tempHead = nextSeg;
            n-=k;
        }
        return newHead;
    }
};