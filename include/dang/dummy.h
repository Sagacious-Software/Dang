#ifndef DUMMY_H
#define DUMMY_H

#include <kit/color.h>

#include "element.h"

/* dummy gui element */
typedef struct dummy_element_t {

    element_t base;
    color_t color;

} dummy_element_t;

/* dummy element constructor */
dummy_element_t *create_dummy_element (color_t color);

#endif /* DUMMY_H */
