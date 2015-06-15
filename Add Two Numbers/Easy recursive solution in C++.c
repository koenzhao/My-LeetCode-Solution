ListNode* addList(ListNode* l1, ListNode* l2, int carry) {
    if(!l1 && !l2) {
        if(carry) return new ListNode(carry);
        else return NULL;
    }
    int val = carry + (l1?l1->val:0) + (l2?l2->val:0);
    ListNode* newNode = new ListNode(val%10);
    newNode->next = addList(l1?l1->next:NULL, l2?l2->next:NULL, val/10);
    return newNode;
}
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    return addList(l1, l2, 0);
}