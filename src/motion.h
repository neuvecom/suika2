/* -*- coding: utf-8; tab-width: 8; indent-tabs-mode: t; -*- */

/*
 * Suika2
 * Copyright (C) 2001-2023, Keiichi Tabata. All rights reserved.
 */

/*
 * Abstract Motion API
 */

#ifndef SUIKA_MOTION_H
#define SUIKA_MOTION_H

#include "types.h"

#if defined(USE_MOTION)

bool init_motion(void);
bool load_motion(int index, const char *fname);
void update_motion(void);
void render_motion(void);
void unload_motion(int index);
void set_motion_offset(int index, int offset_x, int offset_y);
void set_motion_scale(int index, float scale);
void set_motion_rotate(int index, float rot);

#else

static __inline bool init_motion(void)
{
	return true;
}

static __inline bool load_motion(int index, const char *fname)
{
	UNUSED_PARAMETER(index);
	UNUSED_PARAMETER(fname);
	return true;
}

static __inline void update_motion(void)
{
}

static __inline void render_motion(void)
{
}

static __inline void unload_motion(int index)
{
	UNUSED_PARAMETER(index);
}

static __inline void set_motion_offset(int index, int offset_x, int offset_y)
{
	UNUSED_PARAMETER(index);
	UNUSED_PARAMETER(offset_x);
	UNUSED_PARAMETER(offset_y);
}

static __inline void set_motion_scale(int index, float scale)
{
	UNUSED_PARAMETER(index);
	UNUSED_PARAMETER(scale);
}

static __inline void set_motion_rotate(int index, float rot)
{
	UNUSED_PARAMETER(index);
	UNUSED_PARAMETER(rot);
}

#endif /* defined(USE_MOTION) */

#endif /* SUIKA_MOTION_H */
