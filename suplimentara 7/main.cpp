#include <iostream>
#include <fstream>


using namespace std;

int a[10][10];
ifstream f("matrice.in");
ofstream g("matrice.out");

int mut_valid(int m, int i, int j)          ///conditia de valid este ca pozitia sa nu
{                                           ///iasa din vector si elementul sa nu se gaseasca
    if(i<0) return 0;                       ///in alta componenta
    if(i>=m) return 0;
    if(j<0) return 0;
    if(j>=m) return 0;
    if(a[i][j]!=1) return 0;
    return 1;
}

int rec(int m, int i, int j, int cont)
{
    a[i][j]=cont;                               ///merg recursiv maxim in fieare directie
    if(mut_valid(m,i+1,j))                      ///ca sa construiesc componenta
        rec(m,i+1,j,cont);
    if(mut_valid(m,i-1,j))
        rec(m,i-1,j,cont);
    if(mut_valid(m,i,j+1))
        rec(m,i,j+1,cont);
    if(mut_valid(m,i,j-1))
        rec(m,i,j-1,cont);
}

int main()
{
    int m;
    f>>m;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
            f>>a[i][j];
    int ok=0;
    int contor=2;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
    {
            if(a[i][j]==1)
            {
                rec(m,i,j,contor); contor++;
            }
    }



    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++)
            g<<a[i][j]<< " ";
        g<<endl;}
    return 0;
}
