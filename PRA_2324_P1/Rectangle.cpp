
#include "Rectangle.h"
#include <exception>
#include <iostream>

Rectangle::Rectangle():Shape() {
    vs = new Point2D[N_VERTICES];
    vs[0].x = -1;   vs[0].y = 0.5;
    vs[1].x = 1;    vs[1].y = 0.5;
    vs[2].x = 1;    vs[2].y = -0.5;
    vs[3].x = -1;   vs[3].y = -0.5;
}

Rectangle::Rectangle(std::string color, Point2D *vertices):Shape(color) {
    if (Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[2], vertices[3])
        && Point2D::distance(vertices[1], vertices[2]) == Point2D::distance(vertices[3], vertices[0])) {
        vs = new Point2D[N_VERTICES];
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = vertices[i];
        }
    } else {
        throw std::invalid_argument("no es un rectangulo");
    }
}

Rectangle::Rectangle(const Rectangle &r) {
    vs = new Point2D[N_VERTICES];
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i] = r.vs[i];
    }
}

Rectangle::~Rectangle() {
    delete[] vs;
}

Point2D Rectangle::get_vertex(int ind) const {
    if (ind > 3 || ind < 0) {
        throw std::out_of_range("fuera de rango");
    }
    return vs[ind];
}

void Rectangle::set_vertices(Point2D *vertices) {
    if (Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[2], vertices[3])
        && Point2D::distance(vertices[1], vertices[2]) == Point2D::distance(vertices[3], vertices[0])) {
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = vertices[i];
        }
    } else {
        throw std::invalid_argument("skill issue");
    }
}

Rectangle& Rectangle::operator=(const Rectangle &r) {
    if (this != &r) { // Protect against self-assignment
        delete[] vs;
        vs = new Point2D[N_VERTICES];
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = r.vs[i];
        }
    }
    return *this;
}

Point2D Rectangle::operator[](int ind) const {
    if (ind > 3 || ind < 0) {
        throw std::out_of_range("fuera de rango");
    }
    return vs[ind];
}

std::ostream &operator<<(std::ostream &out, const Rectangle &r) {
    out <<"color: " << r.color << "vertices: [";
    for (int i = 0; i < r.N_VERTICES; i++) {
        out << "(" << r.vs[i].x << "," << r.vs[i].y << ")";
    }
    out << "]";
    return out;
}
double Rectangle::area() const {
    return Point2D::distance(vs[0], vs[1]) * Point2D::distance(vs[1], vs[2]);
}

double Rectangle::perimeter() const {
    return (Point2D::distance(vs[0], vs[1]) * 2) + (Point2D::distance(vs[1], vs[2]) * 2);
}

void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; i++) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

void Rectangle::print() const {
    std::cout << *this;
}