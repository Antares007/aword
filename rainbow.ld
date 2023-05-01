SECTIONS
{
  .text : {
    . = 0;            *(.text.Blue   );
    . = 16;           *(.text.Green  );
    . = 32;           *(.text.Red    );
    . = 48;           *(.text.Purple );
    . = 64;           *(.text.Yellow );

    . = 80;           *(.text.Olive_ray  );
    . = 96;           *(.text.Fuchsia_ray);
    . = 112;          *(.text.Maroon_ray );
    . = 128;          *(.text.Lime_ray   );
    . = 144;          *(.text.Navy_ray   );
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
    . = wrist + 0;    *(.text.Blue_ray   );
    . = wrist + 16;   *(.text.Green_ray  );
    . = wrist + 32;   *(.text.Red_ray    );
    . = wrist + 48;   *(.text.Purple_ray );
    . = wrist + 64;   *(.text.Yellow_ray );

    . = wrist + 80;   *(.text.Olive  );
    . = wrist + 96;   *(.text.Fuchsia);
    . = wrist + 112;  *(.text.Maroon );
    . = wrist + 128;  *(.text.Lime   );
    . = wrist + 144;  *(.text.Navy   );
  }
  .text : ALIGN(16) {
    BYTE(0x12); BYTE(0x34); BYTE(0x56); BYTE(0x78);
  }
}

