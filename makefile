SRCDIR = src
ODIR = out
BINDIR = bin
OUT = $(BINDIR)/app
OBJS = $(ODIR)/main.o $(ODIR)/game.o $(ODIR)/input.o $(ODIR)/graphics.o $(ODIR)/shader.o 
CC = g++
DEBUG = -g
DEBUGGER = gdb
CFLAGS = -Wall -c `pkg-config --cflags glfw3` $(DEBUG)
LFLAGS = -Wall `pkg-config --static --libs glfw3` -framework OpenGL -lGLEW $(DEBUG)

$(OUT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUT)

$(ODIR)/main.o : $(SRCDIR)/main.cpp $(SRCDIR)/game.h $(SRCDIR)/gl_include.h
	$(CC) $(CFLAGS) $(SRCDIR)/main.cpp -o $(ODIR)/main.o

$(ODIR)/game.o : $(SRCDIR)/game.cpp $(SRCDIR)/game.h $(SRCDIR)/input.h $(SRCDIR)/graphics.h $(SRCDIR)/gl_include.h $(SRCDIR)/include.h
	$(CC) $(CFLAGS) $(SRCDIR)/game.cpp -o $(ODIR)/game.o

$(ODIR)/input.o : $(SRCDIR)/input.cpp $(SRCDIR)/input.h
	$(CC) $(CFLAGS) $(SRCDIR)/input.cpp -o $(ODIR)/input.o

$(ODIR)/graphics.o : $(SRCDIR)/graphics.cpp $(SRCDIR)/graphics.h $(SRCDIR)/shader.h $(SRCDIR)/gl_include.h $(SRCDIR)/include.h
	$(CC) $(CFLAGS) $(SRCDIR)/graphics.cpp -o $(ODIR)/graphics.o

$(ODIR)/shader.o : $(SRCDIR)/shader.cpp $(SRCDIR)/shader.h $(SRCDIR)/gl_include.h $(SRCDIR)/include.h
	$(CC) $(CFLAGS) $(SRCDIR)/shader.cpp -o $(ODIR)/shader.o

debug : $(OUT)
	$(DEBUGGER) $(OUT)

clean : 
	\rm -rf $(ODIR)/*.o $(OUT)

run : $(OUT)
	$(OUT)

scratch : clean run
	
