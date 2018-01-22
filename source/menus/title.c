#include "tools/neslib_famitracker/neslib.h"
#include "source/menus/title.h"
#include "source/globals.h"
#include "source/configuration/game_states.h"
#include "source/menus/text_helpers.h"

CODE_BANK(PRG_BANK_TITLE);

// Array of 16 colors that make up the palette for the title screen. You can generate this by using NESst, and choosing
// "put to clipboard -> c data" from the "palettes" menu.
const unsigned char titlePalette[16]={ 0x0f,0x21,0x11,0x31,0x0f,0x11,0x21,0x31,0x0f,0x05,0x25,0x35,0x0f,0x00,0x10,0x30 };

// The name of your game :)
const unsigned char gameName[] = "Quirk's Adventure";
const unsigned char gameAuthor[] = "YOU!";

void draw_title_screen() {
    ppu_off();
	pal_bg(titlePalette);
	pal_spr(titlePalette);
    
    put_str(NTADR_A(5, 5), gameName);
	put_str(NTADR_A(5, 18), "Created by:");
	put_str(NTADR_A(5, 20), gameAuthor);
	put_str(NTADR_A(9, 24), "Press Start!");
	ppu_on_all();

	gameState = GAME_STATE_TITLE_INPUT;
}

void handle_title_input() {
	if (pad_trigger(0) & PAD_START) {
		gameState = GAME_STATE_POST_TITLE;
	}
}