// Copyright (c) 2016 Nuxi, https://nuxi.nl/
//
// This file is distributed under a 2-clause BSD license.
// See the LICENSE file for details.

#ifndef POSIX_H
#define POSIX_H

#include <stdbool.h>
#include <stddef.h>

#include <cloudabi_syscalls_struct.h>

#include "locking.h"

struct fd_entry;

struct fd_table {
  struct rwlock lock;
  struct fd_entry *entries;
  size_t size;
  size_t used;
};

extern _Thread_local cloudabi_tid_t curtid;

extern cloudabi_syscalls_t posix_syscalls;

void fd_table_init(struct fd_table *);
bool fd_table_insert_existing(struct fd_table *, cloudabi_fd_t, int);

#endif
