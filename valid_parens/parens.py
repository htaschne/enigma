#!/usr/local/bin/pypy3

from typing import List

class Solution:
  def isValid(self, s: str) -> bool:
    stack: List[str] = []
    for ch in s:
      if ch == '(' or ch == '[' or ch == '{':
        stack.append(ch)
        continue

      if len(stack) == 0:
        return False

      top: str = stack.pop()
      if top == '(' and ch != ')':
        return False
      elif top == '[' and ch != ']':
        return False
      elif top == '{' and ch != '}':
        return False

    return len(stack) == 0

source:str = input()
sol = Solution()
print(sol.isValid(source))
