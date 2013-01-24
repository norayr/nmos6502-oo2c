/*	$Id: __Exception.h,v 1.10 2000/09/23 19:40:49 ooc-devel Exp $	*/
/* __config.h and __StdTypes.h have to be included prior to this file; the 
   definitions for the variables and functions declared below are part of 
   __oo2c.c */

/*  Exception handling part of the OOC run-time system.
    Copyright (C) 1997-1998  Michael van Acken

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

extern _Pos _exception_pos;
/* a failed run-time check, HALT, and ASSERT set this to the position of the
   corresponding construct; set to zero again if the exception has been 
   handled, i.e., by the Exception procedures ACKNOWLEDGE and RETRY */

/* numbers assigned to the various run-time checks: */
#define RT_derefOfNIL 1		/* dereference or type test on NIL */
#define RT_realDivByZero 2	/* integer or real division by zero */
#define RT_integerDivByZero 3	/* integer or real division by zero */
#define RT_realOverflow 4       /* real overflow */
#define RT_integerOverflow 5    /* integer overflow */
#define RT_illegalLength 6	/* NEW was called with negative length for array */
#define RT_outOfMemory 7	/* NEW couldn't allocate the requested memory */
#define RT_indexOutOfRange 8	/* array index out of range */
#define RT_elementOutOfRange 9	/* set element out of range */
#define RT_endOfFunction 10	/* control reaches end of function procedure */
#define RT_noMatchingLabel 11	/* no matching label in CASE construct */
#define RT_noValidGuard 12	/* all guards of WITH failed */
#define RT_typeGuardFailed 13	/* type guard failed */
#define RT_typeAssertFailed 14	/* illegal type of target of record assignment */
#define RT_stackOverflow 15	/* stack overflow */

