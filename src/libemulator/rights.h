// Copyright (c) 2016 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#ifndef RIGHTS_H
#define RIGHTS_H

#define RIGHTS_ALL                                                             \
  (CLOUDABI_RIGHT_FD_DATASYNC | CLOUDABI_RIGHT_FD_READ |                       \
   CLOUDABI_RIGHT_FD_SEEK | CLOUDABI_RIGHT_FD_STAT_PUT_FLAGS |                 \
   CLOUDABI_RIGHT_FD_SYNC | CLOUDABI_RIGHT_FD_TELL | CLOUDABI_RIGHT_FD_WRITE | \
   CLOUDABI_RIGHT_FILE_ADVISE | CLOUDABI_RIGHT_FILE_ALLOCATE |                 \
   CLOUDABI_RIGHT_FILE_CREATE_DIRECTORY | CLOUDABI_RIGHT_FILE_CREATE_FILE |    \
   CLOUDABI_RIGHT_FILE_CREATE_FIFO | CLOUDABI_RIGHT_FILE_LINK_SOURCE |         \
   CLOUDABI_RIGHT_FILE_LINK_TARGET | CLOUDABI_RIGHT_FILE_OPEN |                \
   CLOUDABI_RIGHT_FILE_READDIR | CLOUDABI_RIGHT_FILE_READLINK |                \
   CLOUDABI_RIGHT_FILE_RENAME_SOURCE | CLOUDABI_RIGHT_FILE_RENAME_TARGET |     \
   CLOUDABI_RIGHT_FILE_STAT_FGET | CLOUDABI_RIGHT_FILE_STAT_FPUT_SIZE |        \
   CLOUDABI_RIGHT_FILE_STAT_FPUT_TIMES | CLOUDABI_RIGHT_FILE_STAT_GET |        \
   CLOUDABI_RIGHT_FILE_STAT_PUT_TIMES | CLOUDABI_RIGHT_FILE_SYMLINK |          \
   CLOUDABI_RIGHT_FILE_UNLINK | CLOUDABI_RIGHT_MEM_MAP |                       \
   CLOUDABI_RIGHT_MEM_MAP_EXEC | CLOUDABI_RIGHT_POLL_FD_READWRITE |            \
   CLOUDABI_RIGHT_POLL_MODIFY | CLOUDABI_RIGHT_POLL_PROC_TERMINATE |           \
   CLOUDABI_RIGHT_POLL_WAIT | CLOUDABI_RIGHT_PROC_EXEC |                       \
   CLOUDABI_RIGHT_SOCK_ACCEPT | CLOUDABI_RIGHT_SOCK_BIND_DIRECTORY |           \
   CLOUDABI_RIGHT_SOCK_BIND_SOCKET | CLOUDABI_RIGHT_SOCK_CONNECT_DIRECTORY |   \
   CLOUDABI_RIGHT_SOCK_CONNECT_SOCKET | CLOUDABI_RIGHT_SOCK_LISTEN |           \
   CLOUDABI_RIGHT_SOCK_SHUTDOWN | CLOUDABI_RIGHT_SOCK_STAT_GET)

// Block and character device interaction is outside the scope of
// CloudABI. Simply allow everything.
#define RIGHTS_BLOCK_DEVICE_BASE RIGHTS_ALL
#define RIGHTS_BLOCK_DEVICE_INHERITING RIGHTS_ALL
#define RIGHTS_CHARACTER_DEVICE_BASE RIGHTS_ALL
#define RIGHTS_CHARACTER_DEVICE_INHERITING RIGHTS_ALL

// Only allow directory operations on directories. Directories can only
// yield file descriptors to other directories, files and FIFOs.
#define RIGHTS_DIRECTORY_BASE                                           \
  (CLOUDABI_RIGHT_FD_STAT_PUT_FLAGS | CLOUDABI_RIGHT_FD_SYNC |          \
   CLOUDABI_RIGHT_FILE_ADVISE | CLOUDABI_RIGHT_FILE_CREATE_DIRECTORY |  \
   CLOUDABI_RIGHT_FILE_CREATE_FILE | CLOUDABI_RIGHT_FILE_CREATE_FIFO |  \
   CLOUDABI_RIGHT_FILE_LINK_SOURCE | CLOUDABI_RIGHT_FILE_LINK_TARGET |  \
   CLOUDABI_RIGHT_FILE_OPEN | CLOUDABI_RIGHT_FILE_READDIR |             \
   CLOUDABI_RIGHT_FILE_READLINK | CLOUDABI_RIGHT_FILE_RENAME_SOURCE |   \
   CLOUDABI_RIGHT_FILE_RENAME_TARGET | CLOUDABI_RIGHT_FILE_STAT_FGET |  \
   CLOUDABI_RIGHT_FILE_STAT_FPUT_TIMES | CLOUDABI_RIGHT_FILE_STAT_GET | \
   CLOUDABI_RIGHT_FILE_STAT_PUT_TIMES | CLOUDABI_RIGHT_FILE_SYMLINK |   \
   CLOUDABI_RIGHT_FILE_UNLINK | CLOUDABI_RIGHT_POLL_FD_READWRITE |      \
   CLOUDABI_RIGHT_SOCK_BIND_DIRECTORY | CLOUDABI_RIGHT_SOCK_CONNECT_DIRECTORY)
#define RIGHTS_DIRECTORY_INHERITING \
  (RIGHTS_DIRECTORY_BASE | RIGHTS_REGULAR_FILE_BASE | RIGHTS_FIFO_BASE)

// Only allow basic I/O on pipes.
#define RIGHTS_FIFO_BASE                                       \
  (CLOUDABI_RIGHT_FD_READ | CLOUDABI_RIGHT_FD_STAT_PUT_FLAGS | \
   CLOUDABI_RIGHT_FD_WRITE | CLOUDABI_RIGHT_FILE_STAT_FGET |   \
   CLOUDABI_RIGHT_POLL_FD_READWRITE)
#define RIGHTS_FIFO_INHERITING 0

#define RIGHTS_POLL_BASE                                        \
  (CLOUDABI_RIGHT_FILE_STAT_FGET | CLOUDABI_RIGHT_POLL_MODIFY | \
   CLOUDABI_RIGHT_POLL_WAIT)
#define RIGHTS_POLL_INHERITING 0

#define RIGHTS_PROCESS_BASE \
  (CLOUDABI_RIGHT_FILE_STAT_FGET | CLOUDABI_RIGHT_POLL_PROC_TERMINATE)
#define RIGHTS_PROCESS_INHERITING 0

// Operations that apply to regular files.
#define RIGHTS_REGULAR_FILE_BASE                                               \
  (CLOUDABI_RIGHT_FD_DATASYNC | CLOUDABI_RIGHT_FD_READ |                       \
   CLOUDABI_RIGHT_FD_SEEK | CLOUDABI_RIGHT_FD_STAT_PUT_FLAGS |                 \
   CLOUDABI_RIGHT_FD_SYNC | CLOUDABI_RIGHT_FD_TELL | CLOUDABI_RIGHT_FD_WRITE | \
   CLOUDABI_RIGHT_FILE_ADVISE | CLOUDABI_RIGHT_FILE_ALLOCATE |                 \
   CLOUDABI_RIGHT_FILE_STAT_FGET | CLOUDABI_RIGHT_FILE_STAT_FPUT_SIZE |        \
   CLOUDABI_RIGHT_FILE_STAT_FPUT_TIMES | CLOUDABI_RIGHT_MEM_MAP |              \
   CLOUDABI_RIGHT_MEM_MAP_EXEC | CLOUDABI_RIGHT_POLL_FD_READWRITE |            \
   CLOUDABI_RIGHT_PROC_EXEC)
#define RIGHTS_REGULAR_FILE_INHERITING 0

// Operations that apply to shared memory objects.
#define RIGHTS_SHARED_MEMORY_BASE                                       \
  (CLOUDABI_RIGHT_FD_READ | CLOUDABI_RIGHT_FD_WRITE |                   \
   CLOUDABI_RIGHT_FILE_STAT_FGET | CLOUDABI_RIGHT_FILE_STAT_FPUT_SIZE | \
   CLOUDABI_RIGHT_MEM_MAP | CLOUDABI_RIGHT_MEM_MAP_EXEC)
#define RIGHTS_SHARED_MEMORY_INHERITING 0

// Operations that apply to sockets and socket pairs.
#define RIGHTS_SOCKET_BASE                                                \
  (CLOUDABI_RIGHT_FD_READ | CLOUDABI_RIGHT_FD_STAT_PUT_FLAGS |            \
   CLOUDABI_RIGHT_FD_WRITE | CLOUDABI_RIGHT_FILE_STAT_FGET |              \
   CLOUDABI_RIGHT_POLL_FD_READWRITE | CLOUDABI_RIGHT_SOCK_ACCEPT |        \
   CLOUDABI_RIGHT_SOCK_BIND_SOCKET | CLOUDABI_RIGHT_SOCK_CONNECT_SOCKET | \
   CLOUDABI_RIGHT_SOCK_LISTEN | CLOUDABI_RIGHT_SOCK_SHUTDOWN |            \
   CLOUDABI_RIGHT_SOCK_STAT_GET)
#define RIGHTS_SOCKET_INHERITING RIGHTS_ALL

// Operations that apply to TTYs.
#define RIGHTS_TTY_BASE                                        \
  (CLOUDABI_RIGHT_FD_READ | CLOUDABI_RIGHT_FD_STAT_PUT_FLAGS | \
   CLOUDABI_RIGHT_FD_WRITE | CLOUDABI_RIGHT_FILE_STAT_FGET |   \
   CLOUDABI_RIGHT_POLL_FD_READWRITE)
#define RIGHTS_TTY_INHERITING 0

#endif