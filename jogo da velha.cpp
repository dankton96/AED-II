#include <iostream>
#include <fstream>
#include <malloc.h>
#include <string.h>
#include <string>

using namespace std;

typedef struct house
{
	char slot;
	bool simbol;
};

typedef struct GameStage
{
	char map[5][3];
	/*
	_|_|_
	_|_|_
	 | |
	*/
	house select;
};

typedef class Partida
{
	private:
		GameStage *rodada;
		int p1, p2, nrodadas;//p1=pontuação jogador1//p2=pontuação jogador2
		fstream SaveGame;
	public:
		Partida(){p1=p2=0;}
		void Start()
			{
				cout<<"Quantas rodadas deseja jogar?"<<endl;
				cin>>nrodadas;
				int i=0;
				while(i<rodadas)
					{
						
						rodada=(GameStage*)malloc(sizeof(GameStage));
						if(rodada==NULL){cout<<"Erro ao alocar memoria"<<endl; return;}
						else
							{
							//jogo	
							}

					};
			}
		void save()
			{
				SaveGame.open("SaveGame.txt", ios::in);
				if(!SaveGame){cout<<"Erro ao criar arquivo save"; return;}
				else
					{
						SaveGame<<p1<<"\t"<<p2<<"\t"<<nrodadas;
					}
			}
};


int main(void)
{
}

