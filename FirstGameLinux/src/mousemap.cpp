#include "mousemap.h"

#include <cstdlib>
#include "GLFW/glfw3.h"

static firstgame::input::MouseButton MapGlfwMouseButtonToGameMouseButton(int glfw_button)
{
    using firstgame::input::MouseButton;
    switch (glfw_button) {
        case GLFW_MOUSE_BUTTON_LEFT: return MouseButton::Left;
        case GLFW_MOUSE_BUTTON_MIDDLE: return MouseButton::Middle;
        case GLFW_MOUSE_BUTTON_RIGHT: return MouseButton::Right;
        default: return MouseButton::Unknown;
    }
}

static firstgame::input::MouseAction MapGlfwMouseActionToGameMouseAction(int glfw_action)
{
    using firstgame::input::MouseAction;
    switch (glfw_action) {
        case GLFW_RELEASE: return MouseAction::Release;
        case GLFW_PRESS: return MouseAction::Press;
        default: abort();
    }
}

firstgame::event::MouseEvent MapGlfwMouseEventToGameMouseEvent(int button, int action, int mods)
{
    return {
        .button = MapGlfwMouseButtonToGameMouseButton(button),
        .action = MapGlfwMouseActionToGameMouseAction(action),
    };
}
