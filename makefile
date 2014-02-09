SRCDIR = src
TESTDIR = tests
ODIR = out
BINDIR = bin
OUT = $(BINDIR)/app
TOUT = $(BINDIR)/test
OBJS = $(ODIR)/main.o $(ODIR)/game.o $(ODIR)/mygl.o $(ODIR)/input.o $(ODIR)/graphics.o $(ODIR)/entity_system.o $(ODIR)/entity_pool.o $(ODIR)/basic_entity_factory.o $(ODIR)/entity.o $(ODIR)/physics_component.o $(ODIR)/render_component.o $(ODIR)/basic_renderer.o $(ODIR)/camera.o $(ODIR)/FLAT_utils.o
TESTS = $(ODIR)/tests.o $(ODIR)/fixed_vector_test.o
CC = g++
DEBUG = -g
DEBUGGER = gdb
CFLAGS = -Wall -c `pkg-config --cflags glfw3` $(DEBUG)
LFLAGS = -Wall `pkg-config --static --libs glfw3` -framework OpenGL -lGLEW $(DEBUG)

GL_INCLUDE_H_DEPS =
FLAT_UTILS_C_DEPS =
FLAT_UTILS_H_DEPS =
MYGL_C_DEPS =
MYGL_H_DEPS = $(SRCDIR)/gl_include.h
RENDER_COMPONENTS_C_DEPS =
RENDER_COMPONENTS_H_DEPS =
PHYSICS_COMPONENTS_C_DEPS =
PHYSICS_COMPONENTS_H_DEPS =
ENTITY_C_DEPS =
ENTITY_H_DEPS =
ENTITY_FACTORY_H_DEPS =
ENTITY_POOL_C_DEPS =
ENTITY_POOL_H_DEPS = $(SRCDIR)/entity.h $(ENTITY_H_DEPS) $(SRCDIR)/render_component.h $(RENDER_COMPONENT_H_DEPS) $(SRCDIR)/physics_component.h $(PHYSICS_COMPONENT_H_DEPS)
BASIC_ENTITY_FACTORY_C_DEPS = $(SRCDIR)/entity.h $(ENTITY_H_DEPS) $(SRCDIR)/entity_pool.h $(ENTITY_POOL_H_DEPS) $(SRCDIR)/FLAT_utils.h $(FLAT_UTILS_H_DEPS)
BASIC_ENTITY_FACTORY_H_DEPS = $(SRCDIR)/entity_factory.h $(ENTITY_FACTORY_H_DEPS)
RENDERER_H_DEPS = $(SRCDIR)/mygl.h $(MYGL_H_DEPS)
BASIC_RENDERER_C_DEPS = 
BASIC_RENDERER_H_DEPS = $(SRCDIR)/renderer.h $(RENDERER_H_DEPS)
CAMERA_C_DEPS = 
CAMERA_H_DEPS = $(SRCDIR)/gl_include.h $(GL_INCLUDE_H_DEPS)
ENTITY_SYSTEM_C_DEPS = $(SRCDIR)/entity_factory.h $(ENTITY_FACTORY_H_DEPS)
ENTITY_SYSTEM_H_DEPS = $(SRCDIR)/entity_pool.h $(ENTITY_POOL_H_DEPS) $(SRCDIR)/basic_renderer.h $(BASIC_RENDERER_H_DEPS) $(SRCDIR)/camera.h $(CAMERA_H_DEPS)
GRAPHICS_C_DEPS =
GRAPHICS_H_DEPS = $(SRCDIR)/mygl.h $(MYGL_H_DEPS)
INPUT_C_DEPS =
INPUT_H_DEPS = $(SRCDIR)/mygl.h $(MYGL_H_DEPS)
GAME_C_DEPS = $(SRCDIR)/basic_entity_factory.h $(BASIC_ENTITY_FACTORY_H_DEPS)
GAME_H_DEPS = $(SRCDIR)/mygl.h $(SRCDIR)/input.h $(INPUT_H_DEPS) $(SRCDIR)/graphics.h $(GRAPHICS_H_DEPS) $(SRCDIR)/entity_system.h $(ENTITY_SYSTEM_H_DEPS)
MAIN_C_DEPS = $(SRCDIR)/game.h $(GAME_H_DEPS)
MAIN_H_DEPS = 

$(OUT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(OUT)

$(ODIR)/main.o : $(SRCDIR)/main.cpp $(MAIN_H_DEPS)
	$(CC) $(CFLAGS) $(SRCDIR)/main.cpp -o $(ODIR)/main.o

$(ODIR)/game.o : $(SRCDIR)/game.cpp $(SRCDIR)/game.h $(GAME_C_DEPS) $(GAME_H_DEPS)
	$(CC) $(CFLAGS) $(SRCDIR)/game.cpp -o $(ODIR)/game.o

$(ODIR)/mygl.o : $(SRCDIR)/mygl.cpp $(SRCDIR)/mygl.h $(MYGL_C_DEPS) $(MYGL_H_DEPS)
	$(CC) $(CFLAGS) $(SRCDIR)/mygl.cpp -o $(ODIR)/mygl.o

$(ODIR)/input.o : $(SRCDIR)/input.cpp $(SRCDIR)/input.h $(INPUT_C_DEPS) $(INPUT_H_DEPS)
	$(CC) $(CFLAGS) $(SRCDIR)/input.cpp -o $(ODIR)/input.o

$(ODIR)/graphics.o : $(SRCDIR)/graphics.cpp $(SRCDIR)/graphics.h $(GRAPHICS_C_DEPS) $(GRAPHICS_H_DEPS)
	$(CC) $(CFLAGS) $(SRCDIR)/graphics.cpp -o $(ODIR)/graphics.o

$(ODIR)/entity_system.o : $(SRCDIR)/entity_system.cpp $(SRCDIR)/entity_system.h $(ENTITY_SYSTEM_C_DEPS) $(ENTITY_SYSTEM_H_DEPS)
	$(CC) $(CFLAGS) $(SRCDIR)/entity_system.cpp -o $(ODIR)/entity_system.o

$(ODIR)/entity_pool.o : $(SRCDIR)/entity_pool.cpp $(SRCDIR)/entity_pool.h $(ENTITY_SYSTEM_C_DEPS) $(ENTITY_SYSTEM_H_DEPS)
	$(CC) $(CFLAGS) $(SRCDIR)/entity_pool.cpp -o $(ODIR)/entity_pool.o

$(ODIR)/basic_entity_factory.o : $(SRCDIR)/basic_entity_factory.cpp $(SRCDIR)/basic_entity_factory.h $(BASIC_ENTITY_FACTORY_C_DEPS) $(BASIC_ENTITY_FACTORY_H_DEPS)
	$(CC) $(CFLAGS) $(SRCDIR)/basic_entity_factory.cpp -o $(ODIR)/basic_entity_factory.o

$(ODIR)/entity.o : $(SRCDIR)/entity.cpp $(SRCDIR)/entity.h $(ENTITY_C_DEPS) $(ENTITY_H_DEPS)
	$(CC) $(CFLAGS) $(SRCDIR)/entity.cpp -o $(ODIR)/entity.o

$(ODIR)/physics_component.o : $(SRCDIR)/physics_component.cpp $(SRCDIR)/physics_component.h $(PHYSICS_COMPONENT_C_DEPS) $(PHYSICS_COMPONENT_H_DEPS)
	$(CC) $(CFLAGS) $(SRCDIR)/physics_component.cpp -o $(ODIR)/physics_component.o

$(ODIR)/render_component.o : $(SRCDIR)/render_component.cpp $(SRCDIR)/render_component.h $(RENDER_COMPONENT_C_DEPS) $(RENDER_COMPONENT_H_DEPS)
	$(CC) $(CFLAGS) $(SRCDIR)/render_component.cpp -o $(ODIR)/render_component.o

$(ODIR)/basic_renderer.o : $(SRCDIR)/basic_renderer.cpp $(SRCDIR)/basic_renderer.h $(BASIC_RENDERER_C_DEPS) $(BASIC_RENDERER_H_DEPS)
	$(CC) $(CFLAGS) $(SRCDIR)/basic_renderer.cpp -o $(ODIR)/basic_renderer.o

$(ODIR)/camera.o : $(SRCDIR)/camera.cpp $(SRCDIR)/camera.h $(CAMERA_C_DEPS) $(CAMERA_H_DEPS)
	$(CC) $(CFLAGS) $(SRCDIR)/camera.cpp -o $(ODIR)/camera.o

$(ODIR)/FLAT_utils.o : $(SRCDIR)/FLAT_utils.cpp $(SRCDIR)/FLAT_utils.h $(FLAT_UTILS_C_DEPS) $(FLAT_UTILS_H_DEPS)
	$(CC) $(CFLAGS) $(SRCDIR)/FLAT_utils.cpp -o $(ODIR)/FLAT_utils.o

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

