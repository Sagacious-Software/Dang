#include <stdint.h>

#include <dang/container.h>

void destroy_container_element (element_t *element) {

    free (element);
}

void draw_container_element (element_t *element,
                             image_t image,
                             region_t element_region,
                             region_t draw_region) {


}

container_element_t *create_container_element (orientation_t orientation,
                                               container_style_t style) {

    container_element_t *element = malloc (sizeof (container_element_t));
    element->base.cursor = CURSOR_POINTER;
    element->base.destroy_element_method = destroy_container_element;
    element->base.draw_element_method = draw_container_element;
    element->orientation = orientation;
    element->style = style;
    return element;
}
