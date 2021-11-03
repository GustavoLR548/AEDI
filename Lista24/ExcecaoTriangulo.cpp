#include <iostream>
#include <math.h>
using namespace std;

int TAM = 0;
const int MAX = 5;

    class Erro1:public runtime_error {
        public:
        Erro1():runtime_error("Erro! N�o � poss�vel criar mais tri�ngulos\n"){}
    };
    
    class Erro2 : public runtime_error {
        public:
        Erro2():runtime_error("Erro! N�o existe tri�ngulos nas posi��es mencionadas\nTente novamente:\n"){}
    };
    class figura {
    private:
        float ladoA;
        float ladoB;
        float ladoC;

    public:
        void setLadoA(float ladoA) {
            if (ladoA < 0) {
                this-> ladoA = 0;
            }
            else {
                this-> ladoA = ladoA;
            }
        }

        void setLadoB(float ladoB) {
            if (ladoB < 0) {
                this-> ladoB = 0;
            }
            else {
                this-> ladoB = ladoB;
            }
        }
        void setLadoC(float ladoC) {
            if (ladoC < 0) {
                this-> ladoC = 0;
            }
            else {
                this-> ladoC = ladoC;
            }
        }
        float getLadoA(){
            if (ladoA < 0){
                return 0;
            }
            else {
                return this-> ladoA;
            }
        }

        float getLadoB() {
            if (ladoB < 0){
                return 0;
            }
            else {
                return this-> ladoB;
            }
        }
        float getLadoC() {
            if (ladoC < 0){
                return 0;
            }
            else {
                return this-> ladoC;
            }
        }
        void lerLados() {
            float lado;
            cout << "\nLeitura dos lados:\n";
            do { 
                for (int i = 0; i <= 2; i++) {
                    cin >> lado;
                    if (i == 0) {
                        setLadoA(lado);
                    }
                    else if (i == 1) {
                        setLadoB(lado);
                    }
                    else {
                        setLadoC(lado);
                    }
                }
                if (!(abs(getLadoB() - getLadoC()) < getLadoA() && getLadoA() < (getLadoB() + getLadoC()) || abs(getLadoA() - getLadoC()) < getLadoB() && getLadoB() < (getLadoA() + getLadoC()) || abs(getLadoA() - getLadoB()) < getLadoC() && getLadoC() < (getLadoB() + getLadoA()))) {
                    cout << "\nN�o � poss�vel fazer um tri�ngulo com os dados inseridos!\nTente novamente:\n";    
                }
            } while (!(abs(getLadoB() - getLadoC()) < getLadoA() && getLadoA() < (getLadoB() + getLadoC()) || abs(getLadoA() - getLadoC()) < getLadoB() && getLadoB() < (getLadoA() + getLadoC()) || abs(getLadoA() - getLadoB()) < getLadoC() && getLadoC() < (getLadoB() + getLadoA())));
        }
        float calcularPerimetro() {
            float perimetro = getLadoA() + getLadoB() + getLadoC();
            return perimetro;
        }
        int tipoDoTriangulo() {
            if (getLadoA() == getLadoB() && getLadoB() == getLadoC() ) {
                return 1;
            }
            else if (getLadoA() == getLadoB() && getLadoC() != getLadoB() || getLadoB() == getLadoC() && getLadoA() != getLadoB() || getLadoA() == getLadoC() && getLadoA() != getLadoB()) {
                return 2;
            }
            else if(getLadoA() != getLadoB() && getLadoA() != getLadoC() && getLadoB() != getLadoC()) {
                return 3;
            }
            else {
                return 0;
            }
        }
        bool compararTriangulos(figura *Triangulo,int triangulo1,int triangulo2) {
            float trianguloUmLado[MAX];
            float trianguloDoisLado[MAX];
            if ( Triangulo[triangulo1].tipoDoTriangulo() == 1)  {
                for (int i = 0; i <= 2; i++) {
                    trianguloUmLado[i] = Triangulo[triangulo1].getLadoA();
                }
            }
            else if ( Triangulo[triangulo1].tipoDoTriangulo() == 2 ) {
                if ( Triangulo[triangulo1].getLadoA() == Triangulo[triangulo1].getLadoB() && Triangulo[triangulo1].getLadoA() < Triangulo[triangulo1].getLadoC()) {
                    trianguloUmLado[0] = Triangulo[triangulo1].getLadoA();
                    trianguloUmLado[1] = Triangulo[triangulo1].getLadoB();
                    trianguloUmLado[2] = Triangulo[triangulo1].getLadoC();
                }
                else if ( Triangulo[triangulo1].getLadoA() == Triangulo[triangulo1].getLadoB() && Triangulo[triangulo1].getLadoA() > Triangulo[triangulo1].getLadoC()) {
                    trianguloUmLado[0] = Triangulo[triangulo1].getLadoC();
                    trianguloUmLado[1] = Triangulo[triangulo1].getLadoB();
                    trianguloUmLado[2] = Triangulo[triangulo1].getLadoA();
                }
                else if ( Triangulo[triangulo1].getLadoB() == Triangulo[triangulo1].getLadoC() && Triangulo[triangulo1].getLadoB() < Triangulo[triangulo1].getLadoA()) {
                    trianguloUmLado[0] = Triangulo[triangulo1].getLadoB();
                    trianguloUmLado[1] = Triangulo[triangulo1].getLadoC();
                    trianguloUmLado[2] = Triangulo[triangulo1].getLadoA();
                }
                else if ( Triangulo[triangulo1].getLadoA() == Triangulo[triangulo1].getLadoB() && Triangulo[triangulo1].getLadoB() > Triangulo[triangulo1].getLadoA()) {
                    trianguloUmLado[0] = Triangulo[triangulo1].getLadoA();
                    trianguloUmLado[1] = Triangulo[triangulo1].getLadoB();
                    trianguloUmLado[2] = Triangulo[triangulo1].getLadoC();
                }
                else if ( Triangulo[triangulo1].getLadoA() == Triangulo[triangulo1].getLadoC() && Triangulo[triangulo1].getLadoA() < Triangulo[triangulo1].getLadoB()) {
                    trianguloUmLado[0] = Triangulo[triangulo1].getLadoA();
                    trianguloUmLado[1] = Triangulo[triangulo1].getLadoC();
                    trianguloUmLado[2] = Triangulo[triangulo1].getLadoB();
                }
                else if ( Triangulo[triangulo1].getLadoA() == Triangulo[triangulo1].getLadoC() && Triangulo[triangulo1].getLadoA() > Triangulo[triangulo1].getLadoB()) {
                    trianguloUmLado[0] = Triangulo[triangulo1].getLadoB();
                    trianguloUmLado[1] = Triangulo[triangulo1].getLadoA();
                    trianguloUmLado[2] = Triangulo[triangulo1].getLadoC();
                }
            }
            else if ( Triangulo[triangulo1].tipoDoTriangulo() == 3 ){
                if ( Triangulo[triangulo1].getLadoA() > Triangulo[triangulo1].getLadoB() && Triangulo[triangulo1].getLadoA() > Triangulo[triangulo1].getLadoC()) {
                    if ( Triangulo[triangulo1].getLadoB() > Triangulo[triangulo1].getLadoC() ) {
                        trianguloUmLado[0] = Triangulo[triangulo1].getLadoC();
                        trianguloUmLado[1] = Triangulo[triangulo1].getLadoB();
                        trianguloUmLado[2] = Triangulo[triangulo1].getLadoA();
                    }
                    else {
                        trianguloUmLado[0] = Triangulo[triangulo1].getLadoB();
                        trianguloUmLado[1] = Triangulo[triangulo1].getLadoC();
                        trianguloUmLado[2] = Triangulo[triangulo1].getLadoA();
                    }
                }
                if ( Triangulo[triangulo1].getLadoB() > Triangulo[triangulo1].getLadoA() && Triangulo[triangulo1].getLadoB() > Triangulo[triangulo1].getLadoC()) {
                    if ( Triangulo[triangulo1].getLadoA() > Triangulo[triangulo1].getLadoC() ) {
                        trianguloUmLado[0] = Triangulo[triangulo1].getLadoC();
                        trianguloUmLado[1] = Triangulo[triangulo1].getLadoA();
                        trianguloUmLado[2] = Triangulo[triangulo1].getLadoB();
                    }
                    else {
                        trianguloUmLado[0] = Triangulo[triangulo1].getLadoA();
                        trianguloUmLado[1] = Triangulo[triangulo1].getLadoC();
                        trianguloUmLado[2] = Triangulo[triangulo1].getLadoB();
                    }
                }
                if ( Triangulo[triangulo1].getLadoC() > Triangulo[triangulo1].getLadoA() && Triangulo[triangulo1].getLadoC() > Triangulo[triangulo1].getLadoB()) {
                    if ( Triangulo[triangulo1].getLadoA() > Triangulo[triangulo1].getLadoB() ) {
                        trianguloUmLado[0] = Triangulo[triangulo1].getLadoB();
                        trianguloUmLado[1] = Triangulo[triangulo1].getLadoA();
                        trianguloUmLado[2] = Triangulo[triangulo1].getLadoC();
                    }
                    else {
                        trianguloUmLado[0] = Triangulo[triangulo1].getLadoA();
                        trianguloUmLado[1] = Triangulo[triangulo1].getLadoB();
                        trianguloUmLado[2] = Triangulo[triangulo1].getLadoC();
                    }
                }
            }
            if ( Triangulo[triangulo2].tipoDoTriangulo() == 1)  {
                for (int i = 0; i < 3; i++) {
                    trianguloDoisLado[i] = Triangulo[triangulo2].getLadoA();
                }
            }
            else if ( Triangulo[triangulo2].tipoDoTriangulo() == 2 ) {
                if ( Triangulo[triangulo2].getLadoA() == Triangulo[triangulo2].getLadoB() && Triangulo[triangulo2].getLadoA() < Triangulo[triangulo2].getLadoC()) {
                    trianguloDoisLado[0] = Triangulo[triangulo2].getLadoA();
                    trianguloDoisLado[1] = Triangulo[triangulo2].getLadoB();
                    trianguloDoisLado[2] = Triangulo[triangulo2].getLadoC();
                }
                else if ( Triangulo[triangulo2].getLadoA() == Triangulo[triangulo2].getLadoB() && Triangulo[triangulo2].getLadoA() > Triangulo[triangulo2].getLadoC()) {
                    trianguloDoisLado[0] = Triangulo[triangulo2].getLadoC();
                    trianguloDoisLado[1] = Triangulo[triangulo2].getLadoB();
                    trianguloDoisLado[2] = Triangulo[triangulo2].getLadoA();
                }
                else if ( Triangulo[triangulo2].getLadoB() == Triangulo[triangulo2].getLadoC() && Triangulo[triangulo2].getLadoB() < Triangulo[triangulo2].getLadoA()) {
                    trianguloDoisLado[0] = Triangulo[triangulo2].getLadoB();
                    trianguloDoisLado[1] = Triangulo[triangulo2].getLadoC();
                    trianguloDoisLado[2] = Triangulo[triangulo2].getLadoA();
                }
                else if ( Triangulo[triangulo2].getLadoA() == Triangulo[triangulo2].getLadoB() && Triangulo[triangulo2].getLadoB() > Triangulo[triangulo2].getLadoA()) {
                    trianguloDoisLado[0] = Triangulo[triangulo2].getLadoA();
                    trianguloDoisLado[1] = Triangulo[triangulo2].getLadoB();
                    trianguloDoisLado[2] = Triangulo[triangulo2].getLadoC();
                }
                else if ( Triangulo[triangulo2].getLadoA() == Triangulo[triangulo2].getLadoC() && Triangulo[triangulo2].getLadoA() < Triangulo[triangulo2].getLadoB()) {
                    trianguloDoisLado[0] = Triangulo[triangulo2].getLadoA();
                    trianguloDoisLado[1] = Triangulo[triangulo2].getLadoC();
                    trianguloDoisLado[2] = Triangulo[triangulo2].getLadoB();
                }
                else if ( Triangulo[triangulo2].getLadoA() == Triangulo[triangulo2].getLadoC() && Triangulo[triangulo2].getLadoA() > Triangulo[triangulo2].getLadoB()) {
                    trianguloDoisLado[0] = Triangulo[triangulo2].getLadoB();
                    trianguloDoisLado[1] = Triangulo[triangulo2].getLadoA();
                    trianguloDoisLado[2] = Triangulo[triangulo2].getLadoC();
                }
            }
            else if ( Triangulo[triangulo2].tipoDoTriangulo() == 3 ){
                if ( Triangulo[triangulo2].getLadoA() > Triangulo[triangulo2].getLadoB() && Triangulo[triangulo2].getLadoA() > Triangulo[triangulo2].getLadoC()) {
                    if ( Triangulo[triangulo2].getLadoB() > Triangulo[triangulo2].getLadoC() ) {
                        trianguloDoisLado[0] = Triangulo[triangulo2].getLadoC();
                        trianguloDoisLado[1] = Triangulo[triangulo2].getLadoB();
                        trianguloDoisLado[2] = Triangulo[triangulo2].getLadoA();
                    }
                    else {
                        trianguloDoisLado[0] = Triangulo[triangulo2].getLadoB();
                        trianguloDoisLado[1] = Triangulo[triangulo2].getLadoC();
                        trianguloDoisLado[2] = Triangulo[triangulo2].getLadoA();
                    }
                }
                if ( Triangulo[triangulo2].getLadoB() > Triangulo[triangulo2].getLadoA() && Triangulo[triangulo2].getLadoB() > Triangulo[triangulo2].getLadoC()) {
                    if ( Triangulo[triangulo2].getLadoA() > Triangulo[triangulo2].getLadoC() ) {
                        trianguloDoisLado[0] = Triangulo[triangulo2].getLadoC();
                        trianguloDoisLado[1] = Triangulo[triangulo2].getLadoA();
                        trianguloDoisLado[2] = Triangulo[triangulo2].getLadoB();
                    }
                    else {
                        trianguloDoisLado[0] = Triangulo[triangulo2].getLadoA();
                        trianguloDoisLado[1] = Triangulo[triangulo2].getLadoC();
                        trianguloDoisLado[2] = Triangulo[triangulo2].getLadoB();
                    }
                }
                if ( Triangulo[triangulo2].getLadoC() > Triangulo[triangulo2].getLadoA() && Triangulo[triangulo2].getLadoC() > Triangulo[triangulo2].getLadoB()) {
                    if ( Triangulo[triangulo2].getLadoA() > Triangulo[triangulo2].getLadoB() ) {
                        trianguloDoisLado[0] = Triangulo[triangulo2].getLadoB();
                        trianguloDoisLado[1] = Triangulo[triangulo2].getLadoA();
                        trianguloDoisLado[2] = Triangulo[triangulo2].getLadoC();
                    }
                    else {
                        trianguloDoisLado[0] = Triangulo[triangulo2].getLadoA();
                        trianguloDoisLado[1] = Triangulo[triangulo2].getLadoB();
                        trianguloDoisLado[2] = Triangulo[triangulo2].getLadoC();
                    }
                }
            }
            if (trianguloUmLado[0] == trianguloDoisLado[0] && trianguloUmLado[1] == trianguloDoisLado[1] && trianguloUmLado[2] == trianguloDoisLado[2]) {
                return true;    
            }
            else {
                return false;
            }
        }
};

int main() {
    figura Triangulo[MAX];
    int Opcao = 0,
        triangulo1 = 0,
        triangulo2 = 0;
    do {
        cout << "\nBem vindo ao Tri�ngulo Maker 2019!\nPor favor escolha uma das op��es abaixo:\n0 - Sair do programa\n1 - Fa�a um tri�ngulo\n2 - Verifique se dois tri�ngulos s�o iguais\n";
        cin >> Opcao;
        if ( Opcao == 0 ) {
            cout << "\nObrigado por usar o Triangulo Maker 2019!\n";
        }
        else if ( Opcao == 1) {
            try {
                if (TAM > 5 ) {
                    throw Erro1();
                }
            }
            catch (Erro1 E) {
                cout << E.what();
                break;
            }
            cout << "\nVamos fazer um tri�ngulo:\n";
        	Triangulo[TAM].lerLados();
        	cout << "\nParab�ns!\nO seu tri�ngulo foi feito, vamos conferir as informa��es do seu tri�ngulo:\n";
        	cout << "N�mero do tri�ngulo: " << TAM + 1 << "\nValor dos lados:\n" << Triangulo[TAM].getLadoA() << ", " << Triangulo[TAM].getLadoB() << ", " << Triangulo[TAM].getLadoC() << "\nPer�metro:\n" << Triangulo[TAM].calcularPerimetro() << endl;
        	cout << "\nTipo de tri�ngulo:\n";
        	if ( Triangulo[TAM].tipoDoTriangulo() == 1 ) {
            	cout << "O tri�ngulo lido � equil�tero\n";
        	}
        	else if ( Triangulo[TAM].tipoDoTriangulo() == 2 ) {
            	cout << "O tri�ngulo lido � is�sceles\n";
           	}
        	else if ( Triangulo[TAM].tipoDoTriangulo() == 3 ) {
            	cout << "O tri�ngulo lido � escaleno\n";
        	}
        	else {
            	cout << "\nDesculpe, mas com os dados inseridos, n�o � poss�vel a exist�ncia de um tri�ngulo";
        	}
        	TAM++;
        }
        else if ( Opcao == 2) {
            bool iguais;
            if ( TAM == 0 ) {
                cout << "\nNenhum tri�ngulo foi registrado no sistema\nVoltando ao menu...";
            }
            else {
                cout << "\nDigite o n�mero dos dois tri�ngulos na qual voc� gostaria de comparar:\n";
                do {
                    cin >> triangulo1;
                    triangulo1--;
                    cin >> triangulo2;
                    triangulo2--;
                    try {
                    if (Triangulo[triangulo1].getLadoA() == 0 || Triangulo[triangulo2].getLadoA() == 0) {
                        throw Erro2();
                        }
                    }
                    catch (Erro2 E) {
                        cout << E.what();
                    }
                } while (Triangulo[triangulo1].getLadoA() == 0 || Triangulo[triangulo2].getLadoA() == 0);
                iguais = Triangulo[TAM].compararTriangulos(Triangulo,triangulo1,triangulo2);
                if ( iguais == true ) {
                    cout << "Os tri�ngulos " << triangulo1 + 1 << " e " << triangulo2 + 1 << "  s�o iguais!" << endl;  
                }
                else {
                    cout << "Os tri�ngulos " << triangulo1 + 1 << " e " << triangulo2 + 1 << "  n�o s�o iguais!" << endl;  
                }
            }
        }
        else {
            cout << "\nOp��o inv�lida!Tente novamente:\n";
        }
    } while ( Opcao != 0 );
    return 0;
}

