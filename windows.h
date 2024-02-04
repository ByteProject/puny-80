/**
 @file windows.h

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef int BOOL;
typedef unsigned char CHAR;
typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

typedef FILE * HANDLE;


#define MAX_PATH 8192


/* WARNING 
 * All entries here MUST have corresponding entries in errors_msg [] 
 */
enum errors
{
	NO_ERROR,
	ERROR_BAD_ARGUMENTS,
	ERROR_DISK_FULL,
	ERROR_DISK_TOO_FRAGMENTED,
	ERROR_EMPTY,
	ERROR_FILE_CORRUPT,
	ERROR_FILE_NOT_FOUND,
	ERROR_FLOPPY_ID_MARK_NOT_FOUND,
	ERROR_FLOPPY_WRONG_CYLINDER,
	ERROR_HANDLE_EOF,
	ERROR_INVALID_ADDRESS,
	ERROR_INVALID_NAME,
	ERROR_INVALID_PARAMETER,
	ERROR_INVALID_USER_BUFFER,
	ERROR_NO_MATCH,
	ERROR_NO_MORE_FILES,
	ERROR_NOT_DOS_DISK,
	ERROR_NOT_FOUND,
	ERROR_NOT_SUPPORTED,
	ERROR_OUTOFMEMORY,
	ERROR_READ_FAULT,
	ERROR_SECTOR_NOT_FOUND,
	ERROR_SEEK,
	ERROR_UNRECOGNIZED_MEDIA,
	ERROR_WRITE_FAULT,
	ERROR_LAST
};


#ifdef DEFINE_ERRORS_MSG

const char *errors_msg[] = {
	"NO ERROR",
	"BAD ARGUMENTS",
	"DISK FULL",
	"DISK TOO FRAGMENTED",
	"EMPTY",
	"FILE CORRUPT",
	"FILE NOT FOUND",
	"FLOPPY ID MARK NOT FOUND",
	"FLOPPY WRONG CYLINDER",
	"HANDLE EOF",
	"INVALID ADDRESS",
	"INVALID NAME",
	"INVALID PARAMETER",
	"INVALID USER BUFFER",
	"NO MATCH",
	"NO MORE FILES",
	"NOT DOS DISK",
	"NOT FOUND",
	"NOT SUPPORTED",
	"OUTOFMEMORY",
	"READ FAULT",
	"SECTOR NOT FOUND",
	"SEEK",
	"UNRECOGNIZED MEDIA",
	"WRITE FAULT",
	""
};
#else
	extern const char *errors[];
#endif

