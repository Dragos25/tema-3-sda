#include <iostream>

using namespace std;

struct nod
{
    int info;
    nod* next;
};


void afisare_lista(nod *prim)
{
    nod *p=prim;
    while(p!=NULL)
    {
        cout<<p->info<< " ";
        p=p->next;
        }
}

void adaug_final(nod* prim, int val)
{
    nod* nou=new nod;
    nou->info=val;
    nou->next=NULL;
    nod* p=prim;
    while(p->next!=NULL)
        p=p->next;
    p->next=nou;
}

void inversare_legaturi(nod* &prim)     //inversare intr-o singura lista
    {

        int i=0;
        nod *p=prim;
        nod *inv1=prim->next;
        nod *ramas=inv1->next;
        prim->next=NULL;

        while(ramas!=NULL)
        {
            inv1->next=prim;
            prim=inv1;
            inv1=ramas;
            ramas=ramas->next;
        }
        ramas=prim;
        inv1->next=ramas;
        prim=inv1;





    }

void inversare_leg_b(nod*&a, nod*&b)            //inversare in alta lista
{
    if(a->next==NULL){
        b->info=a->info;
        b->next=NULL;
    }
    else
    {
        inversare_leg_b(a->next,b);
        adaug_final(b,a->info);
    }
}

void supl10(nod*&l1, nod*&l2, nod*&l3)
{
    nod*aux1=l1;
    nod*aux2=l2;
    //afisare_lista(l1);
    cout<<endl;
   // afisare_lista(l2);
    if(l1->info<l2->info)
    {
        l3=l1;
        l1=l1->next;
    }
    else
    {
        l3=l2;
        l2=l2->next;
    }
    nod*aux=l3;
    //cout<<endl<<"Adaug: "<<l3->info<<endl;

    while(l1 && l2)
        if(l1->info<l2->info)
        {
            l3->next=l1;
            l1=l1->next;
            l3=l3->next;
            //cout<<"Adaug: "<<l3->info<<endl;
        }
        else
        {
            l3->next=l2;
            l2=l2->next;
            l3=l3->next;
           // cout<<"Adaug: "<<l3->info<<endl;
        }
    while(l1)
    {
        l3->next=l1;
        l3=l3->next;
        l1=l1->next;
       // cout<<"Adaug: "<<l3->info<<endl;
    }
    while(l2)
    {
        l3->next=l2;
        l3=l3->next;
        l2=l2->next;
        //cout<<"Adaug: "<<l3->info<<endl;
    }
    l1=aux1;
    l2=aux2;
    l3=aux;

}

void supl11(nod*&l1, nod*&l2, nod*&L)
{
    int i=0;
    nod*aux=L;
    l1=aux;
    l2=aux->next;
    aux=aux->next->next;
    nod*aux1=l1;
    nod*aux2=l2;
    while(aux!=NULL)
    {
        if(i%2==0)
        {
            l1->next=aux;
            l1=l1->next;
            i++;
            aux=aux->next;
        }
        else
        {
            l2->next=aux;
            l2=l2->next;
            i++;
            aux=aux->next;
        }
    }
    l1->next=NULL;
    l2->next=NULL;
    l1=aux1;
    l2=aux2;

}

int main()
{
    nod* lista=new nod;
    lista->info=3;
    lista->next=NULL;
    adaug_final(lista,4);
    adaug_final(lista,5);
    adaug_final(lista,6);
    adaug_final(lista,7);
    afisare_lista(lista);
    inversare_legaturi(lista);
    cout<<endl;
    afisare_lista(lista);

    nod *lista2=new nod;
    lista2->info=10;
    lista2->next=NULL;
    adaug_final(lista2,11);
    adaug_final(lista2,12);
    adaug_final(lista2,13);
    adaug_final(lista2,14);
    cout<<endl<<endl;
    nod *lista3=new nod;
    afisare_lista(lista2);
    inversare_leg_b(lista2,lista3);
    cout<<endl;
    afisare_lista(lista3);

    nod* lista_10_A=new nod;
    nod* lista_10_B=new nod;
    lista_10_A->info=8;
    lista_10_A->next=NULL;
    adaug_final(lista_10_A,10);
    adaug_final(lista_10_A,12);
    adaug_final(lista_10_A,14);
    lista_10_B->info=9;
    lista_10_B->next=NULL;
    adaug_final(lista_10_B,11);
    adaug_final(lista_10_B,13);
    adaug_final(lista_10_B,15);
    cout<<endl<<"SUPLIMENTARA 10"<<endl<<"LISTE:"<<endl;
    afisare_lista(lista_10_A);
    cout<<endl;
    afisare_lista(lista_10_B);
    cout<<endl;
    nod* listaconc=new nod;
    supl10(lista_10_A,lista_10_B,listaconc);
    cout<<endl;
    cout<<"Lista finala: ";
    afisare_lista(listaconc);

    cout<<endl<<"SUPLIMENTARA 11"<<endl;
    nod* lista_11=new nod;
    lista_11->info=1;
    lista_11->next=NULL;
    adaug_final(lista_11,2);
    adaug_final(lista_11,3);
    adaug_final(lista_11,4);
    adaug_final(lista_11,5);
    adaug_final(lista_11,6);
    adaug_final(lista_11,7);
    adaug_final(lista_11,8);

    afisare_lista(lista_11);
    nod* lista_11_A= new nod;
    nod* lista_11_B= new nod;
    supl11(lista_11_A,lista_11_B,lista_11);
    cout<<endl<<"Lista impara: ";;
    afisare_lista(lista_11_A);
    cout<<endl<<"Lista para: ";
    afisare_lista(lista_11_B);



    return 0;
}
