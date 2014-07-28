CC=gcc
SRC= \
    Main.cpp \
    ApplicationLayerProtocls.h \
    UrlParser.cpp \
    UrlParser.h

target:$(SRC)
	$(CC) -g $(SRC) -o target
