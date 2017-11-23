all: main

main:
				gcc main.c interpreter/interpreter.c -I ./interpreter -I ./libRoboticFingerCon -L ./libRoboticFingerCon -o main -lroboticFingerCon
clean:
				rm main
