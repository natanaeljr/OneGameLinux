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
#include "firstgame/event/event.h"

#include "keymap.h"
#include "mousemap.h"
#include "filesystem.h"

using firstgame::FirstGame;

static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

struct State {
    std::unique_ptr<FirstGame> firstgame;
};

int main()
{
    spdlog::set_default_logger(spdlog::stdout_color_mt("main"));
    spdlog::set_pattern("%Y-%m-%d %T.%e <%^%l%$> [%n] %s:%#:%!():  %v");
    spdlog::set_level(spdlog::level::trace);
    SPDLOG_INFO("Initializing FirstGameLinux..");

    State state{};

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
    glfwSetWindowUserPointer(window, &state);
    // callbacks
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    // settings
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    glfwSwapInterval(0);  // disable vsync

    glbinding::initialize(glfwGetProcAddress);

    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    state.firstgame = FirstGame::New(width, height, spdlog::stdout_color_mt("firstgame"),
                                     std::make_unique<FileSystemLinux>());

    while (!glfwWindowShouldClose(window)) {
        // update & render
        glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        state.firstgame->Update(0u);

        // imgui
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        state.firstgame->OnImGuiRender();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // window
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    SPDLOG_INFO("Terminating FirstGameLinux..");

    state.firstgame.reset();

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwTerminate();

    SPDLOG_INFO("Terminated.");
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    auto state = static_cast<State*>(glfwGetWindowUserPointer(window));
    state->firstgame->OnEvent(firstgame::event::WindowEvent{
        firstgame::event::WindowEvent::Resize{
            .width = width,
            .height = height,
        },
    });
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        // TODO: move this control to the game variant system
        glfwSetWindowShouldClose(window, true);
    }
    auto state = static_cast<State*>(glfwGetWindowUserPointer(window));
    firstgame::event::KeyEvent key_event =
        MapGlfwKeyEventToGameKeyEvent(key, scancode, action, mods);
    state->firstgame->OnEvent(key_event);
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    auto state = static_cast<State*>(glfwGetWindowUserPointer(window));
    state->firstgame->OnEvent(firstgame::event::CursorEvent{ .xpos = xpos, .ypos = ypos });
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    auto state = static_cast<State*>(glfwGetWindowUserPointer(window));
    firstgame::event::MouseEvent mouse_event =
        MapGlfwMouseEventToGameMouseEvent(button, action, mods);
    state->firstgame->OnEvent(mouse_event);
}
