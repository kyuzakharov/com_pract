#include <iostream>
#include <cmath>
#include <random>

struct Point {
    double x;
    double y;
};
struct Line {
    double A;
    double B;
    double C;
};
double distLine(Point p, Line l) {
    return std::abs(l.A * p.x + l.B * p.y + l.C) / std::sqrt(l.A * l.A + l.B * l.B);
}

Point fIntersection(Line l1, Line l2) {
    double det = l1.A * l2.B - l1.B * l2.A;
    if (det == 0) {
        std::cerr << "Прямые параллельны" << std::endl;
        return {0.0, 0.0};
    }
    double x = (l2.C * l1.B - l1.C * l2.B) / det;
    double y = (l1.C * l2.A - l2.C * l1.A) / det;
    return {x, y};
}

double distPoints(Point p1, Point p2) {
    return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2));
}

double angleLines(Line l1, Line l2) {
    double angle1 = std::atan2(l1.B, l1.A);
    double angle2 = std::atan2(l2.B, l2.A);
    double angle = angle2 - angle1;
    return std::abs(angle) * (180.0 / M_PI);
}

int main() {
    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(-7.0, 7.0);

    Point point = {distribution(generator), distribution(generator)};
    Line line1 = {distribution(generator), distribution(generator), distribution(generator)};
    Line line2 = {distribution(generator), distribution(generator), distribution(generator)};

    double distance1 = distLine(point, line1);
    double distance2 = distLine(point, line2);

    Point intersection = fIntersection(line1, line2);
    double distIntersection = distPoints(point, intersection);

    double angle = angleLines(line1, line2);

    std::cout << "Точка: (" << point.x << ", " << point.y << ")" << std::endl;
    std::cout << "Прямая 1: " << line1.A << "x + " << line1.B << "y + " << line1.C << " = 0" << std::endl;
    std::cout << "Прямая 2: " << line2.A << "x + " << line2.B << "y + " << line2.C << " = 0" << std::endl;
    std::cout << "Расстояние от точки до прямой 1: " << distance1 << std::endl;
    std::cout << "Расстояние от точки до прямой 2: " << distance2 << std::endl;
    std::cout << "Точка пересечения прямых: (" << intersection.x << ", " << intersection.y << ")" << std::endl;
    std::cout << "Расстояние от точки до точки пересечения: " << distIntersection << std::endl;
    std::cout << "Угол между прямыми: " << angle << " градусов" << std::endl;
    return 0;
}