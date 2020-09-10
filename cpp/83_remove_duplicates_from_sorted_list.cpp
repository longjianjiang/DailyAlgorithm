#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

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

// 给定链表，要求删除出现超过一次的节点中重复的。
// 和82类似，使用三个指针，first和second从head开始，third是指向重复的最后一个节点；
// 区别是，每次删除重复的以后，需要移动first，这样可以保证一定会存在一个节点；
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if (!head || !head->next) { return head; }
    
	    ListNode *first = head;
	    ListNode *second = head;
	    ListNode *third = NULL;
	    
	    int val = 0;
	    while (second) {
	        val = second->val;
	        auto nextNode = second->next;
	        if (!nextNode) { break; }
	        
	        if (nextNode->val == val) {
	            third = nextNode;
	        } else {
	            if (third) {
	                first->next = third->next;
	                third = NULL;
	                first = first->next;
	            } else {
	                first = nextNode;
	            }
	        }
	        second = nextNode;
	    }
	    if (third) { first->next = third->next; }
	    return head;
    }
};
