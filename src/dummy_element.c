#include <dang/dummy_element.h>

void destroy_dummy_element (element_t *element) {

    free (element);
}

window_t *present_dummy_element (element_t *element,
                                 backend_t *backend,
                                 region_t region,
                                 char *title) {

    return create_window (backend, region, title, element_window_callback, element);
}

dummy_element_t *create_dummy_element (color_t color) {

    dummy_element_t *element = malloc (sizeof (dummy_element_t));
    element->base.cursor = CURSOR_POINTER;
    element->base.destroy_element_method = destroy_dummy_element;
    element->base.present_element_method = present_dummy_element;
    element->color = color;
    return element;
}
