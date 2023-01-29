#include "event.hpp"
#include "ctx.hpp"

llcd::events::event llcd::events::getMouseDownEvent(vector2D position,bool left){
    event e;
    e.type = mouseDown;
    e.data.mouseDown.x = position.x;
    e.data.mouseDown.y = position.y;
    e.data.mouseDown.left = left;
    return e;
};
llcd::events::event llcd::events::getMouseUpEvent(vector2D position,bool left){
    event e;
    e.type = mouseUp;
    e.data.mouseUp.x = position.x;
    e.data.mouseUp.y = position.y;
    e.data.mouseUp.left = left;
    return e;
};
llcd::events::event llcd::events::getMouseMoveEvent(vector2D position){
    event e;
    e.type = mouseMove;
    e.data.mouseMove.x = position.x;
    e.data.mouseMove.y = position.y;
    return e;
};
llcd::events::event llcd::events::getKeyDownEvent(input::KeyboardInput key){
    event e;
    e.type = keyDown;
    e.data.keyDown.key = key;
    return e;
};
llcd::events::event llcd::events::getPicoEvent(input::legacyInput button){
    event e;
    e.type = pico;
    e.data.pico.button = button;
    return e;
};
llcd::events::event llcd::events::getPspEvent(input::PspInput button){
    event e;
    e.type = psp;
    e.data.psp.button = button;
    return e;
};

void llcd::events::event_handler::handleEvent(event e,ctx& context){
    AnyListener(e,context);
    switch(e.type){
        case mouseDown:
            MouseDownListener(vector2D(e.data.mouseDown.x,e.data.mouseDown.y),e.data.mouseDown.left,context);
            lastX = e.data.mouseDown.x;
            lastY = e.data.mouseDown.y;
            mousedDown = true;
            break;
        case mouseUp:
            MouseUpListener(vector2D(e.data.mouseUp.x,e.data.mouseUp.y),e.data.mouseUp.left,context);
            lastX = e.data.mouseUp.x;
            lastY = e.data.mouseUp.y;
            mousedDown = false;
            break;
        case mouseMove:
            MouseMoveListener(vector2D(e.data.mouseMove.x,e.data.mouseMove.y),context);
            lastX = e.data.mouseMove.x;
            lastY = e.data.mouseMove.y;
            break;
        case keyDown:
            KeyboardEventListener(e.data.keyDown.key,context);
            break;
        case pico:
            LegacyButtonsListener(e.data.pico.button,context);
            break;
        case psp:
            PspInputListener(e.data.psp.button,context);
            break;
    }
};

llcd::events::event_handler& llcd::events::event_handler::addAnyListener(std::function<void(event&,ctx&)> listener){
    AnyListener = listener;
    return *this;
};

llcd::events::event_handler& llcd::events::event_handler::addMouseDownListener(std::function<void(vector2D,bool,llcd::ctx&)> event){
    MouseDownListener = event;
    return *this;
};

llcd::events::event_handler& llcd::events::event_handler::addMouseUpListener(std::function<void(vector2D,bool,llcd::ctx&)> event){
    MouseUpListener = event;
    return *this;
};

llcd::events::event_handler& llcd::events::event_handler::addMouseMoveListener(std::function<void(vector2D,llcd::ctx&)> event){
    MouseMoveListener = event;
    return *this;
};

llcd::events::event_handler& llcd::events::event_handler::addKeyboardEventListener(std::function<void(input::KeyboardInput,llcd::ctx&)> event){
    KeyboardEventListener = event;
    return *this;
};

llcd::events::event_handler& llcd::events::event_handler::addPicoButtonsListener(std::function<void(input::legacyInput,llcd::ctx&)> event){
    LegacyButtonsListener = event;
    return *this;
};

llcd::events::event_handler& llcd::events::event_handler::addPspInputListener(std::function<void(input::PspInput,llcd::ctx&)> event){
    PspInputListener = event;
    return *this;
};