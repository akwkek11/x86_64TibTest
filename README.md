TIB Parsing Example x86_64 Windows

x86 : using inline asm to parse FS register
x64 : cannot use inline asm in the default setting in windows x64,
      so I get the NtCurrentTeb and read GS register ( defined in 'intrin.h' )
      
Notice :  Table size of x64 teb is as twice as big x86 teb.

I just parse 
      1. Address of TEB ( TIB )
      2. Process ID
      3. Address of PEB

You can parse all of x64 TEB. ( Just simply modify code. )

Created by Cho_bo
3/2 , 2016
