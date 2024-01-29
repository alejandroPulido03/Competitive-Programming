#SOLVED
# @lc app=leetcode id=112 lang=python3
#
# [112] Path Sum
#

# @lc code=start
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        visited = {}
        stack = [root]  # Top in last element
        edgeTo = {root: 0}
        while len(stack) > 0:
            top = stack[-1]
            if(top != None):
                if top in visited:
                    stack.pop()
                else:
                    visited[top] = 0
                    if top.left == top.right == None:
                        if edgeTo[top] + top.val == targetSum:
                            return True
                    else:
                        for e in filter(lambda e: e != None, [top.left, top.right]):
                            if not e in visited:
                                edgeTo[e] = top.val + edgeTo[top]
                                stack.append(e)
            else:
                stack.pop(-1)
        return False

# @lc code=end

