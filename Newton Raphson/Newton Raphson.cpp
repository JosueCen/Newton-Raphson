#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

//  Definir la función de trabajo en términos de xi
//  Ejemplo: Cos(x)-x^2     ->>      f = cos(xi) - pow(xi, 2);

float evaluacion(float xi)
{
    float f;
    double e = 2.718281828;
    f = pow(xi, 3) - (pow(e, xi) * sin(xi));   // <<- Mover aquí

    return f;
}

//  Definir la derivada de la función de trabajo en términos de xi
//  Ejemplo: Cos(x)-x^2     ->>      Fx = -sen(xi) - (2 * xi);

float derivada(float xi)
{
    float Fx;
    double e = 2.718281828;
    Fx = (3 * pow(xi, 2)) - (pow(e, xi) * cos(xi)) - (pow(e, xi) * sin(xi));    //  <<- Mover aquí

    return Fx;
}

float siguiente(float xi, float a, float b)
{
    float g;
    g = xi - ((a) / (b));

    return g;
}

// Cambiar la precisión a un decimal más de los que tenga épsilon
// Ejemplo: Si épsilon = 0.0001     ->>     cout << fixed << setprecision(5) << x;

void redondeo(float x)
{
    cout << fixed << setprecision(5) << x;  //  <<- Mover aquí
}

int main()
{
    float xi = 0, eps = 0, dif = 0, a = 0, b = 0, c = 0;
    int cont = 1;

    cout << "Newton-Raphson\n\n";

    cout << "Ingrese xi: ";
    cin >> xi;
    cout << "Ingrese epsilon: ";
    cin >> eps;
    cout << "\n\n";

    do {
        a = evaluacion(xi);
        b = derivada(xi);
        c = siguiente(xi, a, b);
        dif = abs(c - xi);

        cout << "i= " << cont;
        cout << "    xi= " << xi;
        cout << "    f(xi)= ";
        redondeo(a);
        cout << "    f'(x)= ";
        redondeo(b);
        cout << "    xi+1= ";
        redondeo(c);
        cout << "    |xi+1-xi|= ";
        redondeo(dif);
        cout << "\n\n";

        xi = c;
        cont++;

    } while (dif >= eps);

    cout << "\nLa raiz es x = " << xi;

    cin.get();
    cin.get();
    return 0;
}