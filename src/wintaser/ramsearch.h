#ifndef RAM_SEARCH_H
#define RAM_SEARCH_H


////64k in Ram_68k[], 8k in Ram_Z80[]   
//#define _68K_RAM_SIZE 64*1024
//#define Z80_RAM_SIZE 8*1024
///*#define SRAM_SIZE (((SRAM_End - SRAM_Start) > 2) ? SRAM_End - SRAM_Start : 0)
//#define BRAM_SIZE ((8 << BRAM_Ex_Size) * 1024)*/
//#define GENESIS_RAM_SIZE (_68K_RAM_SIZE + Z80_RAM_SIZE)
//
////_32X_Ram[]
//#define _32X_RAM_SIZE 256*1024
//
////512k in Ram_Prg, 256k in Ram_Word_1M and Ram_Word_2M
////(docs say 6Mbit of ram, but I'm not sure what's used when)
//#define SEGACD_RAM_PRG_SIZE 512*1024
//#define SEGACD_1M_RAM_SIZE 256*1024
//#define SEGACD_2M_RAM_SIZE 256*1024
//#define SEGACD_RAM_SIZE (SEGACD_RAM_PRG_SIZE + SEGACD_2M_RAM_SIZE)


//#define MAX_RAM_SIZE (0x112000)
//#define MAX_RAM_SIZE (0xD2000)


extern char rs_type_size;
extern int ResultCount;
typedef unsigned int HWAddressType;

unsigned int sizeConv(unsigned int index,char size, char *prevSize = &rs_type_size, bool usePrev = false);
unsigned int GetRamValue(unsigned int Addr,char Size);
void prune(char Search, char Operater, char Type, int Value, int OperatorParameter);
void CompactAddrs();
void reset_address_info();
void signal_new_frame();
void signal_new_size();
void UpdateRamSearchTitleBar(int percent = 0);
void SetRamSearchUndoType(HWND hDlg, int type);
unsigned int ReadValueAtHardwareAddress(HWAddressType address, unsigned int size);
bool WriteValueAtHardwareAddress(HWAddressType address, unsigned int value, unsigned int size, bool hookless=false);
bool IsHardwareAddressValid(HWAddressType address);
extern int curr_ram_size;
extern bool noMisalign;
//extern bool littleEndian;

void ResetResults();
void CloseRamWindows(); //Close the Ram Search & Watch windows when rom closes
void ReopenRamWindows(); //Reopen them when a new Rom is loaded
void Update_RAM_Search(); //keeps RAM values up to date in the search and watch windows
void InitRamSearch(); // call only once at program startup

#ifdef _MSC_VER
	#define ALIGN16 __declspec(align(16)) // 16-byte alignment speeds up memcpy for size >= 0x100 (as of VS2005, if SSE2 is supported at runtime)
#else
	#define ALIGN16 // __attribute__((aligned(16)))
#endif


#endif

