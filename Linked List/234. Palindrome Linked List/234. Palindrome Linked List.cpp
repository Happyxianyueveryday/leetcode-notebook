/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
// 本题的算法非常经典，需要特别注意 
// 本题最常见的解法就是使用栈来进行求解，一般所使用的算法如下：
// (1) 使用快慢双指针法查找链表的中间结点，在查找过程中依次将慢指针经过的结点入栈，并对快指针经过的结点进行计数 
// (2) 若(1)中的计数结果为偶数，则从慢指针开始依次和栈顶元素比较，每比较一次，移动指针并出栈栈顶元素；若计数结果为计数，则从快指针开始依次和栈顶元素比较 
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	stack<int> sta;
    	int count=0;
    	ListNode *slow=head;
    	ListNode *fast=head;
    	
    	while(fast&&fast->next)
    	{
    		sta.push(slow->val);
    		
    		slow=slow->next;
    		fast=fast->next->next;
    		count+=2;
		}
		if(fast&&!fast->next)   // 补充计数最后的单独奇数结点，这里的计数技巧需要特别注意 
			count+=1;
			
		slow=((count%2)?slow->next:slow);
		
		while(slow)
		{
			int temp=sta.top();
			sta.pop();
			
			if(temp!=slow->val)
				return false;
			else
				slow=slow->next;
		}
		
		return true;
    }
};