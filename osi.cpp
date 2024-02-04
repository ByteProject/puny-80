/**
 @file osi.cpp

PUNY-80
TRS-80 disk image tool for Linux and other *nix operating systems
Copyright (c) 2024 Stefan Vogt and Shawn Sijnstra

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

See file LICENSE for details. 

Based on TRS-80 Virtual Disk Kit by Miguel Dutra and Mike Gore.

*/
//---------------------------------------------------------------------------------
// Operating System Interface
//---------------------------------------------------------------------------------

#include "windows.h"
#include "p80.h"
#include "vdi.h"
#include "osi.h"

COSI::COSI()
: m_pVDI(NULL), m_dwFlags(0), m_DG()
{
}

COSI::~COSI()
{
}
