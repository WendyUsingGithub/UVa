/* ★☆☆ UVa 10242 Fourth Point !! */
/* 2021/8/10 Wendy */

#include <iostream>
#include <iomanip>
using namespace std;

class Point {
public:
    double x;
    double y;
};

class Vector {
public:
    double x;
    double y;
};

int equal(Point a, Point b);
Vector makeVector(Point a, Point b);
Vector addVector(Vector v1, Vector v2);
Point makeFourthPoint(Vector v, Point p);

int main()
{
    Point p1;
    Point p2;
    Point p3;
    Point p4;
    Vector e1;
    Vector e2;
    Vector v; /* diagonal vector */
    Point pc; /* common point */
    Point fourthPoint;

    while(cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y) {
        if(equal(p1, p3)) {
            /* Vector12 & Vector 14 */
            e1 = makeVector(p1, p2);
            e2 = makeVector(p1, p4);
            pc = p1;
        }
        if(equal(p1, p4)) {
            /* Vector 12 & Vector 13 */
            e1 = makeVector(p1, p2);
            e2 = makeVector(p1, p3);
            pc = p1;
        }
        if(equal(p2, p3)) {
            /* Vector 21 & Vector 24 */
            e1 = makeVector(p2, p1);
            e2 = makeVector(p2, p4);
            pc = p2;
        }
        if(equal(p2, p4)) {
            /* Vector 21 & Vector 23 */
            e1 = makeVector(p2, p1);
            e2 = makeVector(p2, p3);
            pc = p2;
        }

        v = addVector(e1, e2);
        fourthPoint = makeFourthPoint(v, pc);
        cout << fixed << setprecision(3);
        cout << fourthPoint.x << " " << fourthPoint.y << endl;
    }

    return 0;
}

int equal(Point a, Point b) 
{
    if(a.x == b.x && a.y == b.y) return 1;
    else return 0;
}

/* make Vector ab */
Vector makeVector(Point a, Point b) 
{
    Vector e;
    e.x = b.x - a.x;
    e.y = b.y - a.y;
    return e;
}

Vector addVector(Vector v1, Vector v2)
{
    Vector v;
    v.x = v1.x + v2.x;
    v.y = v1.y + v2.y;
    return v;
}

Point makeFourthPoint(Vector v, Point p) {
    Point fourthPoint;
    fourthPoint.x = v.x + p.x;
    fourthPoint.y = v.y + p.y;
    return fourthPoint;
}