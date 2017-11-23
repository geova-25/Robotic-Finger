all:libroboticFingerCon

libroboticFingerCon:
				gcc -c roboticFingerCon.c
				ar rv libroboticFingerCon.a roboticFingerCon.o
				ranlib libroboticFingerCon.a
				nm -s libroboticFingerCon.a
clean:
				rm *.a
				rm *.o
