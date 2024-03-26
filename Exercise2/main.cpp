#include <iostream>
#include "Eigen/Eigen"
#include <iomanip>

using namespace std;
using namespace Eigen;


Vector2d qrsolve(const Matrix2d A, const Vector2d b) // la funzione calcola la soluzione del sistema con il metodo qr
{
    Vector2d x = A.colPivHouseholderQr().solve(b);
    return x;
}


Vector2d lusolve(const Matrix2d A, const Vector2d b)  // la funzione calcola la soluzione del sistema per il metodo PA = LU con full pivoting
{
    Vector2d x;
    x << A.fullPivLu().solve(b);  // usa il pivoting per colonne (più lento ma più preciso, ok per matrici di dimensioni piccole)
    return x;
}


double relerr(const Vector2d xstar, const Vector2d x)  // calcola l'errore relativo per ciascun sistema
{
    double err = (x-xstar).norm()/xstar.norm();
    return err;
}

void print(double relerr_xqr, double relerr_xlu, int system_number)  // la funzione ci dice quale dei due sistemi è più preciso
{
    if (relerr_xqr > relerr_xlu)
    {
        cout << "La fattorizzazione PA = LU è più precisa per il " << system_number << "° sistema." << endl;
    }

    else {
        cout << "La fattorizzazione QR è più precisa per il " << system_number << "° sistema." << endl;
    }
}

int main()
{
    Vector2d x; // definisco il vettore soluzione
    x << -1.0e+0, -1.0e+00;


    Matrix2d A1;
    A1 << 5.547001962252291e-01, -3.770900990025203e-02, 8.320502943378437e-01,
        -9.992887623566787e-01;

    Vector2d b1;
    b1 << -5.169911863249772e-01, 1.672384680188350e-01;

    Vector2d x1qr = qrsolve(A1, b1);
    cout << "L'errore relativo per il primo sistema applicando la fattorizzazione QR è: " << scientific << setprecision(16) << relerr(x,x1qr) << endl;

    Vector2d x1lu = lusolve(A1, b1);
    cout << "L'errore relativo per il primo sistema applicando la fattorizzazione PA = LU è: " << scientific << setprecision(16) << relerr(x,x1lu) << endl;

    print(relerr(x,x1qr), relerr(x,x1lu), 1);



    Matrix2d A2;
    A2 << 5.547001962252291e-01, -5.540607316466765e-01, 8.320502943378437e-01,
        -8.324762492991313e-01;

    Vector2d b2;
    b2 << -6.394645785530173e-04, 4.259549612877223e-04;

    Vector2d x2qr = qrsolve(A2, b2);
    cout << " \nL'errore relativo per il secondo sistema applicando la fattorizzazione QR è: " << scientific << setprecision(16) << relerr(x,x2qr) << endl;

    Vector2d x2lu = lusolve(A2, b2);
    cout << "L'errore relativo per il secondo sistema applicando la fattorizzazione PA = LU è: " << scientific << setprecision(16) << relerr(x,x2lu) << endl;

    print(relerr(x,x2qr), relerr(x,x2lu), 2);


    Matrix2d A3;
    A3 << 5.547001962252291e-01, -5.547001955851905e-01, 8.320502943378437e-01,
        -8.320502947645361e-01;

    Vector2d b3;
    b3 << -6.400391328043042e-10, 4.266924591433963e-10;

    Vector2d x3qr = qrsolve(A3, b3);
    cout << "\nL'errore relativo per il terzo sistema applicando la fattorizzazione QR è: " << scientific << setprecision(16) << relerr(x,x3qr) << endl;

    Vector2d x3lu = lusolve(A3, b3);
    cout << "L'errore relativo per il terzo sistema applicando la fattorizzazione PA = LU è: " << scientific << setprecision(16) << relerr(x,x3lu) << endl;

    print(relerr(x,x3qr), relerr(x,x3lu), 3);


  return 0;
}
