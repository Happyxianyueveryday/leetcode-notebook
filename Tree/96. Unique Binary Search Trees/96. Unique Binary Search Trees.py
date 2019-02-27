
# 本题属于卡特兰数的相关题目，主要是含有n个结点的二叉搜索树的种类问题，本算法需要非常熟悉，具体解题算法思路如下所示
# 1. n个结点的二叉树的结点值范围为: 1,2,...,n，首先选择一个值作为树的根节点，这里有n种选择
# 2. 对于每一种选择，计算方法如下：假设k作为树的根节点，则以k为根节点的二叉搜索树的种类=左子树的种类*右子树的种类，其中左子树的结点数为k-1，值分别为1,2,...,k-1，右子树的结点数为n-k，值分别为k+1,...,n

class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        res=[0 for i in range(n+1)]
        res[0]=1
        res[1]=1

        for i in range(2,n+1):
            for k in range(i):
                res[i]+=res[k]*res[i-1-k]
        
        return res[n]