# top-level rule to compile the whole program.
all: nted.exe

# program is made of several source files.
nted.exe: tcpconnection.o tedprotocol.o logindialog.o chatdialog.o deckdialog.o infodialog.o dueldialog.o mainframe.o main.o nted.o
	g++ -o nted.exe main.o mainframe.o logindialog.o chatdialog.o deckdialog.o infodialog.o dueldialog.o tedprotocol.o tcpconnection.o nted.o `wx-config --libs`

main.o: main.cpp main.h
	g++ -c -o main.o -Wall -Werror `wx-config --cxxflags` main.cpp

mainframe.o: mainframe.cpp mainframe.h
	g++ -c -o mainframe.o -Wall -Werror `wx-config --cxxflags` mainframe.cpp

logindialog.o: logindialog.cpp logindialog.h
	g++ -c -o logindialog.o -Wall -Werror `wx-config --cxxflags` logindialog.cpp

chatdialog.o: chatdialog.cpp chatdialog.h
	g++ -c -o chatdialog.o -Wall -Werror `wx-config --cxxflags` chatdialog.cpp

deckdialog.o: deckdialog.cpp deckdialog.h
	g++ -c -o deckdialog.o -Wall -Werror `wx-config --cxxflags` deckdialog.cpp

infodialog.o: infodialog.cpp infodialog.h
	g++ -c -o infodialog.o -Wall -Werror `wx-config --cxxflags` infodialog.cpp

dueldialog.o: dueldialog.cpp dueldialog.h
	g++ -c -o dueldialog.o -Wall -Werror `wx-config --cxxflags` dueldialog.cpp

tedprotocol.o: tedprotocol.cpp tedprotocol.h
	g++ -c -o tedprotocol.o -Wall -Werror `wx-config --cxxflags` tedprotocol.cpp

tcpconnection.o: tcpconnection.cpp tcpconnection.h
	g++ -c -o tcpconnection.o -Wall -Werror `wx-config --cxxflags` tcpconnection.cpp

nted.o: nted.rc
	windres --include-dir=/local/include nted.rc nted.o

# rule for cleaning files generated during compilations.
clean:
	rm -f nted.exe main.o mainframe.o logindialog.o chatdialog.o deckdialog.o infodialog.o dueldialog.o tedprotocol.o tcpconnection.o nted.o

# rule for making final executable
dist: nted.exe
	strip -s -o nted-strip.exe nted.exe
	upx -9 -o nted-strip-upx.exe --compress-icons=0 nted-strip.exe
	mv nted-strip-upx.exe nted.exe

