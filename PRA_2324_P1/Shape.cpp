#include "Shape.h"

Shape::Shape() {
    set_color("red");
}
Shape::Shape(std::string color) {
    set_color(color);
}

void Shape::set_color(std::string c) {
    color = c;
}

std::string Shape::get_color() const {
    return color;
}