
// 用栈验证二叉树的前序遍历的正确性是非常经典的二叉树习题，需要特别注意

// 本题的算法基本步骤为: 因为前序遍历的序列中根结点在前而子结点在后，因此需要倒序进行处理，依次将输出序列中的结点倒序入栈，若当前结点为空结点，则直接入栈；若当前结点为非空结点，则从栈中出栈两个结点(出栈的两个结点就是当前结点的子结点)，然后将当前结点入栈。遍历完成后，若栈中仅含有一个结点，则原遍历正确，否则原遍历不正确

class Solution {
public:
    bool isValidSerialization(string preorder) {
        // 1. 将字符串分拆为字符串数组
        vector<string> lis;
        stack<string> sta;

        int flag=0;
        string temp;

        for(int i=0;i<preorder.size();i++)
        {
            if(flag==0&&preorder[i]!=',')
            {
                temp.push_back(preorder[i]);
                flag=1;
            }
            else if(flag==1&&preorder[i]==',')
            {
                lis.push_back(temp);
                temp="";
                flag=0;
            }
            else if(flag==1&&preorder[i]!=',')
            temp.push_back(preorder[i]);
        }
        lis.push_back(temp);
        
        // 2. 正式使用算法进行处理和判断
        for(int i=lis.size()-1;i>=0;i--)                
        {
            if(lis[i]=="#")
            sta.push(lis[i]);
            else if(lis[i]==",")
            continue;
            else
            {
                if(sta.size()>=2)
                {
                    sta.pop();
                    sta.pop();
                    sta.push(lis[i]);
                }
                else
                return false;
            }
        }

        if(sta.size()==1)
        return true;
        else
        return false;
    }
};