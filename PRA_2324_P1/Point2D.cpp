#include "Point2D.h"

Point2D::Point2D(double x, double y) : x(x), y(y) {}

double Point2D::distance(const Point2D &a, const Point2D &b){
    return std::sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));

}
bool operator==(const Point2D &a, const Point2D &b){
    return a.x == b.x && a.y == b.y;

}
bool operator!=(const Point2D &a, const Point2D &b){
    return a.x != b.x || a.y != b.y;

}
std::ostream& operator<<(std::ostream &out, const Point2D &p){
    return out << "Point (" << p.x << "," << p.y << ")";
}