SECTIONS
{
  .text : {
    . =   0;          *(.text.Blue  ); 
    . =  16;          *(.text.Green ); 
    . =  32;          *(.text.Red   ); 
    . =  48;          *(.text.Yellow); 
    . =  64;          *(.text.Purple); 

    . =  80;          *(.text.Pink___);  
    . =  96;          *(.text.Olive__); 
    . = 112;          *(.text.Maroon_); 
    . = 128;          *(.text.Lime___);  
    . = 144;          *(.text.Aqua___); 
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
    . = wrist +   0;  *(.text.Blue___); 
    . = wrist +  16;  *(.text.Green__); 
    . = wrist +  32;  *(.text.Red____); 
    . = wrist +  48;  *(.text.Yellow_); 
    . = wrist +  64;  *(.text.Purple_); 

    . = wrist +  80;  *(.text.Pink  ); 
    . = wrist +  96;  *(.text.Olive ); 
    . = wrist + 112;  *(.text.Maroon); 
    . = wrist + 128;  *(.text.Lime  ); 
    . = wrist + 144;  *(.text.Aqua  ); 
  }
  .text : ALIGN(16) {
    BYTE(0x12); BYTE(0x34); BYTE(0x56); BYTE(0x78);
  }
}

