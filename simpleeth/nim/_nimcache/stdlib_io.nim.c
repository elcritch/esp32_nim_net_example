/* Generated by Nim Compiler v1.3.5 */
/*   (c) 2020 Andreas Rumpf */
/* The generated code is subject to the original license. */
#define NIM_INTBITS 32
#define NIM_EmulateOverflowChecks

/* section: NIM_merge_HEADERS */

#include "nimbase.h"
#include <stdio.h>
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
  #  define nimfr_(proc, file) \
      TFrame FR_; \
      FR_.procname = proc; FR_.filename = file; FR_.line = 0; FR_.len = 0; nimFrame(&FR_);

  #  define nimfrs_(proc, file, slots, length) \
      struct {TFrame* prev;NCSTRING procname;NI line;NCSTRING filename; NI len; VarSlot s[slots];} FR_; \
      FR_.procname = proc; FR_.filename = file; FR_.line = 0; FR_.len = length; nimFrame((TFrame*)&FR_);

  #  define nimln_(n, file) \
      FR_.line = n; FR_.filename = file;
  
/* section: NIM_merge_FORWARD_TYPES */
typedef struct NimStrPayload NimStrPayload;
typedef struct NimStringV2 NimStringV2;

/* section: NIM_merge_TYPES */
struct NimStrPayload {NI cap;
NIM_CHAR data[SEQ_DECL_SIZE];
};
struct NimStringV2 {NI len;
NimStrPayload* p;
};

/* section: NIM_merge_PROC_HEADERS */
N_LIB_PRIVATE N_NOINLINE(void, raiseIndexError2)(NI i, NI n);
static N_INLINE(NCSTRING, nimToCStringConv)(NimStringV2 s);
static N_INLINE(NIM_BOOL, nimAddInt)(NI a, NI b, NI* res);
N_LIB_PRIVATE N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(void, nimFrame)(TFrame* s);
N_LIB_PRIVATE N_NOINLINE(void, callDepthLimitReached__mMRdr4sgmnykA9aWeM9aDZlw)(void);
static N_INLINE(void, popFrame)(void);

/* section: NIM_merge_VARS */
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;

/* section: NIM_merge_PROCS */

#line 76 "/home/elcritch/.asdf/installs/nim/devel/lib/system/strs_v2.nim"
static N_INLINE(NCSTRING, nimToCStringConv)(NimStringV2 s) {	NCSTRING result;	result = (NCSTRING)0;
#line 77 "/home/elcritch/.asdf/installs/nim/devel/lib/system/strs_v2.nim"
	{
#line 77 "/home/elcritch/.asdf/installs/nim/devel/lib/system/strs_v2.nim"
		if (!(s.len == ((NI) 0))) goto LA3_;

#line 77 "/home/elcritch/.asdf/installs/nim/devel/lib/system/strs_v2.nim"
		result = "";	}
	goto LA1_;
	LA3_: ;
	{
#line 78 "/home/elcritch/.asdf/installs/nim/devel/lib/system/strs_v2.nim"
		result = ((NCSTRING) ((*s.p).data));	}
	LA1_: ;
	return result;}

#line 52 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
static N_INLINE(NIM_BOOL, nimAddInt)(NI a, NI b, NI* res) {	NIM_BOOL result;	NI r;	result = (NIM_BOOL)0;
#line 46 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 46 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	r = ((NI) ((NU)((NU32)(((NU) (a))) + (NU32)(((NU) (b))))));
#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
	{		NIM_BOOL T3_;
#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (NIM_BOOL)0;
#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (((NI) 0) <= (NI)(r ^ a));		if (T3_) goto LA4_;

#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"

#line 47 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		T3_ = (((NI) 0) <= (NI)(r ^ b));		LA4_: ;
		if (!T3_) goto LA5_;

#line 48 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		(*res) = r;	}
	goto LA1_;
	LA5_: ;
	{
#line 50 "/home/elcritch/.asdf/installs/nim/devel/lib/system/integerops.nim"
		result = NIM_TRUE;	}
	LA1_: ;
	return result;}

#line 549 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
static N_INLINE(void, nimFrame)(TFrame* s) {
#line 550 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	{
#line 550 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		if (!(framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw == NIM_NIL)) goto LA3_;

#line 551 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		(*s).calldepth = ((NI16) 0);	}
	goto LA1_;
	LA3_: ;
	{
#line 554 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"

#line 554 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		(*s).calldepth = (NI16)((*framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw).calldepth + ((NI16) 1));	}
	LA1_: ;

#line 556 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	(*s).prev = framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
#line 557 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw = s;
#line 558 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	{
#line 558 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		if (!((*s).calldepth == ((NI16) 2000))) goto LA8_;

#line 558 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"

#line 558 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		callDepthLimitReached__mMRdr4sgmnykA9aWeM9aDZlw();
	}
	LA8_: ;
}

#line 85 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
static N_INLINE(void, popFrame)(void) {
#line 86 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw = (*framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw).prev;}

#line 709 "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim"
N_LIB_PRIVATE N_NIMCALL(void, echoBinSafe)(NimStringV2* args, NI argsLen_0) {	int T5_;	int T6_;	nimfr_("echoBinSafe", "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim");{	{		NimStringV2* s;		NI i;		NI n;		s = (NimStringV2*)0;
#line 16 "/home/elcritch/.asdf/installs/nim/devel/lib/system/iterators.nim"
		nimln_(16, "/home/elcritch/.asdf/installs/nim/devel/lib/system/iterators.ni"
"m");		i = ((NI) 0);
#line 17 "/home/elcritch/.asdf/installs/nim/devel/lib/system/iterators.nim"
		nimln_(17, "/home/elcritch/.asdf/installs/nim/devel/lib/system/iterators.ni"
"m");
#line 17 "/home/elcritch/.asdf/installs/nim/devel/lib/system/iterators.nim"
		n = argsLen_0;		{
#line 18 "/home/elcritch/.asdf/installs/nim/devel/lib/system/iterators.nim"
			nimln_(18, "/home/elcritch/.asdf/installs/nim/devel/lib/system/iterators.ni"
"m");			while (1) {				int T4_;				NI TM__MnCJ0VAmeZ9aTATUB39cx60Q_2;
#line 18 "/home/elcritch/.asdf/installs/nim/devel/lib/system/iterators.nim"
				if (!(i < n)) goto LA3;

#line 723 "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim"
				nimln_(723, "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim");				if ((NU)(i) >= (NU)(argsLen_0)){ raiseIndexError2(i,argsLen_0-1); goto BeforeRet_;}				s = (&args[i]);
#line 727 "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim"
				nimln_(727, "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim");
#line 727 "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim"

#line 727 "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim"

#line 727 "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim"
				T4_ = (int)0;				T4_ = fwrite(((void*) (nimToCStringConv((*s)))), ((size_t) ((*s).len)), ((size_t) 1), stdout);				(void)(T4_);

#line 20 "/home/elcritch/.asdf/installs/nim/devel/lib/system/iterators.nim"
				nimln_(20, "/home/elcritch/.asdf/installs/nim/devel/lib/system/iterators.ni"
"m");				if (nimAddInt(i, ((NI) 1), &TM__MnCJ0VAmeZ9aTATUB39cx60Q_2)) { raiseOverflow(); goto BeforeRet_;};				i = (NI)(TM__MnCJ0VAmeZ9aTATUB39cx60Q_2);			} LA3: ;
		}
	}

#line 729 "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim"
	nimln_(729, "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim");
#line 729 "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim"

#line 729 "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim"
	T5_ = (int)0;	T5_ = fwrite(((void*) ("\012")), ((size_t) 1), ((size_t) 1), stdout);	(void)(T5_);

#line 730 "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim"
	nimln_(730, "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim");
#line 730 "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim"

#line 730 "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim"
	T6_ = (int)0;	T6_ = fflush(stdout);	(void)(T6_);
	}BeforeRet_: ;
	popFrame();}

#line 326 "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim"
N_LIB_PRIVATE N_NIMCALL(NIM_BOOL, setInheritable__avyDiy1HdQrfaD3Ql9b63EQ)(int f, NIM_BOOL inheritable) {	NIM_BOOL result;	nimfr_("setInheritable", "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim");	result = (NIM_BOOL)0;
#line 336 "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim"
	nimln_(336, "/home/elcritch/.asdf/installs/nim/devel/lib/system/io.nim");	result = NIM_TRUE;	popFrame();	return result;}
