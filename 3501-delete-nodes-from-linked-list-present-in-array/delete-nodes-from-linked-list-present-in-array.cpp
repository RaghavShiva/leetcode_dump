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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* node=new ListNode();
        ListNode* t= node;
        sort(nums.begin(),nums.end());
        while(head){
            auto it = upper_bound(nums.begin(),nums.end(),head->val)-nums.begin();
            if(it==0 || nums[it-1]!=head->val){
                node->next=new ListNode(head->val);
                node=node->next;
            }
            head=head->next;
        }
        
        return t->next;
    }
};