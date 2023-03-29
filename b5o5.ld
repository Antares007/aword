SECTIONS
{
  .text : {
    . =   0;          *(.text.Pink); 
    . =  16;          *(.text.Olive); 
    . =  32;          *(.text.Maroon); 
    . =  48;          *(.text.Lime); 
    . =  64;          *(.text.Aqua); 

    . =  80;          *(.text.Blue___);  
    . =  96;          *(.text.Green__); 
    . = 112;          *(.text.Red____); 
    . = 128;          *(.text.Yellow_);  
    . = 144;          *(.text.Purple_); 
  }
  .data : ALIGN(16) {
    *(.data);
    *(.data.*);
    *(.rodata);
    *(.rodata.*);
    *(.bss);
  }
  .text : ALIGN(16) {
    wrist = .;
    . = wrist +   0;  *(.text.Pink___); 
    . = wrist +  16;  *(.text.Olive__); 
    . = wrist +  32;  *(.text.Maroon_); 
    . = wrist +  48;  *(.text.Lime___); 
    . = wrist +  64;  *(.text.Aqua___); 

    . = wrist +  80;  *(.text.Blue); 
    . = wrist +  96;  *(.text.Green); 
    . = wrist + 112;  *(.text.Red); 
    . = wrist + 128;  *(.text.Yellow); 
    . = wrist + 144;  *(.text.Purple); 
  }
  .text : ALIGN(16) {
    BYTE(0x12); BYTE(0x34); BYTE(0x56); BYTE(0x78);
  }
}

