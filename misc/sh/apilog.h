/*
 * Sh Hooking Library - 
 *   API logging
 * 
 * Copyright (C) 2009 wj32
 * 
 * This file is part of Process Hacker.
 * 
 * Process Hacker is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Process Hacker is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Process Hacker.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _APILOG_H
#define _APILOG_H

#include "nthook.h"
#include "common.h"

#define AL_PIPE_NAME (L"\\\\.\\Pipe\\AlLogPipe")

#define AL_LOG_CALL(Name, NtHook, Length, ...) \
    { \
        PBYTE dictionary; \
        ULONG dictionaryLength; \
        \
        dictionary = CmMakeDictStringULong(&dictionaryLength, Length, __VA_ARGS__); \
        AlLogCall(Name, NtHook, dictionary, dictionaryLength); \
        free(dictionary); \
    }

NTSTATUS AlWriteLogPipe(
    PVOID Buffer,
    ULONG BufferLength
    );

NTSTATUS AlLogCall(
    PWSTR Name,
    PNT_HOOK NtHook,
    PBYTE Dictionary,
    ULONG DictionaryLength
    );

NTSTATUS AlPatch();
NTSTATUS AlUnpatch();
NTSTATUS AlInit();
NTSTATUS AlDeinit();

#endif