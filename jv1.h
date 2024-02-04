/**
 @file jv1.h

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
// Virtual Disk Interface for JV1 images
//---------------------------------------------------------------------------------

#define JV1_SECTORSIZE  256                                                             // Standard sector size for a JV1 image

class CJV1: public CVDI
{
protected:
    WORD    m_wSectors;                                                                 // Total number of disk sectors in the disk
public:
    DWORD   Load(HANDLE hFile, DWORD dwFlags);                                          // Validate disk format and detect disk geometry
    DWORD   Read(BYTE nTrack, BYTE nSide, BYTE nSector, BYTE* pBuffer, WORD wSize);     // Read one sector from the disk
    DWORD   Write(BYTE nTrack, BYTE nSide, BYTE nSector, BYTE* pBuffer, WORD wSize);    // Write one sector to the disk
protected:
    virtual DWORD   Seek(BYTE nTrack, BYTE nSide, BYTE nSector);                        // Position the file pointer
};
