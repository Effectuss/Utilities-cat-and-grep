LEAK_CHECK="valgrind --leak-check=full -s -q"

echo "cat --number-nonblank Makefile > txt1.txt && $LEAK_CHECK ./s21_cat --number-nonblank Makefile > txt2.txt && diff txt1.txt txt2.txt"
echo "cat --number Makefile > txt1.txt && $LEAK_CHECK ./s21_cat --number Makefile > txt2.txt && diff txt1.txt txt2.txt"
echo "cat --squeeze-blank Makefile > txt1.txt && $LEAK_CHECK ./s21_cat --squeeze-blank Makefile > txt2.txt && diff txt1.txt txt2.txt"
echo "cat -E Makefile > txt1.txt && $LEAK_CHECK ./s21_cat -E Makefile > txt2.txt && diff txt1.txt txt2.txt"
echo "cat -T Makefile > txt1.txt && $LEAK_CHECK ./s21_cat -T Makefile > txt2.txt && diff txt1.txt txt2.txt"

echo "cat --number-nonblank check.txt  > txt3.txt && $LEAK_CHECK ./s21_cat --number-nonblank check.txt  > txt4.txt && diff txt3.txt txt4.txt"
echo "cat --number check.txt  > txt3.txt && $LEAK_CHECK ./s21_cat --number check.txt  > txt4.txt && diff txt3.txt txt4.txt"
echo "cat --squeeze-blank check.txt  > txt3.txt && $LEAK_CHECK ./s21_cat --squeeze-blank check.txt > txt4.txt && diff txt3.txt txt4.txt"
echo "cat -E check.txt  > txt3.txt && $LEAK_CHECK ./s21_cat -E check.txt  > txt4.txt && diff txt3.txt txt4.txt"
echo "cat -T check.txt > txt3.txt && $LEAK_CHECK ./s21_cat -T check.txt > txt4.txt && diff txt3.txt txt4.txt"

echo "cat --number-nonblank ewe.txt  > txt5.txt && $LEAK_CHECK ./s21_cat --number-nonblank ewe.txt  > txt6.txt && diff txt5.txt txt6.txt"
echo "cat --number ewe.txt  > txt5.txt && $LEAK_CHECK ./s21_cat --number ewe.txt  > txt6.txt && diff txt5.txt txt6.txt"
echo "cat --squeeze-blank ewe.txt > txt5.txt && $LEAK_CHECK ./s21_cat --squeeze-blank ewe.txt > txt6.txt && diff txt5.txt txt6.txt"
echo "cat -E ewe.txt  > txt5.txt && $LEAK_CHECK ./s21_cat -E ewe.txt  > txt6.txt && diff txt5.txt txt6.txt"
echo "cat -T ewe.txt  > txt5.txt && $LEAK_CHECK ./s21_cat -T ewe.txt > txt6.txt && diff txt5.txt txt6.txt"