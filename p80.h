/**
 @file p80.h

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

#define V80_MEM             4096                                                    // Heap memory page

#define V80_FLAG_SYSTEM     0b00000000000000000000000000000001                      // 1: Include System files
#define V80_FLAG_INVISIBLE  0b00000000000000000000000000000010                      // 1: Include Invisible files
#define V80_FLAG_INFO       0b00000000000000000000000000000100                      // 1: Show extra information
#define V80_FLAG_CHKDIR     0b00000000000000000000000000001000                      // 1: Skip the directory structure check
#define V80_FLAG_CHKDSK     0b00000000000000000000000000010000                      // 1: Skip the disk parameters check
#define V80_FLAG_READBAD    0b00000000000000000000000000100000                      // 1: Read as much as possible from bad files
#define V80_FLAG_GATFIX     0b00000000000000000000000001000000                      // 1: Skip GAT auto-fix in TRSDOS Model III system disks
#define V80_FLAG_SS         0b00000000000000000000000010000000                      // 1: Force disk geometry to single-sided
#define V80_FLAG_DS         0b00000000000000000000000100000000                      // 1: Force disk geometry to double-sided
