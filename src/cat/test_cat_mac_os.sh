LEAK_CHECK=

cat Makefile > txt1.txt && $LEAK_CHECK ./cat Makefile > txt2.txt && diff -s txt1.txt txt2.txt
cat -b Makefile > txt1.txt && $LEAK_CHECK ./cat -b Makefile > txt2.txt && diff -s txt1.txt txt2.txt
cat -e Makefile > txt1.txt && $LEAK_CHECK ./cat -e Makefile > txt2.txt && diff -s txt1.txt txt2.txt
cat -n Makefile > txt1.txt && $LEAK_CHECK ./cat -n Makefile > txt2.txt && diff -s txt1.txt txt2.txt
cat -s Makefile > txt1.txt && $LEAK_CHECK ./cat -s Makefile > txt2.txt && diff -s txt1.txt txt2.txt
cat -t Makefile > txt1.txt && $LEAK_CHECK ./cat -t Makefile > txt2.txt && diff -s txt1.txt txt2.txt
cat -v Makefile > txt1.txt && $LEAK_CHECK ./cat -v Makefile > txt2.txt && diff -s txt1.txt txt2.txt

cat check.txt > txt3.txt && $LEAK_CHECK ./cat check.txt > txt4.txt && diff -s txt3.txt txt4.txt
cat -b check.txt  > txt3.txt && $LEAK_CHECK ./cat -b check.txt  > txt4.txt && diff -s txt3.txt txt4.txt
cat -e check.txt  > txt3.txt && $LEAK_CHECK ./cat -e check.txt  > txt4.txt && diff -s txt3.txt txt4.txt
cat -n check.txt  > txt3.txt && $LEAK_CHECK ./cat -n check.txt > txt4.txt && diff -s txt3.txt txt4.txt
cat -s check.txt  > txt3.txt && $LEAK_CHECK ./cat -s check.txt  > txt4.txt && diff -s txt3.txt txt4.txt
cat -t check.txt  > txt3.txt && $LEAK_CHECK ./cat -t check.txt > txt4.txt && diff -s txt3.txt txt4.txt
cat -v check.txt > txt3.txt && $LEAK_CHECK ./cat -v check.txt > txt4.txt && diff -s txt3.txt txt4.txt

cat ewe.txt > txt5.txt && $LEAK_CHECK ./cat ewe.txt > txt6.txt && diff -s txt5.txt txt6.txt
cat -b ewe.txt  > txt5.txt && $LEAK_CHECK ./cat -b ewe.txt  > txt6.txt && diff -s txt5.txt txt6.txt
cat -e ewe.txt  > txt5.txt && $LEAK_CHECK ./cat -e ewe.txt  > txt6.txt && diff -s txt5.txt txt6.txt
cat -n ewe.txt > txt5.txt && $LEAK_CHECK ./cat -n ewe.txt > txt6.txt && diff -s txt5.txt txt6.txt
cat -s ewe.txt  > txt5.txt && $LEAK_CHECK ./cat -s ewe.txt  > txt6.txt && diff -s txt5.txt txt6.txt
cat -t ewe.txt  > txt5.txt && $LEAK_CHECK ./cat -t ewe.txt > txt6.txt && diff -s txt5.txt txt6.txt
cat -v ewe.txt > txt5.txt && $LEAK_CHECK ./cat -v ewe.txt> txt6.txt && diff -s txt5.txt txt6.txt