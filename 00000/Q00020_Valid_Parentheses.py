import unittest


class Solution:
    def isValid(self, s: str) -> bool:
        stack, pairs = [], (('(', ')'), ('{', '}'), ('[', ']'))

        for ch in s:
            if ch in '({[':
                stack.append(ch)
            else:
                if len(stack) > 0 and (stack[-1], ch) in pairs:
                    stack.pop()
                else:
                    return False

        return len(stack) == 0


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        result = Solution().isValid(data)

        self.assertEqual(result, expect)

    def test_case1(self):
        data = "()"
        expect = True
        self.run_test(data, expect)

    def test_case2(self):
        data = "()[]{}"
        expect = True
        self.run_test(data, expect)

    def test_case3(self):
        data = "(]"
        expect = False
        self.run_test(data, expect)

    def test_case4(self):
        data = "{[]}"
        expect = True
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
