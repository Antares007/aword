SECTIONS
{
  .text : {
    . = 0x000; *(.text.Navy);
    . = 0x010; *(.text.blue);
    . = 0x020; *(.text.Maroon);
    . = 0x030; *(.text.red);
    . = 0x040; *(.text.Lime);
    . = 0x050; *(.text.green);
    . = 0x060; *(.text.Olive);
    . = 0x070; *(.text.yellow);
    . = 0x080; *(.text.Fuchsia);
    . = 0x090; *(.text.purple);

    . = 0x0a0; *(.text.Purple_ray);
    . = 0x0b0; *(.text.fuchsia_ray);
    . = 0x0c0; *(.text.Yellow_ray);
    . = 0x0d0; *(.text.olive_ray);
    . = 0x0e0; *(.text.Green_ray);
    . = 0x0f0; *(.text.lime_ray);
    . = 0x100; *(.text.Red_ray);
    . = 0x110; *(.text.maroon_ray);
    . = 0x120; *(.text.Blue_ray);
    . = 0x130; *(.text.navy_ray);
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
    . = wrist + 0x000; *(.text.Navy_ray);
    . = wrist + 0x010; *(.text.blue_ray);
    . = wrist + 0x020; *(.text.Maroon_ray);
    . = wrist + 0x030; *(.text.red_ray);
    . = wrist + 0x040; *(.text.Lime_ray);
    . = wrist + 0x050; *(.text.green_ray);
    . = wrist + 0x060; *(.text.Olive_ray);
    . = wrist + 0x070; *(.text.yellow_ray);
    . = wrist + 0x080; *(.text.Fuchsia_ray);
    . = wrist + 0x090; *(.text.purple_ray);

    . = wrist + 0x0a0; *(.text.Purple);
    . = wrist + 0x0b0; *(.text.fuchsia);
    . = wrist + 0x0c0; *(.text.Yellow);
    . = wrist + 0x0d0; *(.text.olive);
    . = wrist + 0x0e0; *(.text.Green);
    . = wrist + 0x0f0; *(.text.lime);
    . = wrist + 0x100; *(.text.Red);
    . = wrist + 0x110; *(.text.maroon);
    . = wrist + 0x120; *(.text.Blue);
    . = wrist + 0x130; *(.text.navy);
  }
  .text : ALIGN(16) {
    BYTE(0x12); BYTE(0x34); BYTE(0x56); BYTE(0x78);
  }
}

