ODR = out
OUT = $(ODR)/app
OBJS = $(ODR)/main.o $(ODR)/game.o $(ODR)/shader.o $(ODR)/graphics.o 
CC = g++
DEBUG = -g
DEBUGGER = gdb
CFLAGS = -Wall -c `pkg-config --cflags glfw3` $(DEBUG)
LFLAGS = -Wall `pkg-config --static --libs glfw3` -framework OpenGL -lGLEW $(DEBUG)

$(OUT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUT)

$(ODR)/main.o : main.cpp game.h gl_include.h
	$(CC) $(CFLAGS) main.cpp -o $(ODR)/main.o

$(ODR)/game.o : game.cpp game.h graphics.h gl_include.h
	$(CC) $(CFLAGS) game.cpp -o $(ODR)/game.o

$(ODR)/graphics.o : graphics.cpp graphics.h shader.h gl_include.h
	$(CC) $(CFLAGS) graphics.cpp -o $(ODR)/graphics.o

$(ODR)/shader.o : shader.cpp shader.h gl_include.h
	$(CC) $(CFLAGS) shader.cpp -o $(ODR)/shader.o

debug : $(OUT)
	$(DEBUGGER) $(OUT)

clean :
	\rm -rf $(ODR)/*.o $(OUT)

tar : $(OUT)
	tar -czvf $(OUT).tar.gz $(OUT)

untar : $(OUT).tar.gz
	tar -xzvf $(OUT).tar.gz

run : $(OUT)
	./$(OUT)

scratch : clean run
	
