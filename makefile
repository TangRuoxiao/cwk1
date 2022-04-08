EXE = ./exe
SRC= main.c library.c librarian.c user.c utility.c book_management.c user_management.c 
CC=gcc
CFLAGS= -std=c99 -Wall
CLINK= 
OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CLINK) -o $(EXE) 

clean:
	rm -f $(OBJ) $(EXE)

main.o:      main.c library.h
library.o:   library.c user_management.h utility.h book_management.h librarian.h user.h
librarian.o: 	 librarian.c book_management.h utility.h library.h
user.o:      user.c book_management.h utility.h library.h
utility.o:   utility.c utility.h 
book_management.o: book_management.c user_management.h