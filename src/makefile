ODR = out
OUT = $(ODR)/app
OBJS = $(ODR)/main.o $(ODR)/game.o $(ODR)/graphics.o
CC = g++
DEBUG = -g
DEBUGGER = gdb
CFLAGS = -Wall -c `pkg-config --cflags glfw3` $(DEBUG)
LFLAGS = -Wall `pkg-config --static --libs glfw3` $(DEBUG)

$(OUT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUT)

$(ODR)/main.o : main.cpp game.h
	$(CC) $(CFLAGS) main.cpp -o $(ODR)/main.o

$(ODR)/game.o : game.cpp game.h graphics.h
	$(CC) $(CFLAGS) game.cpp -o $(ODR)/game.o

$(ODR)/graphics.o : graphics.cpp graphics.h
	$(CC) $(CFLAGS) graphics.cpp -o $(ODR)/graphics.o

debug : $(OUT)
	$(DEBUGGER) $(OUT)

clean :
	\rm -rf $(ODR)/*.o $(OUT)

tar : $(OUT)
	tar -czvf $(OUT).tar.gz $(OUT)

untar : $(OUT).tar.gz
	tar -xzvf $(OUT).tar.gz

pull :
	scp phildo@phildogames.com:/var/www/html/games/ogam/mazer/$(OUT).tar.gz .

run : $(OUT)
	./$(OUT)

scratch : clean run
	
