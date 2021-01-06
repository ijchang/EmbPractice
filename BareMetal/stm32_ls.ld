ENTRY(Reset_Handler)

MEMORY
{
    FLASH(rx):ORIGIN =0x80000000,LENGTH =1024K /*there should be a space before '='*/
    SRAM(rwx):ORIGIN =0x20000000,LENGTH =128K
}

SECTIONS
{
    .text : /*there should be a space before ':'*/
    {
        *(.isr_vector)
        *(.text)
        *(.text.*) /*to merge the extra .text.xxx sections introduced by newlib_nano library*/
        *(.init) /*to merge the .init section introduced by newlib_nano library*/
        *(.fini) /*to merge the .fini sections introduced by newlib_nano library*/
        *(.rodata)
        *(.rodata.*) /*to merge the extra .text.xxx sections introduced by newlib_nano library*/
        . = ALIGN(4); /*this is to ensure _etext is word-aligned*/
        _etext = .;
    }> FLASH AT> FLASH  /*vma is FLASH and lma is also FLASH*/

    .data :
    {
        _sdata = .; /*location counter always tracks vma, so _sdata is equal to SRAM = 0x20000000*/
       *(.data)
       *(.data.*) /*to merge the extra .data.xxx sections introduced by newlib_nano library*/
       _edata = .;
       . = ALIGN(4);  
    }> SRAM AT> FLASH /*vma is SRAM and lma is FLASH. When linker sees this it will generate load address for this section in FLASH. But the absolute address of this section will fall into memory region SRAM*/

    .bss :
    {
        _sbss = .;
        __bss_start__ = _sbss; /*__bss_start symbol is needed in newlib_nano lib*/
        *(.bss)
        *(COMMON)
        . = ALIGN(4); 
        _ebss = .;
        __bss_end__ = _ebss;  /*__bss_end symbol is needed in newlib_nano lib*/
        . = ALIGN(4);
        end = .; /*end symbol is needed in _sbrk function in syscalls.c*/
    }> SRAM  /*vma is SRAM. .bss is not stored in FLASH, so it does not have lma*/
}
