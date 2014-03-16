/*!The Treasure Box Library
 * 
 * TBox is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 * 
 * TBox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with TBox; 
 * If not, see <a href="http://www.gnu.org/licenses/"> http://www.gnu.org/licenses/</a>
 * 
 * Copyright (C) 2009 - 2015, ruki All rights reserved.
 *
 * @author		ruki
 * @file		prefix.h
 * @ingroup 	object
 *
 */
#ifndef TB_OBJECT_WRITER_PREFIX_H
#define TB_OBJECT_WRITER_PREFIX_H

/* ///////////////////////////////////////////////////////////////////////
 * includes
 */
#include "../prefix.h"

/* ///////////////////////////////////////////////////////////////////////
 * macros
 */

// bytes
#define tb_object_writer_need_bytes(x) 				\
													(((tb_uint64_t)(x)) < (1ull << 8) ? 1 : \
													(((tb_uint64_t)(x)) < (1ull << 16) ? 2 : \
													(((tb_uint64_t)(x)) < (1ull << 24) ? 3 : \
													(((tb_uint64_t)(x)) < (1ull << 32) ? 4 : 8))))

/* ///////////////////////////////////////////////////////////////////////
 * inlines
 */

static __tb_inline__ tb_bool_t tb_object_writer_tab(tb_gstream_t* stream, tb_bool_t deflate, tb_size_t tab)
{
	// writ tab
	if (!deflate) 
	{
		while (tab--) if (tb_gstream_printf(stream, "\t") < 0) return tb_false;
	}

	// ok
	return tb_true;
}
static __tb_inline__ tb_bool_t tb_object_writer_newline(tb_gstream_t* stream, tb_bool_t deflate)
{
	// writ newline
	if (!deflate && tb_gstream_printf(stream, __tb_newline__) < 0) return tb_false;

	// ok
	return tb_true;
}

#endif
