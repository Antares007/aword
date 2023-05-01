SECTIONS
{
  .text : {
    . = 0;            *(.text.Navy    );
    . = 16;           *(.text.Lime    );
    . = 32;           *(.text.Maroon  );
    . = 48;           *(.text.Fuchsia );
    . = 64;           *(.text.Olive   );

    . = 80;           *(.text.Yellow_ray);
    . = 96;           *(.text.Purple_ray);
    . = 112;          *(.text.Red_ray);
    . = 128;          *(.text.Green_ray);
    . = 144;          *(.text.Blue_ray);
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
    . = wrist + 0;    *(.text.Navy_ray);
    . = wrist + 16;   *(.text.Lime_ray);
    . = wrist + 32;   *(.text.Maroon_ray);
    . = wrist + 48;   *(.text.Fuchsia_ray);
    . = wrist + 64;   *(.text.Olive_ray);

    . = wrist + 80;   *(.text.Yellow  );
    . = wrist + 96;   *(.text.Purple  );
    . = wrist + 112;  *(.text.Red     );
    . = wrist + 128;  *(.text.Green   );
    . = wrist + 144;  *(.text.Blue    );
  }
  .text : ALIGN(16) {
    BYTE(0x12); BYTE(0x34); BYTE(0x56); BYTE(0x78);
  }
}

