
#include <stdlib.h>
#include <string.h>

#include <stdlib.h>
#include <string.h>

// include NESLIB header
#include "neslib.h"

// include CC65 NES Header (PPU)
#include <nes.h>

// link the pattern table into CHR ROM
//#link "chr_generic.s"

// BCD arithmetic support
#include "bcd.h"
//#link "bcd.c"

// VRAM update buffer
#include "vrambuf.h"
//#link "vrambuf.c"


// setup PPU and tables
void setup_graphics() {
  // clear sprites
  //oam_clear();
  // set palette colors
  pal_col(0,0x03);
  pal_col(1,0x14);
  pal_col(2,0x10);
  pal_col(3,0x30);
}

void main(void)
{
  int x;
  setup_graphics();
  // draw message  
  vram_adr(NTADR_A(2,2));
  vram_write("Strife es la ostia!", 19);
  // enable rendering
  ppu_on_all();
  
  for(x=0;x<500;x++){
    ppu_wait_frame();
  }
  ppu_off();
  // infinite loop
  while(1) {
  }
}
