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
    int length(ListNode *head) {
        
        int cnt = 0;
        while(head){
            ++cnt;
            head = head->next;
        } 
        return cnt;
        
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int s1 = length(l1); 
        int s2 = length(l2);
        
        int carry = 0;
        ListNode *tl1 = l1, *tl2 = l2;
        while(tl1 && tl2){
            //add lists till one of them reaches NULL
            int sum = tl1->val + tl2->val;
            int temp = (sum+carry)%10;
            carry = (sum+carry)/10;
            if(s1 >= s2) tl1->val = temp;
            else tl2->val = temp;
            if(tl1->next == NULL && tl2->next == NULL && carry != 0){
                tl1->next = new ListNode(carry);
                tl1 = tl1->next;
            }
            tl1 = tl1->next;
            tl2 = tl2->next;
        }
        
        while(tl1){
            // L1 > L2 (in length)
            int temp = tl1->val;
            tl1->val = (tl1->val + carry)%10;
            carry = (temp + carry)/10;
            if(carry != 0 && tl1->next == NULL){
                tl1->next = new ListNode(carry);
                tl1 = tl1->next;
            }
            tl1 = tl1->next;
        }
        
        while(tl2){
            // L2 > L1 (in length) 
            int temp = tl2->val;
            tl2->val = (tl2->val + carry)%10;
            carry = (temp + carry)/10;
            if(carry != 0 && tl2->next == NULL){
                tl2->next = new ListNode(carry);
                tl2 = tl2->next;
            }
            tl2 = tl2->next;
        }
        
        if(s1 >= s2) return l1;
        else return l2;
        
    }
};
