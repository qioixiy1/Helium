#pragma once

#include <string>

#include "Platform/API.h"
#include "Platform/Types.h"

namespace Helium
{
    //
    // Decode the last error string
    //

    HELIUM_PLATFORM_API uint32_t GetLastError();

    HELIUM_PLATFORM_API tstring GetErrorString( uint32_t errorOverride = 0 );
}