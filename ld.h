/**
 @file ld.h

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
// Operating System Interface for LDOS and LSDOS
//---------------------------------------------------------------------------------

class   CLD: public CTD4
{
public:
    DWORD   Load(CVDI* pVDI, DWORD dwFlags);                                        // Validate DOS version and define operating parameters
protected:
    DWORD   ScanHIT(void** pFile, TD4_HIT nMode, BYTE nHash = 0);                   // Scan the Hash Index Table
};
