// Game_Music_Emu 0.6-pre. http://www.slack.net/~ant/

#include "kss_emu.h"

#include "blargg_endian.h"
//#include "z80_cpu_log.h"

/* Copyright (C) 2006-2008 Shay Green. This module is free software; you
can redistribute it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version. This
module is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
details. You should have received a copy of the GNU Lesser General Public
License along with this module; if not, write to the Free Software Foundation,
Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA */

#include "blargg_source.h"

#define OUT_PORT(  addr, data ) cpu_out( this, TIME(), addr, data )
#define IN_PORT(   addr       ) cpu_in( this, TIME(), addr )
#define WRITE_MEM( addr, data ) {FLUSH_TIME(); cpu_write( this, addr, data );}
#define IDLE_ADDR               idle_addr

#define CPU_BEGIN \
bool run_cpu( struct Kss_Emu* this, kss_time_t end_time )\
{\
	struct Z80_Cpu *cpu = &this->cpu; \
	Z80_set_end_time( cpu, end_time );

	#include "z80_cpu_run.h"
	
	return warning;
}
