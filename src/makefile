
OUT = test
OBJS = main.o
CC = g++
GL = -framework glut -framework opengl
DEBUG = -g
DEBUGGER = gdb
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(GL) $(DEBUG)

$(OUT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUT)

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

debug : $(OUT)
	$(DEBUGGER) $(OUT)

clean :
	\rm -rf *.o *.out $(OUT)

tar : $(OUT)
	tar -czvf $(OUT).tar.gz $(OUT) assets

untar : $(OUT).tar.gz
	tar -xzvf $(OUT).tar.gz

pull :
	scp phildo@phildogames.com:/var/www/html/games/ogam/mazer/$(OUT).tar.gz .

run : $(OUT)
	./$(OUT)

scratch : clean run
	
