#CSE320 Project#5 Makefile
#mcgreg45
#Control translation using the make utility program

runProject5: proj05.driver.o proj05.support.o
				gcc proj05.driver.o proj05.support.o -o runProject5

proj05.driver.o: proj05.driver.c /user/cse320/Projects/project05.support.h 
				gcc -Wall -c proj05.driver.c

proj05.dupport.o: proj05.support.c /user/cse320/Projects/project05.support.h
				gcc -Wall -c proj05.support.c

