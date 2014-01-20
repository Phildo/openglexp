SRCDIR = src
TESTDIR = tests
ODIR = out
BINDIR = bin
OUT = $(BINDIR)/app
TOUT = $(BINDIR)/test
#OBJS = $(ODIR)/main.o $(ODIR)/FLAT_utils.o $(ODIR)/game.o $(ODIR)/mygl.o $(ODIR)/graphics.o $(ODIR)/input.o $(ODIR)/world.o $(ODIR)/world_renderer.o
OBJS = $(ODIR)/main.o $(ODIR)/game.o
TESTS = $(ODIR)/tests.o $(ODIR)/fixed_vector_test.o
CC = g++
DEBUG = -g
DEBUGGER = gdb
CFLAGS = -Wall -c `pkg-config --cflags glfw3` $(DEBUG)
LFLAGS = -Wall `pkg-config --static --libs glfw3` -framework OpenGL -lGLEW $(DEBUG)

$(OUT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUT)

$(ODIR)/main.o : $(SRCDIR)/main.cpp $(SRCDIR)/game.h $(SRCDIR)/gl_include.h
	$(CC) $(CFLAGS) $(SRCDIR)/main.cpp -o $(ODIR)/main.o

$(ODIR)/FLAT_utils.o : $(SRCDIR)/FLAT_utils.cpp $(SRCDIR)/FLAT_utils.h
	$(CC) $(CFLAGS) $(SRCDIR)/FLAT_utils.cpp -o $(ODIR)/FLAT_utils.o

$(ODIR)/fixed_vector.o : $(SRCDIR)/fixed_vector.cpp $(SRCDIR)/fixed_vector.h
	$(CC) $(CFLAGS) $(SRCDIR)/fixed_vector.cpp -o $(ODIR)/fixed_vector.oo

#$(ODIR)/game.o : $(SRCDIR)/game.cpp $(SRCDIR)/game.h $(SRCDIR)/mygl.h $(SRCDIR)/graphics.h $(SRCDIR)/input.h $(SRCDIR)/world.h $(SRCDIR)/gl_include.h $(SRCDIR)/FLAT_include.h
$(ODIR)/game.o : $(SRCDIR)/game.cpp $(SRCDIR)/game.h
	$(CC) $(CFLAGS) $(SRCDIR)/game.cpp -o $(ODIR)/game.o

$(ODIR)/mygl.o : $(SRCDIR)/mygl.cpp $(SRCDIR)/mygl.h $(SRCDIR)/gl_include.h $(SRCDIR)/FLAT_include.h
	$(CC) $(CFLAGS) $(SRCDIR)/mygl.cpp -o $(ODIR)/mygl.o

$(ODIR)/graphics.o : $(SRCDIR)/graphics.cpp $(SRCDIR)/graphics.h $(SRCDIR)/gl_include.h $(SRCDIR)/FLAT_include.h $(SRCDIR)/FLAT_utils.h
	$(CC) $(CFLAGS) $(SRCDIR)/graphics.cpp -o $(ODIR)/graphics.o

$(ODIR)/input.o : $(SRCDIR)/input.cpp $(SRCDIR)/input.h
	$(CC) $(CFLAGS) $(SRCDIR)/input.cpp -o $(ODIR)/input.o

$(ODIR)/world.o : $(SRCDIR)/world.cpp $(SRCDIR)/world.h
	$(CC) $(CFLAGS) $(SRCDIR)/world.cpp -o $(ODIR)/world.o

$(ODIR)/world_renderer.o : $(SRCDIR)/world_renderer.cpp $(SRCDIR)/world_renderer.h $(SRCDIR)/renderer.h
	$(CC) $(CFLAGS) $(SRCDIR)/world_renderer.cpp -o $(ODIR)/world_renderer.o

debug : $(OUT)
	$(DEBUGGER) $(OUT)

clean : 
	\rm -rf $(ODIR)/*.o $(OUT)

run : $(OUT)
	$(OUT)

scratch : clean run
	

test: $(TOUT)
	

rtest : $(TOUT)
	$(TOUT)

$(TOUT): $(TESTS) $(ODIR)/fixed_vector.o
	$(CC) $(LFLAGS) $(TESTS) -o $(TOUT)

$(ODIR)/tests.o : $(TESTDIR)/tests.cpp $(TESTDIR)/fixed_vector_test.h
	$(CC) $(CFLAGS) $(TESTDIR)/tests.cpp -o $(ODIR)/tests.o

$(ODIR)/fixed_vector_test.o : $(TESTDIR)/fixed_vector_test.cpp $(TESTDIR)/fixed_vector_test.h $(SRCDIR)/fixed_vector.h
	$(CC) $(CFLAGS) $(TESTDIR)/fixed_vector_test.cpp -o $(ODIR)/fixed_vector_test.o

