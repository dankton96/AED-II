#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <string>
#include <unistd.h>
#include <time.h>

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

typedef class GameStage
{
	public:
	char map[3][3];
	GameStage(){for(int i=0;i<3;i++){for(int j=0;j<3;j++){map[i][j]=' ';}}}
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
		bool Busy(int x, int y)
			{
				return (rodada->map[x][y]!=' ');
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		bool IsFull()
			{
				for(int If=0;If<3;If++)
				{
					for(int Jf=0;Jf<3;Jf++)
						{
							if(!Busy(If,Jf)){return false;}
						}
				}
				return true;
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		bool Win()
			{
			       if(rodada->map[0][0]==rodada->map[0][1] && rodada->map[0][1]==rodada->map[0][2] && rodada->map[0][2]=='x')
			       {p1++; return true;} else 
			       if(rodada->map[1][0]==rodada->map[1][1] && rodada->map[1][1]==rodada->map[1][2] && rodada->map[1][2]=='x')
			       {p1++; return true;} else
			       if(rodada->map[2][0]==rodada->map[2][1] && rodada->map[2][1]==rodada->map[2][2] && rodada->map[2][2]=='x')
			       {p1++; return true;} else
			       if(rodada->map[0][0]==rodada->map[1][0] && rodada->map[1][0]==rodada->map[2][0] && rodada->map[2][0]=='x')
			       {p1++; return true;} else
			       if(rodada->map[0][1]==rodada->map[1][1] && rodada->map[1][1]==rodada->map[2][1] && rodada->map[2][1]=='x')
			       {p1++; return true;} else
			       if(rodada->map[0][2]==rodada->map[1][2] && rodada->map[1][2]==rodada->map[2][2] && rodada->map[2][2]=='x')
			       {p1++; return true;} else
			       if(rodada->map[0][0]==rodada->map[1][1] && rodada->map[1][1]==rodada->map[2][2] && rodada->map[2][2]=='x')
			       {p1++; return true;} else
			       if(rodada->map[0][2]==rodada->map[1][1] && rodada->map[1][1]==rodada->map[2][0] && rodada->map[2][0]=='x')
			       {p1++; return true;} else
			       if(rodada->map[0][0]==rodada->map[0][1] && rodada->map[0][1]==rodada->map[0][2] && rodada->map[0][2]=='o')
			       {p2++; return true;} else
			       if(rodada->map[1][0]==rodada->map[1][1] && rodada->map[1][1]==rodada->map[1][2] && rodada->map[1][2]=='o')
			       {p2++; return true;} else
			       if(rodada->map[2][0]==rodada->map[2][1] && rodada->map[2][1]==rodada->map[2][2] && rodada->map[2][2]=='o')
			       {p2++; return true;} else
			       if(rodada->map[0][0]==rodada->map[1][0] && rodada->map[1][0]==rodada->map[2][0] && rodada->map[2][0]=='o')
			       {p2++; return true;} else
			       if(rodada->map[0][1]==rodada->map[1][1] && rodada->map[1][1]==rodada->map[2][1] && rodada->map[2][1]=='o')
			       {p2++; return true;} else
			       if(rodada->map[0][2]==rodada->map[1][2] && rodada->map[1][2]==rodada->map[2][2] && rodada->map[2][2]=='o')
			       {p2++; return true;} else
			       if(rodada->map[0][0]==rodada->map[1][1] && rodada->map[1][1]==rodada->map[2][2] && rodada->map[2][2]=='o')
			       {p2++; return true;} else
			       if(rodada->map[0][2]==rodada->map[1][1] && rodada->map[1][1]==rodada->map[2][0] && rodada->map[2][0]=='o')
			       {p2++; return true;}
			       else return false;
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*ou erro esta aqui*/
		bool Draw()
			{
				/*if*/return (IsFull() && !Win());//{return true;}
				//else{return false;}
			}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		bool GameOver()
			{
				//if(Win()){cout<<"Vitoria"<<endl;nrodadas++;return true;}
				//if(Draw()){cout<<"Empate"<<endl;nrodadas++;return true;}
				//else return false;
				return Win() || Draw();
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
				cout<<endl<<endl;
			}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		void Play()
			{
				int iplay,jplay;
				while(!GameOver())
					{
						GameShow();
						if(!GameOver())
						{
							cout<<endl<<endl<<"Player 1, escolha a linha(1-3) e coluna(1-3) da posicao[l-c]:";
							scanf("%d-%d", &iplay,&jplay);
							while(iplay<=0 || iplay>3 || jplay<=0 || jplay>3 || Busy(iplay-1,jplay-1))
								{
									LimpaTela();
									GameShow();
									cout<<endl<<endl
									    <<"Posicao invalida ou indisponivel, insira a linha(1-3) e" 									    <<" coluna(1-3) de uma posicao que nao os estejam [l-c]:";
									cin.ignore();
									scanf("%d-%d", &iplay,&jplay);
								}
							rodada->map[iplay-1][jplay-1]='x';
						}
						GameShow();
						if(!GameOver())
						{
							cout<<endl<<endl<<"Player 2, escolha a linha(1-3) e coluna(1-3) da posicao[l-c]:";
							scanf("%d-%d", &iplay,&jplay);

							while(iplay<=0 || iplay>3 || jplay<=0 || jplay>3 || Busy(iplay-1,jplay-1))
								{
									LimpaTela();
									GameShow();
									cout<<endl<<endl
									    <<"Posicao invalida ou indisponivel, insira a linha(1-3) e" 									    <<" coluna(1-3) de uma posicao que nao os estejam [l-c]:";
									cin.ignore();
									scanf("%d-%d", &iplay,&jplay);

								}
							rodada->map[iplay-1][jplay-1]='o';
						}
					};
					nrodadas++;
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
				    <<"Total de rodadas jogadas: "<<nrodadas<<endl;
			
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
				delete rodada;
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
				int i=0;
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
