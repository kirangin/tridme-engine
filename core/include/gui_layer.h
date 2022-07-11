#ifndef GUI_LAYER
#define GUI_LAYER

#include <logging.h>
#include <layer.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>
#include <string>

namespace Tridme {
  class GuiLayer : public Layer {
    public:
      GuiLayer(const std::string& name = "Layer");
      virtual ~GuiLayer();

      virtual void OnAttach(GLFWwindow* handle);
      virtual void OnDetach();
      virtual void OnUpdate(float deltaTime);
      virtual void OnEvent();

      void ImGuiBegin();
      void ImGuiEnd();
      void ImGuiRender();

    private:
      std::string m_layerName;
  };
}

#endif