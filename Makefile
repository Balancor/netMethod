CC=gcc
SRC= \
    GetWebPage.c

target:$(SRC)
	$(CC) -g $(SRC) -o target
