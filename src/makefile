
OUT = test
OBJS = main.o
CC = g++
DEBUG = -g
DEBUGGER = gdb
CFLAGS = -Wall -c `pkg-config --cflags glfw3` $(DEBUG)
LFLAGS = -Wall -v `pkg-config --static --libs glfw3` $(DEBUG)

$(OUT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUT)

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

debug : $(OUT)
	$(DEBUGGER) $(OUT)

clean :
	\rm -rf *.o *.out $(OUT)

tar : $(OUT)
	tar -czvf $(OUT).tar.gz $(OUT)

untar : $(OUT).tar.gz
	tar -xzvf $(OUT).tar.gz

pull :
	scp phildo@phildogames.com:/var/www/html/games/ogam/mazer/$(OUT).tar.gz .

run : $(OUT)
	./$(OUT)

scratch : clean run
	
