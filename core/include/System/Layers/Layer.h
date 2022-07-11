#ifndef __LAYER_H__
#define __LAYER_H__

#include <Kernel/Core.h>

namespace Tridme {
  class Layer {
    public:
      Layer(const std::string& name = "Layer");
      virtual ~Layer();

      virtual void OnAttach() {}
      virtual void OnDetach() {}
      virtual void OnUpdate(float deltaTime) {}
      virtual void OnEvent() {}
      virtual void OnImGuiRender() {}

      inline const std::string& GetName() const { return m_LayerName; }

    private: 
      std::string m_LayerName;
  };
}

#endif // __LAYER_H__