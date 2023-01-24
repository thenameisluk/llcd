#pragma once
#include "stdint.h"

#define e_video_initialation_error 001
#define e_input_initialation_error 002
#define e_memory_alocation_error 003
#define e_outFoBounce_error 004

#define e_audio_initialization_error 101
#define e_data_initialization_error 102
#define e_network_initialization_error 103

#define e_exit 255

#define program_exit throw llcd::exception(e_exit,"close program for me")

namespace llcd{
    class exception{
        public:
            uint8_t error_code;            
            const char* description;
            //0xx - we are going to die
            //1xx - this is not gut
            //2xx - custom
            //255 - exit program (not really an error)
            exception(uint8_t error_code,const char* description):error_code(error_code),description(description){};
            //try to make error visible in any possible way
            void comunitace(){};//to-do
    };
}