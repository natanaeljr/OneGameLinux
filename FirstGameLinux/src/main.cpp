#include <cstdio>
#include <iostream>

#include <glbinding/gl33core/gl.h>
#include <glbinding/glbinding.h>
using namespace gl;

#include <GLFW/glfw3.h>

#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "firstgame/firstgame.h"
#include "firstgame/event.h"

using firstgame::FirstGame;

static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static void processInput(GLFWwindow* window);

int main()
{
    spdlog::set_default_logger(spdlog::stdout_color_mt("main"));
    spdlog::set_pattern("%Y-%m-%d %T.%e <%^%=5l%$> [%n] %s:%#:%!():  %v");
    spdlog::set_level(spdlog::level::trace);
    SPDLOG_INFO("Initializing FirstGameLinux..");

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "FirstGameLinux", nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glbinding::initialize(glfwGetProcAddress);

    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    std::unique_ptr<FirstGame> firstgame = FirstGame::New(spdlog::stdout_color_mt("firstgame"));

    while (!glfwWindowShouldClose(window)) {
        // input
        processInput(window);

        // update & render
        glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        firstgame->Update(0u);

        // imgui
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        firstgame->OnImGuiRender();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // window
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    SPDLOG_INFO("Terminating FirstGameLinux..");

    firstgame.reset();

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();

    SPDLOG_INFO("Terminated.");
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}
