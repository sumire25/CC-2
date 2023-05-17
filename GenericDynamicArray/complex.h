#ifndef complex_h
#define complex_h
#include <iostream>

class Complex{
    friend std::ostream& operator<<(std::ostream&, const Complex&);
	private:
		float re;
		float im;
	public:
		Complex() {re = 0; im = 0;}
        Complex(float r, float i) {re = r; im = i;}
		float getRe() const {return re;}
		float getIm() const {return im;}
		void setRe(float r) {re = r;}
		void setIm(float i) {im = i;}
		Complex invAd();
		Complex invMult() const {
            Complex z;
            float den=re*re + im*im;
            z.setIm(-1*im / den);
            z.setRe(re / den);
            return z;
        }
        Complex operator*(const Complex& z_1) const {
            Complex z;
            float r=z_1.getRe(), i=z_1.getIm();
            z.setRe((re*r) - (im*i));
            z.setIm((re*i) + (r*im));
            return z;
        }
        Complex operator/(const Complex& z_1) const {
            return *this * (z_1.invMult());
        }
        Complex operator-() const {
            Complex z;
            z.setRe(-re); z.setIm(-im);
            return z;
        }       
        Complex operator+(const Complex& z_1) const {
            Complex z;
            z.setRe(re + z_1.getRe());
            z.setIm(im + z_1.getIm());
            return z;
        }
        Complex operator-(const Complex& z_1) const {
            return *this + (-z_1);
        }
};
std::ostream& operator<<(std::ostream& output, const Complex& z){
    if(z.re !=0){
        output << z.re;
        if(z.im < 0)
            output << "-" << -z.im << "i";
        else if(z.im != 0 || z.im != 1)
            output << "+" << z.im << "i";
        else if(z.im == 1)
            output << "i";
    }
    else
        if(z.im < 0)
            output << "-" << -z.im << "i";
        else if(z.im != 0 || z.im != 1)
            output << z.im << "i";
        else if(z.im == 1)
            output << "i";
        else
            output << "0";
    return output;
}

#endif