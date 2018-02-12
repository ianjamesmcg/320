#CSE320 Project #9 Makefile
#created by mcgreg45@msu.edu
#Control translation using the make utility program

proj09: proj09.support.o /user/cse320/Projects/project09.driver.o
		gcc proj09.support.o /user/cse320/Projects/project09.driver.o -o proj09

proj09.support.o: proj09.support.s
		gcc -Wall -c proj09.support.s

