#ifndef CONTAINER_H
#define CONTAINER_H

#include <kit/color.h>
#include <kit/array.h>

#include "element.h"

/* the orientation of the split */
typedef enum orientation_t {

    ORIENTATION_HORIZONTAL,
    ORIENTATION_VERTICAL,

    NUM_ORIENTATION

} orientation_t;

/* ways of specifying amount of occupied space */
typedef enum size_type_t {

    SIZE_PIXEL,      /* absolute space in pixels */
    SIZE_PROPORTION, /* percentage of the remaining space */

    NUM_SIZE_TYPE

} size_type_t;

/* a description of amount of occupied space */
typedef struct slot_size_t {

    size_type_t type;
    double size;

} slot_size_t;

/* a slot for a child element */
typedef struct child_slot_t {

    element_t *child; /* the element occupying the slot */
    slot_size_t size; /* the amount of space the slot occupies */

} child_slot_t;

/* box model styling attributes */
typedef struct container_style_t {

    color_t border_color;
    color_t gap_color;

    double border_size;
    double gap_size;

} container_style_t;

/* split container gui element */
typedef struct container_element_t {

    element_t base;

    /* the orientation of the layout of the children */
    orientation_t orientation;

    /* the appearance of the container */
    container_style_t style;

    /* the slots for the child elements */
    array_t slots;

} container_element_t;

/* container element constructor */
container_element_t *create_container_element (orientation_t orientation
                                               container_style_t style);

#endif /* CONTAINER_H */
