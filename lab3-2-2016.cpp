#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <conio.h>
#include <windows.h>

using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void LimpaTela()
{
    #ifdef _WIN32
    system("cls");
    #endif
    #ifdef __linux__
    system("clear");
    #endif
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef class Aluno
{
    protected:
    string name, addres, tel;
    int reg;
    float height, weight;

    public:
    Aluno *act, *next, *prev;
    Aluno()
        {
        act=next=prev=NULL;
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Setters
    void SetName(string text){name=text;}
    void SetHeight(float num){height=num;}
    void SetAddres(string text1){addres=text1;}
    void SetReg(int num1){reg=num1;}
    void SetTelephone(string text2)
        {
        if(text2[0]!='(' && text2[3]!=')' && text2[8]!='-'){tel=text2;}
        else{tel="error";}
        }
    void SetWeight(float num3){weight=num3;}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Getters
    string GetName()
            {
                return name;
            }
    float GetHeight()
            {
                return height;
            }
    string GetAddres()
            {
                return addres;
            }
    int GetReg()
            {
                return reg;
            }
    string GetTelephone()
            {
                return tel;
            }
    int GetWeight()
            {
                return weight;
            }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void Apresentation()
            {
                LimpaTela();
                cout<<"Name:           "<<name<<endl
                    <<"Height:         "<<height<<endl
                    <<"Telephone:      "<<tel<<endl
                    <<"Address:        "<<addres<<endl
                    <<"Weight:         "<<weight<<endl
                    <<"Registration:   "<<reg;
            }
    void AddNext()
            {

                string name1, addres1, tel1;
                int reg1;
                float height1, weight1;
                next=(Aluno*)malloc(sizeof(Aluno));
                if(next==NULL){"Falha ao alocar memoria. Abortando.\n"; system("pause"); exit(0);}
                else
                    {
                        act=act->next;
                        cout<<"Enter your registration number, height, weight, name, address and telephone number in format "<<endl
                            <<"(XX)XXXX-XXXX:";
                        cin>>reg1>>height1>>weight1;
                        cin.ignore();
                        getline(cin, name1);
                        cin.ignore();
                        getline(cin, addres1);
                        cin.ignore();
                        getline(cin, tel1);
                        act->SetReg(reg1);
                        act->SetHeight(height1);
                        act->SetWeight(weight1);
                        act->SetName(name1);
                        act->SetAddres(addres1);
///////////////////////////////////////////////////////////////
                        while(act->tel=="error")
                            {
                                LimpaTela();
                                cout<<"Numero de telefone invalido. Insira um numero valido no formato (XX)XXXX-XXXX:"<<endl;
                                act->SetTelephone(tel1);
                                LimpaTela();
                            }
                    }
            }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool IsEmpty(Aluno Turma)
        {
            return (Turma.prev)==(Turma.act)==(Turma.next);
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void menu(Aluno *turma0)
{

    char op;
    cout<<"1-Cadastrar um aluno na turma"<<endl
        <<"2-Pesquisar aluno por matricula"<<endl
        <<"3-Mostrar a turma toda"<<endl
        <<"4-Sair";
    op=getch();
    while(op!='4')
    {
        if(op=='1')
            {
                turma0->AddNext();
            }
        if(op=='2')
            {
                while(turma0->prev!=NULL)
                    {
                        turma0=turma0->prev;
                    }
                int MatrPesq;
                cout<<"Insira a matricula do aluno desejado: ";
                cin>>MatrPesq;
                if(turma0->act->reg!=MatrPesq && turma0->act->next==NULL)
                {
                    cout<<"Aluno nao cadastrado"; return;
                }
                else
                    {
                        if(turma0->act->reg==MatrPesq)
                            {
                                LimpaTela();
                                turma0->act->Apresentation();
                            }
                        else{turma0->act=turma0->act->next;}
                    }
            }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BurnInDB(Aluno turma1, FILE *db1)
    {
        if(!turma1.IsEmpty())
        {
            while(turma1.act->prev!=NULL){turma1.act=turma1.act->prev;}
            db1=fopen("database.txt","w+");
            if(db==NULL){cout<<"Erro ao criar banco de dados"; return;}
            else
            {
                while(turma1.act->next!=NULL)
                {
                fprintf(db1, "%s\t%s\t%s\t%i\t%f\t%f\n", turma1.act->name, turma1.act->address, turma1.act->tel, turma1.act->reg, turma.act->height, turma1.act->weight);
                turma1.act=turma1.act->next;
                }
            }
            fclose(db);
        }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ReadFromDB(Aluno turma2, FILE *db2)
    {
        db2=fopen("database.txt","w+");
        if(db==NULL){cout<<"Erro ao criar banco de dados"; return;}
        else
        {
            if(turma2.IsEmpty())
            {
                while(!feof(db2))
                {
                turma2.act=&turma2;
                else
                    {
                        fscanf(db2, "%s\t%s\t%s\t%i\t%f\t%f\n", turma1.act->next->name, turma1.act->address, turma1.act->tel, turma1.act->reg, turma.act->height, turma1.act->weight);
                        turma2->next=(*Aluno)malloc(sizeof(Aluno));
                        if(turma2.next==NULL){cout<<"Erro ao alocar proximo elemento"; return;}
                        else
                        {
                            turma2.next->prev=turma2;
                            turma2.act=turma2.act->next;
                        }
                    }

                }
            }
        }
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(void)
{

}
