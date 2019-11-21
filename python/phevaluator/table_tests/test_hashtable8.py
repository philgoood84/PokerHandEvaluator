import unittest

from table_tests.utils import BaseTestNoFlushTable
from evaluator.hashtable8 import NO_FLUSH_8

class TestNoFlush8Table(BaseTestNoFlushTable):
  TOCOMPARE = NO_FLUSH_8
  TABLE = [0] * len(TOCOMPARE)
  VISIT = [0] * len(TOCOMPARE)
  NUM_CARDS = 8

  def test_noflush8_table(self):
    self.assertListEqual(self.TABLE, self.TOCOMPARE)

if __name__ == "__main__":
  unittest.main()
