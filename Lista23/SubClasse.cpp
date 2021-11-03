#include<iostream>
#include<math.h>
#define PI 3.14
using namespace std;

const int MAX = 100;

class FigGeometrica {
	private:
    static int Quantidade;
    public:
    FigGeometrica() {
        this-> quantidade();
    }
    virtual float perimetro() {
        
    }
    virtual float area() {
        
    }
    void quantidade() {
        Quantidade++; 
    }
    static int getQuant() {
        return Quantidade;
    }
};

class Circulo: public FigGeometrica {
	private:
	float raio;
	int Quantidade;
	public:
    Circulo() {
        this->setRaio(0);
        this-> quantidade();
    }
    Circulo(float raio) {
        this->setRaio(raio);
        this-> quantidade();
    }
    void setRaio(float raio) {
        this->raio = raio;
    }
    float getRaio() {
        return this->raio;
    }
    float perimetro() {
        return this-> getRaio() * PI * 2;
    }
    float area() {
        return ( this-> getRaio() * this-> getRaio() ) * PI;
    }
    void quantidade() {
        Quantidade++;
        FigGeometrica::quantidade();
    }
};

class Quadrado: public FigGeometrica {
	private:
	float lado;
	int Quantidade;
	public:
    Quadrado() {
        this-> setLado(0);
        quantidade();
    }
    Quadrado(float lado) {
        this-> setLado(lado);
        this-> quantidade();
    }
    void setLado(float lado) {
        this-> lado = lado;
    }
    float getLado() {
        return this-> lado;
    }
    float perimetro() {
        return this-> getLado() * 4;
    }
    float area() {
        return this-> getLado() * this-> getLado();
    }
    void quantidade() {
        Quantidade++;
        FigGeometrica::quantidade();
    }
};

class Triangulo: public FigGeometrica {
	private:
	float a,
	      b,
	      c;
	int Quantidade;
	public:
    Triangulo() {
        this-> setTriangulo(0,0,0);
        this-> quantidade();
    }
    Triangulo(float a) {
        this-> setTriangulo(a, a, a);
        this-> quantidade();
    }
    Triangulo(float a, float b, float c) {
        this-> setTriangulo(a, b, c);
        this-> quantidade();
    }
    void setTriangulo(float a, float b, float c) {
        this-> a = a;
        this-> b = b;
        this-> c = c;
    }
    float getA() {
        return this-> a;
    }
    float getB() {
        return this-> b;
    }
    float getC() {
        return this-> c;
    }
    float perimetro() {
        return this-> getA() + this-> getB() + this-> getC();
    }
    float area() {
        float S = (this-> perimetro()/ 2);
        return sqrt(S * (S - this-> getA() ) * (S - this-> getB() ) * (S - this-> getC() ) );
    }
    bool valido() {
        bool trianguloValido = true;
        if (!(abs(getB() - getC()) < getA() && getA() < (getB() + getC()) || abs(getA() - getC()) < getB() && getB() < (getA() + getC()) || abs(getA() - getB()) < getC() && getC() < (getB() + getA()))) {
            trianguloValido = false;
            return trianguloValido;
        }
        else {
            return trianguloValido;
        }
    }
    void quantidade() {
        Quantidade++; 
        FigGeometrica::quantidade();
    }
};

int FigGeometrica::Quantidade = 0;

int main() {
    FigGeometrica *arranjoFiguras[MAX];
    cout << FigGeometrica::getQuant() << endl;
    arranjoFiguras[FigGeometrica::getQuant()] = new Triangulo(5);
    cout << FigGeometrica::getQuant() << endl;
    VerificarTriangulo(arranjoFiguras[2]);
    cout << arranjoFiguras[2]->area() << endl;
    return 0;
}

