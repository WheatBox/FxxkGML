#include <FxxkGML.h>

fgm::asset snd_click = -1;
fgm::rect button_area { 128, 160, 320, 192 };

void fgm_init() {
	snd_click = fgm::asset_get_index("snd_click");
}

void fgm_main() {
	
	fgm::draw_set_alpha(1);
	fgm::draw_set_color(fgm::c_black);
	fgm::draw_roundrect_ext(button_area, 16, 16, false);
	fgm::draw_set_color(fgm::c_white);
	fgm::draw_text(button_area.left_top() + fgm::vec2(20, 6), "A Nameless Button");

	if(button_area.collision(fgm::mouse_pos_get())) {
		fgm::draw_set_alpha(0.3);
		fgm::draw_roundrect_ext(button_area, 16, 16, false);
		fgm::draw_set_alpha(1);

		if(fgm::mouse_check_button_pressed(fgm::mb_left)) {
			fgm::audio_play_sound(snd_click, 1000, false);
		}
	}

}

void fgm_assistant(int) {}
