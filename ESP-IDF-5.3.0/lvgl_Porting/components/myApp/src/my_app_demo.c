#include "my_app.h"
#include "lvgl/lvgl.h"
#include <stdio.h>

// Event handler per il bottone (esempio: cambia il testo della label)
static void button_event_cb(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    if(code == LV_EVENT_CLICKED) {
        lv_obj_t * label = (lv_obj_t *)lv_event_get_user_data(e);
        static bool toggle = false;
        toggle = !toggle;
        lv_label_set_text(label, toggle ? "Hello LVGL!" : "Button Pressed!");
    }
}

void my_app_demo_start(void)
{
    // Crea un contenitore principale (stile screen)
    lv_obj_t * cont = lv_obj_create(lv_scr_act());  // Su screen attivo
    lv_obj_set_size(cont, lv_pct(100), lv_pct(100));
    lv_obj_center(cont);

    // Widget 1: Label (testo)
    lv_obj_t * label = lv_label_create(cont);
    lv_label_set_text(label, "Benvenuto in myApp!");
    lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 20);

    // Widget 2: Button con event
    lv_obj_t * btn = lv_btn_create(cont);
    lv_obj_set_size(btn, 120, 50);
    lv_obj_align(btn, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_event_cb(btn, button_event_cb, LV_EVENT_ALL, label);  // Passa label come user_data

    lv_obj_t * btn_label = lv_label_create(btn);
    lv_label_set_text(btn_label, "Premi!");
    lv_obj_center(btn_label);

    // Widget 3: Slider (barra scorrevole)
    lv_obj_t * slider = lv_slider_create(cont);
    lv_obj_set_size(slider, 200, 20);
    lv_obj_align(slider, LV_ALIGN_BOTTOM_MID, 0, -20);
    lv_slider_set_range(slider, 0, 100);
    lv_slider_set_value(slider, 50, LV_ANIM_OFF);

    // Label per valore slider (opzionale)
    lv_obj_t * slider_label = lv_label_create(cont);
    lv_label_set_text(slider_label, "Valore: 50");
    lv_obj_align_to(slider_label, slider, LV_ALIGN_OUT_TOP_MID, 0, -5);

    // Event per aggiornare label slider
    static void slider_event_cb(lv_event_t * e)
    {
        lv_obj_t * slider = lv_event_get_target(e);
        lv_obj_t * lbl = (lv_obj_t *)lv_event_get_user_data(e);
        char buf[32];
        lv_snprintf(buf, sizeof(buf), "Valore: %u", (uint32_t)lv_slider_get_value(slider));
        lv_label_set_text(lbl, buf);
    }
    lv_obj_add_event_cb(slider, slider_event_cb, LV_EVENT_VALUE_CHANGED, slider_label);

    printf("myApp demo avviata: Widget pronti!\n");
}