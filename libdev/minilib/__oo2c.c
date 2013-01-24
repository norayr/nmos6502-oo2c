/*	$Id: __oo2c.c,v 1.25 2000/12/04 21:40:43 ooc-devel Exp $	*/
/*  Run-time system for oo2c programs.
    Copyright (C) 1997-2000  Michael van Acken

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

#include "__oo2c.h"

char* _top_vs;  /* top of value stack */
char* _end_vs;  /* end of value stack */

LONGINT _program_argc;
OOC_CHAR **_program_argv;
INTEGER _program_exit_code = 0;

/* --- initialization function, called at the beginning of main(): */
void _oo2c_init(void) {
}


/* --- string comparison of LONGCHAR: */
int strcmpl(const LONGCHAR *S1, const LONGCHAR *S2) {
  int i = 0;
  while (S1[i] && (S1[i] == S2[i])) { i++; }
  return ((int)S1[i] - (int)S2[i]);
}


/* --- functions to handle exceptions and failed run-time checks: */
#define POS_MODULO 1024
#define PREFIX "## "

static void /*NORETURN*/ _break_rtc(void) ;//NORETURN2;
static void /*NORETURN*/ raise_exception(LONGINT number, _Pos pos) ;//NORETURN2;


void _break_rtc(void) {
/* use this function as breakpoint when debugging a failed runtime check */
  exit(127);
}

static void raise_exception(LONGINT number, _Pos pos) {
    exit(127);			/* should never be reached */
}


void _deref_of_nil(_Pos pos) {
  raise_exception(RT_derefOfNIL, pos);
}

void _real_div_by_zero(_Pos pos) {
  raise_exception(RT_realDivByZero, pos);
}

void _integer_div_by_zero(_Pos pos) {
  raise_exception(RT_integerDivByZero, pos);
}

void _real_overflow(_Pos pos) {
  raise_exception(RT_realOverflow, pos);
}

void _integer_overflow(_Pos pos) {
  raise_exception(RT_integerOverflow, pos);
}

void _invalid_length(LONGINT length, _Pos pos) {
  raise_exception(RT_illegalLength, pos);
}

void _new_failed(_Pos pos) {
  raise_exception(RT_outOfMemory, pos);
}

void _index_out_of_range(LONGINT index, LONGINT length, _Pos pos) {
  raise_exception(RT_indexOutOfRange, pos);
}

void _element_out_of_range(LONGINT index, LONGINT size, _Pos pos) {
  raise_exception(RT_elementOutOfRange, pos);
}

void _no_return(_Pos pos) {
  raise_exception(RT_endOfFunction, pos);
}

void _case_failed(LONGINT select, _Pos pos) {
  raise_exception(RT_noMatchingLabel, pos);
}

void _with_failed(_Pos pos) {
  raise_exception(RT_noValidGuard, pos);
}

void _type_guard_failed(void* tag, _Pos pos) {
  raise_exception(RT_typeGuardFailed, pos);
}

void _type_assert_failed(_Pos pos) {
  raise_exception(RT_typeAssertFailed, pos);
}

void _assertion_failed(LONGINT code, _Pos pos) {
  raise_exception(code, pos);
}

void _halt(LONGINT code){
  raise_exception(code, 0);
}

void _array_stack_overflow(_Pos pos) {
  raise_exception(RT_stackOverflow, pos);
}


#include "__Descr.c"
