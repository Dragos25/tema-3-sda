#include <iostream>
#include <fstream>
#include <string.h>




using namespace std;

ifstream f("intrare");
ofstream g("iesire");

struct stiva
{
    stiva()
    {
        info=NULL;
        next=NULL;
    }
    int info;
    stiva* next;
};

void push(int a, stiva*&s)
{

    stiva* nou=new stiva;
    nou->info=a;
    nou->next=s;
    s=nou;

}

int pop(stiva *&s)
{
    int a=s->info;
    stiva* temp=s;
    s=s->next;
    delete temp;
    return a;
}

int peek(stiva *&s)
{
    return s->info;
}

bool empty(stiva *&s)
{
    if(s==NULL) return true;
    return false;
}

int search(int a, stiva*&s, int i=0)
{
    if(s==NULL) return -1;
    if(s->info==a) return i;
    return search(a,s->next,i+1);
}
void afiseaza(stiva *&s)
{
    if(s!=NULL)
    {
        g<<peek(s)<<endl;
        afiseaza(s->next);
    }
}

void prob_supl2()
{
    stiva *s=new stiva;
    g<<"stiva din prob sup2"<<endl;
    char sir[100];
    pop(s);
    cout<<"SIR PROB2: ";
    cin.get(sir,100);
    for(int i=0;i<strlen(sir);i++)
    {
        if(empty(s)) push((int)sir[i],s);
        else
        {
        if(sir[i]=='a')
            if(peek(s)=='b') pop(s);
            else push((int)'a',s);
        else
            if(peek(s)=='a') pop(s);
            else push((int)'b',s);
        }
    }
    if(empty(s)) cout<<"Numarul de a este egal cu numarul de b";
    else cout<<"Numarul de a este diferit de numarul de b";

}

void prob_supl3()
{
    stiva *s=new stiva;
    pop(s);
    char sir[100];
    cout<<"Sirul de paranteze: ";
    cin.get(sir,100);
    int i;
    for(i=0;i<strlen(sir);i++)
    {
        if(empty(s))
            if(sir[i]==')')
        {
            cout<<"Sirul de paranteze nu este bun! Pozitia="<<i; return;
        }
            else push(sir[i],s);
        else
        {
            if(sir[i]==')' && peek(s)=='(') pop(s);
            else if(sir[i]=='(' && peek(s)==')') pop(s);
        }


    }

    if(empty(s)) cout<<"sirul de paranteze este bun";


}

void prob_supl4()
{
    stiva *s= new stiva;
    pop(s);
    int n; int pereche[100];
    cout<<"Nr de pini ";
    cin>>n;
    cout<<"Pinii: "<<endl;
    for(int i=0;i<n;i++)
        cin>>pereche[i];
    for(int i=0;i<n;i++)
    {
        if(empty(s)) push(pereche[i],s);
        else
            if(pereche[i]==peek(s)) pop(s);
            else push(pereche[i],s);
    }
    if(empty(s)) cout<<"Configuratia este buna";
    else cout<<"Configuratia nu este buna";
}



int main()
{
    /*stiva *s=new stiva;
    int a;
    f>>a;
    s->info=a;
    s->next=NULL;

    cout<<search(10,s);
    delete s;*/
    stiva *s = new stiva;
    pop(s);
    int a;
    while(f>>a)
        push(a,s);
    afiseaza(s);
    //prob_supl2();
    //prob_supl3();
    prob_supl4();
    return 0;
}
