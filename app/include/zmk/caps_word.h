/*
 * Copyright (c) 2022 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <zephyr/stdbool.h>

extern bool last_state_of_caps_word;
bool zmk_caps_word_state();