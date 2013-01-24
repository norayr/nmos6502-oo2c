/*	$Id: __Descr.c,v 1.6 2000/09/23 19:40:47 ooc-devel Exp $	*/
/* this file is included into __oo2c.c */

/*  Low-level functions to manage module and type descriptors.
    Copyright (C) 1997-1999  Michael van Acken

    This module is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public License
    as published by the Free Software Foundation; either version 2 of
    the License, or (at your option) any later version.

    This module is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with OOC. If not, write to the Free Software Foundation,
    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

/* module descriptor `Kernel' and type descriptor `Kernel.ModuleDesc': */

struct _TD Kernel__ModuleDesc_td;
struct _TD Types__TypeDesc_td;

_ModId _register_module (_Module m, const _Type tdescs) {
}

