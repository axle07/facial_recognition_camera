#include <stdint.h>
#include <list>
#include "face_recognition.h"
#include "fb_gfx.h"
#include <cstdint>
#include <cstring>
#include <cstdarg>
#include <cstdlib>

void rgb_print(fb_data_t *fb, uint32_t color, const char *str) {
    fb_gfx_print(fb, (fb->width - (strlen(str) * 14)) / 2, 10, color, str);
}

int rgb_printf(fb_data_t *fb, uint32_t color, const char *format, ...) {
    char loc_buf[64];
    char *temp = loc_buf;
    int len;
    va_list arg;
    va_list copy;
    va_start(arg, format);
    va_copy(copy, arg);
    len = vsnprintf(loc_buf, sizeof(loc_buf), format, arg);
    va_end(copy);
    if (len >= (int)sizeof(loc_buf)) {
        temp = (char *)malloc(len + 1);
        if (temp == NULL) {
            return 0;
        }
    }
    vsnprintf(temp, len + 1, format, arg);
    va_end(arg);
    rgb_print(fb, color, temp);
    if (len > 64) {
        free(temp);
    }
    return len;
}

int run_face_recognition(fb_data_t *fb, std::list<dl::detect::result_t> *results, FaceRecognition112V1S8 &recognizer, int is_enrolling, int FACE_ID_SAVE_NUMBER) {
    std::vector<int> landmarks = results->front().keypoint;
    int id = -1;
    Tensor<uint8_t> tensor;
    tensor.set_element((uint8_t *)fb->data).set_shape({fb->height, fb->width, 3}).set_auto_free(false);
    int enrolled_count = recognizer.get_enrolled_id_num();
    if (enrolled_count < FACE_ID_SAVE_NUMBER && is_enrolling) {
        id = recognizer.enroll_id(tensor, landmarks, "", true);
        rgb_printf(fb, 0x00FFFF00, "ID[%u]", id); // FACE_COLOR_CYAN
    }
    face_info_t recognize = recognizer.recognize(tensor, landmarks);
    if (recognize.id >= 0) {
        rgb_printf(fb, 0x0000FF00, "ID[%u]: %.2f", recognize.id, recognize.similarity); // FACE_COLOR_GREEN
    } else {
        rgb_print(fb, 0x000000FF, "Intruder Alert!"); // FACE_COLOR_RED
    }
    return recognize.id;
}
