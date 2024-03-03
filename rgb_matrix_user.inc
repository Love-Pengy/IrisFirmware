
RGB_MATRIX_EFFECT(aro_ace_splash)
RGB_MATRIX_EFFECT(no_anim)

#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
    #ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SPLASH
        // ## default customizable values ##
        #ifndef SOLID_REACTIVE_SPLASH_WAVE_WIDTH
            #define SOLID_REACTIVE_SPLASH_WAVE_WIDTH 45  // ~8 keys wide (including fade/dropoff)
        #endif
        // ## default customizable values ##

        #ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

        static bool no_anim(effect_params_t* params) {
            RGB_MATRIX_USE_LIMITS(led_min, led_max);
            for (uint8_t i = led_min; i < led_max; i++) {
                rgb_matrix_set_color(i, RGB_OFF);
            }
            return rgb_matrix_check_finished_leds(led_max);
        }

        //original set
        const RGB darkOrange = {.r = 239, .g = 144, .b = 7};
        //const HSV darkOrange = {.h = 35, .s = 97.1, .v = 93.7};
        const RGB lightOrange = {.r = 246, .g = 211, .b = 23};
        //const HSV lightOrange = {.h = 51, .s = 90.7, .v = 96.5};
        const RGB white = {.r = 255, .g = 255, .b = 255};
        //const HSV white = {.h = 51, .s = 0, .v = 100};
        const RGB lightBlue = {.r = 69, .g = 188, .b = 238};
        //const HSV lightBlue = {.h = 198, .s = 71, .v = 93.3};
        const RGB darkBlue = {.r = 30, .g = 63, .b = 83};
        //const HSV darkBlue = {.h = 203, .s = 63.9, .v = 32.5};
        RGB aroaceFlag[5] = {darkOrange, lightOrange, white, lightBlue, darkBlue};


        const RGB ledsOff = {.r = 0, .g = 0, .b = 0};

        //HSV aroaceFlag[5] = {darkOrange, lightOrange, white, lightBlue, darkBlue};

        /*
        #define DARKORANGE 0xef9007
        #define LIGHTORANGE 0xf6d317
        #define WHITE 0xffffff
        #define lightBlue 0x45bcee
        #define darkBlue 0x1e3f54
        */

            #define _MAX(a, b) ((a) > (b) ? (a) : (b))
            #define _MIN(a, b) ((a) < (b) ? (a) : (b))
            #define _CLAMP(v, min, max) (_MIN(_MAX(v, min), max))

            #define _RGBHEX_R(rgb) ((rgb) >> 16)
            #define _RGBHEX_G(rgb) (((rgb) >> 8) & 0xFF)
            #define _RGBHEX_B(rgb) ((rgb) & 0xFF)
            #define TIMERSCALER 2
            int colorIndex = 0;
            int counter = 0;
            int timerSplit = 10000; // 16 bit max val divided by 5

            RGB getNextRGB(uint16_t timeVal){
                if((timeVal % timerSplit) < 2000){
                    return(aroaceFlag[0]);
                }
                else if(((timeVal % timerSplit) > 2000) && ((timeVal % timerSplit) < 4000)){
                    return(aroaceFlag[1]);
                }
                else if(((timeVal % timerSplit) > 4000) && ((timeVal % timerSplit) < 6000)){
                    return(aroaceFlag[2]);
                }
                else if(((timeVal % timerSplit) > 6000) && ((timeVal % timerSplit < 8000))){
                    return(aroaceFlag[3]);
                }
                else if((timeVal % timerSplit) > 8000){
                    return(aroaceFlag[4]);
                }
                return(ledsOff); //so it stops whining
            }

            bool aro_ace_splash(effect_params_t* params) {
                uint16_t timeElapsed = timer_read();
                RGB_MATRIX_USE_LIMITS(led_min, led_max);
                RGB base_rgb = {.r = 0, .g = 0, .b = 0};

                RGB wave_rgb = getNextRGB(timeElapsed);

                for (uint8_t i = led_min; i < led_max; i++) {
                    RGB_MATRIX_TEST_LED_FLAGS();
                    uint8_t A          = 0;
                    uint8_t hit_count  = g_last_hit_tracker.count;
                    if(hit_count == (counter*10)){
                    }
                    else{
                        colorIndex = rand()%6;
                    }
                    counter = hit_count;

                    uint8_t wave_speed = 40;

                    /* result = (A * wave_color) + ((1 - A) * base_color) */
                    for (uint8_t j = 0; j < hit_count; j++) {
                        uint16_t tick             = g_last_hit_tracker.tick[j];
                        uint16_t wave_travel_dist = scale16by8(tick, qadd8(wave_speed, 1));  // a * (b/255)
                        uint16_t dx               = g_led_config.point[i].x - g_last_hit_tracker.x[j];
                        uint16_t dy               = g_led_config.point[i].y - g_last_hit_tracker.y[j];
                        uint8_t  key_dist         = sqrt16(dx * dx + dy * dy);
                        uint16_t offset           = wave_travel_dist - key_dist;

                        bool before_wave = offset > SOLID_REACTIVE_SPLASH_WAVE_WIDTH;
                        bool after_wave = wave_travel_dist < key_dist;
                        bool inside_wave = !before_wave && !after_wave;

                        if (inside_wave) {
                            A = qadd8(A, qsub8(
                                0xFF, _CLAMP(
                                    255 * offset / SOLID_REACTIVE_SPLASH_WAVE_WIDTH,
                                    0, 0xFF
                                )
                            ));
                        }
                    }

                    RGB rgb = {
                        .r = scale8(wave_rgb.r, A) + scale8(base_rgb.r, 0xFF - A),
                        .g = scale8(wave_rgb.g, A) + scale8(base_rgb.g, 0xFF - A),
                        .b = scale8(wave_rgb.b, A) + scale8(base_rgb.b, 0xFF - A),
                    };

                    rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
                }

                return rgb_matrix_check_finished_leds(led_max);
            }
        #endif
    #endif
#endif

