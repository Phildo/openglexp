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

#MAKEMAKE<
OBJS=$(ODIR)/basic_entity_factory.o $(ODIR)/camera_entity_factory.o $(ODIR)/camera_component.o $(ODIR)/entity_pool.o $(ODIR)/entity_system.o $(ODIR)/models.o $(ODIR)/FLAT_utils.o $(ODIR)/game.o $(ODIR)/input.o $(ODIR)/light_entity_factory.o $(ODIR)/main.o $(ODIR)/mygl.o $(ODIR)/physics_solver.o $(ODIR)/renderer.o $(ODIR)/world_renderer.o 

$(OUT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUT)

$(ODIR)/basic_entity_factory.o: src/basic_entity_factory.cpp src/basic_entity_factory.h src/entity_system/entity_factory.h src/entity_system/entity_pool.h src/entity_system/entity.h src/entity_system/components/camera_component.h src/entity_system/components/geometry_component.h src/entity_system/components/light_component.h src/entity_system/components/spacial_component.h src/entity_system/models.h src/entity_system/model.h src/FLAT_utils.h
	$(CC) $(CFLAGS) src/basic_entity_factory.cpp -o $(ODIR)/basic_entity_factory.o

$(ODIR)/camera_entity_factory.o: src/camera_entity_factory.cpp src/camera_entity_factory.h src/entity_system/entity_factory.h src/entity_system/entity_pool.h src/entity_system/entity.h src/entity_system/components/camera_component.h src/entity_system/components/geometry_component.h src/entity_system/components/light_component.h src/entity_system/components/spacial_component.h
	$(CC) $(CFLAGS) src/camera_entity_factory.cpp -o $(ODIR)/camera_entity_factory.o

$(ODIR)/camera_component.o: src/entity_system/components/camera_component.cpp src/entity_system/components/camera_component.h src/entity_system/components/spacial_component.h src/entity_system/components/../entity.h
	$(CC) $(CFLAGS) src/entity_system/components/camera_component.cpp -o $(ODIR)/camera_component.o

$(ODIR)/entity_pool.o: src/entity_system/entity_pool.cpp src/entity_system/entity_pool.h src/entity_system/entity.h src/entity_system/components/camera_component.h src/entity_system/components/geometry_component.h src/entity_system/components/light_component.h src/entity_system/components/spacial_component.h
	$(CC) $(CFLAGS) src/entity_system/entity_pool.cpp -o $(ODIR)/entity_pool.o

$(ODIR)/entity_system.o: src/entity_system/entity_system.cpp src/entity_system/entity_system.h src/entity_system/entity_pool.h src/entity_system/entity.h src/entity_system/components/camera_component.h src/entity_system/components/geometry_component.h src/entity_system/components/light_component.h src/entity_system/components/spacial_component.h src/entity_system/entity_factory.h src/entity_system/models.h src/entity_system/model.h src/entity_system/../physics_solver.h src/entity_system/../world_renderer.h src/entity_system/../renderer.h src/entity_system/../gl_include.h
	$(CC) $(CFLAGS) src/entity_system/entity_system.cpp -o $(ODIR)/entity_system.o

$(ODIR)/models.o: src/entity_system/models.cpp src/entity_system/models.h src/entity_system/model.h src/entity_system/models/screen_quad_model.h src/entity_system/models/triangle_model.h src/entity_system/models/bilboard_model.h src/entity_system/models/cube_model.h src/entity_system/models/inv_cube_model.h
	$(CC) $(CFLAGS) src/entity_system/models.cpp -o $(ODIR)/models.o

$(ODIR)/FLAT_utils.o: src/FLAT_utils.cpp src/FLAT_utils.h
	$(CC) $(CFLAGS) src/FLAT_utils.cpp -o $(ODIR)/FLAT_utils.o

$(ODIR)/game.o: src/game.cpp src/game.h src/mygl.h src/gl_include.h src/input.h src/entity_system/entity_system.h src/basic_entity_factory.h src/entity_system/entity_factory.h src/light_entity_factory.h src/camera_entity_factory.h
	$(CC) $(CFLAGS) src/game.cpp -o $(ODIR)/game.o

$(ODIR)/input.o: src/input.cpp src/input.h src/mygl.h src/gl_include.h
	$(CC) $(CFLAGS) src/input.cpp -o $(ODIR)/input.o

$(ODIR)/light_entity_factory.o: src/light_entity_factory.cpp src/light_entity_factory.h src/entity_system/entity_factory.h src/entity_system/entity_pool.h src/entity_system/entity.h src/entity_system/components/camera_component.h src/entity_system/components/geometry_component.h src/entity_system/components/light_component.h src/entity_system/components/spacial_component.h src/FLAT_utils.h
	$(CC) $(CFLAGS) src/light_entity_factory.cpp -o $(ODIR)/light_entity_factory.o

$(ODIR)/main.o: src/main.cpp src/game.h
	$(CC) $(CFLAGS) src/main.cpp -o $(ODIR)/main.o

$(ODIR)/mygl.o: src/mygl.cpp src/mygl.h src/gl_include.h
	$(CC) $(CFLAGS) src/mygl.cpp -o $(ODIR)/mygl.o

$(ODIR)/physics_solver.o: src/physics_solver.cpp src/physics_solver.h src/entity_system/components/spacial_component.h
	$(CC) $(CFLAGS) src/physics_solver.cpp -o $(ODIR)/physics_solver.o

$(ODIR)/renderer.o: src/renderer.cpp src/renderer.h src/gl_include.h src/FLAT_utils.h
	$(CC) $(CFLAGS) src/renderer.cpp -o $(ODIR)/renderer.o

$(ODIR)/world_renderer.o: src/world_renderer.cpp src/world_renderer.h src/renderer.h src/gl_include.h src/entity_system/entity.h src/entity_system/components/camera_component.h src/entity_system/components/light_component.h src/entity_system/components/geometry_component.h src/entity_system/components/spacial_component.h src/entity_system/models.h src/entity_system/model.h
	$(CC) $(CFLAGS) src/world_renderer.cpp -o $(ODIR)/world_renderer.o

#MAKEMAKE>

makemake : 
	find $(SRCDIR) -iregex .*\.cpp | xargs makemake

tags : 
	ctags $(SRCDIR)/*.cpp -f $(SRCDIR)/tags

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

