SRCDIR = src
TESTDIR = tests
ODIR = out
BINDIR = bin
OUT = $(BINDIR)/app
TOUT = $(BINDIR)/test
TESTS = $(ODIR)/tests.o $(ODIR)/fixed_vector_test.o
CC = g++
DEBUG = -g
DEBUGGER = gdb
CFLAGS = -Wall -c `pkg-config --cflags glfw3` $(DEBUG)
LFLAGS = -Wall `pkg-config --static --libs glfw3` -framework OpenGL -lGLEW $(DEBUG)

makemake : 
	makemake $(SRCDIR)/*.cpp

tags : 
	cd $(SRCDIR); ctags $(SRCDIR)/*.cpp

#MAKEMAKE<
OBJS=$(ODIR)/FLAT_utils.o $(ODIR)/basic_entity_factory.o $(ODIR)/basic_reconciler.o $(ODIR)/basic_solver.o $(ODIR)/camera.o $(ODIR)/entity.o $(ODIR)/entity_pool.o $(ODIR)/entity_system.o $(ODIR)/game.o $(ODIR)/graphics.o $(ODIR)/input.o $(ODIR)/main.o $(ODIR)/mygl.o $(ODIR)/physics_component.o $(ODIR)/render_component.o $(ODIR)/scener.o $(ODIR)/world_renderer.o 

$(OUT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUT)

$(ODIR)/FLAT_utils.o: src/FLAT_utils.cpp src/FLAT_utils.h
	$(CC) $(CFLAGS) src/FLAT_utils.cpp -o $(ODIR)/FLAT_utils.o

$(ODIR)/basic_entity_factory.o: src/basic_entity_factory.cpp src/basic_entity_factory.h src/entity_factory.h src/entity.h src/entity_pool.h src/render_component.h src/gl_include.h src/physics_component.h src/FLAT_utils.h
	$(CC) $(CFLAGS) src/basic_entity_factory.cpp -o $(ODIR)/basic_entity_factory.o

$(ODIR)/basic_reconciler.o: src/basic_reconciler.cpp src/basic_reconciler.h src/entity.h src/entity_pool.h src/render_component.h src/gl_include.h src/physics_component.h
	$(CC) $(CFLAGS) src/basic_reconciler.cpp -o $(ODIR)/basic_reconciler.o

$(ODIR)/basic_solver.o: src/basic_solver.cpp src/basic_solver.h src/camera.h src/gl_include.h src/physics_component.h
	$(CC) $(CFLAGS) src/basic_solver.cpp -o $(ODIR)/basic_solver.o

$(ODIR)/camera.o: src/camera.cpp src/camera.h src/gl_include.h
	$(CC) $(CFLAGS) src/camera.cpp -o $(ODIR)/camera.o

$(ODIR)/entity.o: src/entity.cpp src/entity.h
	$(CC) $(CFLAGS) src/entity.cpp -o $(ODIR)/entity.o

$(ODIR)/entity_pool.o: src/entity_pool.cpp src/entity_pool.h src/entity.h src/render_component.h src/gl_include.h src/physics_component.h
	$(CC) $(CFLAGS) src/entity_pool.cpp -o $(ODIR)/entity_pool.o

$(ODIR)/entity_system.o: src/entity_system.cpp src/entity_system.h src/entity_factory.h src/entity_pool.h src/entity.h src/render_component.h src/gl_include.h src/physics_component.h src/basic_solver.h src/camera.h src/basic_reconciler.h src/world_renderer.h src/mygl.h
	$(CC) $(CFLAGS) src/entity_system.cpp -o $(ODIR)/entity_system.o

$(ODIR)/game.o: src/game.cpp src/game.h src/basic_entity_factory.h src/entity_factory.h src/mygl.h src/gl_include.h src/input.h src/graphics.h src/entity_system.h src/scener.h
	$(CC) $(CFLAGS) src/game.cpp -o $(ODIR)/game.o

$(ODIR)/graphics.o: src/graphics.cpp src/graphics.h src/mygl.h src/gl_include.h
	$(CC) $(CFLAGS) src/graphics.cpp -o $(ODIR)/graphics.o

$(ODIR)/input.o: src/input.cpp src/input.h src/mygl.h src/gl_include.h
	$(CC) $(CFLAGS) src/input.cpp -o $(ODIR)/input.o

$(ODIR)/main.o: src/main.cpp src/game.h
	$(CC) $(CFLAGS) src/main.cpp -o $(ODIR)/main.o

$(ODIR)/mygl.o: src/mygl.cpp src/mygl.h src/gl_include.h
	$(CC) $(CFLAGS) src/mygl.cpp -o $(ODIR)/mygl.o

$(ODIR)/physics_component.o: src/physics_component.cpp src/physics_component.h
	$(CC) $(CFLAGS) src/physics_component.cpp -o $(ODIR)/physics_component.o

$(ODIR)/render_component.o: src/render_component.cpp src/render_component.h src/gl_include.h
	$(CC) $(CFLAGS) src/render_component.cpp -o $(ODIR)/render_component.o

$(ODIR)/scener.o: src/scener.cpp src/scener.h
	$(CC) $(CFLAGS) src/scener.cpp -o $(ODIR)/scener.o

$(ODIR)/world_renderer.o: src/world_renderer.cpp src/world_renderer.h src/mygl.h src/gl_include.h src/camera.h src/render_component.h src/FLAT_utils.h
	$(CC) $(CFLAGS) src/world_renderer.cpp -o $(ODIR)/world_renderer.o

#MAKEMAKE>

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

