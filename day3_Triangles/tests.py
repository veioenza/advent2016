import unittest

from python import part1 as d3p1
from python import part2 as d3p2

class TestDay3(unittest.TestCase):
    def test_part1(self):
        self.assertEqual(d3p1.compare("23 26 50"), 0)
        self.assertEqual(d3p1.compare("23 27 50"), 0)
        self.assertEqual(d3p1.compare("23 28 50"), 1)

    def test_part2(self):
        input_string = "101 301 501\n102 302 502\n103 303 503\n"
        input_string += "201 401 601\n202 402 602\n203 403 603\n"
        self.assertEqual(d3p2.count(input_string), 6)
        input_string = "01 01 01\n102 302 502\n103 303 503\n"
        input_string += "01 01 01\n202 402 602\n203 403 603\n"
        self.assertEqual(d3p2.count(input_string), 0)

    #To check that any future changes still give the now known solution
    def test_answers(self):
        import os
        if "day3_Triangles" in os.getcwd():
            path = "python/"
        else:
            path = "day3_Triangles/python/"
        self.assertEqual(d3p1.run(path=path), 983)
        self.assertEqual(d3p2.run(path=path), 1836)

def main():
    unittest.main()

if __name__ == "__main__":
    main()
