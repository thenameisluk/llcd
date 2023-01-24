#pragma once
#include <functional>
#include "input.hpp"
#include "objects.hpp"


namespace llcd{
    namespace events{
        enum eventType : uint8_t{
            mouseDown,mouseUp,mouseMove,keyDown,pico,psp
        };
        struct mouseDownEvent {
            int32_t x;
            int32_t y;
            bool left;
        };
        struct mouseUpEvent {
            int32_t x;
            int32_t y;
            bool left;
        };
        struct mouseMoveEvent {
            int32_t x;
            int32_t y;
        };
        struct keyDownEvent {
            input::KeyboardInput key;
        };
        struct picoEvent {
            input::legacyInput button;
        };
        struct pspEvent {
            input::PspInput button;
        };
        struct event{
            eventType type;
            union eventData{
                mouseDownEvent mouseDown;
                mouseUpEvent mouseUp;
                mouseMoveEvent mouseMove;
                keyDownEvent keyDown;
                picoEvent pico;
                pspEvent psp;
            } data;
        };
        event getMouseDownEvent(vector2D position,bool left);
        event getMouseUpEvent(vector2D position,bool left);
        event getMouseMoveEvent(vector2D position);
        event getKeyDownEvent(input::KeyboardInput key);
        event getPicoEvent(input::legacyInput x);
        event getPspEvent(input::PspInput x);
        class event_handler{
            public:
                event_handler(){};
                int32_t lastX;
                int32_t lastY;
                void handleEvent(event e,ctx& context);
            private:
                std::function<void(vector2D,bool,ctx&)> MouseDownListener = [](vector2D pos,bool left,ctx& context){};
                std::function<void(vector2D,bool,ctx&)> MouseUpListener = [](vector2D pos,bool left,ctx& context){};
                std::function<void(vector2D,ctx&)> MouseMoveListener = [](vector2D pos,ctx& context){};
                std::function<void(input::KeyboardInput,ctx&)> KeyboardEventListener = [](input::KeyboardInput key,ctx& context){};
                std::function<void(input::legacyInput,ctx&)> LegacyButtonsListener = [](input::legacyInput key,ctx& context){};
                std::function<void(input::PspInput,ctx&)> PspInputListener = [](input::PspInput key,ctx& context){};
            public:
                /// @brief SETS event that runs when the mouse is pressed
                /// @param event <void(vector2D - mouse position ,bool - left (not working rn))>
                /// @return returns the class itself
                event_handler& addMouseDownListener(std::function<void(vector2D,bool,ctx&)> event);
                
                /// @brief SETS event that runs when the mouse is released
                /// @param event <void(vector2D - mouse position ,bool - left (not working rn))>
                /// @return returns the class itself
                event_handler& addMouseUpListener(std::function<void(vector2D,bool,ctx&)> event);
                
                /// @brief SETS event that runs when the mouse is moved
                /// @param event <void(vector2D - mouse position)>
                /// @return returns the class itself
                event_handler& addMouseMoveListener(std::function<void(vector2D,ctx&)> event);
                
                /// @brief SETS event that runs when the keyboard is pressed
                /// @param event <void(input::KeyboardInput - key)>
                /// @return returns the class itself
                event_handler& addKeyboardEventListener(std::function<void(input::KeyboardInput,ctx&)> event);
                    
                /// @brief SETS event that runs when the legacy buttons are pressed
                /// @param event <void(input::legacyInput - key)>
                /// @return returns the class itself
                event_handler& addPicoButtonsListener(std::function<void(input::legacyInput,ctx&)> event);
                
                /// @brief SETS event that runs when the psp is pressed
                /// @param event <void(input::PspInput - key)>
                /// @return returns the class itself
                event_handler& addPspInputListener(std::function<void(input::PspInput,ctx&)> event);
        };
    }
}