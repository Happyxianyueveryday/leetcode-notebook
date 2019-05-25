/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// 本题的主要算法难点在于如何将给定的嵌套列表扁平化，基本的算法思想非常简单: 依次遍历整个输入的数组，若遇到的元素是一个嵌套链表，常见

class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // 1. 将数组中的嵌套列表元素依次倒序入栈
        for(int i=nestedList.size()-1;i>=0;i--)
        {
            sta.push(nestedList[i]);
        }
    }

    int next() {
        // 1. 因为题目说明了在调用next前会调用hasNext，因此可以直接获取栈顶的数字
        NestedInteger now=sta.top();
        sta.pop();

        return now.getInteger();
    }

    bool hasNext() {
        // note: 因为存在空嵌套链表的情况，因此必须将扁平化的核心算法放在hasNext处进行实现
        // 1. 循环进行以下步骤直到栈为空或者出栈的元素是数字而不是嵌套链表为止: 
        //    (1) 从栈顶出栈一个元素
        //    (2) 判断该出栈的元素是一个数字还是一个嵌套列表，若是一个数字，则直接返回
        //    (3) 若是一个嵌套列表，则依次倒序遍历该嵌套链表中的元素，并将这些元素倒序入栈
        while(sta.size()&&!sta.top().isInteger())
        {
            NestedInteger now=sta.top();
            sta.pop();
            
            vector<NestedInteger> temp=now.getList();

            for(int i=temp.size()-1;i>=0;i--)
            {
                sta.push(temp[i]);
            }
        }

        if(sta.size())
        return true;
        else
        return false;
    }

    private:
    stack<NestedInteger> sta;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */