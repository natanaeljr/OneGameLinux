#ifndef FIRSTGAMELINUX_KEYMAP_H_
#define FIRSTGAMELINUX_KEYMAP_H_

#include "firstgame/event/key.h"

firstgame::event::KeyEvent MapGlfwKeyEventToGameKeyEvent(int key, int scancode, int action,
                                                         int mods);

#endif  // FIRSTGAMELINUX_KEYMAP_H_
