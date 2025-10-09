#include <zmk/caps_word.h>

#include <stdbool.h>
#include <zephyr/kernel.h>

bool zmk_caps_word_state() { return behavior_caps_word_data.data->active; }
