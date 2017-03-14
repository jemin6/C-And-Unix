gcc -std=c99 -c first.c
/bin/rm -f first *.o && make -f g_Makefile first
diff -y -B -b first.output first.master
numdiffs=`diff  -B -b first.output first.master | wc -l`
gcc -std=c99 -c avg.c
/bin/rm -f avg *.o && make -f g_Makefile avg
./avg
./avg
diff -y -B -b avg.output avg.master
numdiffs=`diff  -B -b avg.output avg.master | wc -l`
gcc -std=c99 -c sticks.c
/bin/rm -f sticks *.o && make -f g_Makefile sticks
./sticks
