import unittest


class MyQueue:
    def __init__(self):
        self.stack_in = []
        self.stack_out = []

    def push(self, x: int) -> None:
        self.stack_in.append(x)

    def pop(self) -> int:
        self.peek()
        return self.stack_out.pop()

    def peek(self) -> int:
        if not self.stack_out:
            while self.stack_in:
                self.stack_out.append(self.stack_in.pop())
        return self.stack_out[-1]

    def empty(self) -> bool:
        return not len(self.stack_in) and not len(self.stack_out)


class TestResult(unittest.TestCase):
    def run_test(self, data, expect):
        obj = MyQueue()
        for i, cmd in enumerate(data['op'][1:]):
            func = getattr(obj, cmd)
            args = data['val'][1:][i]
            result = func(args[0]) if args else func()
            self.assertEqual(result, expect[1:][i])

    def test_case1(self):
        data = {'op': ["MyQueue", "push", "push", "peek", "pop", "empty"],
                'val': [[], [1], [2], [], [], []]}
        expect = [None, None, None, 1, 1, False]
        self.run_test(data, expect)


if __name__ == "__main__":
    unittest.main()
