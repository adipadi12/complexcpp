ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1; // for empty lists
        if(l1->val > l2->val) swap(l1, l2); // ensure l1 always points to the smallest head
        ListNode* res = l1; // store address as a pointer variable

        while(l1 != NULL && l2 != NULL)
        {
            ListNode* temp = NULL;
            while(l1 != NULL && l1->val <= l2->val) // when l1 < l2 say node 3 <= node 5
            {
                temp = l1; // store l1
                l1 = l1->next; // advance l1
            }
            temp->next = l2; // make next of temp l2
            swap(l1, l2); // l2 becomes smaller than l1 so swap
        }

        return res;
    }