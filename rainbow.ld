SECTIONS
{
  .text : {
    . = 0x000;  *(.text.Navy);                . = 0x010; *(.text.navy);      
    . = 0x020;  *(.text.Maroon);              . = 0x030; *(.text.maroon);    
    . = 0x040;  *(.text.Lime);                . = 0x050; *(.text.lime);      
    . = 0x060;  *(.text.Olive);               . = 0x070; *(.text.olive);     
    . = 0x080;  *(.text.Fuchsia);             . = 0x090; *(.text.fuchsia);   
                                                                             
    . = 0x0a0;  *(.text.Purple_ray);          . = 0x0b0; *(.text.purple_ray);
    . = 0x0c0;  *(.text.Yellow_ray);          . = 0x0d0; *(.text.yellow_ray);
    . = 0x0e0;  *(.text.Green_ray);           . = 0x0f0; *(.text.green_ray); 
    . = 0x100;  *(.text.Red_ray);             . = 0x110; *(.text.red_ray);   
    . = 0x120;  *(.text.Blue_ray);            . = 0x130; *(.text.blue_ray);  
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
    . = wrist + 0x000; *(.text.Navy_ray);     . = wrist + 0x010; *(.text.navy_ray);   
    . = wrist + 0x020; *(.text.Maroon_ray);   . = wrist + 0x030; *(.text.maroon_ray); 
    . = wrist + 0x040; *(.text.Lime_ray);     . = wrist + 0x050; *(.text.lime_ray);   
    . = wrist + 0x060; *(.text.Olive_ray);    . = wrist + 0x070; *(.text.olive_ray);  
    . = wrist + 0x080; *(.text.Fuchsia_ray);  . = wrist + 0x090; *(.text.fuchsia_ray);
                                                                                      
    . = wrist + 0x0a0; *(.text.Purple);       . = wrist + 0x0b0; *(.text.purple);     
    . = wrist + 0x0c0; *(.text.Yellow);       . = wrist + 0x0d0; *(.text.yellow);     
    . = wrist + 0x0e0; *(.text.Green);        . = wrist + 0x0f0; *(.text.green);      
    . = wrist + 0x100; *(.text.Red);          . = wrist + 0x110; *(.text.red);        
    . = wrist + 0x120; *(.text.Blue);         . = wrist + 0x130; *(.text.blue);       
  }
  .text : ALIGN(16) { BYTE(0x12); BYTE(0x34); BYTE(0x56); BYTE(0x78); }
}

