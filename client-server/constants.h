#pragma once
#include "stdafx.h"

namespace Constants
{
    const unsigned long MAX_DATA_SIZE = 255;

    const BYTE MIN_REQUEST_PRIORITY = 0;
    const BYTE MAX_REQUEST_PRIORITY = 255;

    const unsigned long MIN_CLIENTS = 1;
    const unsigned long MAX_CLIENTS = 10;
    const unsigned long DEFAULT_CLIENTS = 1;

    // In milliseconds.
    const unsigned long MIN_REQUEST = 6000;
    // In milliseconds.
    const unsigned long MAX_REQUEST = 10000;

    // In milliseconds.
    const unsigned long MIN_SERVER_RESPONSE = 1000;
    // In milliseconds.
    const unsigned long MAX_SERVER_RESPONSE = 1500;

    const std::wstring DEFAULT_LOG_FILE_NAME = L"file.log";

    // In milliseconds.
    const unsigned long FLASHING_TIME = 300;
}
