/* Generated by Nim Compiler v1.3.5 */
/*   (c) 2020 Andreas Rumpf */
/* The generated code is subject to the original license. */
#define NIM_INTBITS 32
#define NIM_EmulateOverflowChecks

/* section: NIM_merge_HEADERS */

#include "nimbase.h"
#undef LANGUAGE_C
#undef MIPSEB
#undef MIPSEL
#undef PPC
#undef R3000
#undef R4000
#undef i386
#undef linux
#undef mips
#undef near
#undef far
#undef powerpc
#undef unix

/* section: NIM_merge_FRAME_DEFINES */
#define nimfr_(x, y)
#define nimln_(x, y)

/* section: NIM_merge_PROCS */

#line 161 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/math.nim"
N_LIB_PRIVATE N_NIMCALL(NIM_BOOL, isPowerOfTwo__1xdTQapFveM9bImKot7h9cdw)(NI x) {	NIM_BOOL result;	NIM_BOOL T1_;{	result = (NIM_BOOL)0;
#line 173 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/math.nim"

#line 173 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/math.nim"

#line 173 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/math.nim"
	T1_ = (NIM_BOOL)0;
#line 173 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/math.nim"
	T1_ = (((NI) 0) < x);	if (!(T1_)) goto LA2_;

#line 173 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/math.nim"

#line 173 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/math.nim"

#line 173 "/home/elcritch/.asdf/installs/nim/devel/lib/pure/math.nim"
	T1_ = ((NI)(x & (NI)(x - ((NI) 1))) == ((NI) 0));	LA2_: ;
	result = T1_;	goto BeforeRet_;
	}BeforeRet_: ;
	return result;}
