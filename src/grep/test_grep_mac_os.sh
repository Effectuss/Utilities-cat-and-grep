grep "a" Makefile test_grep.txt > txt1.txt && ./grep "a" Makefile test_grep.txt > txt2.txt && diff -s txt1.txt txt2.txt
grep -e "[ap]" Makefile test_grep.txt > txt1.txt && ./grep -e "[ap]" Makefile test_grep.txt > txt2.txt && diff -s txt1.txt txt2.txt
grep -i "P" Makefile test_grep.txt > txt1.txt && ./grep -i "P" Makefile test_grep.txt > txt2.txt && diff -s txt1.txt txt2.txt
grep -v "M" Makefile test_grep.txt > txt1.txt && ./grep -v "M" Makefile test_grep.txt > txt2.txt && diff -s txt1.txt txt2.txt
grep -c "." Makefile test_grep.txt > txt1.txt && ./grep -c "." Makefile test_grep.txt > txt2.txt && diff -s txt1.txt txt2.txt
grep -l "a" Makefile test_grep.txt > txt1.txt && ./grep -l "a" Makefile test_grep.txt > txt2.txt && diff -s txt1.txt txt2.txt
grep -n "21" Makefile test_grep.txt > txt1.txt && ./grep -n "21" Makefile test_grep.txt > txt2.txt && diff -s txt1.txt txt2.txt
grep -h "." Makefile test_grep.txt > txt1.txt && ./grep -h "." Makefile test_grep.txt > txt2.txt && diff -s txt1.txt txt2.txt
grep -s "21" Makefile test_grep.txt > txt1.txt && ./grep -s "21" Makefile test_grep.txt > txt2.txt && diff -s txt1.txt txt2.txt
grep -o "a" Makefile test_grep.txt > txt1.txt && ./grep -o "a" Makefile test_grep.txt > txt2.txt && diff -s txt1.txt txt2.txt

grep "[ap]" Makefile  > txt1.txt && ./grep "[ap]" Makefile > txt2.txt && diff -s txt1.txt txt2.txt
grep -e "[ap]" Makefile  > txt1.txt && ./grep -e "[ap]" Makefile > txt2.txt && diff -s txt1.txt txt2.txt
grep -i "P" Makefile  > txt1.txt && ./grep -i "P" Makefile  > txt2.txt && diff -s txt1.txt txt2.txt
grep -v "M" Makefile  > txt1.txt && ./grep -v "M" Makefile  > txt2.txt && diff -s txt1.txt txt2.txt
grep -c "." Makefile  > txt1.txt && ./grep -c "." Makefile  > txt2.txt && diff -s txt1.txt txt2.txt
grep -l "a" Makefile  > txt1.txt && ./grep -l "a" Makefile  > txt2.txt && diff -s txt1.txt txt2.txt
grep -n "21" Makefile > txt1.txt && ./grep -n "21" Makefile  > txt2.txt && diff -s txt1.txt txt2.txt
grep -h "." Makefile  > txt1.txt && ./grep -h "." Makefile  > txt2.txt && diff -s txt1.txt txt2.txt
grep -s "21" Makefile  > txt1.txt && ./grep -s "21" Makefile  > txt2.txt && diff -s txt1.txt txt2.txt
grep -o "[al]" Makefile > txt1.txt && ./grep -o "[al]" Makefile > txt2.txt && diff -s txt1.txt txt2.txt

grep -f f_flag.txt Makefile test_grep.txt > txt1.txt && ./grep -f f_flag.txt Makefile test_grep.txt > txt2.txt && diff -s txt1.txt txt2.txt
grep -f f_flag.txt Makefile > txt1.txt && ./grep -f f_flag.txt Makefile > txt2.txt && diff -s txt1.txt txt2.txt
grep -f f_flag.txt Makefile test_grep.txt > txt1.txt && ./grep -f f_flag.txt Makefile test_grep.txt > txt2.txt && diff -s txt1.txt txt2.txt