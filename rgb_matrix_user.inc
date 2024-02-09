RGB_MATRIX_EFFECT(ARO_ACE_REACTIVE_SIMPLE)

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
RGB_MATRIX_EFFECT(SOLID_REACTIVE_SIMPLE)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

const RGB ledsOff = {.r = 0, .g = 0, .b = 0};

const RGB darkOrange = {.r = 239, .g = 144, .b = 7};
const RGB lightOrange = {.r = 246, .g = 211, .b = 23};
const RGB white = {.r = 255, .g = 255, .b = 255};
const RGB lightBlue = {.r = 69, .g = 188, .b = 238};
const RGB darkBlue = {.r = 30, .g = 63, .b = 83};

float max(float a, float b, float c) {
   return ((a > b)? (a > c ? a : c) : (b > c ? b : c));
}
float min(float a, float b, float c) {
   return ((a < b)? (a < c ? a : c) : (b < c ? b : c));
}

//RGB aroaceFlag[5] = {darkOrange, lightOrange, white, lightBlue, darkBlue};
HSV rgb_to_hsv(RGB color) {
   // R, G, B values are divided by 255
   // to change the range from 0..255 to 0..1:
   float r = color.r/255.0;
   float g = color.g/255.0;
   float b = color.b/255.0;

   float h = 0, s = 0, v = 0;

   float cmax = max(r, g, b); // maximum of r, g, b
   float cmin = min(r, g, b); // minimum of r, g, b
   float diff = cmax-cmin; // diff of cmax and cmin.
   if (cmax == cmin){
      h = 0;
    }
   else if (cmax == r){
      h = fmod((60 * ((g - b) / diff) + 360), 360.0);
  }
   else if (cmax == g){
      h = fmod((60 * ((b - r) / diff) + 120), 360.0);
  }
   else if (cmax == b){
      h = fmod((60 * ((r - g) / diff) + 240), 360.0);
   // if cmax equal zero
      if (cmax == 0)
         s = 0;
      else
         s = (diff / cmax) * 100;
    }
   // compute v
   v = cmax * 100;

   HSV hsv = rgb_matrix_get_hsv();
   hsv.h = h;
   hsv.s = s;
   hsv.v = v;
   return(hsv);
}

static HSV ARO_ACE_REACTIVE_SIMPLE_math(HSV hsv, uint16_t offset) {
    if(!(offset % 6)){
        return(rgb_to_hsv(darkOrange));
    }
    else if(!(offset % 5)){
        return(rgb_to_hsv(lightOrange));
    }
    else if(!(offset % 4)){
        return(rgb_to_hsv(white));
    }
    else if(!(offset % 3)){
        return(rgb_to_hsv(lightBlue));
    }
    else if(!(offset % 2)){
        return(rgb_to_hsv(darkBlue));
    }
    return(rgb_to_hsv(ledsOff));
}


bool ARO_ACE_REACTIVE_SIMPLE(effect_params_t* params) {
    return effect_runner_reactive(params, &ARO_ACE_REACTIVE_SIMPLE_math);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED









































/*
RGB_MATRIX_EFFECT(aro_ace_heatmap)

#if defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS) && defined(ENABLE_RGB_MATRIX_TYPING_HEATMAP)
RGB_MATRIX_EFFECT(TYPING_HEATMAP)
#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#        ifndef RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP
#            define RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP 32
#        endif

#        ifndef RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS
#            define RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS 25
#        endif

#        ifndef RGB_MATRIX_TYPING_HEATMAP_SPREAD
#            define RGB_MATRIX_TYPING_HEATMAP_SPREAD 40
#        endif

#        ifndef RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT
#            define RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT 16
#        endif

const RGB ledsOff = {.r = 0, .g = 0, .b = 0};

const RGB darkOrange = {.r = 239, .g = 144, .b = 7};
const RGB lightOrange = {.r = 246, .g = 211, .b = 23};
const RGB white = {.r = 255, .g = 255, .b = 255};
const RGB lightBlue = {.r = 69, .g = 188, .b = 238};
const RGB darkBlue = {.r = 30, .g = 63, .b = 83};
RGB aroaceFlag[5] = {darkOrange, lightOrange, white, lightBlue, darkBlue};

int compareRGB(RGB color1, RGB color2){
    if(color1.r == color2.r){
        if(color1.g == color2.g){
            if(color1.b == color2.b){
                return(1);
            }
        }
    }
    return(0);
}


RGB get_rgb_color(int index, int max, int min){
    //RGB_MATRIX_USE_LIMITS(led_min, led_max);
    RGB color;
    ws2812_led led;
    if((index >= min) && (index < max)){
        memcpy_P(&led, (&g_ckled2001_leds[index]), sizeof(led));
        color.r = g_pwm_buffer[led.driver][led.r];
        color.g = g_pwm_buffer[led.driver][led.g];
        color.b = g_pwm_buffer[led.driver][led.b];
    }
    return(color);

}

RGB getNextColor(RGB color){
    int size = sizeof(aroaceFlag)/sizeof(aroaceFlag[0]);
    val = rand() % 6;
    return(aroaceFlag[val]);
    for(int i = 0; i < size; i++){
        if(compareRGB(color, aroaceFlag[i])){
            if(i == (size - 1)){
                return(aroaceFlag[i]);
            }
            else{
                return(aroaceFlag[i+1]);
            }
        }
    }
}

RGB getPreviousColor(RGB color){
    int size = sizeof(aroaceFlag)/sizeof(aroaceFlag[0]);
    for(int i = 0; i < size; i++){
        if(compareRGB(color, aroaceFlag[i])){
            if(i == 0){
                return(ledsOff);
            }
            else{
                return(aroaceFlag[i-1]);
            }
        }
    }
}

//get index of color passed
int getIndex(RGB value){
    switch(value){
        case aroaceFlag[0]:
            return(0);
            break;
        case aroaceFlag[1]:
            return(1);
            break;
        case aroaceFlag[2]:
            return(2);
            break;
        case aroaceFlag[3]:
            return(3);
            break;
        default:
            return(4);
            break;

}

void process_rgb_matrix_typing_heatmap(uint8_t row, uint8_t col) {
#        ifdef RGB_MATRIX_TYPING_HEATMAP_SLIM
    // Limit effect to pressed keys
    g_rgb_frame_buffer[row][col] = qadd8(g_rgb_frame_buffer[row][col], RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP);
#        else
    if (g_led_config.matrix_co[row][col] == NO_LED) { // skip as pressed key doesn't have an led position
        return;
    }
    for (uint8_t i_row = 0; i_row < MATRIX_ROWS; i_row++) {
        for (uint8_t i_col = 0; i_col < MATRIX_COLS; i_col++) {
            if (g_led_config.matrix_co[i_row][i_col] == NO_LED) { // skip as target key doesn't have an led position
                continue;
            }
            if (i_row == row && i_col == col) {
                g_rgb_frame_buffer[row][col] = qadd8(g_rgb_frame_buffer[row][col], RGB_MATRIX_TYPING_HEATMAP_INCREASE_STEP);
            } else {
#            define LED_DISTANCE(led_a, led_b) sqrt16(((int16_t)(led_a.x - led_b.x) * (int16_t)(led_a.x - led_b.x)) + ((int16_t)(led_a.y - led_b.y) * (int16_t)(led_a.y - led_b.y)))
                uint8_t distance = LED_DISTANCE(g_led_config.point[g_led_config.matrix_co[row][col]], g_led_config.point[g_led_config.matrix_co[i_row][i_col]]);
#            undef LED_DISTANCE
                if (distance <= RGB_MATRIX_TYPING_HEATMAP_SPREAD) {
                    uint8_t amount = qsub8(RGB_MATRIX_TYPING_HEATMAP_SPREAD, distance);
                    if (amount > RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT) {
                        amount = RGB_MATRIX_TYPING_HEATMAP_AREA_LIMIT;
                    }
                    g_rgb_frame_buffer[i_row][i_col] = qadd8(g_rgb_frame_buffer[i_row][i_col], amount);
                }
            }
        }
    }
#        endif
}

// A timer to track the last time we decremented all heatmap values.
static uint16_t heatmap_decrease_timer;
// Whether we should decrement the heatmap values during the next update.
static bool decrease_heatmap_values;

bool TYPING_HEATMAP(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    if (params->init) {
        rgb_matrix_set_color_all(0, 0, 0);
        memset(g_rgb_frame_buffer, 0, sizeof g_rgb_frame_buffer);
    }

    // The heatmap animation might run in several iterations depending on
    // `RGB_MATRIX_LED_PROCESS_LIMIT`, therefore we only want to update the
    // timer when the animation starts.
    if (params->iter == 0) {
        decrease_heatmap_values = timer_elapsed(heatmap_decrease_timer) >= RGB_MATRIX_TYPING_HEATMAP_DECREASE_DELAY_MS;

        // Restart the timer if we are going to decrease the heatmap this frame.
        if (decrease_heatmap_values) {
            heatmap_decrease_timer = timer_read();
        }
    }

    // Render heatmap & decrease
    uint8_t count = 0;
    for (uint8_t row = 0; row < MATRIX_ROWS && count < RGB_MATRIX_LED_PROCESS_LIMIT; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS && RGB_MATRIX_LED_PROCESS_LIMIT; col++) {
            if (g_led_config.matrix_co[row][col] >= led_min && g_led_config.matrix_co[row][col] < led_max) {
                count++;
                uint8_t val = g_rgb_frame_buffer[row][col];
                if (!HAS_ANY_FLAGS(g_led_config.flags[g_led_config.matrix_co[row][col]], params->flags)) continue;

                //get index and add one. If greater than 4 then stay at 4`
                HSV hsv = {170 - qsub8(val, 85), rgb_matrix_config.hsv.s, scale8((qadd8(170, val) - 170) * 3, rgb_matrix_config.hsv.v)};
                RGB rgb = rgb_matrix_hsv_to_rgb(hsv);

                count++;
                //RGB currentColor = get_rgb_color(g_led_config.matrix_co[row][col], led_min, led_max);
                //assuming this is the index value for the current pin

                RGB rgb = getNextColor();

                if (decrease_heatmap_values) {
                    //get index and subtract 1. If less than 0 then turn off led
                    RGB rgb = getPreviousColor(currentColor);
                    //g_rgb_frame_buffer[row][col] = qsub8(val, 1);
                }
                rgb_matrix_set_color(g_led_config.matrix_co[row][col], rgb.r, rgb.g, rgb.b);
            }
        }
    }

    return rgb_matrix_check_finished_leds(led_max);
}

#    endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif     // defined(RGB_MATRIX_FRAMEBUFFER_EFFECTS) && defined(ENABLE_RGB_MATRIX_TYPING_HEATMAP)
*/
