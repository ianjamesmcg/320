#CSE320 Project#5 Makefile
#mcgreg45
#Control translation using the make utility program

proj06: proj06.driver.o proj06.support.o
								gcc proj06.driver.o proj06.support.o -o proj06

proj05.driver.o: proj06.driver.c /user/cse320/Projects/project06.support.h 
								gcc -Wall -c proj06.driver.c

proj05.support.o: proj06.support.c /user/cse320/Projects/project06.support.h
								gcc -Wall -c proj06.support.c
