draw_set_color(c_black);
draw_text(x, y, "Hello! I'm obj_test2");
draw_set_color(c_white);
if(sprite_index != -1)
draw_self();
if(mask_index != -1)
draw_sprite_ext(mask_index, image_index, x, y + bbox_bottom - bbox_top + 16, image_xscale, image_yscale, image_angle, image_blend, image_alpha);
