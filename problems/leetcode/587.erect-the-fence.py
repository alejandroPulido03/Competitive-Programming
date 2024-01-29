#
# @lc app=leetcode id=587 lang=python3
#
# [587] Erect the Fence
#

# @lc code=start
class Solution(object):
    def outerTrees(self, trees):
        """
        :type trees: List[List[int]]
        :rtype: List[List[int]]
        """
        sortedTrees = sorted(trees, key=lambda coord: (coord[0], coord[1]))
        convexHull = []
        if len(sortedTrees) > 1:
            leftConv = self.outerTrees(sortedTrees[:len(sortedTrees)//2])
            rightConv = self.outerTrees(sortedTrees[len(sortedTrees)//2:])
            convexHull += self.merge(leftConv, rightConv)

        else:
            return sortedTrees

        return convexHull

    def merge(self, subConv1, subConv2):
        # sbuConvs sorted by X axis
        mid = (subConv1[-1][1] + subConv2[0][1]) / 2
        max2 = max(subConv2, key=lambda x: x[1])
        max1 = max(subConv1, key=lambda tree: (self.val_in_mid(tree, max2, mid), tree[1], 1 - tree[0]))

        min2 = min(subConv2, key=lambda x: x[1])
        min1 = min(subConv1, key=lambda tree: (self.val_in_mid(tree, min2, mid), tree[1], 1 - tree[0]))

        convMerged = [min1, min2, max1, max2]
        

        for tree in subConv1:
            if tree[0] < max1[0] or tree[0] < min1[0]:
                convMerged.append(tree)

        for tree in subConv2:
            if tree[0] > max2[0] or tree[0] > min2[0]:
                convMerged.append(tree)

        tupled_lst = set(map(tuple, convMerged))
        return map(list, tupled_lst)

    def val_in_mid(self, t1, t2, mid):
        if t2[0] - t1[0] != 0:
            if t2[1] - t1[1] == 0:
                return t1[0]
            m = (t2[1] - t1[1])/(t2[0] - t1[0])
            return mid * m + t1[1] - t1[0] * m
        return 0



        
# @lc code=end

