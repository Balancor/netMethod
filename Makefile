CC=g++
BROWSER_SRC= \
    Main.cpp \
    Browser.h \
    Browser.cpp \
    UrlParser.cpp \
    UrlParser.h \
    HostInfo.h \
    HostInfo.cpp

GET_WEB_PAGE_SRC= \
    GetWebPage.c

Browser:$(BROWSER_SRC)
	$(CC) -g $(BROWSER_SRC) -o Browser

GetWebPage:$(GET_WEB_PAGE_SRC)
	gcc -g $(GET_WEB_PAGE_SRC) -o GetWebPage
