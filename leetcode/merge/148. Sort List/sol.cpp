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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* mid = getMid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left,right);
    }
    ListNode* merge(ListNode* list1,ListNode* list2){
        ListNode dummy(0);
        ListNode*ptr = &dummy;
        while(list1&&list2){
            if(list1->val < list2->val){
                ptr->next = list1;
                list1 = list1->next;
            }
            else{
                ptr->next = list2;
                list2 = list2->next;
            }
            ptr=ptr->next;
        }
        if(list1)ptr->next = list1;
        else ptr->next = list2;
        return dummy.next;
    }
    ListNode* getMid(ListNode* head){
        ListNode* midPrev = nullptr;
        
        while(head && head->next){
            midPrev = (midPrev==nullptr)?head:midPrev->next;
            head=head->next->next;
        }
        ListNode* mid = midPrev->next;
        midPrev->next = nullptr;
        return mid;
    }
};