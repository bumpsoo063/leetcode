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
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val (0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void push_bak(ListNode **n, int val) {
    if (*n == nullptr) {
        *n = new ListNode(val);
    } else {
        ListNode *t = *n;
        while (t->next) {
            t = t->next;
        }
        t->next = new ListNode(val);
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = nullptr;
        int count = 0;
	int a = 0;
        while (l1 != nullptr && l2 != nullptr) {
            a = l1->val + l2->val + count;
            if (count)
                count -= 1;
            if (a > 9) {
                a %= 10;
                count += 1;
            }
            push_bak(&ret, a);
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != nullptr) {
		a = l1->val + count;
		if (count)
			count -= 1;
		if (a > 9) {
			a %= 10;
			count += 1;
		}
		push_bak(&ret, a);
		l1 = l1->next;
        }
        while (l2 != nullptr) {
        	a = l2->val + count;
		if (count)
                	count -= 1;
		if (a > 9) {
                	a %= 10;
			count += 1;
		}
		push_bak(&ret, a);
		l2 = l2->next;
        }
	if (count)
		push_bak(&ret, count);
        return ret;
    }
};
