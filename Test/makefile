%.o: %.cpp
	g++ -c $^ -o $@ -I ../Includes

%.o: %.c
	gcc -c $^ -o $@ -I ../Includes

main: main.o glad.o
	g++ -o $@ $^ -I ../Includes -L libcore.so -lglfw3 -lGL -lXrandr -lX11 -lXi -ldl -lpthread