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
static N_INLINE(void, nimFrame)(TFrame* s_0);
N_LIB_PRIVATE N_NOINLINE(void, callDepthLimitReached__mMRdr4sgmnykA9aWeM9aDZlw)(void);
static N_INLINE(void, popFrame)(void);
N_LIB_PRIVATE N_NIMCALL(NimStringV2, nimIntToStr)(NI x);

/* section: NIM_merge_VARS */
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
extern NIM_THREADVAR TFrame* framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;

/* section: NIM_merge_PROCS */

#line 549 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
static N_INLINE(void, nimFrame)(TFrame* s_0) {
#line 550 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	{
#line 550 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		if (!(framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw == NIM_NIL)) goto LA3_;

#line 551 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		(*s_0).calldepth = ((NI16) 0);	}
	goto LA1_;
	LA3_: ;
	{
#line 554 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"

#line 554 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		(*s_0).calldepth = (NI16)((*framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw).calldepth + ((NI16) 1));	}
	LA1_: ;

#line 556 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	(*s_0).prev = framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw;
#line 557 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	framePtr__HRfVMH3jYeBJz6Q6X9b6Ptw = s_0;
#line 558 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
	{
#line 558 "/home/elcritch/.asdf/installs/nim/devel/lib/system/excpt.nim"
		if (!((*s_0).calldepth == ((NI16) 2000))) goto LA8_;

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

#line 49 "/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim/einode/src/einode/ei.nim"
N_LIB_PRIVATE N_NIMCALL(NIM_BOOL, eqeq___a89b2C3VWxlbZL6R9b5SVw1Q)(int o, int e) {	NIM_BOOL result;	nimfr_("==", "/home/elcritch/projects/pt/third-party/esp32_nim_net_example/ni"
"m/einode/src/einode/ei.nim");	result = (NIM_BOOL)0;
#line 49 "/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim/einode/src/einode/ei.nim"
	nimln_(49, "/home/elcritch/projects/pt/third-party/esp32_nim_net_example/ni"
"m/einode/src/einode/ei.nim");
#line 49 "/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim/einode/src/einode/ei.nim"
	result = (e == o);	popFrame();	return result;}

#line 48 "/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim/einode/src/einode/ei.nim"
N_LIB_PRIVATE N_NIMCALL(NimStringV2, dollar___8fGJUa6l9cFeeChmx2iqkqQ)(int e) {	NimStringV2 result;	nimfr_("$", "/home/elcritch/projects/pt/third-party/esp32_nim_net_example/ni"
"m/einode/src/einode/ei.nim");	result.len = 0; result.p = NIM_NIL;
#line 48 "/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim/einode/src/einode/ei.nim"
	nimln_(48, "/home/elcritch/projects/pt/third-party/esp32_nim_net_example/ni"
"m/einode/src/einode/ei.nim");
#line 48 "/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim/einode/src/einode/ei.nim"
	result = nimIntToStr(((NI) (e)));	popFrame();	return result;}

#line 89 "/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim/einode/src/einode/ei.nim"
N_LIB_PRIVATE N_NIMCALL(NimStringV2, dollar___KYrIimviN8dOUrL8Ne8pEQ)(int e) {	NimStringV2 result;	nimfr_("$", "/home/elcritch/projects/pt/third-party/esp32_nim_net_example/ni"
"m/einode/src/einode/ei.nim");	result.len = 0; result.p = NIM_NIL;
#line 89 "/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim/einode/src/einode/ei.nim"
	nimln_(89, "/home/elcritch/projects/pt/third-party/esp32_nim_net_example/ni"
"m/einode/src/einode/ei.nim");
#line 89 "/home/elcritch/projects/pt/third-party/esp32_nim_net_example/nim/einode/src/einode/ei.nim"
	result = nimIntToStr(((NI) (e)));	popFrame();	return result;}