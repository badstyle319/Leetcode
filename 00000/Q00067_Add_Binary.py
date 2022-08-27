import unittest


class Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a, 2) + int(b, 2))[2:]


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        # TODO: call function to get result
        result = Solution().addBinary(**data)

        self.assertEqual(result, expect)

    def test_case1(self):
        data = {'a': '11', 'b': '1'}
        expect = '100'
        self.run_test(data, expect)

    def test_case2(self):
        data = {'a': '1010', 'b': '1011'}
        expect = '10101'
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
