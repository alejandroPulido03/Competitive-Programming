#
# @lc app=leetcode id=133 lang=python3
#
# [133] Clone Graph
#

# @lc code=start
"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

import queue
from typing import Optional


class Solution:

    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        newNodes = {}

        visited = set()
        stack = [node]
        while(stack):
            top = stack[-1]
            if top.val in visited:
                newNodes[top.val] = Node(top.val)
                stack.pop()
            else:
                visited.add(top.val)
                for v in top.neighbors:
                    stack.append(v)


        print(newNodes)

    
        

# @lc code=end

