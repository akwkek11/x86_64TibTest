TIB Parsing Example x86_64 Windows

x86 : using inline asm to parse FS register
x64 : cannot use inline asm in the default setting in windows x64,
      so I get the NtCurrentTeb and read GS register ( defined in 'intrin.h' )
      
Notice :  Table size of x64 teb is as twice as big x64 teb.
