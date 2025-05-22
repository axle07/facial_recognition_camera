#ifndef FACE_RECOGNITION_H
#define FACE_RECOGNITION_H

#include <stdint.h>
#include <list>
#include "fb_gfx.h"
#include "face_recognition_tool.hpp"
#include "face_recognition_112_v1_s16.hpp"
#include "face_recognition_112_v1_s8.hpp"
#include "human_face_detect_msr01.hpp"

int run_face_recognition(fb_data_t *fb, std::list<dl::detect::result_t> *results, FaceRecognition112V1S8 &recognizer, int is_enrolling, int FACE_ID_SAVE_NUMBER);
void rgb_print(fb_data_t *fb, uint32_t color, const char *str);
int rgb_printf(fb_data_t *fb, uint32_t color, const char *format, ...);

#endif // FACE_RECOGNITION_H
