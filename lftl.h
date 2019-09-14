/*
 * The little FLASH translation layer for small MCUs
 *
 * Copyright (c) 2019, John-Yu. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 */
#ifndef LFTL_H
#define LFTL_H

#include "lfs.h"

#ifdef __cplusplus
extern "C"
{
#endif

// Mounts a littleftl
//
// Requires a config struct. 
int lftl_map_mount(const struct lfs_config *config);

// Unmounts a littleftl
//
// Does nothing besides releasing any allocated resources.
// Returns a negative error code on failure.
int lftl_map_unmount();

/* Find the physical block which holds the current data for this sector.
 * Returns 0 on success or -1 if an error occurs.
 */
int lftl_map_find(lfs_block_t s, lfs_block_t *loc);

/* Read from the given logical sector. If the sector is unmapped, a
 * blank page (0xff) will be returned.
 */
int lftl_map_read(lfs_block_t s,  uint8_t *data);

/* Write data to a logical sector. */
int lftl_map_write(lfs_block_t s,  const uint8_t *data);




#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
