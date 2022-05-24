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
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (!list1) {
        return list2;
    }
    if (!list2) {
        return list1;
    }
    ListNode *newHead;
    auto temp1 = list1, temp2 = list2;
    if (temp1->val < temp2->val) {
        newHead = temp1;
        temp1 = temp1->next;
        newHead->next = NULL;
    } else {
        newHead = temp2;
        temp2 = temp2->next;
        newHead->next = NULL;
    }

    auto temp = newHead;

    while (temp1 && temp2) {
        if (temp1->val < temp2->val) {
            temp->next = temp1;
            temp1 = temp1->next;
        } else {
            temp->next = temp2;
            temp2 = temp2->next;
        }
        temp = temp->next;
        temp->next = NULL;
    }
    if(temp1){
        temp->next = temp1;
    }
    if(temp2){
        temp->next = temp2;
    }
    return newHead;
}
};