#include "Square.h"
#include <exception>

bool Square::check(Point2D *vertices) {
    return Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[1], vertices[2])
            && Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[2], vertices[3])
            && Point2D::distance(vertices[0], vertices[1]) == Point2D::distance(vertices[3], vertices[0]);
}

Square::Square(){
    color = "red";
    vs = new Point2D[N_VERTICES];
    vs[0].x = -1;   vs[0].y = 1;
    vs[1].x = 1;    vs[1].y = 1;
    vs[2].x = 1;    vs[2].y = -1;
    vs[3].x = -1;   vs[3].y = -1;
}

Square::Square(std::string color, Point2D *vertices) {
    this->color = color;
    if (check(vertices)) {
        vs = new Point2D[N_VERTICES];
        for (int i = 0; i < N_VERTICES; i++){
            vs[i].x = vertices[i].x;   vs[i].y = vertices[i].y;
        }
    } else {
        throw std::invalid_argument("no es un cuadrado");
    }
}

void Square::set_vertices(Point2D *vertices) {
    if (check(vertices)) {
        for (int i = 0; i < N_VERTICES; i++) {
            vs[i] = vertices[i];
        }
    } else {
        throw std::invalid_argument("no es un cuadrado");
    }
}

std::ostream &operator<<(std::ostream &out, const Square &square) {
    out << "color: " << square.color << "vertices: [";
    for (int i = 0; i < square.N_VERTICES; i++) {
        out << "(" << square.vs[i].x << "," << square.vs[i].y << ")";
    }
    out << "]";
    return out;
}
void Square::print() const {
    std::cout << *this;
}