/**
 @file td1.cpp

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
// Operating System Interface for TRSDOS (Model I)
//---------------------------------------------------------------------------------

#include "windows.h"
#include "p80.h"
#include "vdi.h"
#include "osi.h"
#include "td4.h"
#include "td1.h"

//---------------------------------------------------------------------------------
// Validate DOS version and define operating parameters
//---------------------------------------------------------------------------------

DWORD CTD1::Load(CVDI* pVDI, DWORD dwFlags)
{

    DWORD   dwBytes;
    DWORD   dwError = NO_ERROR;

    // Copy VDI pointer and user flags to member variables
    m_pVDI = pVDI;
    m_dwFlags = dwFlags;

    // Get disk geometry
    m_pVDI->GetDG(m_DG);

    // Calculate the number of disk sides
    if (m_dwFlags & V80_FLAG_SS)
        m_nSides = 1;
    else if (m_dwFlags & V80_FLAG_DS)
        m_nSides = 2;
    else
        m_nSides = m_DG.LT.nLastSide - m_DG.LT.nFirstSide + 1;

    // Calculate the number of sectors per track
    m_nSectorsPerTrack = m_DG.LT.nLastSector - m_DG.LT.nFirstSector + 1;

    // Check internal buffer size (just in case)
    if (sizeof(m_Buffer) < m_DG.FT.wSectorSize)
    {
        dwError = ERROR_INVALID_USER_BUFFER;
        goto Done;
    }

    // Read boot sector
    if ((dwError = m_pVDI->Read(m_DG.FT.nTrack, m_DG.FT.nFirstSide, m_DG.FT.nFirstSector, m_Buffer, m_DG.FT.wSectorSize)) != NO_ERROR)
        goto Done;

    // Get directory track and reset MSB (set on some DOS to indicate the disk density)
    m_nDirTrack = m_Buffer[2] & 0x7F;

    // Calculate the number of directory sectors
    m_nDirSectors = m_nSectorsPerTrack * m_nSides;

    // Max Dir Sectors = HIT Size / Entries per Sector
    m_nMaxDirSectors = (m_DG.LT.wSectorSize / (BYTE)(m_DG.LT.wSectorSize / sizeof(TD4_FPDE)));

    // If dir sectors exceeds max sectors, limit to max
    if (m_nDirSectors > m_nMaxDirSectors)
        m_nDirSectors = m_nMaxDirSectors;

    // If not first Load, release the previously allocated memory
    if (m_pDir != NULL)
        free(m_pDir);

    // Calculate needed memory to hold the entire directory
    dwBytes = m_nDirSectors * m_DG.LT.wSectorSize + (V80_MEM - (m_nDirSectors * m_DG.LT.wSectorSize) % V80_MEM);

    // Allocate memory for the entire directory
    if ((m_pDir = (BYTE*)calloc(dwBytes,1)) == NULL)
    {
        dwError = ERROR_OUTOFMEMORY;
        goto Done;
    }

    // Load directory into memory
    if ((dwError = DirRW(TD4_DIR_READ)) != NO_ERROR)
        goto Done;

    // Calculate disk parameters

    m_nGranulesPerTrack = (m_DG.LT.nDensity == VDI_DENSITY_SINGLE ? 2 : 3);

    m_nGranulesPerCylinder = m_nGranulesPerTrack * m_nSides;

    m_nSectorsPerGranule = m_nSectorsPerTrack / m_nGranulesPerTrack;

    // This division must leave no remainder
    if (m_nSectorsPerTrack % m_nGranulesPerTrack != 0)
    {
        dwError = ERROR_NOT_DOS_DISK;
        goto Done;
    }

    // Check directory structure
    if (!(m_dwFlags & V80_FLAG_CHKDIR))
        if ((dwError = CheckDir()) != NO_ERROR)
            goto Done;

    Done:
    return dwError;

}
