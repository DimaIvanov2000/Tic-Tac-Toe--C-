#include <stdio.h>
#include <math.h>

// Functions lvl 1:
void playerMove();//
int checkWin();//
void aiMove();//
void display();//
void clear();

// Functions lvl 2:
void mode1();
void mode2();
void mode3();

// Global Variables:
int tiles[3][3]={0};
int turn;

main()
{
	
	// Local Variables:
	int mode;
	
	// Initialization:
	srand((unsigned int) time(NULL));
	
	while(1)
	{
		printf("--- Dima's Tic Tac Toe Simulator ---\n\nSelect a game mode:\n1 - Multiplayer\n2 - Vs. AI\n3 - AI Deathmatch\nElse - Exit\n\n");
		scanf("%i",&mode);
		scanf("");
		// Execution:
		switch(mode)
		{
			case 1:
				mode1();
				break;
			case 2:
				mode2();
				break;
			case 3:
				mode3();
				break;
			default:
				printf("\n\nExiting, thank you for playing...\n");
				return;
		}
	}
}

void playerMove(pnum)
{
	int selectionOk=0;
	int occupied=1;
	char input[7];
	int x;
	int y;
	
	while(occupied==1)
	{
		while(selectionOk==0)
		{
			scanf("%s",&input);
			if(strcmp(input,"top")==0)
			{
				x=0;
				selectionOk=1;
			}
			else if(strcmp(input,"middle")==0)
			{
				x=1;
				selectionOk=1;
			}
			else if(strcmp(input,"bottom")==0)
			{
				x=2;
				selectionOk=1;
			}
			else
			{
				printf("Input invalid, please select a row...\n");
			}
		}
		
		selectionOk=0;
		while(selectionOk==0)
		{
			scanf("%s",&input);
			if(strcmp(input,"left")==0)
			{
				y=0;
				selectionOk=1;
			}
			else if(strcmp(input,"middle")==0)
			{
				y=1;
				selectionOk=1;
			}
			else if(strcmp(input,"right")==0)
			{
				y=2;
				selectionOk=1;
			}
			else
			{
				printf("Input invalid, please select a column...\n");
			}
		}
		
		if(tiles[x][y]==0)
		{
			occupied=0;
		}
		else
		{
			printf("This space is occupied, try again.\n");
		}
		
	}	
	tiles[x][y]=pnum;
}

int checkWin()
{
	int i;
	int j;
	int win=0;
	//Checking for horizontal lines
		for(i=1;i<=3;i++)
		{
			int tile1=tiles[i-1][0];
			int tile2=tiles[i-1][1];
			int tile3=tiles[i-1][2];
			
			if(tile1!=0 && tile2!=0 && tile3!=0)
			{
				if(tile1==tile2 && tile1==tile3)
				{
					for(j=1;j<=3;j++)
					{
						tiles[i-1][j-1]=3;
					}
					win=1;
				}
			}
		}
		
		//Checking for vertical lines
		for(i=1;i<=3;i++)
		{
			int tile1=tiles[0][i-1];
			int tile2=tiles[1][i-1];
			int tile3=tiles[2][i-1];
			
			if(tile1!=0 && tile2!=0 && tile3!=0)
			{
				if(tile1==tile2 && tile1==tile3)
				{
					for(j=1;j<=3;j++)
					{
						tiles[j-1][i-1]=3;
					}
					win=1;
				}
			}
		}
		
		//Checking for diagonals
		if(tiles[0][0]!=0 && tiles[1][1]!=0 && tiles[2][2]!=0)
		{
			if(tiles[0][0]==tiles[1][1] && tiles[0][0]==tiles[2][2])
			{
				tiles[0][0]=3;
				tiles[1][1]=3;
				tiles[2][2]=3;
				win=1;
			}
		}
		
		if(tiles[2][0]!=0 && tiles[1][1]!=0 && tiles[0][2]!=0)
		{
			if(tiles[2][0]==tiles[1][1] && tiles[2][0]==tiles[0][2])
			{
				tiles[2][0]=3;
				tiles[1][1]=3;
				tiles[0][2]=3;
				win=1;
			}
		}
		return win;
}

void aiMove(ainum)
{
	int i;
	int j;
	int decisionMade=0;
	int random;
	int xSelect;
	int ySelect;
	printf("The AI is making a move...\n");
	//Attempting to occupy centre
	if(turn<=2)
	{
		if(tiles[1][1]==0)
		{
			tiles[1][1]=ainum;
		}
		else
		{
			random=rand()%(2)+1;
			xSelect=random*2-2;
			random=rand()%(2)+1;
			ySelect=random*2-2;
			tiles[xSelect][ySelect]=ainum;
		}
	}
	else
	{
		decisionMade=0;
		//checking for win scenarios
		for(i=1;i<=3;i++)
		{
			int tile1=tiles[0][i-1];
			int tile2=tiles[1][i-1];
			int tile3=tiles[2][i-1];
			
			if(tile1+tile2+tile3==2*ainum&&tile1!=ainum%2+1&&tile2!=ainum%2+1&&tile3!=ainum%2+1)
			{
				for(j=1;j<=3;j++)
				{
						tiles[j-1][i-1]=ainum;
						decisionMade=1;
				}
			}
		}
		if(decisionMade==0)
		{
			for(i=1;i<=3;i++)
			{
				int tile1=tiles[i-1][0];
				int tile2=tiles[i-1][1];
				int tile3=tiles[i-1][2];
				
				if(tile1+tile2+tile3==2*ainum&&tile1!=ainum%2+1&&tile2!=ainum%2+1&&tile3!=ainum%2+1)
				{
					for(j=1;j<=3;j++)
					{
						tiles[i-1][j-1]=ainum;
						decisionMade=1;
					}
				}
			}
		}
		if(decisionMade==0)
		{
			int tile1=tiles[0][0];
			int tile2=tiles[1][1];
			int tile3=tiles[2][2];
			if(tile1+tile2+tile3==2*ainum&&tile1!=ainum%2+1&&tile2!=ainum%2+1&&tile3!=ainum%2+1)
			{
				for(j=1;j<=3;j++)
				{
					tiles[j-1][j-1]=ainum;
					decisionMade=1;
				}
			}
		}
		if(decisionMade==0)
		{
			int tile1=tiles[0][2];
			int tile2=tiles[1][1];
			int tile3=tiles[2][0];
			if(tile1+tile2+tile3==2*ainum&&tile1!=ainum%2+1&&tile2!=ainum%2+1&&tile3!=ainum%2+1)
			{
				for(j=1;j<=3;j++)
				{
					tiles[j-1][3-j]=ainum;
					decisionMade=1;
				}
			}
		}
		//checking for lose scenarios
		if(decisionMade==0)
		{
			for(i=1;i<=3;i++)
			{
				int tile1=tiles[0][i-1];
				int tile2=tiles[1][i-1];
				int tile3=tiles[2][i-1];
				
				if(tile1+tile2+tile3==2*(ainum%2)+2&&tile1!=ainum&&tile2!=ainum&&tile3!=ainum)
				{
					if(tile1==0)
					{
						tiles[0][i-1]=ainum;
					}
					else if(tile2==0)
					{
						tiles[1][i-1]=ainum;
					}
					else
					{
						tiles[2][i-1]=ainum;
					}
					decisionMade=1;
				}
			}
		}
		
		if(decisionMade==0)
		{
			for(i=1;i<=3;i++)
			{
				int tile1=tiles[i-1][0];
				int tile2=tiles[i-1][1];
				int tile3=tiles[i-1][2];
				
				if(tile1+tile2+tile3==2*(ainum%2)+2&&tile1!=ainum&&tile2!=ainum&&tile3!=ainum)
				{
					if(tile1==0)
					{
						tiles[i-1][0]=ainum;
					}
					else if(tile2==0)
					{
						tiles[i-1][1]=ainum;
					}
					else
					{
						tiles[i-1][2]=ainum;
					}
					decisionMade=1;
				}
			}
		}
		if(decisionMade==0)
		{
			int tile1=tiles[0][0];
			int tile2=tiles[1][1];
			int tile3=tiles[2][2];
			if(tile1+tile2+tile3==2*(ainum%2)+2&&tile1!=ainum&&tile2!=ainum&&tile3!=ainum)
			{
				if(tile1==0)
				{
					tiles[0][0]=ainum;
				}
				else if(tile2==0)
				{
					tiles[1][1]=ainum;
				}
				else
				{
					tiles[2][2]=ainum;
				}
				decisionMade=1;
			}
		}
		if(decisionMade==0)
		{
			int tile1=tiles[0][2];
			int tile2=tiles[1][1];
			int tile3=tiles[2][0];
			if(tile1+tile2+tile3==2*(ainum%2)+2&&tile1!=ainum&&tile2!=ainum&&tile3!=ainum)
			{
				if(tile1==0)
				{
					tiles[0][2]=ainum;
				}
				else if(tile2==0)
				{
					tiles[1][1]=ainum;
				}
				else
				{
					tiles[2][0]=ainum;
				}
				decisionMade=1;
			}
		}
		//putting in random square
//		while(decisionMade==0)
//		{
//			random=rand()%(9)+1;
//			xSelect=(random-1)%3;
//			ySelect=floor(((float)random-1)/3);
//			if(tiles[xSelect][ySelect]==0)
//			{
//				tiles[xSelect][ySelect]=ainum;
//				decisionMade=1;
//			}
//		}
		//putting in random corner
		for(i=0;i<=1;i++)
		{
			for(j=0;j<=1;j++)
			{
				if(tiles[i*2][j*2]==0&&decisionMade==0)
				{
					tiles[i*2][j*2]=ainum;
					decisionMade=1;
				}
			}
		}
		//putting in random edge
		for(i=0;i<=1;i++)
		{
			if(tiles[i][i+1]==0&&decisionMade==0)
			{
				tiles[i][i+1]=ainum;
				decisionMade=1;
			}
			if(tiles[i+1][i]==0&&decisionMade==0)
			{
				tiles[i+1][i]=ainum;
				decisionMade=1;
			}
		}
		
	}
}

void display()
{
	int i;
	int j;
	printf("\n");
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			char sign;
			
			switch(tiles[i-1][j-1])
			{
				case 0:
					sign='-';
					break;
				case 1:
					sign='X';
					break;
				case 2:
					sign='O';
					break;
				case 3:
					sign='#';
					break;
			}
			printf(" %c",sign);
		}
		printf("\n");
	}
	printf("\n");
}

void clear()
{
	int i;
	int j;
	
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=2;j++)
		{
			tiles[i][j]=0;
		}
	}
}

void mode1()
{
	turn=1;
	while(turn<10)
	{
		playerMove((turn+1)%2+1);
		if(checkWin()==1)
		{
			display();
			break;
		}
		display();
		turn++;
	}
	if(turn!=10)
	{
		printf("Player%i has won! Game Over.\n\n",(turn+1)%2+1);
	}
	else
	{
		printf("The game is a tie! Game Over.\n\n");
	}
	clear();
}

void mode2()
{
	turn=1;
	while(turn<10)
	{
		if(turn%2==1)
		{
			playerMove(1);
		}
		else
		{
			aiMove(2);
		}
		if(checkWin()==1)
		{
			display();
			break;
		}
		display();
		turn++;
	}
	if(turn==10)
	{
		printf("The game is a tie! Better luck next time player!\n\n");
	}
	else if(turn%2==1)
	{
		printf("Gongrats player! You beat the AI! You're a genius!");
	}
	else
	{
		printf("The AI has won! Nice try player!");
	}
	clear();
}

void mode3()
{
	turn=1;
	while(turn<10)
	{
		aiMove((turn+1)%2+1);
		if(checkWin()==1)
		{
			display();
			break;
		}
		display();
		turn++;
	}
	if(turn!=10)
	{
		printf("AI%i has won! Game Over.\n\n",(turn+1)%2+1);
	}
	else
	{
		printf("The game is a tie! Good work AI!\n\n");
	}
	clear();
}
