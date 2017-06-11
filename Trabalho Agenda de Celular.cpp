#include <iostream>
#include <ostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
using namespace std;

struct Telefone{
       string telcasa,telelfax,telecom,telemovel;
       };
struct Agenda{
       string nome;
       string email;
       string aniversario;
       Telefone fone;
       Agenda *prox;};
       
       Agenda *prim, *ulti, *aux; //Criaçao dos ponteiros
     
     void criar_lista(){     //Criaçao da Funçao Opçao 1
                                   if(ulti==NULL){
                                                  prim=new(Agenda);
                                                  ulti=prim;
                                                  }
                                                  else{
                                                       ulti->prox=new(Agenda);
                                                       ulti=ulti->prox;
                                                       }
     ulti->prox=NULL;
            cout<<"Digite o Nome: ";
            cin>>ulti->nome;
            cout<<"E-mail :";
            cin>>ulti->email;
            cout<<"Data de Nascimento :";
            cin>>ulti->aniversario;
            cout<<"Telefone Residencial :";
            cin>>ulti->fone.telcasa;
            cout<<"Telefone Movel: ";
            cin>>ulti->fone.telemovel;
            cout<<"Telefone Comercial: ";
            cin>>ulti->fone.telecom;
            cout<<"Telefone Fax :";
            cin>>ulti->fone.telelfax;
            system("cls");
            cout<<"\n\n\n\n\n\tSeu contato foi inserido com sucesso!\n"<<flush;
            getch();
}
void insere_depois(Agenda *ant){//Criaçao da Funçao Opçao 2
     string n;
     cout<<"Digite o Nome Escolhido: ";
     cin>>n;
     if(prim==NULL){
                     cout<<"Sua Agenda Esta Vazia!"<<endl;
                     getch();
     }
     else{
          while(ant!=NULL){
                      if(ant->nome==n){
                                    Agenda* n=new(Agenda);
                                              cout<<"Digite o Nome: ";
                                              cin>>n->nome;
                                              cout<<"E-mail :";
                                              cin>>n->email;
                                              cout<<"Data de Nascimento :";
                                              cin>>n->aniversario;
                                              cout<<"Telefone Residencial :";
                                              cin>>n->fone.telcasa;
                                              cout<<"Telefone Movel: ";
                                              cin>>n->fone.telemovel;
                                              cout<<"Telefone Comercial: ";
                                              cin>>n->fone.telecom;
                                              cout<<"Telefone Fax :";
                                              cin>>n->fone.telelfax;
                                                                    system("cls");            
                                              cout<<"\n\n\n\n\n\tSeu contato foi inserido com sucesso!\n"<<flush;
                                    getch();
                                                                    n->prox=ant->prox;
                                                                    ant->prox=n;
                                                                    return;             
                      }
                      ant=ant->prox;
     }
      if(ant==NULL){
                    cout<<"Contato Nao Encontrado!"<<endl;
                    getch();
      }
      }
}
int perc(){ //Contador que percorre a Funçao 3
    int perc=0;
    Agenda *aux=prim;
    while(aux!=NULL){
                     perc++;
                     aux=aux->prox;
    }
     return perc;
}

void insere_elemento(Agenda *ant){ //Criaçao da Funçao Opçao 3
     Agenda *novo=new(Agenda);
            cout<<"Digite o Nome: ";
            cin>>novo->nome;
            cout<<"E-mail :";
            cin>>novo->email;
            cout<<"Data de Nascimento :";
            cin>>novo->aniversario;
            cout<<"Telefone Residencial :";
            cin>>novo->fone.telcasa;
            cout<<"Telefone Movel: ";
            cin>>novo->fone.telemovel;
            cout<<"Telefone Comercial: ";
            cin>>novo->fone.telecom;
            cout<<"Telefone Fax :";
            cin>>novo->fone.telelfax;
                                     system("cls");
            cout<<"\n\n\n\n\n\tSeu contato foi inserido com sucesso!\n"<<flush;
     getch();
                          if(ant==NULL){
                                         novo->prox=prim; 
                                         prim=novo;
                          }
                          else {
                               novo->prox=ant->prox;
                               ant->prox=novo;
                          }
}

void busca_contatos(Agenda *aux){ //Criaçao da Funçao Opçao 4
     string nome;
     cout<<"Pesquisar Um Contato: ";
     cin>>nome;
     system("cls");
     if(aux==NULL){cout<<"===========Buscar Contato==========="<<endl;
                   cout<<"= Contato Nao Encontrado!          ="<<endl;
                   cout<<"===================================="<<endl;
                   getch();
                   return;
                                 }
     while(aux!=NULL){
                      if(aux->nome==nome){
                                   cout<<"===========Buscar Contato==========="<<endl;
                                   cout<<"Nome: "<<aux->nome<<endl;
                                   cout<<"E-mail: "<<aux->email<<endl;
                                   cout<<"Data de Nascimento: "<<aux->aniversario<<endl;
                                   cout<<"Telefone Residencial: "<<aux->fone.telcasa<<endl;
                                   cout<<"Telefone Movel: "<<aux->fone.telemovel<<endl;
                                   cout<<"Telefone Comercial: "<<aux->fone.telecom<<endl;
                                   cout<<"Telefone Fax: "<<aux->fone.telelfax<<endl;
                                   cout<<"====================================\n"<<flush;
                                   getch();
                                   return;
                      }
                      else{
                                  aux=aux->prox;
                      }
     }
     if(aux==NULL){cout<<"Elemento nao encontrado"<<endl;
     getch();
     }
}
void remove_primeiro(Agenda *aux){//Criaçao Funçao Opçao 5
     if(prim==NULL){
     cout<<"= Agenda Sem Contatos Listados!            ="<<endl;
     cout<<"============================================"<<endl;
     getch();
     return;
     }
      else{ 
            Agenda *aux2=prim;
            prim=prim->prox;
            ulti=prim;
            delete(aux2);
            cout<<"O Primeiro Contato Foi Removido Com Sucesso!"<<endl;
            cout<<"============================================"<<endl;
            getch();
      }
}

Agenda* verificaanterior(){//Criaçao da Auxiliar da Funçao 7
        Agenda *aux=prim;
        Agenda *ant=NULL;
        string procura;
        cout<<"Digite o nome a ser excluido: ";
        cin>>procura;
        system("cls");
        while(aux!=NULL){
                         if( (procura==aux->nome) ){
                             return ant;
                             }
        ant=aux;
        aux=aux->prox;
        }
        return ant;
}
void remove_elemento(Agenda *ant){//Criaçao da Funçao Opçao 7
     Agenda *aux;
     if(ant==ulti){
                   cout<<"==========Remover Elemento Desejado========="<<endl;
                   cout<<"Contato Nao Encontrado!"<<endl;
                   cout<<"============================================"<<endl;
                   getch();
                   system("cls");
                   return;
     }
     if(ant!=NULL){
                   aux=ant->prox;
                   ant->prox=aux->prox;
                                       if(aux->prox==NULL){
                                       ulti=ant;
                                       }
     }
                        else{
                        if (prim==NULL){
                                        cout<<"==========Remover Elemento Desejado========="<<endl;
                                        cout<<"= Agenda Sem Contatos Listados!            ="<<endl;
                                        cout<<"============================================\n"<<flush;
                                        getch();
                                        return;
                        }
                        aux=prim;
                        prim=prim->prox;
                        ulti=prim;
                   
                   }
                   delete(aux);
                   system("cls");
                   cout<<"\n\n\n\n\n\tContato Removido com Sucesso!\n"<<flush;
                   getch();
     }
void ultimo_elemento(Agenda *aux){//Criaçao da Funçao Opçao 8
     if(aux==NULL){
                   cout<<"= Agenda Sem Contatos Listados!          ="<<endl;
                   cout<<"=========================================="<<endl;
                   getch();
                   return;
     }
                   while(aux!=ulti){
                                    aux=aux->prox;
                   }                
                                    cout<<"Nome: "<<aux->nome<<endl;
                                    cout<<"E-mail: "<<aux->email<<endl;
                                    cout<<"Data de Nascimento: "<<aux->aniversario<<endl;
                                    cout<<"Telefone Residencial: "<<aux->fone.telcasa<<endl;
                                    cout<<"Telefone Movel: "<<aux->fone.telemovel<<endl;
                                    cout<<"Telefone Comercial: "<<aux->fone.telecom<<endl;
                                    cout<<"Telefone Fax: "<<aux->fone.telelfax<<endl;
                                    cout<<"====================================\n"<<flush;
                                    getch();
}
void numero_de_contatos(Agenda *prim){//Criaçao da Funçao Opçao 9
     if(prim==NULL){
                    cout<<"= Sua Agenda Possui 0 Contatos!            ="<<endl;
                    cout<<"============================================"<<endl;
                    getch();
     }
                    else{
                         int elem=0;
                             while(prim!=NULL){
                                               elem++;
                                               prim=prim->prox;
                             }
                             if(elem==1){cout<<"\nSua Agenda Possui "<<elem<<" Contato!"<<endl;
                             cout<<"\n============================================"<<endl;
                             getch();
                             }
                             else if(elem>=2){cout<<"\nSua Agenda Possui "<<elem<<" Contatos!"<<endl;
                             cout<<"\n============================================"<<flush;
                             getch();
                             }
                    }
}
void print_contatos(Agenda *aux){ //Criaçao da Funçao Opçao 10
     if(aux==NULL){
                   cout<<"= Agenda Sem Contatos Listados! ="<<endl;
                   cout<<"================================="<<endl;
                   getch();
                   return;
     }              
                     while(aux!=NULL){
                                   cout<<"Nome: "<<aux->nome<<endl;
                                   cout<<"E-mail: "<<aux->email<<endl;
                                   cout<<"Data de Nascimento: "<<aux->aniversario<<endl;
                                   cout<<"Telefone Residencial: "<<aux->fone.telcasa<<endl;
                                   cout<<"Telefone Movel: "<<aux->fone.telemovel<<endl;
                                   cout<<"Telefone Comercial: "<<aux->fone.telecom<<endl;
                                   cout<<"Telefone Fax: "<<aux->fone.telelfax<<endl;
                                   cout<<"=================================="<<flush;
                                   aux=aux->prox;
                                   }
                     getch();
}
int main(){
    int a;
    string usuario;
             cout<<"Para Comecar Digite seu Nome: ";
             cin>>usuario;
    while(1){
             system("cls");
             cout<<"======================Agenda do "<<usuario<<"======================="<<endl;
             cout<<"(01) Criar Novo Contato"<<endl;
             cout<<"(02) Criar Novo Contato Apos Contato Desejado"<<endl;
             cout<<"(03) Criar Novo Contato em Posicao Desejada"<<endl;
             cout<<"(04) Buscar Contatos"<<endl;
             cout<<"(05) Excluir Primeiro Contato"<<endl;
             cout<<"(06) Excluir Contato Na Posicao Desejada"<<endl;
             cout<<"(07) Excluir Contato Desejado"<<endl;
             cout<<"(08) Exibir Ultimo Contato Listado"<<endl;
             cout<<"(09) Exibir o Numero De Contatos Listados"<<endl;
             cout<<"(10) Exibir Todos Os Contatos Listados"<<endl; 
             cout<<"\n(0) Sair Da Agenda"<<endl;
             cout<<"========================================================="<<flush;
             cin>>a;
             system("cls");
             if(a==1){//Opçao 1
                      cout<<"========= Novo Cadastro ========= \n"<<endl;
                                     criar_lista();
                                     system("cls");
             }
             else if(a==2){//Opçao 2
                      cout<<"=====Novo Elemento Apos Determinado Por Valor====="<<endl;
                      insere_depois(prim);
                      system("cls");
                     }
             else if(a==3){//Opçao 3
                  int pos, c=1, b=perc();
                  cout<<"==========Novo Contato em Posicao Desejada=========="<<endl;
                  cout<<"Digite o Local Desejado: ";
                  cin>>pos;
                  Agenda *aux=prim;
                         if(pos==1){
                                   insere_elemento(NULL);
                         }
                         else if(pos<=b){
                              while(c<pos-1){
                                            aux=aux->prox;
                                            c++;
                              }
                         insere_elemento(aux);
                         }
                         else if(pos>b){
                                        criar_lista();
                         }                                    
             }
             else if(a==4){//Opçao 4
                     cout<<"===========Buscar Contato==========="<<endl;
                     busca_contatos(prim);
                     system("cls");
                     }
             else if(a==5){//Opçao 5
                     cout<<"==============Remove o Primeiro============="<<endl;
                     remove_primeiro(prim);
                     system("cls");
                     }
             else if(a==6){//Opçao 6
                  cout<<"==========Remover Contato em Posicao Desejada=========="<<endl;
                  Agenda *aux=prim;
                  int pos, cont=1;
                  cout<<"Digite a Posicao Que Deseja Ser Removida: "<<flush;
                  cin>>pos;
                  system("cls");
                           if(pos==1){
                                      remove_elemento(NULL);
                           }
                            else if (pos<=perc()){
                                 while(cont<pos-1){
                                                   aux=aux->prox;
                                                   cont++;
                                 }
                                 remove_elemento(aux);
                            }
                            else if(pos>perc()){
                                 cout<<"==========Remover Contato em Posicao Desejada=========="<<endl;
                                 cout<<"= Contato Nao Existe!                                 ="<<endl;
                                 cout<<"======================================================="<<flush;
                                 getch();
                            }
                  system("cls");
             }
             else if(a==7){//Opçao 7
                     cout<<"==========Remover Elemento Desejado========="<<endl;
                     remove_elemento(verificaanterior());
                     system("cls");
                     }
             else if(a==8){//Opçao 8
                     cout<<"=========Ultimo Contato da Agenda========="<<endl;
                     ultimo_elemento(prim);
                     system("cls");
                     }
             else if(a==9){//Opçao 9
                     cout<<"=============Numero de Contatos============="<<endl;
                     numero_de_contatos(prim);
                     system("cls");
                     }
            else if(a==10){//Opçao 10
                     cout<<"========Todos os Contatos========"<<endl;
                     print_contatos(prim);
                     system("cls");
            }
            else if(a==0){//Opçao 11
                     break;
            }         
    }            
}
