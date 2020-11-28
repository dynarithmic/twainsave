/*
This file is part of the Dynarithmic TWAIN Library (DTWAIN).
Copyright (c) 2002-2020 Dynarithmic Software.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

FOR ANY PART OF THE COVERED WORK IN WHICH THE COPYRIGHT IS OWNED BY
DYNARITHMIC SOFTWARE. DYNARITHMIC SOFTWARE DISCLAIMS THE WARRANTY OF NON INFRINGEMENT
OF THIRD PARTY RIGHTS.
*/

#ifndef DTWAIN_LOGGER_CALLBACK_HPP
#define DTWAIN_LOGGER_CALLBACK_HPP

#include <dynarithmic/twain/twain_values.hpp>
#include <dynarithmic/twain/session/twain_session_base.hpp>

namespace dynarithmic
{
    namespace twain
    {
        class twain_session;
        inline LRESULT CALLBACK logger_callback_proc(const char* msg, DTWAIN_LONG64 UserData)
        {
            const auto thisObject = reinterpret_cast<twain_session_base*>(UserData);
            if (thisObject)
            {
                twain_session_base::logger_callback_type& sesObject = thisObject->get_logger_callback();
                if (thisObject->get_twain_characteristics().get_logger_characteristics().is_enabled() && sesObject.second)
                    sesObject.second->log_message(msg);
            }
            return 1;
        }

        inline LRESULT CALLBACK error_callback_proc(LONG error, LONG64 UserData)
        {
            const auto thisObject = reinterpret_cast<twain_session_base*>(UserData);
            if (thisObject)
                thisObject->log_error(error);
            return 1;
        }
    }
}
#endif
