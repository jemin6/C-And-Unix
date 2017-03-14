gcc -std=c99 -c triangle1.c
/bin/rm -f test-triangle1 *.o && make -f g_Makefile test-triangle1
diff -y -B -b triangle1.output triangle1.master
numdiffs=`diff  -B -b triangle1.output triangle1.master | wc -l`
gcc -std=c99 -c triangle2.c
/bin/rm -f test-triangle2 *.o && make -f g_Makefile test-triangle2
./test-triangle2
diff -y -B -b triangle2.output triangle2.master
numdiffs=`diff  -B -b triangle2.output triangle2.master | wc -l`
gcc -std=c99 -c test.c
/bin/rm -f test *.o && make -f g_Makefile test
./test
diff -y -B -b test.output test.master
numdiffs=`diff  -B -b test.output test.master | wc -l`
gcc -std=c99 -c mountain.c
/bin/rm -f mountain *.o && make -f g_Makefile mountain
gcc -std=c99 -c main.c
/bin/rm -f main *.o && make -f g_Makefile main
./main
diff -y -B -b main.output main.master
numdiffs=`diff  -B -b main.output main.master | wc -l`
