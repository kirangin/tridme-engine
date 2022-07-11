#include <gui_layer.h>
#include <window.h>

namespace Tridme {
  GuiLayer::GuiLayer(const std::string& name) 
  : m_layerName(name) {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;      // Enable Gamepad Controls
    io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;      // Enable Gamepad Controls

    ImGui::StyleColorsDark();
  }

  GuiLayer::~GuiLayer() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
  }

  void GuiLayer::OnAttach(GLFWwindow* handle) {
    ImGui_ImplGlfw_InitForOpenGL(handle, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    LOG(INFO, "GUI Layer Attached");
  }

  void GuiLayer::OnDetach() {
    
  }

  void GuiLayer::OnUpdate(float deltaTime) {

  }

  void GuiLayer::OnEvent() {

  }

  void GuiLayer::ImGuiBegin() {
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

  };

  void GuiLayer::ImGuiEnd() {
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    ImGuiIO& io = ImGui::GetIO(); (void) io;

    if (io.ConfigFlags& ImGuiConfigFlags_ViewportsEnable) {
      GLFWwindow* backup_current = glfwGetCurrentContext();
      ImGui::UpdatePlatformWindows();
      ImGui::RenderPlatformWindowsDefault();
      glfwMakeContextCurrent(backup_current);
    }
  };

  void GuiLayer::ImGuiRender() {
    static float f = 0.0f;
    static int counter = 0;
    bool show_demo_window = true;

    ImGui::Begin("Hello, world!");
    ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
    ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state

    if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
      counter++;

    ImGui::SameLine();
    ImGui::Text("counter = %d", counter);

    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
  };
}