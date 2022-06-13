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
    ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next){
        return head;
    }
    bool isOdd = true;
    ListNode* temp = head;ListNode* head1 = NULL; ListNode* tail1 = NULL; ListNode* tail2 = NULL; ListNode* head2 = NULL;
    while(temp){
        if(isOdd){
            if(!head1){
                head1 = temp;
                tail1 = temp;
            }else{
                tail1->next = temp;
                tail1 = temp;
            }
        }else{
            if(!head2){
                head2 = temp;
                tail2 = temp;
            }else{
                tail2->next = temp;
                tail2 = temp;
            }
        }
        temp = temp->next;
        isOdd = !isOdd;
    }
    tail1->next = NULL;
    tail2->next =NULL;
    tail1->next = head2;
    return head1;
}
};