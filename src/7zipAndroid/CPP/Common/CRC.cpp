// Common/CRC.cpp

#include "7zStdAfx.h"

#include "../../C/7zCrc.h"

struct CCRCTableInit { CCRCTableInit() { CrcGenerateTable(); } } g_CRCTableInit;
