#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <string>
#include <unistd.h>

using namespace std;

void LimpaTela()
{
    #ifdef _Win32
    system("cls");
    #endif
    #ifdef __linux__
    system("clear");
    #endif
}

typedef struct GameStage
{
	char map[3][3];
}GameStage;

typedef class Partida
{
	private:
		GameStage *rodada;
		int nrodadas,p1, p2;//p1=pontuação jogador1//p2=pontuação jogador2
		fstream SaveGame;
	public:
		Partida()
			{
				nrodadas=p1=p2=0;
				rodada=NULL;
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*corrigir*/	bool Win()
			{
				if(rodada->map[0][0]==rodada->map[0][1]==rodada->map[0][2]=='x')
					{
						
						p1++;
						return true;
					}
				if(rodada->map[1][0]==rodada->map[1][1]==rodada->map[1][2]=='x')
					{
						
						p1++;
						return true;
					}
				if(rodada->map[2][0]==rodada->map[2][1]==rodada->map[2][2]=='x')
					{
						
						p1++;
						return true;
					}
				if(rodada->map[0][0]==rodada->map[1][1]==rodada->map[2][2]=='x')
					{
						
						p1++;
						return true;
					}
				if(rodada->map[0][2]==rodada->map[1][1]==rodada->map[2][0]=='x')
					{
						
						p1++;
						return true;
					}
				if(rodada->map[0][0]==rodada->map[1][0]==rodada->map[2][0]=='x')
					{
						
						p1++;
						return true;
					}
				if(rodada->map[0][1]==rodada->map[1][1]==rodada->map[2][1]=='x')
					{
						
						p1++;
						return true;
					}
				if(rodada->map[0][2]==rodada->map[1][2]==rodada->map[2][2]=='x')
					{
						
						p1++;
						return true;
					}
				if(rodada->map[0][0]==rodada->map[0][1]==rodada->map[0][2]=='o')
					{
						
						p2++;
						return true;
					}
				if(rodada->map[1][0]==rodada->map[1][1]==rodada->map[1][2]=='o')
					{
						
						p2++;
						return true;
					}
				if(rodada->map[2][0]==rodada->map[2][1]==rodada->map[2][2]=='o')
					{
						
						p2++;
						return true;
					}
				if(rodada->map[0][0]==rodada->map[1][1]==rodada->map[2][2]=='o')
					{
						
						p2++;
						return true;
					}
				if(rodada->map[0][2]==rodada->map[1][1]==rodada->map[2][0]=='o')
					{
						
						p2++;
						return true;
					}
				if(rodada->map[0][0]==rodada->map[1][0]==rodada->map[2][0]=='o')
					{
						
						p2++;
						return true;
					}
				if(rodada->map[0][1]==rodada->map[1][1]==rodada->map[2][1]=='o')
					{
						
						p2++;
						return true;
					}
				if(rodada->map[0][2]==rodada->map[1][2]==rodada->map[2][2]=='o')
					{
						
						p2++;
						return true;
					}
				else{return false;}
				
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*corrigir*/	bool Busy(int x, int y)
			{
				if(rodada->map[x][y]=='x'){return true;}
				if(rodada->map[x][y]=='o'){return true;}
				else{return false;}
				/*
				int ib,jb;
				ib=jb=0;
				while(ib<3)
				{
					while(jb<3)
					{
						if(rodada->map[x][y]!='x' && rodada->map[x][y]!='o'){return false;}
						jb++;
					}
					ib++;
				}
				return true;
				*/
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*corrigir*/	bool IsFull()
			{
				int If,Jf;
				If=Jf=0;
				while(If<3)
				{
					while(Jf<3)
						{
							if(!Busy(If,Jf)){return false;}
							Jf++;
						};
					If++;
				};
				return true;
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*corrigir*/	bool Draw()
			{
				if(IsFull() && !Win()){return true;}
				else{return false;}
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		bool GameOver()
			{
				if(Win()){return true;}
				if(Draw()){return true;}
				else return false;
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		void GameShow()
			{
				LimpaTela();
				int i,j;
				i=j=0;
				while(i<3)
				{
					while(j<3)
						{
							cout<<rodada->map[i][j];
							if(j==0 || j==1)cout<<"|";j++;
						};
					j=0;
					if(i==0 || i==1)cout<<endl<<"______"<<endl;
					i++;
				};
			}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		void Play()
			{
				int iplay,jplay;
				while(!GameOver() && !Draw())
					{
						nrodadas++;
						GameShow();
						//if(!GameOver())
						//{
							cout<<endl<<endl<<"Player 1, escolha a linha(1-3) e coluna(1-3) da posicao: ";
							cin>>iplay>>jplay;
							while(iplay<=0 || iplay>3 || jplay<=0 || jplay>3 || Busy(iplay,jplay))
								{
									LimpaTela();
									GameShow();
									cout<<endl<<endl
									    <<"Posicao invalida ou indisponivel, insira a linha(1-3) e" 									    <<" coluna(1-3) de uma posicao que nao os estejam:";
									cin.ignore();
									cin>>iplay>>jplay;
								};
							rodada->map[iplay-1][jplay-1]='x';
						//}
						GameShow();
						//if(!GameOver())
						//{
							cout<<endl<<endl<<"Player 2, escolha a linha(1-3) e coluna(1-3) da posicao: ";
							cin>>iplay>>jplay;
							while(iplay<=0 || iplay>3 || jplay<=0 || jplay>3 || Busy(iplay,jplay))
								{
									LimpaTela();
									GameShow();
									cout<<endl<<endl
									    <<"Posicao invalida ou indisponivel, insira a linha(1-3) e" 									    <<" coluna(1-3) de uma posicao que nao os estejam:";
									cin.ignore();
									cin>>iplay>>jplay;
								};
							rodada->map[iplay-1][jplay-1]='o';
						//}
					};
					int aux=0;
				while(aux<5)
					{
						system("clear");
						sleep(1);
						cout<<"Game Over"<<endl<<endl;
						sleep(1);
						aux++;
					}
				cout<<"Placar: "<<endl
				    <<"Player 1: "<<p1<<endl
				    <<"Player 2: "<<p2<<endl
				    <<"Total de rodadas jogadas"<<nrodadas<<endl;
			
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*testar*/
/*	void Save()
			{
				SaveGame.open("SaveGame.txt", ios::out);
				if(!SaveGame){cout<<"Erro ao criar arquivo save"<<endl; return;}
				else
					{
						SaveGame<<p1<<"\t"<<p2<<"\t"<<nrodadas;
					}
				SaveGame.close();
			}
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*corrigir*/
/*	void Load()
			{
				SaveGame.open("SaveGame.txt", ios::in);
				if(!SaveGame){cout<<"Erro ao abrir arquivo save ou arquivo inexistente"<<endl<<endl; return;}
				else
					{
						SaveGame>>p1>>p2>>nrodadas;
					}
				SaveGame.close();
			}
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		void Start()
			{
				LimpaTela();
				cout<<"********************************Trabalho AED-II*********************************"<<endl
				    <<"**************************Aluno:Danton Coelho Valadares*************************"<<endl
				    <<"****************************Engenharia de Computacao****************************"<<endl
				    <<"********************************Semestre: 2/2016********************************"<<endl
				    <<"****************************Professor:Julio Conway******************************"<<endl
				    <<"**************************Jogo Escolhido:Jogo da velha**************************"<<endl 					    <<endl<<endl;
				char wait=getchar();
				LimpaTela();
				cout<<"Quantas rodadas deseja jogar?"<<endl;
				cin>>nrodadas;
				int i=0,istage,jstage;
				istage=jstage=0;
				//Load();
				while(i<nrodadas)
					{
						if(i!=0)
							{
								while(rodada!=NULL){rodada++;};
							}	
						//rodada=(GameStage*)malloc(sizeof(GameStage));
						rodada=new GameStage;
						if(rodada==NULL){cout<<"Erro ao alocar memoria"<<endl;/*Save()*/; return;}
						else
							{
								while(istage<3)
								{
									while(jstage<3){rodada->map[istage][jstage]=' ';jstage++;};
									jstage=0;
									istage++;
								};
								Play();
								i++;
							}

					};
				//Save();
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}Partida;


int main(void)
{
Partida game;
game.Start();
}
