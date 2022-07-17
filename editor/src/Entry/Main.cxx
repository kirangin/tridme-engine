#include <iostream>
#include <Kernel/Engine.h>

int main(int argc, char **argv) {
  Tridme::Engine* engine = new Tridme::Engine(argc, argv);
  engine->Start();

  return 0;
}
