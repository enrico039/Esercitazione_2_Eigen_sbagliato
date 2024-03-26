#include <iostream>  // parentesi angolari: la libreria la trovi nel sistema
// #include "Eigen/Eigen" // "": la libreria l'ho inserita localmente, non è errore usare <>, i doppi apici sono solo un suggerimento per dire di cercare vicino

using namespace std;
// using namespace Eigen;

int foo(int c)
{
    c++;
    return c;
}

int main()
{
    int a = 0;
    int c = a;  //  copy

    a++;  // modificare a non significa modificare c

    cout <<"c: " << c << endl;

    const int i = 1;  // è obbligatorio inizializzarla, const è costante

    int &ref = a;  // a è una variabile a cui posso accedere sia con a che con ref

    // NOTA: creare un alias non crea una vera e propria copia, non è un oggetto nuovo e quindi non spreca memoria

    a++;

    cout << "ref: " << ref << endl;

    double d = 5.5;
    // int &reff = d;
    int ii = d;

    // se l'oggetto è const, allora anche la referenza deve essere const
    // al contrario, se l'oggetto di partenza è modificabile, la referenza può comunque essere const

    int temp = d;
    const int &reff = temp;  // prende un double, lo inserisce in una variabile temporanea temp, la referenza diventà un alias per quell'oggetto temporaneo che vale 5

    d+=2;

    cout << "ii: " << ii << endl;
    cout << "reff: " << reff << endl;


    int aa = 0;
    int jj = 0;
    int b = foo(jj);

    // Step 1: int c = jj;
    // Step 2: eseguire il corpo {}
    // Step 3: return -> int b = valueReturn
    // la keyword return restituisce il controllo al main


    // creiamo un vettore
    // // srand(5);
    // Vector4d v = Vector4d::Constant(4.0); // 4 specifica la dimensione, d è il tipo (d sta per double)
    // RowVector4d w = Vector3d::Constant(7.0);
    // cout << v << endl;
    // cout << w* w.transpose() <<endl;
    // cout << w.cwiseProduct(w) <<endl;
    // cout << w.cwiseAbs() << endl;

    // MatrixXd A = MatrixXd::Zero(3,4);
    // MatrixXd B = MatrixXd::Ones(3,4);
    // cout << A << endl;
    return 0;
}
