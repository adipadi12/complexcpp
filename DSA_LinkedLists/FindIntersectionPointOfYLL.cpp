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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map <ListNode*, int> mpp;
        ListNode* temp = headA;
        while(temp != NULL){
            mpp[temp] = 1;
            temp = temp -> next; // hashing used for traversal and count check till end
        }
        temp = headB;
        while(temp != NULL){ // traverse through 2nd list
            if(mpp.find(temp) != mpp.end()){
                return temp; // if temp found in 1st list through hashmap then return temp as that is the intersection point
            }
            temp = temp -> next;
        }
        return NULL; // if nothing is true return NULL
    }
};

ListNode *getIntersectionNode2Pointer(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        if(temp1 == NULL || temp2 == NULL) return NULL; // 2 pointer approach, NULL returned if if either head is already NULL
        while(temp1 != temp2)
        {
            temp1 = temp1 -> next;
            temp2 = temp2 -> next; // keep traversing through respective LL
            if(temp1 == temp2) return temp1;
            if(temp1 == NULL) temp1 = headB; // move temp1 to other list's head
            if(temp2 == NULL) temp2 = headA;
        }

        return temp1; 
    }