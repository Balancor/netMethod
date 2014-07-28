CC=g++
SRC= \
    Main.cpp \
    UrlParser.cpp \
    UrlParser.h \
    Browser.h \
    Browser.cpp

target:$(SRC)
	$(CC) -g $(SRC) -o target
