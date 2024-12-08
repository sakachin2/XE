//*CID://+v@01R~:                                                  //~v@01R~
//*********************************************************************//~v208I~
//* uimage.h                                                       //~v208I~
//*    exe image  from winnt.h                                     //~v208I~
//*    exe image  from exe386.h  for os2 LX format                 //~v215I~
//*    exe image  from newexe.h  for     NE format                 //~v215I~
//*********************************************************************//~v208I~
//*v@01 050809:win compile err(duplicate symbol with winnt.h)      //~v@01I~
//v315 000520:vc6 header change(new import object hdr)             //~v315I~
//v215:990103 disas:LX relocation support                          //~v215I~
//v208:981223 uimage.h                                             //~v208I~
//*********************************************************************//~v208I~
#define FOR_EXEHDR 1                                               //~v215I~
//*********************************************************************//~v215M~
//*coyed from winnt.h  for os/2 or win compile speedup             //~v215I~
//*********************************************************************//~v215I~
#ifndef _WINNT_                                                    //~v208I~
                                                                   //~v208I~
#define UNALIGNED                                                  //~v208I~
#define NTAPI                                                      //~v208I~
typedef BYTE  BOOLEAN;                                             //~v208I~
typedef BOOLEAN *PBOOLEAN;                                         //~v208I~
                                                                   //~v208I~
#define MIDL_PASS         for pop/push pack @@@@                   //~v208I~
                                                                   //~v208I~
#if ( _MSC_VER >= 800 )                                            //~v208I~
#pragma warning(disable:4103)                                      //~v208I~
#endif                                                             //~v208I~
//*********************************************************************//~v215I~
//                                                                 //~8C22I~
// Image Format
//

//#include "pshpack4.h"                   // 4 byte packing is the default//~v208R~
#pragma pack(4)                                                    //~v208I~

#define IMAGE_DOS_SIGNATURE                 0x5A4D      // MZ
#define IMAGE_OS2_SIGNATURE                 0x454E      // NE
#define IMAGE_OS2_SIGNATURE_LE              0x454C      // LE
#define IMAGE_VXD_SIGNATURE                 0x454C      // LE
#define IMAGE_NT_SIGNATURE                  0x00004550  // PE00

//#include "pshpack2.h"                   // 16 bit headers are 2 byte packed//~v208R~
#pragma pack(2)                                                    //~v208I~

typedef struct _IMAGE_DOS_HEADER {      // DOS .EXE header
    WORD   e_magic;                     // Magic number
    WORD   e_cblp;                      // Bytes on last page of file
    WORD   e_cp;                        // Pages in file
    WORD   e_crlc;                      // Relocations
    WORD   e_cparhdr;                   // Size of header in paragraphs
    WORD   e_minalloc;                  // Minimum extra paragraphs needed
    WORD   e_maxalloc;                  // Maximum extra paragraphs needed
    WORD   e_ss;                        // Initial (relative) SS value
    WORD   e_sp;                        // Initial SP value
    WORD   e_csum;                      // Checksum
    WORD   e_ip;                        // Initial IP value
    WORD   e_cs;                        // Initial (relative) CS value
    WORD   e_lfarlc;                    // File address of relocation table
    WORD   e_ovno;                      // Overlay number
    WORD   e_res[4];                    // Reserved words
    WORD   e_oemid;                     // OEM identifier (for e_oeminfo)
    WORD   e_oeminfo;                   // OEM information; e_oemid specific
    WORD   e_res2[10];                  // Reserved words
    LONG   e_lfanew;                    // File address of new exe header
  } IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;

typedef struct _IMAGE_OS2_HEADER {      // OS/2 .EXE header
    WORD   ne_magic;                    // Magic number
    CHAR   ne_ver;                      // Version number
    CHAR   ne_rev;                      // Revision number
    WORD   ne_enttab;                   // Offset of Entry Table
    WORD   ne_cbenttab;                 // Number of bytes in Entry Table
    LONG   ne_crc;                      // Checksum of whole file
    WORD   ne_flags;                    // Flag word
    WORD   ne_autodata;                 // Automatic data segment number
    WORD   ne_heap;                     // Initial heap allocation
    WORD   ne_stack;                    // Initial stack allocation
    LONG   ne_csip;                     // Initial CS:IP setting
    LONG   ne_sssp;                     // Initial SS:SP setting
    WORD   ne_cseg;                     // Count of file segments
    WORD   ne_cmod;                     // Entries in Module Reference Table
    WORD   ne_cbnrestab;                // Size of non-resident name table
    WORD   ne_segtab;                   // Offset of Segment Table
    WORD   ne_rsrctab;                  // Offset of Resource Table
    WORD   ne_restab;                   // Offset of resident name table
    WORD   ne_modtab;                   // Offset of Module Reference Table
    WORD   ne_imptab;                   // Offset of Imported Names Table
    LONG   ne_nrestab;                  // Offset of Non-resident Names Table
    WORD   ne_cmovent;                  // Count of movable entries
    WORD   ne_align;                    // Segment alignment shift count
    WORD   ne_cres;                     // Count of resource segments
    BYTE   ne_exetyp;                   // Target Operating system
    BYTE   ne_flagsothers;              // Other .EXE flags
    WORD   ne_pretthunks;               // offset to return thunks
    WORD   ne_psegrefbytes;             // offset to segment ref. bytes
    WORD   ne_swaparea;                 // Minimum code swap area size
    WORD   ne_expver;                   // Expected Windows version number
  } IMAGE_OS2_HEADER, *PIMAGE_OS2_HEADER;

typedef struct _IMAGE_VXD_HEADER {      // Windows VXD header
    WORD   e32_magic;                   // Magic number
    BYTE   e32_border;                  // The byte ordering for the VXD
    BYTE   e32_worder;                  // The word ordering for the VXD
    DWORD  e32_level;                   // The EXE format level for now = 0
    WORD   e32_cpu;                     // The CPU type
    WORD   e32_os;                      // The OS type
    DWORD  e32_ver;                     // Module version
    DWORD  e32_mflags;                  // Module flags
    DWORD  e32_mpages;                  // Module # pages
    DWORD  e32_startobj;                // Object # for instruction pointer
    DWORD  e32_eip;                     // Extended instruction pointer
    DWORD  e32_stackobj;                // Object # for stack pointer
    DWORD  e32_esp;                     // Extended stack pointer
    DWORD  e32_pagesize;                // VXD page size
    DWORD  e32_lastpagesize;            // Last page size in VXD
    DWORD  e32_fixupsize;               // Fixup section size
    DWORD  e32_fixupsum;                // Fixup section checksum
    DWORD  e32_ldrsize;                 // Loader section size
    DWORD  e32_ldrsum;                  // Loader section checksum
    DWORD  e32_objtab;                  // Object table offset
    DWORD  e32_objcnt;                  // Number of objects in module
    DWORD  e32_objmap;                  // Object page map offset
    DWORD  e32_itermap;                 // Object iterated data map offset
    DWORD  e32_rsrctab;                 // Offset of Resource Table
    DWORD  e32_rsrccnt;                 // Number of resource entries
    DWORD  e32_restab;                  // Offset of resident name table
    DWORD  e32_enttab;                  // Offset of Entry Table
    DWORD  e32_dirtab;                  // Offset of Module Directive Table
    DWORD  e32_dircnt;                  // Number of module directives
    DWORD  e32_fpagetab;                // Offset of Fixup Page Table
    DWORD  e32_frectab;                 // Offset of Fixup Record Table
    DWORD  e32_impmod;                  // Offset of Import Module Name Table
    DWORD  e32_impmodcnt;               // Number of entries in Import Module Name Table
    DWORD  e32_impproc;                 // Offset of Import Procedure Name Table
    DWORD  e32_pagesum;                 // Offset of Per-Page Checksum Table
    DWORD  e32_datapage;                // Offset of Enumerated Data Pages
    DWORD  e32_preload;                 // Number of preload pages
    DWORD  e32_nrestab;                 // Offset of Non-resident Names Table
    DWORD  e32_cbnrestab;               // Size of Non-resident Name Table
    DWORD  e32_nressum;                 // Non-resident Name Table Checksum
    DWORD  e32_autodata;                // Object # for automatic data object
    DWORD  e32_debuginfo;               // Offset of the debugging information
    DWORD  e32_debuglen;                // The length of the debugging info. in bytes
    DWORD  e32_instpreload;             // Number of instance pages in preload section of VXD file
    DWORD  e32_instdemand;              // Number of instance pages in demand load section of VXD file
    DWORD  e32_heapsize;                // Size of heap - for 16-bit apps
    BYTE   e32_res3[12];                // Reserved words
    DWORD  e32_winresoff;
    DWORD  e32_winreslen;
    WORD   e32_devid;                   // Device ID for VxD
    WORD   e32_ddkver;                  // DDK version for VxD
  } IMAGE_VXD_HEADER, *PIMAGE_VXD_HEADER;

//#include "poppack.h"                      // Back to 4 byte packing//~v208R~
#pragma pack()                                                     //~v208I~

//
// File header format.
//

typedef struct _IMAGE_FILE_HEADER {
    WORD    Machine;
    WORD    NumberOfSections;
    DWORD   TimeDateStamp;
    DWORD   PointerToSymbolTable;
    DWORD   NumberOfSymbols;
    WORD    SizeOfOptionalHeader;
    WORD    Characteristics;
} IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;

#define IMAGE_SIZEOF_FILE_HEADER             20

#define IMAGE_FILE_RELOCS_STRIPPED           0x0001  // Relocation info stripped from file.
#define IMAGE_FILE_EXECUTABLE_IMAGE          0x0002  // File is executable  (i.e. no unresolved externel references).
#define IMAGE_FILE_LINE_NUMS_STRIPPED        0x0004  // Line nunbers stripped from file.
#define IMAGE_FILE_LOCAL_SYMS_STRIPPED       0x0008  // Local symbols stripped from file.
#define IMAGE_FILE_AGGRESIVE_WS_TRIM         0x0010  // Agressively trim working set
#define IMAGE_FILE_BYTES_REVERSED_LO         0x0080  // Bytes of machine word are reversed.
#define IMAGE_FILE_32BIT_MACHINE             0x0100  // 32 bit word machine.
#define IMAGE_FILE_DEBUG_STRIPPED            0x0200  // Debugging info stripped from file in .DBG file
#define IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP   0x0400  // If Image is on removable media, copy and run from the swap file.
#define IMAGE_FILE_NET_RUN_FROM_SWAP         0x0800  // If Image is on Net, copy and run from the swap file.
#define IMAGE_FILE_SYSTEM                    0x1000  // System File.
#define IMAGE_FILE_DLL                       0x2000  // File is a DLL.
#define IMAGE_FILE_UP_SYSTEM_ONLY            0x4000  // File should only be run on a UP machine
#define IMAGE_FILE_BYTES_REVERSED_HI         0x8000  // Bytes of machine word are reversed.

#define IMAGE_FILE_MACHINE_UNKNOWN           0
#define IMAGE_FILE_MACHINE_I386              0x14c   // Intel 386.
#define IMAGE_FILE_MACHINE_R3000             0x162   // MIPS little-endian, 0x160 big-endian
#define IMAGE_FILE_MACHINE_R4000             0x166   // MIPS little-endian
#define IMAGE_FILE_MACHINE_R10000            0x168   // MIPS little-endian
#define IMAGE_FILE_MACHINE_ALPHA             0x184   // Alpha_AXP
#define IMAGE_FILE_MACHINE_POWERPC           0x1F0   // IBM PowerPC Little-Endian

//
// Directory format.
//

typedef struct _IMAGE_DATA_DIRECTORY {
    DWORD   VirtualAddress;
    DWORD   Size;
} IMAGE_DATA_DIRECTORY, *PIMAGE_DATA_DIRECTORY;

#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES    16

//
// Optional header format.
//

typedef struct _IMAGE_OPTIONAL_HEADER {
    //
    // Standard fields.
    //

    WORD    Magic;
    BYTE    MajorLinkerVersion;
    BYTE    MinorLinkerVersion;
    DWORD   SizeOfCode;
    DWORD   SizeOfInitializedData;
    DWORD   SizeOfUninitializedData;
    DWORD   AddressOfEntryPoint;
    DWORD   BaseOfCode;
    DWORD   BaseOfData;

    //
    // NT additional fields.
    //

    DWORD   ImageBase;
    DWORD   SectionAlignment;
    DWORD   FileAlignment;
    WORD    MajorOperatingSystemVersion;
    WORD    MinorOperatingSystemVersion;
    WORD    MajorImageVersion;
    WORD    MinorImageVersion;
    WORD    MajorSubsystemVersion;
    WORD    MinorSubsystemVersion;
    DWORD   Win32VersionValue;
    DWORD   SizeOfImage;
    DWORD   SizeOfHeaders;
    DWORD   CheckSum;
    WORD    Subsystem;
    WORD    DllCharacteristics;
    DWORD   SizeOfStackReserve;
    DWORD   SizeOfStackCommit;
    DWORD   SizeOfHeapReserve;
    DWORD   SizeOfHeapCommit;
    DWORD   LoaderFlags;
    DWORD   NumberOfRvaAndSizes;
    IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER, *PIMAGE_OPTIONAL_HEADER;

typedef struct _IMAGE_ROM_OPTIONAL_HEADER {
    WORD   Magic;
    BYTE   MajorLinkerVersion;
    BYTE   MinorLinkerVersion;
    DWORD  SizeOfCode;
    DWORD  SizeOfInitializedData;
    DWORD  SizeOfUninitializedData;
    DWORD  AddressOfEntryPoint;
    DWORD  BaseOfCode;
    DWORD  BaseOfData;
    DWORD  BaseOfBss;
    DWORD  GprMask;
    DWORD  CprMask[4];
    DWORD  GpValue;
} IMAGE_ROM_OPTIONAL_HEADER, *PIMAGE_ROM_OPTIONAL_HEADER;

#define IMAGE_SIZEOF_ROM_OPTIONAL_HEADER      56
#define IMAGE_SIZEOF_STD_OPTIONAL_HEADER      28
#define IMAGE_SIZEOF_NT_OPTIONAL_HEADER      224

#define IMAGE_NT_OPTIONAL_HDR_MAGIC        0x10b
#define IMAGE_ROM_OPTIONAL_HDR_MAGIC       0x107

typedef struct _IMAGE_NT_HEADERS {
    DWORD Signature;
    IMAGE_FILE_HEADER FileHeader;
    IMAGE_OPTIONAL_HEADER OptionalHeader;
} IMAGE_NT_HEADERS, *PIMAGE_NT_HEADERS;

typedef struct _IMAGE_ROM_HEADERS {
    IMAGE_FILE_HEADER FileHeader;
    IMAGE_ROM_OPTIONAL_HEADER OptionalHeader;
} IMAGE_ROM_HEADERS, *PIMAGE_ROM_HEADERS;

#define IMAGE_FIRST_SECTION( ntheader ) ((PIMAGE_SECTION_HEADER)        \
    ((DWORD)ntheader +                                                  \
     FIELD_OFFSET( IMAGE_NT_HEADERS, OptionalHeader ) +                 \
     ((PIMAGE_NT_HEADERS)(ntheader))->FileHeader.SizeOfOptionalHeader   \
    ))


// Subsystem Values

#define IMAGE_SUBSYSTEM_UNKNOWN              0   // Unknown subsystem.
#define IMAGE_SUBSYSTEM_NATIVE               1   // Image doesn't require a subsystem.
#define IMAGE_SUBSYSTEM_WINDOWS_GUI          2   // Image runs in the Windows GUI subsystem.
#define IMAGE_SUBSYSTEM_WINDOWS_CUI          3   // Image runs in the Windows character subsystem.
#define IMAGE_SUBSYSTEM_OS2_CUI              5   // image runs in the OS/2 character subsystem.
#define IMAGE_SUBSYSTEM_POSIX_CUI            7   // image run  in the Posix character subsystem.
#define IMAGE_SUBSYSTEM_RESERVED8            8   // image run  in the 8 subsystem.


// Directory Entries

#define IMAGE_DIRECTORY_ENTRY_EXPORT         0   // Export Directory
#define IMAGE_DIRECTORY_ENTRY_IMPORT         1   // Import Directory
#define IMAGE_DIRECTORY_ENTRY_RESOURCE       2   // Resource Directory
#define IMAGE_DIRECTORY_ENTRY_EXCEPTION      3   // Exception Directory
#define IMAGE_DIRECTORY_ENTRY_SECURITY       4   // Security Directory
#define IMAGE_DIRECTORY_ENTRY_BASERELOC      5   // Base Relocation Table
#define IMAGE_DIRECTORY_ENTRY_DEBUG          6   // Debug Directory
#define IMAGE_DIRECTORY_ENTRY_COPYRIGHT      7   // Description String
#define IMAGE_DIRECTORY_ENTRY_GLOBALPTR      8   // Machine Value (MIPS GP)
#define IMAGE_DIRECTORY_ENTRY_TLS            9   // TLS Directory
#define IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG   10   // Load Configuration Directory
#define IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT  11   // Bound Import Directory in headers
#define IMAGE_DIRECTORY_ENTRY_IAT           12   // Import Address Table

//
// Section header format.
//

#define IMAGE_SIZEOF_SHORT_NAME              8

typedef struct _IMAGE_SECTION_HEADER {
    BYTE    Name[IMAGE_SIZEOF_SHORT_NAME];
    union {
            DWORD   PhysicalAddress;
            DWORD   VirtualSize;
    } Misc;
    DWORD   VirtualAddress;
    DWORD   SizeOfRawData;
    DWORD   PointerToRawData;
    DWORD   PointerToRelocations;
    DWORD   PointerToLinenumbers;
    WORD    NumberOfRelocations;
    WORD    NumberOfLinenumbers;
    DWORD   Characteristics;
} IMAGE_SECTION_HEADER, *PIMAGE_SECTION_HEADER;

#define IMAGE_SIZEOF_SECTION_HEADER          40

//
// Section characteristics.
//

//      IMAGE_SCN_TYPE_REG                   0x00000000  // Reserved.
//      IMAGE_SCN_TYPE_DSECT                 0x00000001  // Reserved.
//      IMAGE_SCN_TYPE_NOLOAD                0x00000002  // Reserved.
//      IMAGE_SCN_TYPE_GROUP                 0x00000004  // Reserved.
#define IMAGE_SCN_TYPE_NO_PAD                0x00000008  // Reserved.
//      IMAGE_SCN_TYPE_COPY                  0x00000010  // Reserved.

#define IMAGE_SCN_CNT_CODE                   0x00000020  // Section contains code.
#define IMAGE_SCN_CNT_INITIALIZED_DATA       0x00000040  // Section contains initialized data.
#define IMAGE_SCN_CNT_UNINITIALIZED_DATA     0x00000080  // Section contains uninitialized data.

#define IMAGE_SCN_LNK_OTHER                  0x00000100  // Reserved.
#define IMAGE_SCN_LNK_INFO                   0x00000200  // Section contains comments or some other type of information.
//      IMAGE_SCN_TYPE_OVER                  0x00000400  // Reserved.
#define IMAGE_SCN_LNK_REMOVE                 0x00000800  // Section contents will not become part of image.
#define IMAGE_SCN_LNK_COMDAT                 0x00001000  // Section contents comdat.
//                                           0x00002000  // Reserved.

//      IMAGE_SCN_MEM_PROTECTED - Obsolete   0x00004000
#define IMAGE_SCN_MEM_FARDATA                0x00008000
//      IMAGE_SCN_MEM_SYSHEAP  - Obsolete    0x00010000
#define IMAGE_SCN_MEM_PURGEABLE              0x00020000
#define IMAGE_SCN_MEM_16BIT                  0x00020000
#define IMAGE_SCN_MEM_LOCKED                 0x00040000
#define IMAGE_SCN_MEM_PRELOAD                0x00080000

#define IMAGE_SCN_ALIGN_1BYTES               0x00100000  //
#define IMAGE_SCN_ALIGN_2BYTES               0x00200000  //
#define IMAGE_SCN_ALIGN_4BYTES               0x00300000  //
#define IMAGE_SCN_ALIGN_8BYTES               0x00400000  //
#define IMAGE_SCN_ALIGN_16BYTES              0x00500000  // Default alignment if no others are specified.
#define IMAGE_SCN_ALIGN_32BYTES              0x00600000  //
#define IMAGE_SCN_ALIGN_64BYTES              0x00700000  //
// Unused                                    0x00800000

#define IMAGE_SCN_LNK_NRELOC_OVFL            0x01000000  // Section contains extended relocations.
#define IMAGE_SCN_MEM_DISCARDABLE            0x02000000  // Section can be discarded.
#define IMAGE_SCN_MEM_NOT_CACHED             0x04000000  // Section is not cachable.
#define IMAGE_SCN_MEM_NOT_PAGED              0x08000000  // Section is not pageable.
#define IMAGE_SCN_MEM_SHARED                 0x10000000  // Section is shareable.
#define IMAGE_SCN_MEM_EXECUTE                0x20000000  // Section is executable.
#define IMAGE_SCN_MEM_READ                   0x40000000  // Section is readable.
#define IMAGE_SCN_MEM_WRITE                  0x80000000  // Section is writeable.


//
// TLS Chaacteristic Flags
//
#define IMAGE_SCN_SCALE_INDEX                0x00000001  // Tls index is scaled

//#include "pshpack2.h"                         // Symbols, relocs, and linenumbers are 2 byte packed//~v208R~
#pragma pack(2)                                                    //~v208I~

//
// Symbol format.
//

typedef struct _IMAGE_SYMBOL {
    union {
        BYTE    ShortName[8];
        struct {
            DWORD   Short;     // if 0, use LongName
            DWORD   Long;      // offset into string table
        } Name;
        PBYTE   LongName[2];
    } N;
    DWORD   Value;
    SHORT   SectionNumber;
    WORD    Type;
    BYTE    StorageClass;
    BYTE    NumberOfAuxSymbols;
} IMAGE_SYMBOL;
typedef IMAGE_SYMBOL UNALIGNED *PIMAGE_SYMBOL;


#define IMAGE_SIZEOF_SYMBOL                  18

//
// Section values.
//
// Symbols have a section number of the section in which they are
// defined. Otherwise, section numbers have the following meanings:
//

#define IMAGE_SYM_UNDEFINED           (SHORT)0          // Symbol is undefined or is common.
#define IMAGE_SYM_ABSOLUTE            (SHORT)-1         // Symbol is an absolute value.
#define IMAGE_SYM_DEBUG               (SHORT)-2         // Symbol is a special debug item.

//
// Type (fundamental) values.
//

#define IMAGE_SYM_TYPE_NULL                 0x0000  // no type.
#define IMAGE_SYM_TYPE_VOID                 0x0001  //
#define IMAGE_SYM_TYPE_CHAR                 0x0002  // type character.
#define IMAGE_SYM_TYPE_SHORT                0x0003  // type short integer.
#define IMAGE_SYM_TYPE_INT                  0x0004  //
#define IMAGE_SYM_TYPE_LONG                 0x0005  //
#define IMAGE_SYM_TYPE_FLOAT                0x0006  //
#define IMAGE_SYM_TYPE_DOUBLE               0x0007  //
#define IMAGE_SYM_TYPE_STRUCT               0x0008  //
#define IMAGE_SYM_TYPE_UNION                0x0009  //
#define IMAGE_SYM_TYPE_ENUM                 0x000A  // enumeration.
#define IMAGE_SYM_TYPE_MOE                  0x000B  // member of enumeration.
#define IMAGE_SYM_TYPE_BYTE                 0x000C  //
#define IMAGE_SYM_TYPE_WORD                 0x000D  //
#define IMAGE_SYM_TYPE_UINT                 0x000E  //
#define IMAGE_SYM_TYPE_DWORD                0x000F  //
#define IMAGE_SYM_TYPE_PCODE                0x8000  //

//
// Type (derived) values.
//

#define IMAGE_SYM_DTYPE_NULL                0       // no derived type.
#define IMAGE_SYM_DTYPE_POINTER             1       // pointer.
#define IMAGE_SYM_DTYPE_FUNCTION            2       // function.
#define IMAGE_SYM_DTYPE_ARRAY               3       // array.

//
// Storage classes.
//

#define IMAGE_SYM_CLASS_END_OF_FUNCTION     (BYTE )-1
#define IMAGE_SYM_CLASS_NULL                0x0000
#define IMAGE_SYM_CLASS_AUTOMATIC           0x0001
#define IMAGE_SYM_CLASS_EXTERNAL            0x0002
#define IMAGE_SYM_CLASS_STATIC              0x0003
#define IMAGE_SYM_CLASS_REGISTER            0x0004
#define IMAGE_SYM_CLASS_EXTERNAL_DEF        0x0005
#define IMAGE_SYM_CLASS_LABEL               0x0006
#define IMAGE_SYM_CLASS_UNDEFINED_LABEL     0x0007
#define IMAGE_SYM_CLASS_MEMBER_OF_STRUCT    0x0008
#define IMAGE_SYM_CLASS_ARGUMENT            0x0009
#define IMAGE_SYM_CLASS_STRUCT_TAG          0x000A
#define IMAGE_SYM_CLASS_MEMBER_OF_UNION     0x000B
#define IMAGE_SYM_CLASS_UNION_TAG           0x000C
#define IMAGE_SYM_CLASS_TYPE_DEFINITION     0x000D
#define IMAGE_SYM_CLASS_UNDEFINED_STATIC    0x000E
#define IMAGE_SYM_CLASS_ENUM_TAG            0x000F
#define IMAGE_SYM_CLASS_MEMBER_OF_ENUM      0x0010
#define IMAGE_SYM_CLASS_REGISTER_PARAM      0x0011
#define IMAGE_SYM_CLASS_BIT_FIELD           0x0012

#define IMAGE_SYM_CLASS_FAR_EXTERNAL        0x0044  //

#define IMAGE_SYM_CLASS_BLOCK               0x0064
#define IMAGE_SYM_CLASS_FUNCTION            0x0065
#define IMAGE_SYM_CLASS_END_OF_STRUCT       0x0066
#define IMAGE_SYM_CLASS_FILE                0x0067
// new
#define IMAGE_SYM_CLASS_SECTION             0x0068
#define IMAGE_SYM_CLASS_WEAK_EXTERNAL       0x0069

// type packing constants

#define N_BTMASK                            0x000F
#define N_TMASK                             0x0030
#define N_TMASK1                            0x00C0
#define N_TMASK2                            0x00F0
#define N_BTSHFT                            4
#define N_TSHIFT                            2

// MACROS

// Basic Type of  x
#define BTYPE(x) ((x) & N_BTMASK)

// Is x a pointer?
#ifndef ISPTR
#define ISPTR(x) (((x) & N_TMASK) == (IMAGE_SYM_DTYPE_POINTER << N_BTSHFT))
#endif

// Is x a function?
#ifndef ISFCN
#define ISFCN(x) (((x) & N_TMASK) == (IMAGE_SYM_DTYPE_FUNCTION << N_BTSHFT))
#endif

// Is x an array?

#ifndef ISARY
#define ISARY(x) (((x) & N_TMASK) == (IMAGE_SYM_DTYPE_ARRAY << N_BTSHFT))
#endif

// Is x a structure, union, or enumeration TAG?
#ifndef ISTAG
#define ISTAG(x) ((x)==IMAGE_SYM_CLASS_STRUCT_TAG || (x)==IMAGE_SYM_CLASS_UNION_TAG || (x)==IMAGE_SYM_CLASS_ENUM_TAG)
#endif

#ifndef INCREF
#define INCREF(x) ((((x)&~N_BTMASK)<<N_TSHIFT)|(IMAGE_SYM_DTYPE_POINTER<<N_BTSHFT)|((x)&N_BTMASK))
#endif
#ifndef DECREF
#define DECREF(x) ((((x)>>N_TSHIFT)&~N_BTMASK)|((x)&N_BTMASK))
#endif

//
// Auxiliary entry format.
//

typedef union _IMAGE_AUX_SYMBOL {
    struct {
        DWORD    TagIndex;                      // struct, union, or enum tag index
        union {
            struct {
                WORD    Linenumber;             // declaration line number
                WORD    Size;                   // size of struct, union, or enum
            } LnSz;
           DWORD    TotalSize;
        } Misc;
        union {
            struct {                            // if ISFCN, tag, or .bb
                DWORD    PointerToLinenumber;
                DWORD    PointerToNextFunction;
            } Function;
            struct {                            // if ISARY, up to 4 dimen.
                WORD     Dimension[4];
            } Array;
        } FcnAry;
        WORD    TvIndex;                        // tv index
    } Sym;
    struct {
        BYTE    Name[IMAGE_SIZEOF_SYMBOL];
    } File;
    struct {
        DWORD   Length;                         // section length
        WORD    NumberOfRelocations;            // number of relocation entries
        WORD    NumberOfLinenumbers;            // number of line numbers
        DWORD   CheckSum;                       // checksum for communal
        SHORT   Number;                         // section number to associate with
        BYTE    Selection;                      // communal selection type
    } Section;
} IMAGE_AUX_SYMBOL;
typedef IMAGE_AUX_SYMBOL UNALIGNED *PIMAGE_AUX_SYMBOL;

#define IMAGE_SIZEOF_AUX_SYMBOL             18

//
// Communal selection types.
//

#define IMAGE_COMDAT_SELECT_NODUPLICATES    1
#define IMAGE_COMDAT_SELECT_ANY             2
#define IMAGE_COMDAT_SELECT_SAME_SIZE       3
#define IMAGE_COMDAT_SELECT_EXACT_MATCH     4
#define IMAGE_COMDAT_SELECT_ASSOCIATIVE     5
#define IMAGE_COMDAT_SELECT_LARGEST         6
#define IMAGE_COMDAT_SELECT_NEWEST          7

#define IMAGE_WEAK_EXTERN_SEARCH_NOLIBRARY  1
#define IMAGE_WEAK_EXTERN_SEARCH_LIBRARY    2
#define IMAGE_WEAK_EXTERN_SEARCH_ALIAS      3

//
// Relocation format.
//

typedef struct _IMAGE_RELOCATION {
    union {
        DWORD   VirtualAddress;
        DWORD   RelocCount;             // Set to the real count when IMAGE_SCN_LNK_NRELOC_OVFL is set
    } _union_;                                                     //~v215R~
    DWORD   SymbolTableIndex;
    WORD    Type;
} IMAGE_RELOCATION;
typedef IMAGE_RELOCATION UNALIGNED *PIMAGE_RELOCATION;

#define IMAGE_SIZEOF_RELOCATION         10

//
// I386 relocation types.
//

#define IMAGE_REL_I386_ABSOLUTE         0x0000  // Reference is absolute, no relocation is necessary
#define IMAGE_REL_I386_DIR16            0x0001  // Direct 16-bit reference to the symbols virtual address
#define IMAGE_REL_I386_REL16            0x0002  // PC-relative 16-bit reference to the symbols virtual address
#define IMAGE_REL_I386_DIR32            0x0006  // Direct 32-bit reference to the symbols virtual address
#define IMAGE_REL_I386_DIR32NB          0x0007  // Direct 32-bit reference to the symbols virtual address, base not included
#define IMAGE_REL_I386_SEG12            0x0009  // Direct 16-bit reference to the segment-selector bits of a 32-bit virtual address
#define IMAGE_REL_I386_SECTION          0x000A
#define IMAGE_REL_I386_SECREL           0x000B
#define IMAGE_REL_I386_REL32            0x0014  // PC-relative 32-bit reference to the symbols virtual address

//
// MIPS relocation types.
//

#define IMAGE_REL_MIPS_ABSOLUTE         0x0000  // Reference is absolute, no relocation is necessary
#define IMAGE_REL_MIPS_REFHALF          0x0001
#define IMAGE_REL_MIPS_REFWORD          0x0002
#define IMAGE_REL_MIPS_JMPADDR          0x0003
#define IMAGE_REL_MIPS_REFHI            0x0004
#define IMAGE_REL_MIPS_REFLO            0x0005
#define IMAGE_REL_MIPS_GPREL            0x0006
#define IMAGE_REL_MIPS_LITERAL          0x0007
#define IMAGE_REL_MIPS_SECTION          0x000A
#define IMAGE_REL_MIPS_SECREL           0x000B
#define IMAGE_REL_MIPS_SECRELLO         0x000C  // Low 16-bit section relative referemce (used for >32k TLS)
#define IMAGE_REL_MIPS_SECRELHI         0x000D  // High 16-bit section relative reference (used for >32k TLS)
#define IMAGE_REL_MIPS_REFWORDNB        0x0022
#define IMAGE_REL_MIPS_PAIR             0x0025

//
// Alpha Relocation types.
//

#define IMAGE_REL_ALPHA_ABSOLUTE        0x0000
#define IMAGE_REL_ALPHA_REFLONG         0x0001
#define IMAGE_REL_ALPHA_REFQUAD         0x0002
#define IMAGE_REL_ALPHA_GPREL32         0x0003
#define IMAGE_REL_ALPHA_LITERAL         0x0004
#define IMAGE_REL_ALPHA_LITUSE          0x0005
#define IMAGE_REL_ALPHA_GPDISP          0x0006
#define IMAGE_REL_ALPHA_BRADDR          0x0007
#define IMAGE_REL_ALPHA_HINT            0x0008
#define IMAGE_REL_ALPHA_INLINE_REFLONG  0x0009
#define IMAGE_REL_ALPHA_REFHI           0x000A
#define IMAGE_REL_ALPHA_REFLO           0x000B
#define IMAGE_REL_ALPHA_PAIR            0x000C
#define IMAGE_REL_ALPHA_MATCH           0x000D
#define IMAGE_REL_ALPHA_SECTION         0x000E
#define IMAGE_REL_ALPHA_SECREL          0x000F
#define IMAGE_REL_ALPHA_REFLONGNB       0x0010
#define IMAGE_REL_ALPHA_SECRELLO        0x0011  // Low 16-bit section relative reference
#define IMAGE_REL_ALPHA_SECRELHI        0x0012  // High 16-bit section relative reference

//
// IBM PowerPC relocation types.
//

#define IMAGE_REL_PPC_ABSOLUTE          0x0000  // NOP
#define IMAGE_REL_PPC_ADDR64            0x0001  // 64-bit address
#define IMAGE_REL_PPC_ADDR32            0x0002  // 32-bit address
#define IMAGE_REL_PPC_ADDR24            0x0003  // 26-bit address, shifted left 2 (branch absolute)
#define IMAGE_REL_PPC_ADDR16            0x0004  // 16-bit address
#define IMAGE_REL_PPC_ADDR14            0x0005  // 16-bit address, shifted left 2 (load doubleword)
#define IMAGE_REL_PPC_REL24             0x0006  // 26-bit PC-relative offset, shifted left 2 (branch relative)
#define IMAGE_REL_PPC_REL14             0x0007  // 16-bit PC-relative offset, shifted left 2 (br cond relative)
#define IMAGE_REL_PPC_TOCREL16          0x0008  // 16-bit offset from TOC base
#define IMAGE_REL_PPC_TOCREL14          0x0009  // 16-bit offset from TOC base, shifted left 2 (load doubleword)

#define IMAGE_REL_PPC_ADDR32NB          0x000A  // 32-bit addr w/o image base
#define IMAGE_REL_PPC_SECREL            0x000B  // va of containing section (as in an image sectionhdr)
#define IMAGE_REL_PPC_SECTION           0x000C  // sectionheader number
#define IMAGE_REL_PPC_IFGLUE            0x000D  // substitute TOC restore instruction iff symbol is glue code
#define IMAGE_REL_PPC_IMGLUE            0x000E  // symbol is glue code; virtual address is TOC restore instruction
#define IMAGE_REL_PPC_SECREL16          0x000F  // va of containing section (limited to 16 bits)
#define IMAGE_REL_PPC_REFHI             0x0010
#define IMAGE_REL_PPC_REFLO             0x0011
#define IMAGE_REL_PPC_PAIR              0x0012
#define IMAGE_REL_PPC_SECRELLO          0x0013  // Low 16-bit section relative reference (used for >32k TLS)
#define IMAGE_REL_PPC_SECRELHI          0x0014  // High 16-bit section relative reference (used for >32k TLS)

#define IMAGE_REL_PPC_TYPEMASK          0x00FF  // mask to isolate above values in IMAGE_RELOCATION.Type

// Flag bits in IMAGE_RELOCATION.TYPE

#define IMAGE_REL_PPC_NEG               0x0100  // subtract reloc value rather than adding it
#define IMAGE_REL_PPC_BRTAKEN           0x0200  // fix branch prediction bit to predict branch taken
#define IMAGE_REL_PPC_BRNTAKEN          0x0400  // fix branch prediction bit to predict branch not taken
#define IMAGE_REL_PPC_TOCDEFN           0x0800  // toc slot defined in file (or, data in toc)

//
// Line number format.
//

typedef struct _IMAGE_LINENUMBER {
    union {
        DWORD   SymbolTableIndex;               // Symbol table index of function name if Linenumber is 0.
        DWORD   VirtualAddress;                 // Virtual address of line number.
    } Type;
    WORD    Linenumber;                         // Line number.
} IMAGE_LINENUMBER;
typedef IMAGE_LINENUMBER UNALIGNED *PIMAGE_LINENUMBER;

#define IMAGE_SIZEOF_LINENUMBER              6

//#include "poppack.h"                          // Back to 4 byte packing//~v208R~
#pragma pack()                                                     //~v208I~

//
// Based relocation format.
//

typedef struct _IMAGE_BASE_RELOCATION {
    DWORD   VirtualAddress;
    DWORD   SizeOfBlock;
//  WORD    TypeOffset[1];
} IMAGE_BASE_RELOCATION;
typedef IMAGE_BASE_RELOCATION UNALIGNED * PIMAGE_BASE_RELOCATION;

#define IMAGE_SIZEOF_BASE_RELOCATION         8

//
// Based relocation types.
//

#define IMAGE_REL_BASED_ABSOLUTE              0
#define IMAGE_REL_BASED_HIGH                  1
#define IMAGE_REL_BASED_LOW                   2
#define IMAGE_REL_BASED_HIGHLOW               3
#define IMAGE_REL_BASED_HIGHADJ               4
#define IMAGE_REL_BASED_MIPS_JMPADDR          5
#define IMAGE_REL_BASED_SECTION               6
#define IMAGE_REL_BASED_REL32                 7

//
// Archive format.
//

#define IMAGE_ARCHIVE_START_SIZE             8
#define IMAGE_ARCHIVE_START                  "!<arch>\n"
#define IMAGE_ARCHIVE_END                    "`\n"
#define IMAGE_ARCHIVE_PAD                    "\n"
#define IMAGE_ARCHIVE_LINKER_MEMBER          "/               "
#define IMAGE_ARCHIVE_LONGNAMES_MEMBER       "//              "

typedef struct _IMAGE_ARCHIVE_MEMBER_HEADER {
    BYTE     Name[16];                          // File member name - `/' terminated.
    BYTE     Date[12];                          // File member date - decimal.
    BYTE     UserID[6];                         // File member user id - decimal.
    BYTE     GroupID[6];                        // File member group id - decimal.
    BYTE     Mode[8];                           // File member mode - octal.
    BYTE     Size[10];                          // File member size - decimal.
    BYTE     EndHeader[2];                      // String to end header.
} IMAGE_ARCHIVE_MEMBER_HEADER, *PIMAGE_ARCHIVE_MEMBER_HEADER;

#define IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR      60

//
// DLL support.
//

//
// Export Format
//

typedef struct _IMAGE_EXPORT_DIRECTORY {
    DWORD   Characteristics;
    DWORD   TimeDateStamp;
    WORD    MajorVersion;
    WORD    MinorVersion;
    DWORD   Name;
    DWORD   Base;
    DWORD   NumberOfFunctions;
    DWORD   NumberOfNames;
    PDWORD  *AddressOfFunctions;
    PDWORD  *AddressOfNames;
    PWORD   *AddressOfNameOrdinals;
} IMAGE_EXPORT_DIRECTORY, *PIMAGE_EXPORT_DIRECTORY;

//
// Import Format
//

typedef struct _IMAGE_IMPORT_BY_NAME {
    WORD    Hint;
    BYTE    Name[1];
} IMAGE_IMPORT_BY_NAME, *PIMAGE_IMPORT_BY_NAME;

typedef struct _IMAGE_THUNK_DATA {
    union {
        PBYTE  ForwarderString;
        PDWORD Function;
        DWORD Ordinal;
        PIMAGE_IMPORT_BY_NAME AddressOfData;
    } u1;
} IMAGE_THUNK_DATA;
typedef IMAGE_THUNK_DATA * PIMAGE_THUNK_DATA;

#define IMAGE_ORDINAL_FLAG 0x80000000
#define IMAGE_SNAP_BY_ORDINAL(Ordinal) ((Ordinal & IMAGE_ORDINAL_FLAG) != 0)
#define IMAGE_ORDINAL(Ordinal) (Ordinal & 0xffff)

typedef struct _IMAGE_IMPORT_DESCRIPTOR {
    union {
        DWORD   Characteristics;                // 0 for terminating null import descriptor
        PIMAGE_THUNK_DATA OriginalFirstThunk;   // RVA to original unbound IAT
    }_union_;                                                      //~v215R~
    DWORD   TimeDateStamp;                  // 0 if not bound,
                                            // -1 if bound, and real date\time stamp
                                            //     in IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT (new BIND)
                                            // O.W. date/time stamp of DLL bound to (Old BIND)

    DWORD   ForwarderChain;                 // -1 if no forwarders
    DWORD   Name;
    PIMAGE_THUNK_DATA FirstThunk;           // RVA to IAT (if bound this IAT has actual addresses)
} IMAGE_IMPORT_DESCRIPTOR;
typedef IMAGE_IMPORT_DESCRIPTOR UNALIGNED *PIMAGE_IMPORT_DESCRIPTOR;

//
// New format import descriptors pointed to by DataDirectory[ IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT ]
//

typedef struct _IMAGE_BOUND_IMPORT_DESCRIPTOR {
    DWORD   TimeDateStamp;
    WORD    OffsetModuleName;
    WORD    NumberOfModuleForwarderRefs;
// Array of zero or more IMAGE_BOUND_FORWARDER_REF follows
} IMAGE_BOUND_IMPORT_DESCRIPTOR,  *PIMAGE_BOUND_IMPORT_DESCRIPTOR;

typedef struct _IMAGE_BOUND_FORWARDER_REF {
    DWORD   TimeDateStamp;
    WORD    OffsetModuleName;
    WORD    Reserved;
} IMAGE_BOUND_FORWARDER_REF, *PIMAGE_BOUND_FORWARDER_REF;


//
// Thread Local Storage
//

typedef VOID
(NTAPI *PIMAGE_TLS_CALLBACK) (
    PVOID DllHandle,
    DWORD Reason,
    PVOID Reserved
    );

typedef struct _IMAGE_TLS_DIRECTORY {
    DWORD   StartAddressOfRawData;
    DWORD   EndAddressOfRawData;
    PDWORD  AddressOfIndex;
    PIMAGE_TLS_CALLBACK *AddressOfCallBacks;
    DWORD   SizeOfZeroFill;
    DWORD   Characteristics;
} IMAGE_TLS_DIRECTORY, *PIMAGE_TLS_DIRECTORY;


//
// Resource Format.
//

//
// Resource directory consists of two counts, following by a variable length
// array of directory entries.  The first count is the number of entries at
// beginning of the array that have actual names associated with each entry.
// The entries are in ascending order, case insensitive strings.  The second
// count is the number of entries that immediately follow the named entries.
// This second count identifies the number of entries that have 16-bit integer
// Ids as their name.  These entries are also sorted in ascending order.
//
// This structure allows fast lookup by either name or number, but for any
// given resource entry only one form of lookup is supported, not both.
// This is consistant with the syntax of the .RC file and the .RES file.
//

typedef struct _IMAGE_RESOURCE_DIRECTORY {
    DWORD   Characteristics;
    DWORD   TimeDateStamp;
    WORD    MajorVersion;
    WORD    MinorVersion;
    WORD    NumberOfNamedEntries;
    WORD    NumberOfIdEntries;
//  IMAGE_RESOURCE_DIRECTORY_ENTRY DirectoryEntries[];
} IMAGE_RESOURCE_DIRECTORY, *PIMAGE_RESOURCE_DIRECTORY;

#define IMAGE_RESOURCE_NAME_IS_STRING        0x80000000
#define IMAGE_RESOURCE_DATA_IS_DIRECTORY     0x80000000

//
// Each directory contains the 32-bit Name of the entry and an offset,
// relative to the beginning of the resource directory of the data associated
// with this directory entry.  If the name of the entry is an actual text
// string instead of an integer Id, then the high order bit of the name field
// is set to one and the low order 31-bits are an offset, relative to the
// beginning of the resource directory of the string, which is of type
// IMAGE_RESOURCE_DIRECTORY_STRING.  Otherwise the high bit is clear and the
// low-order 16-bits are the integer Id that identify this resource directory
// entry. If the directory entry is yet another resource directory (i.e. a
// subdirectory), then the high order bit of the offset field will be
// set to indicate this.  Otherwise the high bit is clear and the offset
// field points to a resource data entry.
//

typedef struct _IMAGE_RESOURCE_DIRECTORY_ENTRY {
    union {
        struct {
            DWORD NameOffset:31;
            DWORD NameIsString:1;
        }  Name2;		//@@@@ name "Name2" is added for OS/2      //~v208R~
        DWORD   Name;
        WORD    Id;
    }_union_1;                                                     //~v215R~
    union {
        DWORD   OffsetToData;
        struct {
            DWORD   OffsetToDirectory:31;
            DWORD   DataIsDirectory:1;
        }  Name3;		//@@@@ name "Name3" is added for OS/2      //~v208R~
    }_union_2;                                                     //~v215R~
} IMAGE_RESOURCE_DIRECTORY_ENTRY, *PIMAGE_RESOURCE_DIRECTORY_ENTRY;

//
// For resource directory entries that have actual string names, the Name
// field of the directory entry points to an object of the following type.
// All of these string objects are stored together after the last resource
// directory entry and before the first resource data object.  This minimizes
// the impact of these variable length objects on the alignment of the fixed
// size directory entry objects.
//

typedef struct _IMAGE_RESOURCE_DIRECTORY_STRING {
    WORD    Length;
    CHAR    NameString[ 1 ];
} IMAGE_RESOURCE_DIRECTORY_STRING, *PIMAGE_RESOURCE_DIRECTORY_STRING;


typedef struct _IMAGE_RESOURCE_DIR_STRING_U {
    WORD    Length;
    WCHAR   NameString[ 1 ];
} IMAGE_RESOURCE_DIR_STRING_U, *PIMAGE_RESOURCE_DIR_STRING_U;


//
// Each resource data entry describes a leaf node in the resource directory
// tree.  It contains an offset, relative to the beginning of the resource
// directory of the data for the resource, a size field that gives the number
// of bytes of data at that offset, a CodePage that should be used when
// decoding code point values within the resource data.  Typically for new
// applications the code page would be the unicode code page.
//

typedef struct _IMAGE_RESOURCE_DATA_ENTRY {
    DWORD   OffsetToData;
    DWORD   Size;
    DWORD   CodePage;
    DWORD   Reserved;
} IMAGE_RESOURCE_DATA_ENTRY, *PIMAGE_RESOURCE_DATA_ENTRY;

//
// Load Configuration Directory Entry
//

typedef struct _IMAGE_LOAD_CONFIG_DIRECTORY {
    DWORD   Characteristics;
    DWORD   TimeDateStamp;
    WORD    MajorVersion;
    WORD    MinorVersion;
    DWORD   GlobalFlagsClear;
    DWORD   GlobalFlagsSet;
    DWORD   CriticalSectionDefaultTimeout;
    DWORD   DeCommitFreeBlockThreshold;
    DWORD   DeCommitTotalFreeThreshold;
    PVOID   LockPrefixTable;
    DWORD   MaximumAllocationSize;
    DWORD   VirtualMemoryThreshold;
    DWORD   ProcessHeapFlags;
    DWORD   ProcessAffinityMask;
    DWORD   Reserved[ 3 ];
} IMAGE_LOAD_CONFIG_DIRECTORY, *PIMAGE_LOAD_CONFIG_DIRECTORY;


//
// Function table entry format for MIPS/ALPHA images.  Function table is
// pointed to by the IMAGE_DIRECTORY_ENTRY_EXCEPTION directory entry.
// This definition duplicates ones in ntmips.h and ntalpha.h for use
// by portable image file mungers.
//

typedef struct _IMAGE_RUNTIME_FUNCTION_ENTRY {
    DWORD BeginAddress;
    DWORD EndAddress;
    PVOID ExceptionHandler;
    PVOID HandlerData;
    DWORD PrologEndAddress;
} IMAGE_RUNTIME_FUNCTION_ENTRY, *PIMAGE_RUNTIME_FUNCTION_ENTRY;

//
// Debug Format
//

typedef struct _IMAGE_DEBUG_DIRECTORY {
    DWORD   Characteristics;
    DWORD   TimeDateStamp;
    WORD    MajorVersion;
    WORD    MinorVersion;
    DWORD   Type;
    DWORD   SizeOfData;
    DWORD   AddressOfRawData;
    DWORD   PointerToRawData;
} IMAGE_DEBUG_DIRECTORY, *PIMAGE_DEBUG_DIRECTORY;

#define IMAGE_DEBUG_TYPE_UNKNOWN          0
#define IMAGE_DEBUG_TYPE_COFF             1
#define IMAGE_DEBUG_TYPE_CODEVIEW         2
#define IMAGE_DEBUG_TYPE_FPO              3
#define IMAGE_DEBUG_TYPE_MISC             4
#define IMAGE_DEBUG_TYPE_EXCEPTION        5
#define IMAGE_DEBUG_TYPE_FIXUP            6
#define IMAGE_DEBUG_TYPE_OMAP_TO_SRC      7
#define IMAGE_DEBUG_TYPE_OMAP_FROM_SRC    8


typedef struct _IMAGE_COFF_SYMBOLS_HEADER {
    DWORD   NumberOfSymbols;
    DWORD   LvaToFirstSymbol;
    DWORD   NumberOfLinenumbers;
    DWORD   LvaToFirstLinenumber;
    DWORD   RvaToFirstByteOfCode;
    DWORD   RvaToLastByteOfCode;
    DWORD   RvaToFirstByteOfData;
    DWORD   RvaToLastByteOfData;
} IMAGE_COFF_SYMBOLS_HEADER, *PIMAGE_COFF_SYMBOLS_HEADER;

#define FRAME_FPO       0
#define FRAME_TRAP      1
#define FRAME_TSS       2
#define FRAME_NONFPO    3

typedef struct _FPO_DATA {
    DWORD       ulOffStart;             // offset 1st byte of function code
    DWORD       cbProcSize;             // # bytes in function
    DWORD       cdwLocals;              // # bytes in locals/4
    WORD        cdwParams;              // # bytes in params/4
//    WORD        cbProlog : 8;           // # bytes in prolog     //~v208R~
//    WORD        cbRegs   : 3;           // # regs saved          //~v208R~
//    WORD        fHasSEH  : 1;           // TRUE if SEH in func   //~v208R~
//    WORD        fUseBP   : 1;           // TRUE if EBP has been allocated//~v208R~
//    WORD        reserved : 1;           // reserved for future use//~v208R~
//    WORD        cbFrame  : 2;           // frame type            //~v208R~
      WORD        aaaaaaa;  //@@@@for OS/2 compile bit fld is allowed only for int//~v208R~
} FPO_DATA, *PFPO_DATA;
#define SIZEOF_RFPO_DATA 16


#define IMAGE_DEBUG_MISC_EXENAME    1

typedef struct _IMAGE_DEBUG_MISC {
    DWORD       DataType;               // type of misc data, see defines
    DWORD       Length;                 // total length of record, rounded to four
                                        // byte multiple.
    BOOLEAN     Unicode;                // TRUE if data is unicode string
    BYTE        Reserved[ 3 ];
    BYTE        Data[ 1 ];              // Actual data
} IMAGE_DEBUG_MISC, *PIMAGE_DEBUG_MISC;


//
// Function table extracted from MIPS/ALPHA images.  Does not contain
// information needed only for runtime support.  Just those fields for
// each entry needed by a debugger.
//

typedef struct _IMAGE_FUNCTION_ENTRY {
    DWORD   StartingAddress;
    DWORD   EndingAddress;
    DWORD   EndOfPrologue;
} IMAGE_FUNCTION_ENTRY, *PIMAGE_FUNCTION_ENTRY;

//
// Debugging information can be stripped from an image file and placed
// in a separate .DBG file, whose file name part is the same as the
// image file name part (e.g. symbols for CMD.EXE could be stripped
// and placed in CMD.DBG).  This is indicated by the IMAGE_FILE_DEBUG_STRIPPED
// flag in the Characteristics field of the file header.  The beginning of
// the .DBG file contains the following structure which captures certain
// information from the image file.  This allows a debug to proceed even if
// the original image file is not accessable.  This header is followed by
// zero of more IMAGE_SECTION_HEADER structures, followed by zero or more
// IMAGE_DEBUG_DIRECTORY structures.  The latter structures and those in
// the image file contain file offsets relative to the beginning of the
// .DBG file.
//
// If symbols have been stripped from an image, the IMAGE_DEBUG_MISC structure
// is left in the image file, but not mapped.  This allows a debugger to
// compute the name of the .DBG file, from the name of the image in the
// IMAGE_DEBUG_MISC structure.
//

typedef struct _IMAGE_SEPARATE_DEBUG_HEADER {
    WORD        Signature;
    WORD        Flags;
    WORD        Machine;
    WORD        Characteristics;
    DWORD       TimeDateStamp;
    DWORD       CheckSum;
    DWORD       ImageBase;
    DWORD       SizeOfImage;
    DWORD       NumberOfSections;
    DWORD       ExportedNamesSize;
    DWORD       DebugDirectorySize;
    DWORD       SectionAlignment;
    DWORD       Reserved[2];
} IMAGE_SEPARATE_DEBUG_HEADER, *PIMAGE_SEPARATE_DEBUG_HEADER;

#define IMAGE_SEPARATE_DEBUG_SIGNATURE  0x4944

#define IMAGE_SEPARATE_DEBUG_FLAGS_MASK 0x8000
#define IMAGE_SEPARATE_DEBUG_MISMATCH   0x8000  // when DBG was updated, the
                                                // old checksum didn't match.

#include "poppack.h"                          // Return to the default//~v208R~
#pragma pack()                                                     //~v208I~

//
// End Image Format
//
#endif /* _WINNT_ */                                               //~v208I~
//**********************************************************************//~v215I~
//*  END of image from winnt.h                                     //~v215I~
//**********************************************************************//~v215I~
                                                                   //~v215I~
//**************************************************************** //~v208I~
//*from ddk\inc32\vmm.h ****************************************** //~v208I~
//**************************************************************** //~v208I~
                                                                   //~v208I~
#ifndef DDK_VERSION                                                //~v208I~
                                                                   //~v208I~
#ifdef WIN31COMPAT                                                 //~v208I~
	#define DDK_VERSION 0x30A           /* 3.10 */                 //~v208I~
#else  /* WIN31COMPAT */                                           //~v208I~
	#define DDK_VERSION 0x400           /* 4.00 */                 //~v208I~
#endif                                                             //~v208I~
                                                                   //~v208I~
#endif                                                             //~v208I~
                                                                   //~v208I~
struct VxD_Desc_Block {                                            //~v208I~
    ULONG DDB_Next;         /* VMM RESERVED FIELD */               //~v208I~
    USHORT DDB_SDK_Version;     /* INIT <DDK_VERSION> RESERVED FIELD *///~v208I~
    USHORT DDB_Req_Device_Number;   /* INIT <UNDEFINED_DEVICE_ID> *///~v208I~
    UCHAR DDB_Dev_Major_Version;    /* INIT <0> Major device number *///~v208I~
    UCHAR DDB_Dev_Minor_Version;    /* INIT <0> Minor device number *///~v208I~
    USHORT DDB_Flags;           /* INIT <0> for init calls complete *///~v208I~
    UCHAR DDB_Name[8];          /* AINIT <"        "> Device name *///~v208I~
    ULONG DDB_Init_Order;       /* INIT <UNDEFINED_INIT_ORDER> */  //~v208I~
    ULONG DDB_Control_Proc;     /* Offset of control procedure */  //~v208I~
    ULONG DDB_V86_API_Proc;     /* INIT <0> Offset of API procedure *///~v208I~
    ULONG DDB_PM_API_Proc;      /* INIT <0> Offset of API procedure *///~v208I~
    ULONG DDB_V86_API_CSIP;     /* INIT <0> CS:IP of API entry point *///~v208I~
    ULONG DDB_PM_API_CSIP;      /* INIT <0> CS:IP of API entry point *///~v208I~
    ULONG DDB_Reference_Data;       /* Reference data from real mode *///~v208I~
    ULONG DDB_Service_Table_Ptr;    /* INIT <0> Pointer to service table *///~v208I~
    ULONG DDB_Service_Table_Size;   /* INIT <0> Number of services *///~v208I~
    ULONG DDB_Win32_Service_Table;  /* INIT <0> Pointer to Win32 services *///~v208I~
    ULONG DDB_Prev;         /* INIT <'Prev'> Ptr to prev 4.0 DDB *///~v208I~
    ULONG DDB_Size;		/* INIT <SIZE(VxD_Desc_Block)> Reserved */ //~v208I~
    ULONG DDB_Reserved1;        /* INIT <'Rsv1'> Reserved */       //~v208I~
    ULONG DDB_Reserved2;        /* INIT <'Rsv2'> Reserved */       //~v208I~
    ULONG DDB_Reserved3;        /* INIT <'Rsv3'> Reserved */       //~v208I~
};                                                                 //~v208R~
                                                                   //~v208I~
typedef struct VxD_Desc_Block       VMMDDB;	//@@@@                 //~v208I~
typedef struct VxD_Desc_Block       *PVMMDDB;                      //~v208I~
typedef PVMMDDB             *PPVMMDDB;                             //~v208I~
                                                                   //~v208I~
//#ifndef Not_VxD    @@@@@@@@@                                     //~v208I~
                                                                   //~v208I~
/*                                                                 //~v208I~
 *  Flag values for DDB_Flags                                      //~v208I~
 */                                                                //~v208I~
                                                                   //~v208I~
#define DDB_SYS_CRIT_INIT_DONE_BIT  0                              //~v208I~
#define DDB_SYS_CRIT_INIT_DONE      (1 << DDB_SYS_CRIT_INIT_DONE_BIT)//~v208I~
#define DDB_DEVICE_INIT_DONE_BIT    1                              //~v208I~
#define DDB_DEVICE_INIT_DONE        (1 << DDB_DEVICE_INIT_DONE_BIT)//~v208I~
                                                                   //~v208I~
#define DDB_HAS_WIN32_SVCS_BIT      14                             //~v208I~
#define DDB_HAS_WIN32_SVCS      (1 << DDB_HAS_WIN32_SVCS_BIT)      //~v208I~
#define DDB_DYNAMIC_VXD_BIT     15                                 //~v208I~
#define DDB_DYNAMIC_VXD         (1 << DDB_DYNAMIC_VXD_BIT)         //~v208I~
                                                                   //~v208I~
#define DDB_DEVICE_DYNALINKED_BIT   13                             //~v208I~
#define DDB_DEVICE_DYNALINKED       (1 << DDB_DEVICE_DYNALINKED_BIT)//~v208I~
                                                                   //~v215I~
//**********************************************************************//~v215I~
//*  END of vmm.h                                                  //~v215I~
//**********************************************************************//~v215I~
                                                                   //~v215I~
//**********************************************************************//~v215R~
//*from toolkt21\os2h  for win compile,os2 compile speed           //~v215I~
//*  exe386.h                                                      //~v215I~
//**********************************************************************//~v215I~
/*static char *SCCSID = "@(#)exe386.h   6.10 92/01/09";*/          //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  Title                                                          //~v215I~
 *                                                                 //~v215I~
 *      exe386.h                                                   //~v215I~
 *                                                                 //~v215I~
 *      Copyright (c) IBM Corporation 1987, 1991                   //~v215I~
 *      Copyright (c) Microsoft Corp 1988, 1991                    //~v215I~
 *                                                                 //~v215I~
 *  Description                                                    //~v215I~
 *                                                                 //~v215I~
 *      Data structure definitions for the OS/2                    //~v215I~
 *      executable file format (flat model).                       //~v215I~
 *                                                                 //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
#ifdef __IBMC__                                                    //~v215I~
#pragma checkout( suspend )                                        //~v215I~
   #ifndef __CHKHDR__                                              //~v215I~
      #pragma checkout( suspend )                                  //~v215I~
   #endif                                                          //~v215I~
#pragma checkout( resume )                                         //~v215I~
#endif                                                             //~v215I~
                                                                   //~v215I~
#ifndef __EXE386__                                                 //~v215I~
#define __EXE386__                                                 //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
#pragma pack(1)    /* Force byte alignment */                      //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
/*_________________________________________________________________//~v215R~
     |                                                                 |//~v215I~
     |                                                                 |//~v215I~
     |  OS/2 .EXE FILE HEADER DEFINITION - 386 version 0:32            |//~v215I~
     |                                                                 |//~v215I~
     |_________________________________________________________________|//~v215I~
                                                                       *///~v215R~
                                                                   //~v215I~
                                                                   //~v215I~
#define BITPERWORD      16                                         //~v215I~
#define BITPERBYTE      8                                          //~v215I~
#define OBJPAGELEN      4096                                       //~v215I~
#define E32MAGIC1       'L'        /* New magic number  "LX" */    //~v215I~
#define E32MAGIC2       'X'        /* New magic number  "LX" */    //~v215I~
#define E32MAGIC        0x584c     /* New magic number  "LX" */    //~v215I~
#define E32RESBYTES1    0          /* First bytes reserved */      //~v215I~
#define E32RESBYTES2    0          /* Second bytes reserved */     //~v215I~
#define E32RESBYTES3    20         /* Third bytes reserved */      //~v215I~
#define E32LEBO         0x00       /* Little Endian Byte Order */  //~v215I~
#define E32BEBO         0x01       /* Big Endian Byte Order */     //~v215I~
#define E32LEWO         0x00       /* Little Endian Word Order */  //~v215I~
#define E32BEWO         0x01       /* Big Endian Word Order */     //~v215I~
#define E32LEVEL        0L         /* 32-bit EXE format level */   //~v215I~
#define E32CPU286       0x001      /* Intel 80286 or upwardly compatibile *///~v215I~
#define E32CPU386       0x002      /* Intel 80386 or upwardly compatibile *///~v215I~
#define E32CPU486       0x003      /* Intel 80486 or upwardly compatibile *///~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
struct e32_exe                          /* New 32-bit .EXE header *///~v215I~
{                                                                  //~v215I~
    unsigned char       e32_magic[2];   /* Magic number E32_MAGIC *///~v215I~
    unsigned char       e32_border;     /* The byte ordering for the .EXE *///~v215I~
    unsigned char       e32_worder;     /* The word ordering for the .EXE *///~v215I~
    unsigned long       e32_level;      /* The EXE format level for now = 0 *///~v215I~
    unsigned short      e32_cpu;        /* The CPU type */         //~v215I~
    unsigned short      e32_os;         /* The OS type */          //~v215I~
    unsigned long       e32_ver;        /* Module version */       //~v215I~
    unsigned long       e32_mflags;     /* Module flags */         //~v215I~
    unsigned long       e32_mpages;     /* Module # pages */       //~v215I~
    unsigned long       e32_startobj;   /* Object # for instruction pointer *///~v215I~
    unsigned long       e32_eip;        /* Extended instruction pointer *///~v215I~
    unsigned long       e32_stackobj;   /* Object # for stack pointer *///~v215I~
    unsigned long       e32_esp;        /* Extended stack pointer *///~v215I~
    unsigned long       e32_pagesize;   /* .EXE page size */       //~v215I~
    unsigned long       e32_pageshift;  /* Page alignment shift in .EXE *///~v215I~
    unsigned long       e32_fixupsize;  /* Fixup section size */   //~v215I~
    unsigned long       e32_fixupsum;   /* Fixup section checksum *///~v215I~
    unsigned long       e32_ldrsize;    /* Loader section size */  //~v215I~
    unsigned long       e32_ldrsum;     /* Loader section checksum *///~v215I~
    unsigned long       e32_objtab;     /* Object table offset */  //~v215I~
    unsigned long       e32_objcnt;     /* Number of objects in module *///~v215I~
    unsigned long       e32_objmap;     /* Object page map offset *///~v215I~
    unsigned long       e32_itermap;    /* Object iterated data map offset *///~v215I~
    unsigned long       e32_rsrctab;    /* Offset of Resource Table *///~v215I~
    unsigned long       e32_rsrccnt;    /* Number of resource entries *///~v215I~
    unsigned long       e32_restab;     /* Offset of resident name table *///~v215I~
    unsigned long       e32_enttab;     /* Offset of Entry Table *///~v215I~
    unsigned long       e32_dirtab;     /* Offset of Module Directive Table *///~v215I~
    unsigned long       e32_dircnt;     /* Number of module directives *///~v215I~
    unsigned long       e32_fpagetab;   /* Offset of Fixup Page Table *///~v215I~
    unsigned long       e32_frectab;    /* Offset of Fixup Record Table *///~v215I~
    unsigned long       e32_impmod;     /* Offset of Import Module Name Table *///~v215I~
    unsigned long       e32_impmodcnt;  /* Number of entries in Import Module Name Table *///~v215I~
    unsigned long       e32_impproc;    /* Offset of Import Procedure Name Table *///~v215I~
    unsigned long       e32_pagesum;    /* Offset of Per-Page Checksum Table *///~v215I~
    unsigned long       e32_datapage;   /* Offset of Enumerated Data Pages *///~v215I~
    unsigned long       e32_preload;    /* Number of preload pages *///~v215I~
    unsigned long       e32_nrestab;    /* Offset of Non-resident Names Table *///~v215I~
    unsigned long       e32_cbnrestab;  /* Size of Non-resident Name Table *///~v215I~
    unsigned long       e32_nressum;    /* Non-resident Name Table Checksum *///~v215I~
    unsigned long       e32_autodata;   /* Object # for automatic data object *///~v215I~
    unsigned long       e32_debuginfo;  /* Offset of the debugging information *///~v215I~
    unsigned long       e32_debuglen;   /* The length of the debugging info. in bytes *///~v215I~
    unsigned long       e32_instpreload;/* Number of instance pages in preload section of .EXE file *///~v215I~
    unsigned long       e32_instdemand; /* Number of instance pages in demand load section of .EXE file *///~v215I~
    unsigned long       e32_heapsize;   /* Size of heap - for 16-bit apps *///~v215I~
    unsigned long       e32_stacksize;  /* Size of stack */        //~v215I~
    unsigned char       e32_res3[E32RESBYTES3];                    //~v215I~
                                        /* Pad structure to 196 bytes *///~v215I~
  };                                                               //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
#define E32_MAGIC1(x)       (x).e32_magic[0]                       //~v215I~
#define E32_MAGIC2(x)       (x).e32_magic[1]                       //~v215I~
#define E32_BORDER(x)       (x).e32_border                         //~v215I~
#define E32_WORDER(x)       (x).e32_worder                         //~v215I~
#define E32_LEVEL(x)        (x).e32_level                          //~v215I~
#define E32_CPU(x)          (x).e32_cpu                            //~v215I~
#define E32_OS(x)           (x).e32_os                             //~v215I~
#define E32_VER(x)          (x).e32_ver                            //~v215I~
#define E32_MFLAGS(x)       (x).e32_mflags                         //~v215I~
#define E32_MPAGES(x)       (x).e32_mpages                         //~v215I~
#define E32_STARTOBJ(x)     (x).e32_startobj                       //~v215I~
#define E32_EIP(x)          (x).e32_eip                            //~v215I~
#define E32_STACKOBJ(x)     (x).e32_stackobj                       //~v215I~
#define E32_ESP(x)          (x).e32_esp                            //~v215I~
#define E32_PAGESIZE(x)     (x).e32_pagesize                       //~v215I~
#define E32_PAGESHIFT(x)    (x).e32_pageshift                      //~v215I~
#define E32_FIXUPSIZE(x)    (x).e32_fixupsize                      //~v215I~
#define E32_FIXUPSUM(x)     (x).e32_fixupsum                       //~v215I~
#define E32_LDRSIZE(x)      (x).e32_ldrsize                        //~v215I~
#define E32_LDRSUM(x)       (x).e32_ldrsum                         //~v215I~
#define E32_OBJTAB(x)       (x).e32_objtab                         //~v215I~
#define E32_OBJCNT(x)       (x).e32_objcnt                         //~v215I~
#define E32_OBJMAP(x)       (x).e32_objmap                         //~v215I~
#define E32_ITERMAP(x)      (x).e32_itermap                        //~v215I~
#define E32_RSRCTAB(x)      (x).e32_rsrctab                        //~v215I~
#define E32_RSRCCNT(x)      (x).e32_rsrccnt                        //~v215I~
#define E32_RESTAB(x)       (x).e32_restab                         //~v215I~
#define E32_ENTTAB(x)       (x).e32_enttab                         //~v215I~
#define E32_DIRTAB(x)       (x).e32_dirtab                         //~v215I~
#define E32_DIRCNT(x)       (x).e32_dircnt                         //~v215I~
#define E32_FPAGETAB(x)     (x).e32_fpagetab                       //~v215I~
#define E32_FRECTAB(x)      (x).e32_frectab                        //~v215I~
#define E32_IMPMOD(x)       (x).e32_impmod                         //~v215I~
#define E32_IMPMODCNT(x)    (x).e32_impmodcnt                      //~v215I~
#define E32_IMPPROC(x)      (x).e32_impproc                        //~v215I~
#define E32_PAGESUM(x)      (x).e32_pagesum                        //~v215I~
#define E32_DATAPAGE(x)     (x).e32_datapage                       //~v215I~
#define E32_PRELOAD(x)      (x).e32_preload                        //~v215I~
#define E32_NRESTAB(x)      (x).e32_nrestab                        //~v215I~
#define E32_CBNRESTAB(x)    (x).e32_cbnrestab                      //~v215I~
#define E32_NRESSUM(x)      (x).e32_nressum                        //~v215I~
#define E32_AUTODATA(x)     (x).e32_autodata                       //~v215I~
#define E32_DEBUGINFO(x)    (x).e32_debuginfo                      //~v215I~
#define E32_DEBUGLEN(x)     (x).e32_debuglen                       //~v215I~
#define E32_INSTPRELOAD(x)  (x).e32_instpreload                    //~v215I~
#define E32_INSTDEMAND(x)   (x).e32_instdemand                     //~v215I~
#define E32_HEAPSIZE(x)     (x).e32_heapsize                       //~v215I~
#define E32_STACKSIZE(x)    (x).e32_stacksize                      //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  Format of E32_MFLAGS(x):                                       //~v215I~
 *                                                                 //~v215I~
 *  Low word has the following format:                             //~v215I~
 *                                                                 //~v215I~
 *  15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0  - bit no                //~v215I~
 *   |     |          | |     | | | |                              //~v215I~
 *   |     |          | |     | | | +------- Per-Process Library Initialization//~v215I~
 *   |     |          | |     | | +--------- SystemDLL (internal fixups discarded)//~v215I~
 *   |     |          | |     | +----------- No Internal Fixups for Module in .EXE//~v215I~
 *   |     |          | |     +------------- No External Fixups for Module in .EXE//~v215I~
 *   |     |          | +------------------- Incompatible with PM Windowing//~v215I~
 *   |     |          +--------------------- Compatible with PM Windowing//~v215I~
 *   |     |                                 Uses PM Windowing API //~v215I~
 *   |     +-------------------------------- Module not Loadable   //~v215I~
 *   +-------------------------------------- Library Module        //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
#define E32NOTP          0x8000L        /* Library Module - used as NENOTP *///~v215I~
#define E32NOLOAD        0x2000L        /* Module not Loadable */  //~v215I~
#define E32PMAPI         0x0300L        /* Uses PM Windowing API *///~v215I~
#define E32PMW           0x0200L        /* Compatible with PM Windowing *///~v215I~
#define E32NOPMW         0x0100L        /* Incompatible with PM Windowing *///~v215I~
#define E32NOEXTFIX      0x0020L        /* NO External Fixups in .EXE *///~v215I~
#define E32NOINTFIX      0x0010L        /* NO Internal Fixups in .EXE *///~v215I~
#define E32SYSDLL        0x0008L        /* System DLL, Internal Fixups discarded*///~v215I~
#define E32LIBINIT       0x0004L        /* Per-Process Library Initialization *///~v215I~
#define E32LIBTERM       0x40000000L    /* Per-Process Library Termination *///~v215I~
#define E32APPMASK       0x0300L        /* Application Type Mask *///~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  Format of E32_MFLAGS(x):                                       //~v215I~
 *                                                                 //~v215I~
 *  High word has the following format:                            //~v215I~
 *                                                                 //~v215I~
 *  15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0  - bit no                //~v215I~
 *                                    | |                          //~v215I~
 *                                    | +--- Protected memory library module//~v215I~
 *                                    +----- Device driver         //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
#define E32PROTDLL       0x10000L       /* Protected memory library module *///~v215I~
#define E32DEVICE        0x20000L       /* Device driver                   *///~v215I~
#define E32MODEXE        0x00000L       /* .EXE module                     *///~v215I~
#define E32MODDLL        0x08000L       /* .DLL module                     *///~v215I~
#define E32MODPROTDLL    0x18000L       /* Protected memory library module *///~v215I~
#define E32MODPDEV       0x20000L       /* Physical device driver          *///~v215I~
#define E32MODVDEV       0x28000L       /* Virtual device driver           *///~v215I~
#define E32MODMASK       0x38000L       /* Module type mask                *///~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  RELOCATION DEFINITIONS - RUN-TIME FIXUPS                       //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
typedef union _offset                                              //~v215I~
{                                                                  //~v215I~
    unsigned short offset16;                                       //~v215I~
    unsigned long  offset32;                                       //~v215I~
}                                                                  //~v215I~
    offset;                             /* 16-bit or 32-bit offset *///~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
/***ET+ r32_rlc - Relocation item */                               //~v215I~
                                                                   //~v215I~
struct r32_rlc                          /* Relocation item */      //~v215I~
{                                                                  //~v215I~
    unsigned char       nr_stype;       /* Source type - field shared with new_rlc *///~v215I~
    unsigned char       nr_flags;       /* Flag byte - field shared with new_rlc *///~v215I~
    short               r32_soff;       /* Source offset */        //~v215I~
    unsigned short      r32_objmod;     /* Target object number or Module ordinal *///~v215I~
                                                                   //~v215I~
    union targetid                                                 //~v215I~
    {                                                              //~v215I~
        offset             intref;      /* Internal fixup */       //~v215I~
                                                                   //~v215I~
        union extfixup                                             //~v215I~
        {                                                          //~v215I~
            offset         proc;        /* Procedure name offset *///~v215I~
            unsigned long  ord;         /* Procedure odrinal */    //~v215I~
        }                                                          //~v215I~
                           extref;      /* External fixup */       //~v215I~
                                                                   //~v215I~
        struct addfixup                                            //~v215I~
        {                                                          //~v215I~
            unsigned short entry;       /* Entry ordinal */        //~v215I~
            offset         addval;      /* Value added to the address *///~v215I~
        }                                                          //~v215I~
                           addfix;      /* Additive fixup */       //~v215I~
    }                                                              //~v215I~
                        r32_target;     /* Target data */          //~v215I~
    unsigned short      r32_srccount;   /* Number of chained fixup records *///~v215I~
    unsigned short      r32_chain;      /* Chain head */           //~v215I~
};                                                                 //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  In 32-bit .EXE file run-time relocations are written as varying size//~v215I~
 *  records, so we need many size definitions.                     //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
#define RINTSIZE16      8                                          //~v215I~
#define RINTSIZE32      10                                         //~v215I~
#define RORDSIZE        8                                          //~v215I~
#define RNAMSIZE16      8                                          //~v215I~
#define RNAMSIZE32      10                                         //~v215I~
#define RADDSIZE16      10                                         //~v215I~
#define RADDSIZE32      12                                         //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
#if FALSE                                                          //~v215I~
/*                                                                 //~v215I~
 *  Access macros defined in NEWEXE.H !!!                          //~v215I~
 */                                                                //~v215I~
#define NR_STYPE(x)      (x).nr_stype                              //~v215I~
#define NR_FLAGS(x)      (x).nr_flags                              //~v215I~
#endif                                                             //~v215I~
                                                                   //~v215I~
#define R32_SOFF(x)      (x).r32_soff                              //~v215I~
#define R32_OBJNO(x)     (x).r32_objmod                            //~v215I~
#define R32_MODORD(x)    (x).r32_objmod                            //~v215I~
#define R32_OFFSET16(x)  (x).r32_target.intref.offset16            //~v215I~
#define R32_OFFSET32(x)  (x).r32_target.intref.offset32            //~v215I~
#define R32_PROCOFF16(x) (x).r32_target.extref.proc.offset16       //~v215I~
#define R32_PROCOFF32(x) (x).r32_target.extref.proc.offset32       //~v215I~
#define R32_PROCORD(x)   (x).r32_target.extref.ord                 //~v215I~
#define R32_ENTRY(x)     (x).r32_target.addfix.entry               //~v215I~
#define R32_ADDVAL16(x)  (x).r32_target.addfix.addval.offset16     //~v215I~
#define R32_ADDVAL32(x)  (x).r32_target.addfix.addval.offset32     //~v215I~
#define R32_SRCCNT(x)    (x).r32_srccount                          //~v215I~
#define R32_CHAIN(x)     (x).r32_chain                             //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  Format of NR_STYPE(x)                                          //~v215I~
 *                                                                 //~v215I~
 *       7 6 5 4 3 2 1 0  - bit no                                 //~v215I~
 *           | | | | | |                                           //~v215I~
 *           | | +-+-+-+--- Source type                            //~v215I~
 *           | +----------- Fixup to 16:16 alias                   //~v215I~
 *           +------------- List of source offset follows fixup record//~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
#if FALSE                                                          //~v215R~
                                                                   //~v215I~
            /* DEFINED in newexe.h !!! */                          //~v215I~
                                                                   //~v215I~
#define NRSTYP          0x0f            /* Source type mask */     //~v215I~
#define NRSBYT          0x00            /* lo byte (8-bits)*/      //~v215I~
#define NRSSEG          0x02            /* 16-bit segment (16-bits) *///~v215I~
#define NRSPTR          0x03            /* 16:16 pointer (32-bits) *///~v215I~
#define NRSOFF          0x05            /* 16-bit offset (16-bits) *///~v215I~
#define NRPTR48         0x06            /* 16:32 pointer (48-bits) *///~v215I~
#define NROFF32         0x07            /* 32-bit offset (32-bits) *///~v215I~
#define NRSOFF32        0x08            /* 32-bit self-relative offset (32-bits) *///~v215I~
#endif                                                             //~v215R~
                                                                   //~v215I~
                                                                   //~v215I~
#define NRSRCMASK       0x0f            /* Source type mask */     //~v215I~
#define NRALIAS         0x10            /* Fixup to alias */       //~v215I~
#define NRCHAIN         0x20            /* List of source offset follows *///~v215I~
                                        /* fixup record, source offset field *///~v215I~
                                        /* in fixup record contains number *///~v215I~
                                        /* of elements in list */  //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  Format of NR_FLAGS(x) and R32_FLAGS(x):                        //~v215I~
 *                                                                 //~v215I~
 *       7 6 5 4 3 2 1 0  - bit no                                 //~v215I~
 *       | | | |   | | |                                           //~v215I~
 *       | | | |   | +-+--- Reference type                         //~v215I~
 *       | | | |   +------- Additive fixup                         //~v215I~
 *       | | | +----------- 32-bit Target Offset Flag (1 - 32-bit; 0 - 16-bit)//~v215I~
 *       | | +------------- 32-bit Additive Flag (1 - 32-bit; 0 - 16-bit)//~v215I~
 *       | +--------------- 16-bit Object/Module ordinal (1 - 16-bit; 0 - 8-bit)//~v215I~
 *       +----------------- 8-bit import ordinal (1 - 8-bit;       //~v215I~
 *                                                0 - NR32BITOFF toggles//~v215I~
 *                                                    between 16 and 32 bit//~v215I~
 *                                                    ordinal)     //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
#if FALSE                                                          //~v215R~
                                                                   //~v215I~
            /* DEFINED in newexe.h !!! */                          //~v215I~
                                                                   //~v215I~
#define NRRTYP          0x03            /* Reference type mask */  //~v215I~
#define NRRINT          0x00            /* Internal reference */   //~v215I~
#define NRRORD          0x01            /* Import by ordinal */    //~v215I~
#define NRRNAM          0x02            /* Import by name */       //~v215I~
#define NRADD           0x04            /* Additive fixup */       //~v215I~
#endif                                                             //~v215R~
                                                                   //~v215I~
#define NRRENT          0x03            /* Internal entry table fixup *///~v215I~
                                                                   //~v215I~
#define NR32BITOFF      0x10            /* 32-bit Target Offset */ //~v215I~
#define NR32BITADD      0x20            /* 32-bit Additive fixup *///~v215I~
#define NR16OBJMOD      0x40            /* 16-bit Object/Module ordinal *///~v215I~
#define NR8BITORD       0x80            /* 8-bit import ordinal */ //~v215I~
/*end*/                                                            //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  Data structures for storing run-time fixups in linker virtual memory.//~v215I~
 *                                                                 //~v215I~
 *  Each object has a list of Object Page Directories which specify//~v215I~
 *  fixups for given page. Each page has its own hash table which is//~v215I~
 *  used to detect fixups to the same target.                      //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
#define PAGEPERDIR      62                                         //~v215I~
#define LG2DIR          7                                          //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
typedef struct _OBJPAGEDIR                                         //~v215I~
{                                                                  //~v215I~
    DWORD   next;                       /* Virtual pointer to next dir on list *///~v215I~
    WORD    ht[PAGEPERDIR];             /* Pointers to individual hash tables *///~v215I~
}                                                                  //~v215I~
    OBJPAGEDIR;                                                    //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  OBJECT TABLE                                                   //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
/***ET+ o32_obj Object Table Entry */                              //~v215I~
                                                                   //~v215I~
struct o32_obj                          /* Flat .EXE object table entry *///~v215I~
{                                                                  //~v215I~
    unsigned long       o32_size;       /* Object virtual size */  //~v215I~
    unsigned long       o32_base;       /* Object base virtual address *///~v215I~
    unsigned long       o32_flags;      /* Attribute flags */      //~v215I~
    unsigned long       o32_pagemap;    /* Object page map index *///~v215I~
    unsigned long       o32_mapsize;    /* Number of entries in object page map *///~v215I~
    unsigned long       o32_reserved;   /* Reserved */             //~v215I~
};                                                                 //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
#define O32_SIZE(x)     (x).o32_size                               //~v215I~
#define O32_BASE(x)     (x).o32_base                               //~v215I~
#define O32_FLAGS(x)    (x).o32_flags                              //~v215I~
#define O32_PAGEMAP(x)  (x).o32_pagemap                            //~v215I~
#define O32_MAPSIZE(x)  (x).o32_mapsize                            //~v215I~
#define O32_RESERVED(x) (x).o32_reserved                           //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  Format of O32_FLAGS(x)                                         //~v215I~
 *                                                                 //~v215I~
 *  High word of dword flag field is not used for now.             //~v215I~
 *  Low word has the following format:                             //~v215I~
 *                                                                 //~v215I~
 *  15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0  - bit no                //~v215I~
 *   |  |  |  |     | | | | | | | | | | |                          //~v215I~
 *   |  |  |  |     | | | | | | | | | | +--- Readable Object       //~v215I~
 *   |  |  |  |     | | | | | | | | | +----- Writeable Object      //~v215I~
 *   |  |  |  |     | | | | | | | | +------- Executable Object     //~v215I~
 *   |  |  |  |     | | | | | | | +--------- Resource Object       //~v215I~
 *   |  |  |  |     | | | | | | +----------- Object is Discardable //~v215I~
 *   |  |  |  |     | | | | | +------------- Object is Shared      //~v215I~
 *   |  |  |  |     | | | | +--------------- Object has preload pages//~v215I~
 *   |  |  |  |     | | | +----------------- Object has invalid pages//~v215I~
 *   |  |  |  |     | | +------------------- Object is permanent and swappable//~v215I~
 *   |  |  |  |     | +--------------------- Object is permanent and resident//~v215I~
 *   |  |  |  |     +----------------------- Object is permanent and long lockable//~v215I~
 *   |  |  |  +----------------------------- 16:16 alias required (80x86 specific)//~v215I~
 *   |  |  +-------------------------------- Big/Default bit setting (80x86 specific)//~v215I~
 *   |  +----------------------------------- Object is conforming for code (80x86 specific)//~v215I~
 *   +-------------------------------------- Object I/O privilege level (80x86 specific)//~v215I~
 *                                                                 //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
#define OBJREAD         0x0001L             /* Readable Object   *///~v215I~
#define OBJWRITE        0x0002L             /* Writeable Object  *///~v215I~
#define OBJRSRC         0x0008L             /* Resource Object   *///~v215I~
#define OBJINVALID      0x0080L             /* Object has invalid pages  *///~v215I~
#define LNKNONPERM      0x0600L             /* Object is nonpermanent - should be *///~v215I~
#define OBJNONPERM      0x0000L             /* zero in the .EXE but LINK386 uses 6 *///~v215I~
#define OBJPERM         0x0100L             /* Object is permanent and swappable *///~v215I~
#define OBJRESIDENT     0x0200L             /* Object is permanent and resident *///~v215I~
#define OBJCONTIG       0x0300L             /* Object is resident and contiguous *///~v215I~
#define OBJDYNAMIC      0x0400L             /* Object is permanent and long locable *///~v215I~
#define OBJTYPEMASK     0x0700L             /* Object type mask */ //~v215I~
#define OBJALIAS16      0x1000L             /* 16:16 alias required (80x86 specific)           *///~v215I~
#define OBJBIGDEF       0x2000L             /* Big/Default bit setting (80x86 specific)        *///~v215I~
#define OBJIOPL         0x8000L             /* Object I/O privilege level (80x86 specific)     *///~v215I~
#if FOR_EXEHDR                                                     //~v215I~
/*                                                                 //~v215I~
 *  Name these flags differently for EXEHDR.EXE - avoid conflicts with 286 version//~v215I~
 */                                                                //~v215I~
#define OBJDISCARD       0x0010L            /* Object is Discardable *///~v215I~
#define OBJSHARED        0x0020L            /* Object is Shared */ //~v215I~
#define OBJPRELOAD       0x0040L            /* Object has preload pages  *///~v215I~
#define OBJEXEC          0x0004L            /* Executable Object *///~v215I~
#define OBJCONFORM       0x4000L            /* Object is conforming for code (80x86 specific)  *///~v215I~
#else                                                              //~v215I~
/*                                                                 //~v215I~
 *  Life will be easier, if we keep the same names for the following flags://~v215I~
 */                                                                //~v215I~
#define NSDISCARD       0x0010L             /* Object is Discardable *///~v215I~
#define NSMOVE          NSDISCARD           /* Moveable object is for sure Discardable *///~v215I~
#define NSSHARED        0x0020L             /* Object is Shared */ //~v215I~
#define NSPRELOAD       0x0040L             /* Object has preload pages  *///~v215I~
#define NSEXRD          0x0004L             /* Executable Object *///~v215I~
#define NSCONFORM       0x4000L             /* Object is conforming for code (80x86 specific)  *///~v215I~
#endif                                                             //~v215I~
/*end*/                                                            //~v215I~
                                                                   //~v215I~
/***ET+ o32_map - Object Page Map entry */                         //~v215I~
                                                                   //~v215I~
struct o32_map                              /* Object Page Table entry *///~v215I~
{                                                                  //~v215I~
    unsigned long   o32_pagedataoffset;     /* file offset of page *///~v215I~
    unsigned short  o32_pagesize;           /* # bytes of page data *///~v215I~
    unsigned short  o32_pageflags;          /* Per-Page attributes *///~v215I~
};                                                                 //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
#define GETPAGEIDX(x)    ((x).o32_pagedataoffset)                  //~v215I~
                                                                   //~v215I~
#define PUTPAGEIDX(x,i)  ((x).o32_pagedataoffset = ((unsigned long)(i)))//~v215I~
                                                                   //~v215I~
#define PUTPAGESIZ(x,i)  ((x).o32_pagesize = ((unsigned int)(i)))  //~v215I~
                                                                   //~v215I~
#define GETPAGESIZ(x)    ((x).o32_pagesize)                        //~v215I~
                                                                   //~v215I~
#define PAGEFLAGS(x)    (x).o32_pageflags                          //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
#define VALID           0x0000                /* Valid Physical Page in .EXE *///~v215I~
#define ITERDATA        0x0001                /* Iterated Data Page *///~v215I~
#define INVALID         0x0002                /* Invalid Page */   //~v215I~
#define ZEROED          0x0003                /* Zero Filled Page *///~v215I~
#define RANGE           0x0004                /* Range of pages */ //~v215I~
#define ITERDATA2       0x0005                /* Iterated Data Page Type II *///~v215I~
/*end*/                                                            //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  RESOURCE TABLE                                                 //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
/***ET+ rsrc32 - Resource Table Entry */                           //~v215I~
                                                                   //~v215I~
struct rsrc32                               /* Resource Table Entry *///~v215I~
{                                                                  //~v215I~
    unsigned short      type;               /* Resource type */    //~v215I~
    unsigned short      name;               /* Resource name */    //~v215I~
    unsigned long       cb;                 /* Resource size */    //~v215I~
    unsigned short      obj;                /* Object number */    //~v215I~
    unsigned long       offset;             /* Offset within object *///~v215I~
};                                                                 //~v215I~
/*end*/                                                            //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
 /*                                                                //~v215I~
  * Iteration Record format for 'EXEPACK'ed pages.                 //~v215I~
  */                                                               //~v215I~
struct LX_Iter                                                     //~v215I~
{                                                                  //~v215I~
    unsigned short LX_nIter;            /* number of iterations */ //~v215I~
    unsigned short LX_nBytes;           /* number of bytes */      //~v215I~
    unsigned char  LX_Iterdata;         /* iterated data byte(s) *///~v215I~
};                                                                 //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  ENTRY TABLE DEFINITIONS                                        //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
/***ET+ b32_bundle - Entry Table */                                //~v215I~
                                                                   //~v215I~
struct b32_bundle                                                  //~v215I~
{                                                                  //~v215I~
    unsigned char       b32_cnt;        /* Number of entries in this bundle *///~v215I~
    unsigned char       b32_type;       /* Bundle type */          //~v215I~
    unsigned short      b32_obj;        /* Object number */        //~v215I~
};                                      /* Follows entry types */  //~v215I~
                                                                   //~v215I~
struct e32_entry                                                   //~v215I~
{                                                                  //~v215I~
    unsigned char       e32_flags;      /* Entry point flags */    //~v215I~
    union entrykind                                                //~v215I~
    {                                                              //~v215I~
        offset          e32_offset;     /* 16-bit/32-bit offset entry *///~v215I~
        struct callgate                                            //~v215I~
        {                                                          //~v215I~
            unsigned short offset;      /* Offset in segment */    //~v215I~
            unsigned short callgate;    /* Callgate selector */    //~v215I~
        }                                                          //~v215I~
                        e32_callgate;   /* 286 (16-bit) call gate *///~v215I~
        struct fwd                                                 //~v215I~
        {                                                          //~v215I~
            unsigned short  modord;     /* Module ordinal number *///~v215I~
            unsigned long   value;      /* Proc name offset or ordinal *///~v215I~
        }                                                          //~v215I~
                        e32_fwd;        /* Forwarder */            //~v215I~
    }                                                              //~v215I~
                        e32_variant;    /* Entry variant */        //~v215I~
};                                                                 //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
#define B32_CNT(x)      (x).b32_cnt                                //~v215I~
#define B32_TYPE(x)     (x).b32_type                               //~v215I~
#define B32_OBJ(x)      (x).b32_obj                                //~v215I~
                                                                   //~v215I~
#define E32_EFLAGS(x)   (x).e32_flags                              //~v215I~
#define E32_OFFSET16(x) (x).e32_variant.e32_offset.offset16        //~v215I~
#define E32_OFFSET32(x) (x).e32_variant.e32_offset.offset32        //~v215I~
#define E32_GATEOFF(x)  (x).e32_variant.e32_callgate.offset        //~v215I~
#define E32_GATE(x)     (x).e32_variant.e32_callgate.callgate      //~v215I~
#define E32_MODORD(x)   (x).e32_variant.e32_fwd.modord             //~v215I~
#define E32_VALUE(x)    (x).e32_variant.e32_fwd.value              //~v215I~
                                                                   //~v215I~
#define FIXENT16        3                                          //~v215I~
#define FIXENT32        5                                          //~v215I~
#define GATEENT16       5                                          //~v215I~
#define FWDENT          7                                          //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  BUNDLE TYPES                                                   //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
#define EMPTY        0x00               /* Empty bundle */         //~v215I~
#define ENTRY16      0x01               /* 16-bit offset entry point *///~v215I~
#define GATE16       0x02               /* 286 call gate (16-bit IOPL) *///~v215I~
#define ENTRY32      0x03               /* 32-bit offset entry point *///~v215I~
#define ENTRYFWD     0x04               /* Forwarder entry point *///~v215I~
#define TYPEINFO     0x80               /* Typing information present flag *///~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  Format for E32_EFLAGS(x)                                       //~v215I~
 *                                                                 //~v215I~
 *       7 6 5 4 3 2 1 0  - bit no                                 //~v215I~
 *       | | | | | | | |                                           //~v215I~
 *       | | | | | | | +--- exported entry                         //~v215I~
 *       | | | | | | +----- uses shared data                       //~v215I~
 *       +-+-+-+-+-+------- parameter word count                   //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
#define E32EXPORT       0x01            /* Exported entry */       //~v215I~
#define E32SHARED       0x02            /* Uses shared data */     //~v215I~
#define E32PARAMS       0xf8            /* Parameter word count mask *///~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  Flags for forwarders only:                                     //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
#define FWD_ORDINAL     0x01            /* Imported by ordinal */  //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
#pragma pack()       /* Restore default alignment */               //~v215I~
                                                                   //~v215I~
/*end*/                                                            //~v215I~
                                                                   //~v215I~
#endif /* __EXE386__ */                                            //~v215I~
                                                                   //~v215I~
#ifdef __IBMC__                                                    //~v215I~
#pragma checkout( suspend )                                        //~v215I~
   #ifndef __CHKHDR__                                              //~v215I~
      #pragma checkout( resume )                                   //~v215I~
   #endif                                                          //~v215I~
#pragma checkout( resume )                                         //~v215I~
#endif                                                             //~v215I~
//**********************************************************************//~v215I~
//*  END of exe386.h                                               //~v215I~
//**********************************************************************//~v215I~
/*static char *SCCSID = "@(#)newexe.h	6.3 92/03/15";*/           //~v215I~
/*                                                                 //~v215I~
 *      SCCSID = @(#)newexe.h	6.3 92/03/15                       //~v215I~
 *                                                                 //~v215I~
 *  Title                                                          //~v215I~
 *                                                                 //~v215I~
 *      newexe.h                                                   //~v215I~
 *      (C) Copyright IBM Corp 1984-1992                           //~v215I~
 *      (C) Copyright Microsoft Corp 1984-1987                     //~v215I~
 *                                                                 //~v215I~
 *  Description                                                    //~v215I~
 *                                                                 //~v215I~
 *      Data structure definitions for the DOS 4.0/Windows 2.0/OS-2//~v215I~
 *      executable file format.  Includes WLO definitions.         //~v215I~
 *                                                                 //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
#ifdef __IBMC__                                                    //~v215I~
#pragma checkout( suspend )                                        //~v215I~
   #ifndef __CHKHDR__                                              //~v215I~
      #pragma checkout( suspend )                                  //~v215I~
   #endif                                                          //~v215I~
#pragma checkout( resume )                                         //~v215I~
#endif                                                             //~v215I~
                                                                   //~v215I~
#ifndef __NEWEXE__                                                 //~v215I~
#define __NEWEXE__                                                 //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
   //*_________________________________________________________________*//~v215R~
   //|                                                                 |//~v215R~
   //|                                                                 |//~v215R~
   //|  DOS3 .EXE FILE HEADER DEFINITION                               |//~v215R~
   //|                                                                 |//~v215R~
   //|_________________________________________________________________|//~v215R~
   //*                                                                 *///~v215R~
                                                                   //~v215I~
                                                                   //~v215I~
#define EMAGIC          0x5A4D          /* Old magic number */     //~v215I~
#define ENEWEXE         sizeof(struct exe_hdr)                     //~v215I~
                                        /* Value of E_LFARLC for new .EXEs *///~v215I~
#define ENEWHDR         0x003C          /* Offset in old hdr. of ptr. to new *///~v215I~
#define ERESWDS         0x0010          /* No. of reserved words (OLD) *///~v215I~
#define ERES1WDS        0x0004          /* No. of reserved words in e_res *///~v215I~
#define ERES2WDS        0x000A          /* No. of reserved words in e_res2 *///~v215I~
#define ECP             0x0004          /* Offset in struct of E_CP *///~v215I~
#define ECBLP           0x0002          /* Offset in struct of E_CBLP *///~v215I~
#define EMINALLOC       0x000A          /* Offset in struct of E_MINALLOC *///~v215I~
                                                                   //~v215I~
struct exe_hdr                          /* DOS 1, 2, 3 .EXE header *///~v215I~
  {                                                                //~v215I~
    unsigned short      e_magic;        /* Magic number */         //~v215I~
    unsigned short      e_cblp;         /* Bytes on last page of file *///~v215I~
    unsigned short      e_cp;           /* Pages in file */        //~v215I~
    unsigned short      e_crlc;         /* Relocations */          //~v215I~
    unsigned short      e_cparhdr;      /* Size of header in paragraphs *///~v215I~
    unsigned short      e_minalloc;     /* Minimum extra paragraphs needed *///~v215I~
    unsigned short      e_maxalloc;     /* Maximum extra paragraphs needed *///~v215I~
    unsigned short      e_ss;           /* Initial (relative) SS value *///~v215I~
    unsigned short      e_sp;           /* Initial SP value */     //~v215I~
    unsigned short      e_csum;         /* Checksum */             //~v215I~
    unsigned short      e_ip;           /* Initial IP value */     //~v215I~
    unsigned short      e_cs;           /* Initial (relative) CS value *///~v215I~
    unsigned short      e_lfarlc;       /* File address of relocation table *///~v215I~
    unsigned short      e_ovno;         /* Overlay number */       //~v215I~
    unsigned short      e_res[ERES1WDS];/* Reserved words */       //~v215I~
    unsigned short      e_oemid;        /* OEM identifier (for e_oeminfo) *///~v215I~
    unsigned short      e_oeminfo;      /* OEM information; e_oemid specific *///~v215I~
    unsigned short      e_res2[ERES2WDS];/* Reserved words */      //~v215I~
    long                e_lfanew;       /* File address of new exe header *///~v215I~
  };                                                               //~v215I~
                                                                   //~v215I~
#define E_MAGIC(x)      (x).e_magic                                //~v215I~
#define E_CBLP(x)       (x).e_cblp                                 //~v215I~
#define E_CP(x)         (x).e_cp                                   //~v215I~
#define E_CRLC(x)       (x).e_crlc                                 //~v215I~
#define E_CPARHDR(x)    (x).e_cparhdr                              //~v215I~
#define E_MINALLOC(x)   (x).e_minalloc                             //~v215I~
#define E_MAXALLOC(x)   (x).e_maxalloc                             //~v215I~
#define E_SS(x)         (x).e_ss                                   //~v215I~
#define E_SP(x)         (x).e_sp                                   //~v215I~
#define E_CSUM(x)       (x).e_csum                                 //~v215I~
#define E_IP(x)         (x).e_ip                                   //~v215I~
#define E_CS(x)         (x).e_cs                                   //~v215I~
#define E_LFARLC(x)     (x).e_lfarlc                               //~v215I~
#define E_OVNO(x)       (x).e_ovno                                 //~v215I~
#define E_RES(x)        (x).e_res                                  //~v215I~
#define E_OEMID(x)      (x).e_oemid                                //~v215I~
#define E_OEMINFO(x)    (x).e_oeminfo                              //~v215I~
#define E_RES2(x)       (x).e_res2                                 //~v215I~
#define E_LFANEW(x)     (x).e_lfanew                               //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
   //*_________________________________________________________________*//~v215R~
   //|                                                                 |//~v215R~
   //|                                                                 |//~v215R~
   //|  OS/2 & WINDOWS .EXE FILE HEADER DEFINITION - 286 version       |//~v215R~
   //|                                                                 |//~v215R~
   //|_________________________________________________________________|//~v215R~
   //*                                                                 *///~v215R~
                                                                   //~v215I~
#define NEMAGIC         0x454E          /* New magic number */     //~v215I~
#define NERESBYTES      8               /* Eight bytes reserved (now) *///~v215I~
#define NECRC           8               /* Offset into new header of NE_CRC *///~v215I~
                                                                   //~v215I~
struct new_exe                          /* New .EXE header */      //~v215I~
  {                                                                //~v215I~
    unsigned short      ne_magic;       /* Magic number NE_MAGIC *///~v215I~
    unsigned char       ne_ver;         /* Version number */       //~v215I~
    unsigned char       ne_rev;         /* Revision number */      //~v215I~
    unsigned short      ne_enttab;      /* Offset of Entry Table *///~v215I~
    unsigned short      ne_cbenttab;    /* Number of bytes in Entry Table *///~v215I~
    long                ne_crc;         /* Checksum of whole file *///~v215I~
    unsigned short      ne_flags;       /* Flag word */            //~v215I~
    unsigned short      ne_autodata;    /* Automatic data segment number *///~v215I~
    unsigned short      ne_heap;        /* Initial heap allocation *///~v215I~
    unsigned short      ne_stack;       /* Initial stack allocation *///~v215I~
    long                ne_csip;        /* Initial CS:IP setting *///~v215I~
    long                ne_sssp;        /* Initial SS:SP setting *///~v215I~
    unsigned short      ne_cseg;        /* Count of file segments *///~v215I~
    unsigned short      ne_cmod;        /* Entries in Module Reference Table *///~v215I~
    unsigned short      ne_cbnrestab;   /* Size of non-resident name table *///~v215I~
    unsigned short      ne_segtab;      /* Offset of Segment Table *///~v215I~
    unsigned short      ne_rsrctab;     /* Offset of Resource Table *///~v215I~
    unsigned short      ne_restab;      /* Offset of resident name table *///~v215I~
    unsigned short      ne_modtab;      /* Offset of Module Reference Table *///~v215I~
    unsigned short      ne_imptab;      /* Offset of Imported Names Table *///~v215I~
    long                ne_nrestab;     /* Offset of Non-resident Names Table *///~v215I~
    unsigned short      ne_cmovent;     /* Count of movable entries *///~v215I~
    unsigned short      ne_align;       /* Segment alignment shift count *///~v215I~
    unsigned short      ne_cres;        /* Count of resource entries *///~v215I~
    unsigned char       ne_exetyp;      /* Target operating system *///~v215I~
    unsigned char       ne_flagsothers; /* Other .EXE flags */     //~v215I~
    char                ne_res[NERESBYTES];                        //~v215I~
                                        /* Pad structure to 64 bytes *///~v215I~
  };                                                               //~v215I~
                                                                   //~v215I~
#define NE_MAGIC(x)         (x).ne_magic                           //~v215I~
#define NE_VER(x)           (x).ne_ver                             //~v215I~
#define NE_REV(x)           (x).ne_rev                             //~v215I~
#define NE_ENTTAB(x)        (x).ne_enttab                          //~v215I~
#define NE_CBENTTAB(x)      (x).ne_cbenttab                        //~v215I~
#define NE_CRC(x)           (x).ne_crc                             //~v215I~
#define NE_FLAGS(x)         (x).ne_flags                           //~v215I~
#define NE_AUTODATA(x)      (x).ne_autodata                        //~v215I~
#define NE_HEAP(x)          (x).ne_heap                            //~v215I~
#define NE_STACK(x)         (x).ne_stack                           //~v215I~
#define NE_CSIP(x)          (x).ne_csip                            //~v215I~
#define NE_SSSP(x)          (x).ne_sssp                            //~v215I~
#define NE_CSEG(x)          (x).ne_cseg                            //~v215I~
#define NE_CMOD(x)          (x).ne_cmod                            //~v215I~
#define NE_CBNRESTAB(x)     (x).ne_cbnrestab                       //~v215I~
#define NE_SEGTAB(x)        (x).ne_segtab                          //~v215I~
#define NE_RSRCTAB(x)       (x).ne_rsrctab                         //~v215I~
#define NE_RESTAB(x)        (x).ne_restab                          //~v215I~
#define NE_MODTAB(x)        (x).ne_modtab                          //~v215I~
#define NE_IMPTAB(x)        (x).ne_imptab                          //~v215I~
#define NE_NRESTAB(x)       (x).ne_nrestab                         //~v215I~
#define NE_CMOVENT(x)       (x).ne_cmovent                         //~v215I~
#define NE_ALIGN(x)         (x).ne_align                           //~v215I~
#define NE_CRES(x)          (x).ne_cres                            //~v215I~
#define NE_RES(x)           (x).ne_res                             //~v215I~
#define NE_EXETYP(x)        (x).ne_exetyp                          //~v215I~
#define NE_FLAGSOTHERS(x)   (x).ne_flagsothers                     //~v215I~
                                                                   //~v215I~
#define NE_USAGE(x)     (WORD)*((WORD *)(x)+1)                     //~v215I~
#define NE_PNEXTEXE(x)  (WORD)(x).ne_cbenttab                      //~v215I~
#define NE_ONEWEXE(x)   (WORD)(x).ne_crc                           //~v215I~
#define NE_PFILEINFO(x) (WORD)((DWORD)(x).ne_crc >> 16)            //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  Target operating systems                                       //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
#define NE_UNKNOWN      0x0             /* Unknown (any "new-format" OS) *///~v215I~
#define NE_OS2          0x1             /* OS/2 (default)  */      //~v215I~
#define NE_WINDOWS      0x2             /* Windows */              //~v215I~
#define NE_DOS4         0x3             /* DOS 4.x */              //~v215I~
#define NE_DEV386       0x4             /* Windows 386 */          //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  Format of NE_FLAGS(x):                                         //~v215I~
 *                                                                 //~v215I~
 *  p                                   Not-a-process              //~v215I~
 *   x                                  Unused                     //~v215I~
 *    e                                 Errors in image            //~v215I~
 *     x                                Unused                     //~v215I~
 *      b                               Bound Family/API           //~v215I~
 *       ttt                            Application type           //~v215I~
 *          f                           Floating-point instructions//~v215I~
 *           3                          386 instructions           //~v215I~
 *            2                         286 instructions           //~v215I~
 *             0                        8086 instructions          //~v215I~
 *              P                       Protected mode only        //~v215I~
 *               p                      Per-process library initialization//~v215I~
 *                i                     Instance data              //~v215I~
 *                 s                    Solo data                  //~v215I~
 */                                                                //~v215I~
#define NENOTP          0x8000          /* Not a process */        //~v215I~
#define NEIERR          0x2000          /* Errors in image */      //~v215I~
#define NEBOUND         0x0800          /* Bound Family/API */     //~v215I~
#define NEAPPTYP        0x0700          /* Application type mask *///~v215I~
#define NENOTWINCOMPAT  0x0100          /* Not compatible with P.M. Windowing *///~v215I~
#define NEWINCOMPAT     0x0200          /* Compatible with P.M. Windowing *///~v215I~
#define NEWINAPI        0x0300          /* Uses P.M. Windowing API *///~v215I~
#define NEFLTP          0x0080          /* Floating-point instructions *///~v215I~
#define NEI386          0x0040          /* 386 instructions */     //~v215I~
#define NEI286          0x0020          /* 286 instructions */     //~v215I~
#define NEI086          0x0010          /* 8086 instructions */    //~v215I~
#define NEPROT          0x0008          /* Runs in protected mode only *///~v215I~
#define NEPPLI          0x0004          /* Per-Process Library Initialization *///~v215I~
#define NEINST          0x0002          /* Instance data */        //~v215I~
#define NESOLO          0x0001          /* Solo data */            //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  Format of NE_FLAGSOTHERS(x):                                   //~v215I~
 *                                                                 //~v215I~
 *      7 6 5 4 3 2 1 0  - bit no                                  //~v215I~
 *      |         | | |                                            //~v215I~
 *      |         | | +---------------- Support for long file names//~v215I~
 *      |         | +------------------ Windows 2.x app runs in prot mode//~v215I~
 *      |         +-------------------- Windows 2.x app gets prop. font//~v215I~
 *      +------------------------------ WLO appl on OS/2 (markwlo.exe)//~v215I~
 *                                                                 //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
#define NELONGNAMES     0x01                                       //~v215I~
#define NEWINISPROT     0x02                                       //~v215I~
#define NEWINGETPROPFON 0x04                                       //~v215I~
#define NEWLOAPPL       0x80                                       //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
struct new_seg                          /* New .EXE segment table entry *///~v215I~
  {                                                                //~v215I~
    unsigned short      ns_sector;      /* File sector of start of segment *///~v215I~
    unsigned short      ns_cbseg;       /* Number of bytes in file *///~v215I~
    unsigned short      ns_flags;       /* Attribute flags */      //~v215I~
    unsigned short      ns_minalloc;    /* Minimum allocation in bytes *///~v215I~
  };                                                               //~v215I~
                                                                   //~v215I~
#define NS_SECTOR(x)    (x).ns_sector                              //~v215I~
#define NS_CBSEG(x)     (x).ns_cbseg                               //~v215I~
#define NS_FLAGS(x)     (x).ns_flags                               //~v215I~
#define NS_MINALLOC(x)  (x).ns_minalloc                            //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  Format of NS_FLAGS(x)                                          //~v215I~
 *                                                                 //~v215I~
 *  Flag word has the following format:                            //~v215I~
 *                                                                 //~v215I~
 *      15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0  - bit no            //~v215I~
 *          |  |  |  |  | | | | | | | | | | |                      //~v215I~
 *          |  |  |  |  | | | | | | | | +-+-+--- Segment type DATA/CODE//~v215I~
 *          |  |  |  |  | | | | | | | +--------- Iterated segment  //~v215I~
 *          |  |  |  |  | | | | | | +----------- Movable segment   //~v215I~
 *          |  |  |  |  | | | | | +------------- Segment can be shared//~v215I~
 *          |  |  |  |  | | | | +--------------- Preload segment   //~v215I~
 *          |  |  |  |  | | | +----------------- Execute/read-only for code/data segment//~v215I~
 *          |  |  |  |  | | +------------------- Segment has relocations//~v215I~
 *          |  |  |  |  | +--------------------- Code conforming/Data is expand down//~v215I~
 *          |  |  |  +--+----------------------- I/O privilege level//~v215I~
 *          |  |  +----------------------------- Discardable segment//~v215I~
 *          |  +-------------------------------- 32-bit code segment//~v215I~
 *          +----------------------------------- Huge segment/GDT allocation requested//~v215I~
 *                                                                 //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
#define NSTYPE          0x0007          /* Segment type mask */    //~v215I~
                                                                   //~v215I~
#if (EXE386 == 0)                                                  //~v215I~
#define NSCODE          0x0000          /* Code segment */         //~v215I~
#define NSDATA          0x0001          /* Data segment */         //~v215I~
#define NSITER          0x0008          /* Iterated segment flag *///~v215I~
#define NSMOVE          0x0010          /* Movable segment flag */ //~v215I~
#define NSSHARED        0x0020          /* Shared segment flag */  //~v215I~
#define NSPRELOAD       0x0040          /* Preload segment flag */ //~v215I~
#define NSEXRD          0x0080          /* Execute-only (code segment), or//~v215I~
                                        *  read-only (data segment)//~v215I~
                                        */                         //~v215I~
#define NSRELOC         0x0100          /* Segment has relocations *///~v215I~
#define NSCONFORM       0x0200          /* Conforming segment */   //~v215I~
#define NSEXPDOWN       0x0200          /* Data segment is expand down *///~v215I~
#define NSDPL           0x0C00          /* I/O privilege level (286 DPL bits) *///~v215I~
#define SHIFTDPL        10              /* Left shift count for SEGDPL field *///~v215I~
#define NSDISCARD       0x1000          /* Segment is discardable *///~v215I~
#define NS32BIT         0x2000          /* 32-bit code segment */  //~v215I~
#define NSHUGE          0x4000          /* Huge memory segment, length of//~v215I~
                                         * segment and minimum allocation//~v215I~
                                         * size are in segment sector units//~v215I~
                                         */                        //~v215I~
#define NSGDT           0x8000          /* GDT allocation requested *///~v215I~
                                                                   //~v215I~
#define NSPURE          NSSHARED        /* For compatibility */    //~v215I~
                                                                   //~v215I~
#define NSALIGN 9       /* Segment data aligned on 512 byte boundaries *///~v215I~
                                                                   //~v215I~
#define NSLOADED    0x0004      /* ns_sector field contains memory addr *///~v215I~
#endif                                                             //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
struct new_segdata                      /* Segment data */         //~v215I~
  {                                                                //~v215I~
    union                                                          //~v215I~
      {                                                            //~v215I~
        struct                                                     //~v215I~
          {                                                        //~v215I~
            unsigned short      ns_niter;       /* number of iterations *///~v215I~
            unsigned short      ns_nbytes;      /* number of bytes *///~v215I~
            char                ns_iterdata;    /* iterated data bytes *///~v215I~
          } ns_iter;                                               //~v215I~
        struct                                                     //~v215I~
          {                                                        //~v215I~
            char                ns_data;        /* data bytes */   //~v215I~
          } ns_noniter;                                            //~v215I~
      } ns_union;                                                  //~v215I~
  };                                                               //~v215I~
                                                                   //~v215I~
struct new_rlcinfo                      /* Relocation info */      //~v215I~
  {                                                                //~v215I~
    unsigned short      nr_nreloc;      /* number of relocation items that *///~v215I~
  };                                    /* follow */               //~v215I~
                                                                   //~v215I~
#pragma pack(1)                                                    //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
struct new_rlc                          /* Relocation item */      //~v215I~
  {                                                                //~v215I~
    char                nr_stype;       /* Source type */          //~v215I~
    char                nr_flags;       /* Flag byte */            //~v215I~
    unsigned short      nr_soff;        /* Source offset */        //~v215I~
    union                                                          //~v215I~
      {                                                            //~v215I~
        struct                                                     //~v215I~
          {                                                        //~v215I~
            char        nr_segno;       /* Target segment number *///~v215I~
            char        nr_res;         /* Reserved */             //~v215I~
            unsigned short nr_entry;    /* Target Entry Table offset *///~v215I~
          }             nr_intref;      /* Internal reference */   //~v215I~
        struct                                                     //~v215I~
          {                                                        //~v215I~
            unsigned short nr_mod;      /* Index into Module Reference Table *///~v215I~
            unsigned short nr_proc;     /* Procedure ordinal or name offset *///~v215I~
          }             nr_import;      /* Import */               //~v215I~
        struct                                                     //~v215I~
          {                                                        //~v215I~
            unsigned short nr_ostype;   /* OSFIXUP type */         //~v215I~
            unsigned short nr_osres;    /* reserved */             //~v215I~
          }             nr_osfix;       /* Operating system fixup *///~v215I~
      }                 nr_union;       /* Union */                //~v215I~
  };                                                               //~v215I~
                                                                   //~v215I~
#pragma pack()                                                     //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
#define NR_STYPE(x)     (x).nr_stype                               //~v215I~
#define NR_FLAGS(x)     (x).nr_flags                               //~v215I~
#define NR_SOFF(x)      (x).nr_soff                                //~v215I~
#define NR_SEGNO(x)     (x).nr_union.nr_intref.nr_segno            //~v215I~
#define NR_RES(x)       (x).nr_union.nr_intref.nr_res              //~v215I~
#define NR_ENTRY(x)     (x).nr_union.nr_intref.nr_entry            //~v215I~
#define NR_MOD(x)       (x).nr_union.nr_import.nr_mod              //~v215I~
#define NR_PROC(x)      (x).nr_union.nr_import.nr_proc             //~v215I~
#define NR_OSTYPE(x)    (x).nr_union.nr_osfix.nr_ostype            //~v215I~
#define NR_OSRES(x)     (x).nr_union.nr_osfix.nr_osres             //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  Format of NR_STYPE(x) and R32_STYPE(x):                        //~v215I~
 *                                                                 //~v215I~
 *       7 6 5 4 3 2 1 0  - bit no                                 //~v215I~
 *               | | | |                                           //~v215I~
 *               +-+-+-+--- source type                            //~v215I~
 *                                                                 //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
#define NRSTYP          0x0f            /* Source type mask */     //~v215I~
#define NRSBYT          0x00            /* lo byte (8-bits)*/      //~v215I~
#define NRSSEG          0x02            /* 16-bit segment (16-bits) *///~v215I~
#define NRSPTR          0x03            /* 16:16 pointer (32-bits) *///~v215I~
#define NRSOFF          0x05            /* 16-bit offset (16-bits) *///~v215I~
#define NRPTR48         0x06            /* 16:32 pointer (48-bits) *///~v215I~
#define NROFF32         0x07            /* 32-bit offset (32-bits) *///~v215I~
#define NRSOFF32        0x08            /* 32-bit self-relative offset (32-bits) *///~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
/*                                                                 //~v215I~
 *  Format of NR_FLAGS(x) and R32_FLAGS(x):                        //~v215I~
 *                                                                 //~v215I~
 *       7 6 5 4 3 2 1 0  - bit no                                 //~v215I~
 *                 | | |                                           //~v215I~
 *                 | +-+--- Reference type                         //~v215I~
 *                 +------- Additive fixup                         //~v215I~
 */                                                                //~v215I~
                                                                   //~v215I~
#define NRADD           0x04            /* Additive fixup */       //~v215I~
#define NRRTYP          0x03            /* Reference type mask */  //~v215I~
#define NRRINT          0x00            /* Internal reference */   //~v215I~
#define NRRORD          0x01            /* Import by ordinal */    //~v215I~
#define NRRNAM          0x02            /* Import by name */       //~v215I~
#define NRROSF          0x03            /* Operating system fixup *///~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
#if (EXE386 == 0)                                                  //~v215I~
                                                                   //~v215I~
/* Resource type or name string */                                 //~v215I~
struct rsrc_string                                                 //~v215I~
    {                                                              //~v215I~
    char rs_len;            /* number of bytes in string */        //~v215I~
    char rs_string[ 1 ];    /* text of string */                   //~v215I~
    };                                                             //~v215I~
                                                                   //~v215I~
#define RS_LEN( x )    (x).rs_len                                  //~v215I~
#define RS_STRING( x ) (x).rs_string                               //~v215I~
                                                                   //~v215I~
/* Resource type information block */                              //~v215I~
struct rsrc_typeinfo                                               //~v215I~
    {                                                              //~v215I~
    unsigned short rt_id;                                          //~v215I~
    unsigned short rt_nres;                                        //~v215I~
    long rt_proc;                                                  //~v215I~
    };                                                             //~v215I~
                                                                   //~v215I~
#define RT_ID( x )   (x).rt_id                                     //~v215I~
#define RT_NRES( x ) (x).rt_nres                                   //~v215I~
#define RT_PROC( x ) (x).rt_proc                                   //~v215I~
                                                                   //~v215I~
/* Resource name information block */                              //~v215I~
struct rsrc_nameinfo                                               //~v215I~
    {                                                              //~v215I~
    /* The following two fields must be shifted left by the value of  *///~v215I~
    /* the rs_align field to compute their actual value.  This allows *///~v215I~
    /* resources to be larger than 64k, but they do not need to be    *///~v215I~
    /* aligned on 512 byte boundaries, the way segments are           *///~v215I~
    unsigned short rn_offset;   /* file offset to resource data */ //~v215I~
    unsigned short rn_length;   /* length of resource data */      //~v215I~
    unsigned short rn_flags;    /* resource flags */               //~v215I~
    unsigned short rn_id;       /* resource name id */             //~v215I~
    unsigned short rn_handle;   /* If loaded, then global handle *///~v215I~
    unsigned short rn_usage;    /* Initially zero.  Number of times *///~v215I~
                                /* the handle for this resource has *///~v215I~
                                /* been given out */               //~v215I~
    };                                                             //~v215I~
                                                                   //~v215I~
#define RN_OFFSET( x ) (x).rn_offset                               //~v215I~
#define RN_LENGTH( x ) (x).rn_length                               //~v215I~
#define RN_FLAGS( x )  (x).rn_flags                                //~v215I~
#define RN_ID( x )     (x).rn_id                                   //~v215I~
#define RN_HANDLE( x ) (x).rn_handle                               //~v215I~
#define RN_USAGE( x )  (x).rn_usage                                //~v215I~
                                                                   //~v215I~
#define RSORDID     0x8000      /* if high bit of ID set then integer id *///~v215I~
                                /* otherwise ID is offset of string from//~v215I~
                                   the beginning of the resource table *///~v215I~
                                                                   //~v215I~
                                /* Ideally these are the same as the *///~v215I~
                                /* corresponding segment flags */  //~v215I~
#define RNMOVE      0x0010      /* Moveable resource */            //~v215I~
#define RNPURE      0x0020      /* Pure (read-only) resource */    //~v215I~
#define RNPRELOAD   0x0040      /* Preloaded resource */           //~v215I~
#define RNDISCARD   0xF000      /* Discard priority level for resource *///~v215I~
                                                                   //~v215I~
/* Resource table */                                               //~v215I~
struct new_rsrc                                                    //~v215I~
    {                                                              //~v215I~
    unsigned short rs_align;    /* alignment shift count for resources *///~v215I~
    struct rsrc_typeinfo rs_typeinfo;                              //~v215I~
    };                                                             //~v215I~
                                                                   //~v215I~
#define RS_ALIGN( x ) (x).rs_align                                 //~v215I~
                                                                   //~v215I~
                                                                   //~v215I~
#endif /* NOT EXE386 */                                            //~v215I~
                                                                   //~v215I~
#endif /* __NEWEXE__ */                                            //~v215I~
                                                                   //~v215I~
#ifdef __IBMC__                                                    //~v215I~
#pragma checkout( suspend )                                        //~v215I~
   #ifndef __CHKHDR__                                              //~v215I~
      #pragma checkout( resume )                                   //~v215I~
   #endif                                                          //~v215I~
#pragma checkout( resume )                                         //~v215I~
#endif                                                             //~v215I~
//**********************************************************************//~v215I~
//*  END of newexe.h                                               //~v215I~
//**********************************************************************//~v215I~
//**********************************************************************//~v215I~
//*  entry table for NE from w95ua                                 //~v215I~
//**********************************************************************//~v215I~
                                                                   //~v215I~
#pragma pack(1)                                                    //~v215I~
                                                                   //~v215I~
typedef struct {                                                   //~v215I~
	unsigned char ep_flags;                                        //~v215I~
	unsigned short ep_int_3f;                                      //~v215I~
	unsigned char ep_segnum;                                       //~v215I~
	unsigned short ep_offset;                                      //~v215I~
	} ENTRY_MOVEABLE;                                              //~v215I~
                                                                   //~v215I~
typedef	struct {                                                   //~v215I~
	unsigned char ep_flags;                                        //~v215I~
	unsigned short ep_offset;                                      //~v215I~
	} ENTRY_FIXED;                                                 //~v215I~
                                                                   //~v215I~
typedef struct {                                                   //~v215I~
	union {                                                        //~v215I~
		ENTRY_MOVEABLE ep_moveable;                                //~v215I~
		ENTRY_FIXED ep_fixed;                                      //~v215I~
		} ep_union;                                                //~v215I~
	} ENTRY_POINT;                                                 //~v215I~
                                                                   //~v215I~
typedef struct {                                                   //~v215I~
	unsigned char eb_nentry;                                       //~v215I~
	unsigned char eb_segnum;                                       //~v215I~
	} BUNDLE_HEADER;                                               //~v215I~
                                                                   //~v215I~
typedef struct {                                                   //~v215I~
	BUNDLE_HEADER eb_hdr;                                          //~v215I~
	ENTRY_POINT eb_epoint [1] ;                                    //~v215I~
	} ENTRY_BUNDLE;                                                //~v215I~
                                                                   //~v315I~
#ifdef OS2                                                         //~v@01I~
//*********************************************************************//~v315M~
//* copy from winnt.h of vc6.0                                     //~v315M~
//*********************************************************************//~v315M~
// The following structure defines the new import object.  Note the values of the first two fields,//~v315M~
// which must be set as stated in order to differentiate old and new import members.//~v315M~
// Following this structure, the linker emits two null-terminated strings used to recreate the//~v315M~
// import at the time of use.  The first string is the import's name, the second is the dll's name.//~v315M~
                                                                   //~v315M~
#define IMAGE_FILE_MACHINE_UNKNOWN           0                     //~v315M~
#define IMPORT_OBJECT_HDR_SIG2  0xffff                             //~v315M~
                                                                   //~v315M~
typedef struct IMPORT_OBJECT_HEADER {                              //~v315M~
    WORD    Sig1;                       // Must be IMAGE_FILE_MACHINE_UNKNOWN//~v315M~
    WORD    Sig2;                       // Must be IMPORT_OBJECT_HDR_SIG2.//~v315M~
    WORD    Version;                                               //~v315M~
    WORD    Machine;                                               //~v315M~
    DWORD   TimeDateStamp;              // Time/date stamp         //~v315M~
    DWORD   SizeOfData;                 // particularly useful for incremental links//~v315M~
                                                                   //~v315M~
    union {                                                        //~v315M~
        WORD    Ordinal;                // if grf & IMPORT_OBJECT_ORDINAL//~v315M~
        WORD    Hint;                                              //~v315M~
    };                                                             //~v315M~
                                                                   //~v315M~
//    WORD    Type : 2;                   // IMPORT_TYPE           //~v315R~
//    WORD    NameType : 3;               // IMPORT_NAME_TYPE      //~v315R~
//    WORD    Reserved : 11;              // Reserved. Must be zero.//~v315R~
//OS/2 Toolkt not support USHORT bit definition *****              //~v315I~
    USHORT  NameType_Type;               // IMPORT_TYPE            //~v315R~
#define Type(NameType_Type) (NameType_Type & 0x03)                 //~v315I~
#define NameType(NameType_Type) ((NameType_Type>>2) & 0x07)        //~v315I~
} IMPORT_OBJECT_HEADER;                                            //~v315M~
                                                                   //~v315M~
typedef enum IMPORT_OBJECT_TYPE                                    //~v315M~
{                                                                  //~v315M~
    IMPORT_OBJECT_CODE = 0,                                        //~v315M~
    IMPORT_OBJECT_DATA = 1,                                        //~v315M~
    IMPORT_OBJECT_CONST = 2                                        //~v315R~
} IMPORT_OBJECT_TYPE;                                              //~v315M~
                                                                   //~v315M~
typedef enum IMPORT_OBJECT_NAME_TYPE                               //~v315R~
{                                                                  //~v315M~
    IMPORT_OBJECT_ORDINAL = 0,          // Import by ordinal       //~v315M~
    IMPORT_OBJECT_NAME = 1,             // Import name == public symbol name.//~v315M~
    IMPORT_OBJECT_NAME_NO_PREFIX = 2,   // Import name == public symbol name skipping leading ?, @, or optionally _.//~v315M~
    IMPORT_OBJECT_NAME_UNDECORATE = 3   // Import name == public symbol name skipping leading ?, @, or optionally _//~v315R~
                                        // and truncating at first @//~v315M~
} IMPORT_OBJECT_NAME_TYPE;                                         //~v315M~
                                                                   //~v315M~
                                                                   //~v215I~
#pragma pack()                                                     //~v215I~
#endif  // OS2                                                     //+v@01M~
                                                                   //~v215I~
#define MOVEABLE	0xFF                                           //~v215I~
#define REFCONST	0xFE                                           //~v215I~
//**********************************************************************//~v215I~
//*  END of newexe entray table from w95ua                         //~v215I~
//**********************************************************************//~v215I~
