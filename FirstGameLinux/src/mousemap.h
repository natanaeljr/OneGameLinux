#ifndef FIRSTGAMELINUX_MOUSEMAP_H_
#define FIRSTGAMELINUX_MOUSEMAP_H_

#include "firstgame/event/mouse.h"

firstgame::event::MouseEvent MapGlfwMouseEventToGameMouseEvent(int button, int action, int mods);

#endif  // FIRSTGAMELINUX_MOUSEMAP_H_
