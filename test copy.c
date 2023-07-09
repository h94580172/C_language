/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1 == NULL && list2 == NULL){
        return NULL;
    }
    struct ListNode* l1 = list1;
    struct ListNode* l2 = list2;
    struct ListNode* head = malloc(sizeof(struct ListNode));
    struct ListNode* temp = head;
    while(l1 != NULL && l2 != NULL){
        if(l1->val >= l2->val){
            temp->next = l2;
            l2 = l2->next;
        }
        else{
            temp->next = l1;
            l1 = l1->next;
        }
        temp = temp->next;
    }
    if(l1){
        temp->next = l1;
    }
    if(l2){
        temp->next = l2;
    }
    return head->next;
}