#include <iostream>
#include <fstream>

using namespace std;

struct nod
{
    int info;
    nod* next;
};

struct coada
{
    nod* prim;
    nod* ultim;
};



void push(int a, coada* &c)
{
    if(c==NULL)
    {
        c=new coada;
        nod *nou=new nod;
        nou->info=a;
        nou->next=NULL;
        c->prim=nou;
        c->ultim=nou;
    }
    else
    {
        nod *nou=new nod;
        nou->info=a;
        nou->next=c->ultim;
        c->ultim=nou;
    }
}

int pop(coada* &c)
{
    if(c==NULL) return -1;
    if(c->prim==c->ultim)
    {
        int val=c->prim->info;
        delete c->prim;
        delete c->ultim;
        c=NULL;
        return val;
    }
    int val=c->prim->info;
    nod *temp=c->ultim;
    while(temp->next!=c->prim)
        temp=temp->next;
    c->prim=temp;
    c->prim->next=NULL;
    return val;
}

int peek(coada * &c)
{
    return c->prim->info;
}

bool empty(coada * &c)
{
    if(c==NULL)
        return true;
    else return false;
}

void af_nod(nod* p)
{
    if(p==NULL) return;
    af_nod(p->next);
    cout<<p->info<<" ";
}

void afiseaza(coada* &c)
{
    af_nod(c->ultim);
}

int search(int a, coada * &c)
{
    nod* nou=c->ultim;
    int i=-1,nr=0;
    while(nou!=NULL)
    {
        if(nou->info==a) i=nr;
        nr++;
        nou=nou->next;
    }
    if(i==-1) return i;
    else return nr-i-1;
}



void supl8()
{
    ifstream f("vagoane.in");
    ofstream g("vagoane.out");
    int k, n;
    f>>n>>k;
    coada *c=new coada;
    coada *fin=new coada;
    fin=NULL;
    c=NULL;
    coada **sir=new coada*[10];
    int val;
    for(int i=0;i<=k;i++)
        {sir[i]=new coada; sir[i]=NULL;}
    while(f>>val)
        push(val,c);
    int max=n;
    int i;

    while(!empty(c))
    {
        if(peek(c)==max) {push(max,fin); max--; pop(c);}
        else{
        for(i=0;i<k-1;i++)
            if(empty(sir[i]) || peek(c)<peek(sir[i])) {push(peek(c),sir[i]); pop(c); break;}
        if(i==k-1)
        {
            g<<"Nu are solutie"; return;
        }
        }
        for(i=0;i<k-1;i++)
            if(!empty(sir[i]) && peek(sir[i])==max)
        {
            push(max,fin);
            max--;
            afiseaza(sir[i]);cout<<endl;
            pop(sir[i]);

        }



    }
    //afiseaza(fin);


}

int main()
{
    /*
    coada *c=NULL;
    c=NULL;
    push(3,c);
    push(4,c);
    push(5,c);
    afiseaza(c);cout<<endl;
    pop(c);
    afiseaza(c);
    pop(c);
    afiseaza(c);*/
    supl8();
}

