
#include "Drawing.h"
#include "Circle.h"
#include "Square.h"

Drawing::Drawing(){
    shapes = new ListArray<Shape*>();
}

Drawing::~Drawing() {
    delete shapes;
}

void Drawing::add_front(Shape *shape) {
    shapes->prepend(shape);
}

void Drawing::add_back(Shape *shape) {
    shapes->append(shape);
}

void Drawing::print_all() {
    for (int i = 0; i < shapes->size(); i++) {
        if(dynamic_cast<Circle*>(shapes->get(i))) {
            Circle* r = dynamic_cast<Circle*>(shapes->get(i));
            r->print();
            std::cout<< std::endl;
        } else if(dynamic_cast<Square*>(shapes->get(i))) {
            Square* r = dynamic_cast<Square*>(shapes->get(i));
            r->print();
            std::cout<< std::endl;
        } else if(dynamic_cast<Rectangle*>(shapes->get(i))) {
            Rectangle* r = dynamic_cast<Rectangle*>(shapes->get(i));
            r->print();
            std::cout<< std::endl;
        }
    }
}

double Drawing::get_area_all_circles() {
    double r = 0;
    for (int i = 0; i < shapes->size(); i++) {
        if(Circle* c = dynamic_cast<Circle*>(shapes->get(i))) {
            r += c->area();
        }
    }
    return r;
}

void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); i++) {
        if(Square* s = dynamic_cast<Square*>(shapes->get(i))) {
            s->translate(incX, incY);
        }
    }
}
