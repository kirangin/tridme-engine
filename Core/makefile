CXX=g++
PARAMS=-lGL -lX11 -lpthread -lXrandr -lXi -ldl 

HEADERS = -I ./include \
					-I ../vendors/glad/include \
					-I ../vendors/glfw/include \
					-I ../vendors/glm/glm \
					-I ../vendors/imgui \
					-I ../vendors/stbi

OBJS= src/glad.o \
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
	@g++ -c $^ -o $@ -Wno-int-to-pointer-cast -std=c++11 $(HEADERS) -fpic

src/%.o:src/%.c
	@mkdir -p $(@D)
	@echo " [CC]  $<"
	@gcc -c $^ -o $@ -Isrc/include -I ./include/ $(HEADERS) -fpic

libcore.so: $(OBJS)
	@echo [LINKING]
	$(CXX) -shared -o $@ $^  $(PARAMS)

clean: 
	rm -rf $(OBJS)
