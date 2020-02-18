#ifndef BTN_LOG_H
#define BTN_LOG_H

#include "btn_common.h"
#include "btn_config_log.h"

#if BTN_CFG_LOG_ENABLED
    #include "btn_input_string_stream.h"

    #define BTN_LOG(...) \
        do \
        { \
            char _btn_string[0x100]; \
            btn::istring_base _btn_istring(_btn_string, 0, BTN_CFG_ASSERT_BUFFER_SIZE - 1); \
            btn::input_string_stream _btn_input_string_stream(_btn_istring); \
            _btn_input_string_stream.append_args(__VA_ARGS__); \
            btn::log(_btn_string); \
        } while(false)

    namespace btn
    {
        void log(const char* message);
    }
#else
    #define BTN_LOG(...) \
        do \
        { \
        } while(false)
#endif

#endif
