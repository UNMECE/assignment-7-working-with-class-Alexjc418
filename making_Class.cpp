#include <iostream>
#include <cmath>

class Electric_Field {
private:
    double *E;

public:
    Electric_Field(){ 
            E = new double[3]{0.0, 0.0, 0.0}; }
    Electric_Field(double ex, double ey, double ez){ 
            E = new double[3]{ex, ey, ez}; }
    ~Electric_Field(){ 
            delete[] E; }

    double Calculate_Magnitude(){ 
            return std::sqrt(E[0] * E[0] + E[1] * E[1] + E[2] * E[2]); }
    double innerProduct(){ 
            return E[0] * E[0] + E[1] * E[1] + E[2] * E[2]; }

    double getE_X(){ 
            return E[0]; }
    double getE_Y(){ 
            return E[1]; }
    double getE_Z(){ 
            return E[2]; }

    void setE_X(double ex){ 
            E[0] = ex; }
    void setE_Y(double ey){ 
            E[1] = ey; }
    void setE_Z(double ez){ 
            E[2] = ez; }
};

class Magnetic_Field {
private:
    double *B;

public:
    Magnetic_Field(){ 
            B = new double[3]{0.0, 0.0, 0.0}; }
    Magnetic_Field(double bx, double by, double bz){ 
            B = new double[3]{bx, by, bz}; }
    ~Magnetic_Field(){ 
            delete[] B; }

    double Calculate_Magnitude(){ 
            return std::sqrt(B[0] * B[0] + B[1] * B[1] + B[2] * B[2]); }

    void calculateUnitVector(){
        double magnitude = Calculate_Magnitude();
        if (magnitude == 0){
            std::cout << "Unit vector: (0, 0, 0)" << std::endl;
            } else {
            std::cout << "Unit vector: (" << B[0] / magnitude << ", " 
                      << B[1] / magnitude << ", " << B[2] / magnitude << ")" << std::endl;
        }
    }

    double getB_X(){ 
            return B[0]; }
    double getB_Y(){ 
            return B[1]; }
    double getB_Z(){ 
            return B[2]; }

    void setB_X(double bx){ 
            B[0] = bx; }
    void setB_Y(double by){ 
            B[1] = by; }
    void setB_Z(double bz){ 
            B[2] = bz; }
};

int main(){
    Electric_Field E1;
    Electric_Field E2(1e5, 10.9, 1.7e2);

    Magnetic_Field B1;
    Magnetic_Field B2(2.5, 5.3, 7.1);

    E1.setE_X(2.0);
    E1.setE_Y(3.0);
    E1.setE_Z(4.0);

    B1.setB_X(0.1);
    B1.setB_Y(0.2);
    B1.setB_Z(0.3);

    std::cout << "Electric Field Magnitude: " << E2.Calculate_Magnitude() << std::endl;
    std::cout << "Electric Field Inner Product: " << E2.innerProduct() << std::endl;

    std::cout << "Magnetic Field Magnitude: " << B2.Calculate_Magnitude() << std::endl;
    std::cout << "Magnetic Field Unit Vector: ";
    B2.calculateUnitVector();

    return 0;
}
