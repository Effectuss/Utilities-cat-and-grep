LEAK_CHECK="valgrind --leak-check=full -s -q"

cat --number-nonblank Makefile > txt1.txt && $LEAK_CHECK ./cat --number-nonblank Makefile > txt2.txt && diff -s txt1.txt txt2.txt
cat --number Makefile > txt1.txt && $LEAK_CHECK ./cat --number Makefile > txt2.txt && diff -s txt1.txt txt2.txt
cat --squeeze-blank Makefile > txt1.txt && $LEAK_CHECK ./cat --squeeze-blank Makefile > txt2.txt && diff -s txt1.txt txt2.txt
cat -E Makefile > txt1.txt && $LEAK_CHECK ./cat -E Makefile > txt2.txt && diff -s txt1.txt txt2.txt
cat -T Makefile > txt1.txt && $LEAK_CHECK ./cat -T Makefile > txt2.txt && diff -s txt1.txt txt2.txt

cat --number-nonblank check.txt  > txt3.txt && $LEAK_CHECK ./cat --number-nonblank check.txt  > txt4.txt && diff -s txt3.txt txt4.txt
cat --number check.txt  > txt3.txt && $LEAK_CHECK ./cat --number check.txt  > txt4.txt && diff -s txt3.txt txt4.txt
cat --squeeze-blank check.txt  > txt3.txt && $LEAK_CHECK ./cat --squeeze-blank check.txt > txt4.txt && diff -s txt3.txt txt4.txt
cat -E check.txt  > txt3.txt && $LEAK_CHECK ./cat -E check.txt  > txt4.txt && diff -s txt3.txt txt4.txt
cat -T check.txt > txt3.txt && $LEAK_CHECK ./cat -T check.txt > txt4.txt && diff -s txt3.txt txt4.txt

cat --number-nonblank ewe.txt  > txt5.txt && $LEAK_CHECK ./cat --number-nonblank ewe.txt  > txt6.txt && diff -s txt5.txt txt6.txt
cat --number ewe.txt  > txt5.txt && $LEAK_CHECK ./cat --number ewe.txt  > txt6.txt && diff -s txt5.txt txt6.txt
cat --squeeze-blank ewe.txt > txt5.txt && $LEAK_CHECK ./cat --squeeze-blank ewe.txt > txt6.txt && diff -s txt5.txt txt6.txt
cat -E ewe.txt  > txt5.txt && $LEAK_CHECK ./cat -E ewe.txt  > txt6.txt && diff -s txt5.txt txt6.txt
cat -T ewe.txt  > txt5.txt && $LEAK_CHECK ./cat -T ewe.txt > txt6.txt && diff -s txt5.txt txt6.txt