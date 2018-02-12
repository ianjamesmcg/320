#CSE320 Project#7 Makefile
#Ian McGregor
#Control translation using the make utility program

proj07: proj07.student.o
						gcc proj07.student.o -o proj07

proj07.student.o: proj07.student.s
						gcc -Wall -c proj07.student.s
