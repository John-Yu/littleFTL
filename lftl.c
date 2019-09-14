/*
 * The little FLASH translation layer for small MCUs
 *
 * Copyright (c) 2019, John-Yu. All rights reserved.
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include "lftl.h"

 // lfs declarations
lfs_t lfs;
lfs_file_t file;


int lftl_map_mount(const struct lfs_config *config)
{
	int err = lfs_mount(&lfs, config);
	if (err) {
		// reformat if we can't mount the filesystem
		// this should only happen on the first boot
		lfs_format(&lfs, config);
		err = lfs_mount(&lfs, config);
	}
	return err;
}

int lftl_map_unmount()
{
	int err = lfs_unmount(&lfs);
	return err;
}

int lftl_map_find(lfs_block_t s, lfs_block_t *loc)
{
	char fn[10];
	int err = 0;

	sprintf(fn, "%d", s);
	err = lfs_file_open(&lfs, &file, fn, LFS_O_RDONLY);
	if (err == 0)
	{
		*loc = file.ctz.head;
	}
	lfs_file_close(&lfs, &file);
	return err;
}



int lftl_map_read(lfs_block_t s, uint8_t *data)
{
	char fn[10];
	int err;

	sprintf(fn, "%d", s);
	err = lfs_file_open(&lfs, &file, fn, LFS_O_RDONLY);
	//block_size == sector size
	if(err == 0)
	{
	    err = lfs_file_read(&lfs, &file, data, lfs.cfg->block_size);
	}
	else 
	{
	    memset(data, 0xff, lfs.cfg->block_size);
	}
	lfs_file_close(&lfs, &file);
	return err;
}


int lftl_map_write(lfs_block_t s, const uint8_t *data)
{
	char fn[10];
	int err;

	sprintf(fn, "%d", s);
	err = lfs_file_open(&lfs, &file, fn, LFS_O_WRONLY | LFS_O_CREAT);
	err = lfs_file_write(&lfs, &file, data, lfs.cfg->block_size);
	lfs_file_close(&lfs, &file);
	return err;
}



