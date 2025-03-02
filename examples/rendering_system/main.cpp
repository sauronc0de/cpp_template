#include "rendering_system.h"

int main(int argc, char *args[])
{
  {
    //* Create rendering system
    RenderingSystemAO *renderingSystem = new RenderingSystemAO();
    renderingSystem->update();
  }
  //* Destroy rendering system

  return 0;
}
