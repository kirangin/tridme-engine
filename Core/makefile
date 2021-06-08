CXX=g++
PARAMS=-lGL -lX11 -lpthread -lXrandr -lXi -ldl 

OBJS= src/extern/glad/glad.o \
		  src/index_buffer.o \
		  src/vertex_buffer.o \
		  src/vertex_array.o \
		  src/renderer.o \
		  src/shader.o \
		  src/camera.o \
		  src/texture.o \
		  src/mesh.o

src/%.o:src/%.cpp
	@mkdir -p $(@D)
	@echo " [CXX] $<"
	@g++ -c $^ -o $@ -Wno-int-to-pointer-cast -std=c++11 -I ./include/ -I ./include/extern/ -fpic

src/%.o:src/%.c
	@mkdir -p $(@D)
	@echo " [CC]  $<"
	@gcc -c $^ -o $@ -Isrc/include -I ./include/ -I ./include/extern/ -fpic

libcore.so: $(OBJS)
	@echo [LINKING]
	$(CXX) -shared -o $@ $^  $(PARAMS)

clean: 
	rm -rf $(OBJS) app sandbox src/main.o src/sandbox.o
