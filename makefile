SRCDIR = src
TESTDIR = tests
ODIR = out
BINDIR = bin
OUT = $(BINDIR)/app
TOUT = $(BINDIR)/test
OBJS = $(ODIR)/main.o $(ODIR)/game.o $(ODIR)/mygl.o $(ODIR)/input.o $(ODIR)/graphics.o $(ODIR)/entity_system.o $(ODIR)/entity_pool.o $(ODIR)/entity_factory.o $(ODIR)/basic_entity_factory.o $(ODIR)/entity.o $(ODIR)/component.o $(ODIR)/physics_component.o $(ODIR)/render_component.o
TESTS = $(ODIR)/tests.o $(ODIR)/fixed_vector_test.o
CC = g++
DEBUG = -g
DEBUGGER = gdb
CFLAGS = -Wall -c `pkg-config --cflags glfw3` $(DEBUG)
LFLAGS = -Wall `pkg-config --static --libs glfw3` -framework OpenGL -lGLEW $(DEBUG)

$(OUT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUT)

$(ODIR)/main.o : $(SRCDIR)/main.cpp $(SRCDIR)/game.h
	$(CC) $(CFLAGS) $(SRCDIR)/main.cpp -o $(ODIR)/main.o

$(ODIR)/game.o : $(SRCDIR)/game.cpp $(SRCDIR)/game.h $(SRCDIR)/mygl.h $(SRCDIR)/input.h $(SRCDIR)/graphics.h $(SRCDIR)/entity_system.h $(SRCDIR)/basic_entity_factory.h
	$(CC) $(CFLAGS) $(SRCDIR)/game.cpp -o $(ODIR)/game.o

$(ODIR)/mygl.o : $(SRCDIR)/mygl.cpp $(SRCDIR)/mygl.h $(SRCDIR)/gl_include.h
	$(CC) $(CFLAGS) $(SRCDIR)/mygl.cpp -o $(ODIR)/mygl.o

$(ODIR)/input.o : $(SRCDIR)/input.cpp $(SRCDIR)/input.h $(SRCDIR)/mygl.h
	$(CC) $(CFLAGS) $(SRCDIR)/input.cpp -o $(ODIR)/input.o

$(ODIR)/graphics.o : $(SRCDIR)/graphics.cpp $(SRCDIR)/graphics.h $(SRCDIR)/mygl.h
	$(CC) $(CFLAGS) $(SRCDIR)/graphics.cpp -o $(ODIR)/graphics.o

$(ODIR)/entity_system.o : $(SRCDIR)/entity_system.cpp $(SRCDIR)/entity_system.h $(SRCDIR)/entity_pool.h $(SRCDIR)/entity_factory.h 
	$(CC) $(CFLAGS) $(SRCDIR)/entity_system.cpp -o $(ODIR)/entity_system.o

$(ODIR)/entity_pool.o : $(SRCDIR)/entity_pool.cpp $(SRCDIR)/entity_pool.h $(SRCDIR)/entity.h $(SRCDIR)/physics_component.h $(SRCDIR)/render_component.h
	$(CC) $(CFLAGS) $(SRCDIR)/entity_pool.cpp -o $(ODIR)/entity_pool.o

$(ODIR)/entity_factory.o : $(SRCDIR)/entity_factory.cpp $(SRCDIR)/entity_factory.h $(SRCDIR)/entity_pool.h $(SRCDIR)/entity.h $(SRCDIR)/component.h
	$(CC) $(CFLAGS) $(SRCDIR)/entity_factory.cpp -o $(ODIR)/entity_factory.o

$(ODIR)/basic_entity_factory.o : $(SRCDIR)/basic_entity_factory.cpp $(SRCDIR)/basic_entity_factory.h $(SRCDIR)/entity_factory.h $(SRCDIR)/entity_pool.h $(SRCDIR)/entity.h $(SRCDIR)/component.h
	$(CC) $(CFLAGS) $(SRCDIR)/basic_entity_factory.cpp -o $(ODIR)/basic_entity_factory.o

$(ODIR)/entity.o : $(SRCDIR)/entity.cpp $(SRCDIR)/entity.h
	$(CC) $(CFLAGS) $(SRCDIR)/entity.cpp -o $(ODIR)/entity.o

$(ODIR)/component.o : $(SRCDIR)/component.cpp $(SRCDIR)/component.h
	$(CC) $(CFLAGS) $(SRCDIR)/component.cpp -o $(ODIR)/component.o

$(ODIR)/physics_component.o : $(SRCDIR)/physics_component.cpp $(SRCDIR)/physics_component.h $(SRCDIR)/component.h
	$(CC) $(CFLAGS) $(SRCDIR)/physics_component.cpp -o $(ODIR)/physics_component.o

$(ODIR)/render_component.o : $(SRCDIR)/render_component.cpp $(SRCDIR)/render_component.h $(SRCDIR)/component.h
	$(CC) $(CFLAGS) $(SRCDIR)/render_component.cpp -o $(ODIR)/render_component.o

debug : $(OUT)
	$(DEBUGGER) $(OUT)

clean : 
	\rm -rf $(ODIR)/*.o $(OUT)

go : $(OUT)
	$(OUT)

scratch : clean go
	

test: $(TOUT)
	

rtest : $(TOUT)
	$(TOUT)

$(TOUT): $(TESTS)
	$(CC) $(LFLAGS) $(TESTS) -o $(TOUT)

$(ODIR)/tests.o : $(TESTDIR)/tests.cpp
	$(CC) $(CFLAGS) $(TESTDIR)/tests.cpp -o $(ODIR)/tests.o

