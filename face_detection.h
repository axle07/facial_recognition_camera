#ifndef FACE_DETECTION_H
#define FACE_DETECTION_H

#include <stdint.h>
#include <list>
#include "fb_gfx.h"
#include "human_face_detect_msr01.hpp"
#include "human_face_detect_mnp01.hpp"

void draw_face_boxes(fb_data_t *fb, std::list<dl::detect::result_t> *results, int face_id);

#endif // FACE_DETECTION_H
