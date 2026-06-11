/**
 * MSVC / MinGW-w64 cross-compilation compatibility header.
 * Force-included via -include flag so it's available before every TU.
 */
#pragma once

/* -----------------------------------------------------------------------
 * Windows headers – always include winsock2 first to avoid conflicts
 * ----------------------------------------------------------------------- */
#ifdef _WIN32
#  ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#  endif
#  include <winsock2.h>
#  include <ws2tcpip.h>
#  include <windows.h>
#  include <ntdef.h>   /* NTSTATUS */
#endif

/* -----------------------------------------------------------------------
 * Missing SAL annotations not present in MinGW sal.h
 * ----------------------------------------------------------------------- */
#ifndef _Check_return_opt_
#  define _Check_return_opt_
#endif
#ifndef _Post_ptr_invalid_
#  define _Post_ptr_invalid_
#endif
#ifndef _Frees_ptr_opt_
#  define _Frees_ptr_opt_
#endif
#ifndef _Out_writes_to_
#  define _Out_writes_to_(a, b)
#endif
#ifndef _Out_writes_bytes_opt_
#  define _Out_writes_bytes_opt_(x)
#endif
#ifndef _Out_writes_opt_
#  define _Out_writes_opt_(x)
#endif
#ifndef _Out_writes_
#  define _Out_writes_(x)
#endif
#ifndef _When_
#  define _When_(x, y)
#endif
#ifndef _Success_
#  define _Success_(x)
#endif
#ifndef _Printf_format_string_
#  define _Printf_format_string_
#endif
#ifndef _Inout_bytecount_
#  define _Inout_bytecount_(x)
#endif
#ifndef _Inout_updates_opt_
#  define _Inout_updates_opt_(x)
#endif

/* -----------------------------------------------------------------------
 * MSVC-specific integer types
 * ----------------------------------------------------------------------- */
#include <stdint.h>
#include <stddef.h>

/* -----------------------------------------------------------------------
 * Console / conio compatibility (MinGW provides conio.h)
 * ----------------------------------------------------------------------- */
#ifdef _WIN32
#  include <conio.h>
#endif
