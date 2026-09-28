ListNode* removeNthFromEndBrute(ListNode* head, int n) 
{
    int count = 0;
    ListNode* temp = head;
    while(temp != NULL){
        count++; // traverse
        temp = temp->next;
    }
    if(count == n){
        ListNode* newHead = head->next; // if count same as n just return head
        return newHead;
    }
    int res = count - n;
    temp = head;
    while(temp != NULL){
        res--;
        if(res == 0) break;
        temp = temp->next; // traverse to before the nth element
    }

    ListNode* delNode = temp->next; // delete next node
    temp->next = temp->next->next;
    return head;
}

ListNode* removeNthFromEndOPTIMAL(ListNode* head, int n) {
    ListNode* fast = head;
    for(int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
    if(fast == NULL){
        return head->next;            
    }
    ListNode* slow = head;

    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* delNode = slow->next;
    slow->next = slow->next->next;
    return head;
}