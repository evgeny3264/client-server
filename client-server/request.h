#pragma once

#include "stdafx.h"
#include "constants.h"

//
// Request
//
typedef struct tagTDATA
{
    // Priority of request 0-255 (0 - highest priority)
    BYTE cPriority;
    // Request's creation time in system clock ticks
    unsigned long dwTicks;
    // Unique client ID
    unsigned long dwClientId;
    // Abstract data
    std::vector<char> data;
} TDATA, *PTDATA;
