proj08: proj08.driver.o proj08.support.o
					gcc proj08.driver.o proj08.support.o -o proj08

proj08.driver.o: proj08.driver.c /user/cse320/Projects/project08.support.h
					gcc -Wall -c -march=native proj08.driver.c

proj08.support.o: proj08.support.s /user/cse320/Projects/project08.support.h
									gcc -Wall -c -march=native proj08.support.s
