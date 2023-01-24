/*
a great pice of code

coded and delivered by L team
code by luk the oop programmer
debbugged by zoz the glaceon

it may break everything it touches
or something i dont know why
some people state that but yes

also no touch touch credits
without premission but if
you want you can modify code
itself so yes
*/

#pragma oncd
#include <functional>
#include "input.hpp"
#include "ctx.hpp"
#include "graphic.hpp"
#include "audio.hpp"
#include "objects.hpp"
#include "scenes.hpp"

namespace llcd{
    enum platform : uint8_t
    {
        pico,desktop,psp,web  
    };
    class llcd{
        private:
            uint32_t lastscene = -1;
        public:
            ctx context;
            uint32_t sceneNow = 0;
            scenes::sceneManager s_menager;
            llcd(int height, int width,const char* name = "name");
            ///direct checks///
            
            /// @brief tells you what platform we are currently on
            /// @return the platform
            platform system();
            
            /// @brief tells you the latest mouse position
            /// @return the latest mouse position
            vector2D getMousePosition();
            
            /// @brief tells you if a key is pressed
            /// @param key key you want to check
            /// @return is pressed
            bool keboardIsPressed(input::KeyboardInput key);
            
            /// @brief tells you if a mouse button is pressed
            /// @param button button you want to check (not working rn)
            /// @return is pressed
            bool mouseIsDown(bool left);

            /// @brief tells you if legacy button is pressed
            /// @param key button you want to check
            /// @return is pressed
            bool IsPressed(input::legacyInput key);
            
            /// @brief tells you if psp button is pressed
            /// @param button button you want to check
            /// @return is pressed
            bool pspIsPressed(input::PspInput key);
            
            /// @brief tells you the position of the psp joystick
            /// @return the position of the psp joystick
            fvector2D pspJoystickPosition();

            ///setups///
            
            llcd& addScene(scenes::scene s);

            ///event listeners///
            
            std::function<void(vector2D,bool)> MouseDownListener = [](vector2D pos,bool left){};
            std::function<void(vector2D,bool)> MouseUpListener = [](vector2D pos,bool left){};
            std::function<void(vector2D)> MouseMoveListener = [](vector2D pos){};
            std::function<void(input::KeyboardInput)> KeyboardEventListener = [](input::KeyboardInput key){};
            std::function<void(input::legacyInput)> LegacyButtonsListener = [](input::legacyInput key){};
            std::function<void(input::PspInput)> PspInputListener = [](input::PspInput key){};
            std::function<bool()> exitListener = [](){return true;};


            /// @brief SETS event that runs when the mouse is pressed
            /// @param event <void(vector2D - mouse position ,bool - left (not working rn))>
            /// @return returns the class itself
            llcd& addMouseDownListener(std::function<void(vector2D,bool)> event);
            
            /// @brief SETS event that runs when the mouse is released
            /// @param event <void(vector2D - mouse position ,bool - left (not working rn))>
            /// @return returns the class itself
            llcd& addMouseUpListener(std::function<void(vector2D,bool)> event);
            
            /// @brief SETS event that runs when the mouse is moved
            /// @param event <void(vector2D - mouse position)>
            /// @return returns the class itself
            llcd& addMouseMoveListener(std::function<void(vector2D)> event);
            
            /// @brief SETS event that runs when the keyboard is pressed
            /// @param event <void(input::KeyboardInput - key)>
            /// @return returns the class itself
            llcd& addKeyboardEventListener(std::function<void(input::KeyboardInput)> event);
                 
            /// @brief SETS event that runs when the legacy buttons are pressed
            /// @param event <void(input::legacyInput - key)>
            /// @return returns the class itself
            llcd& addPicoButtonsListener(std::function<void(input::legacyInput)> event);
            
            /// @brief SETS event that runs when the psp is pressed
            /// @param event <void(input::PspInput - key)>
            /// @return returns the class itself
            llcd& addPspInputListener(std::function<void(input::PspInput)> event);

            /// @brief SETS event that runs when the exit button is pressed
            /// @param event <bool()> return true if you want to exit the game
            /// or false if you want to ask the user if he/she wants to exit
            /// @return returns the class itself
            llcd& addExitListener(std::function<bool()> event);
            

            ///start///

            /// @brief calling this function will start the game
            /// and the rest of the code will be executed
            /// when the game will end
            void start();
        private:
            void eventChecker();

    };
}