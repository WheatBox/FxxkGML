#include <FxxkGML.h>

fgm::asset snd_click = -1;
fgm::instance insgame;
fgm::rect button_area { 128, 160, 320, 192 };

void fgm_init() {
	snd_click = fgm::audio_create_stream("snd_click.ogg");
	insgame = fgm::instance_find(fgm::asset_get_index("Object1"), 0);
}

std::string GetVersionStr(const fgm::instance & ins) {
	int l, m, r;
	fgm::FxxkGML_GetVersion(ins, & l, & m, & r);
	return std::to_string(l) + "." + std::to_string(m) + "." + std::to_string(r);
}

void fgm_main() {
	
	fgm::draw_set_alpha(1);
	fgm::draw_set_color(fgm::c_black);
	fgm::draw_roundrect_ext(button_area, 16, 16, false);
	fgm::draw_set_color(fgm::c_white);
	fgm::draw_text(button_area.left_top() + fgm::vec2(20, 9), "A Nameless Button");

	if(button_area.collision(fgm::mouse_pos_get())) {
		fgm::draw_set_alpha(0.3);
		fgm::draw_roundrect_ext(button_area, 16, 16, false);
		fgm::draw_set_alpha(1);

		if(fgm::mouse_check_button_pressed(fgm::mb_left)) {
			fgm::audio_play_sound(snd_click, 1000, false);
			fgm::show_debug_message(std::to_string(fgm::irandom_range(5, 10)) + "   " + std::to_string(fgm::variable_instance_get_real(insgame.get_id(), "vartest")));

			fgm::FxxkGML_Assistant(insgame, 233);
			fgm::show_debug_message(GetVersionStr(insgame));
			fgm::show_debug_message("Hi, I'm " + std::to_string(fgm::instance_id_get_self()));
		}
	}

}

void fgm_assistant(int assistant_index) {
	switch(assistant_index) {
		case 100:
			fgm::audio_destroy_stream(snd_click);
			break;
	}
}
