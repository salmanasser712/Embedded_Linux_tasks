#ifndef POINT_H
#define POINT_H

class Point{
    public:
    void cartesianToPolar();
    void polarToCartesian();

    void setCartesian(double x, double y);
    void setPolar(double r, double q);

    void DisplayPoint();

    private:
    int availabe;

    double Cart_x;
    double Cart_y;

    double Polar_r;
    double Polar_q;

};



#endif