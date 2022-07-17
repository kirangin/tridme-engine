#ifndef EDITOR_LAYER_H
#define EDITOR_LAYER_H
#include <System/Layers/GUILayer.h>

namespace Tridme {
  namespace Editor {
    class EditorLayer : public GuiLayer {
      public:
        EditorLayer();
        ~EditorLayer();

        void OnAttach(GLFWwindow* handle) override;
        void OnDetach() override;
        void OnUpdate(float deltaTime) override;
        void OnEvent() override;

        void ImGuiBegin() override;
        void ImGuiEnd() override;
        void ImGuiRender() override;

      private:
        std::string m_layerName;
    };
  }
}

#endif