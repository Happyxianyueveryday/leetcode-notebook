class Solution {
public:
    /*
 * decodeString: 字符串解码
 * note: 本题中的字符串解码同样是使用栈来进行实现
 *       具体的算法步骤为: 首先先将原始字符串分割为字符串数组，然后顺序遍历整个字符串数组: 
 *       (1) 若当前元素为数字或字母，则直接将当前元素入栈
 *       (2) 若当前元素为左括号，则直接将当前元素入栈
 *       (3) 若当前元素为右括号，则不断出栈元素并拼接为一个字符串str，直到栈顶元素为左括号为止，左括号出栈但是不输出，然后再不断出栈元素并拼接为一个数字num，直到栈顶元素不为数字时停止，将前面的字符串str重复num次即可, 最后再将重复得到的结果入栈 
 *       上述的算法步骤可以简单使用一个例子进行模拟，例如3[a12[bcd]] 
*/
string decodeString(string s) 
{
	// 0. 处理特殊情况 
	if(s=="")
	return s;
	
	stack<char> sta;
	
	// 1. 依次遍历并处理整个输入字符串 
	for(int i=0;i<s.size();i++)
	{
		// 1.1 若当前元素是左括号，则直接入栈 
		if(s[i]=='[')     	
		sta.push(s[i]);
		
		// 1.2 若当前元素为右括号，执行如下的三步
		// (1) 从栈中不断出栈元素，并将出栈的元素拼接为一个字符串str，直到栈顶元素为左括号为止 
		// (2) 将栈顶的左括号出栈，但是不拼接到字符串str上 
		// (3) 再从栈中不断出栈元素，并将出栈的元素拼接为一个整数num，直到栈顶元素不为数组为止
		// (4) 将上述步骤中得到的字符串str重复num次，并将重复的结果逐个字母入栈 
		else if(s[i]==']')
		{
			string str;
			while(sta.top()!='[')
			{
				str.insert(0, 1, sta.top());
				sta.pop();
			}
			
			sta.pop();
			
			int num=0;
			int exp=0;
			while(sta.size()&&sta.top()>='0'&&sta.top()<='9')
			{
				num+=(sta.top()-'0')*pow(10, exp);   // 注意，char的'0'直接隐式转换为int是ASCII值48，因此需要先减去48（即'0）后再隐式转换为int才能得到正确的结果 
				exp+=1;
				sta.pop();
			}
			
			string tempres;
			for(int k=0;k<num;k++)
			{
				tempres+=str;
			}
			for(int k=0;k<tempres.size();k++)     
			{
				sta.push(tempres[k]);
			}
		}
		
		// 1.3 若当前元素是数字或者字母，则直接入栈 
		else
		sta.push(s[i]);
	}
	
	string res;
	
	while(sta.size())
	{
		res.insert(0, 1, sta.top());
		sta.pop();
	}
	
	return res;
}
};
