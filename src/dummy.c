#include <stdint.h>

#include <freaking/pen.h>
#include <freaking/shape.h>

#include <dang/dummy.h>

void destroy_dummy_element (element_t *element) {

    free (element);
}

void draw_dummy_element (element_t *element,
                         image_t image,
                         region_t element_region,
                         region_t draw_region) {

    dummy_element_t *dummy_element;

    region_t region;
    uint32_t packed_color;
    pen_t pen;
    shape_t shape;
        
    dummy_element = (dummy_element_t *) element;

    region = intersect_region (element_region, draw_region);
    pack_color (image.format, &packed_color, dummy_element->color);

    pen = make_pen (0, &packed_color);                                          
    shape = make_shape (SHAPE_RECTANGLE);                                       
    shape.shapes.rectangle = make_shape_rectangle_with_region (region);
    fill_shape (shape, image.buffer, pen);                              
}

dummy_element_t *create_dummy_element (color_t color) {

    dummy_element_t *element = malloc (sizeof (dummy_element_t));
    element->base.cursor = CURSOR_POINTER;
    element->base.destroy_element_method = destroy_dummy_element;
    element->base.draw_element_method    = draw_dummy_element;
    element->color = color;
    return element;
}
