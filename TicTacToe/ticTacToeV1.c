#include <stdio.h>
#include <math.h>

// Functions:
void playerMove();
int aiMove();
int checkWin();

// Global Variables:
int tiles[3][3]={0};

main()
{
	// Local Variables:
	int turn;
	int mode;
	
	// Initialization:
	while(1)
	{
		printf("--- Dima's Tic Tac Toe Simulator ---\n\nSelect a game mode:\n1 - Multiplayer\n2 - Vs. AI\n3 - AI Deathmatch\n\n");
		scanf("%i",&mode);
		scanf("");
		// Execution:
		switch(mode)
		{
			case 1:
				
				break;
			case 2:
				
				break;
			case 3:
				
				break;
			default:
				printf("\n\nExiting, thank you for playing...\n");
				return;
		}
	}
}


int getInputY()
{
	int selectionOk=0;
	char input[7];
	int output;
	while(selectionOk==0)
	{
		scanf("%s",&input);
		if(strcmp(input,"left")==0)
		{
			output=0;
			selectionOk=1;
		}
		else if(strcmp(input,"middle")==0)
		{
			output=1;
			selectionOk=1;
		}
		else if(strcmp(input,"right")==0)
		{
			output=2;
			selectionOk=1;
		}
		else
		{
			printf("Input invalid, please select a column...\n");
		}
	}
	return output;
}

int getInputX()
{
	int selectionOk=0;
	char input[7];
	int output;
	while(selectionOk==0)
	{
		scanf("%s",&input);
		if(strcmp(input,"top")==0)
		{
			output=0;
			selectionOk=1;
		}
		else if(strcmp(input,"middle")==0)
		{
			output=1;
			selectionOk=1;
		}
		else if(strcmp(input,"bottom")==0)
		{
			output=2;
			selectionOk=1;
		}
		else
		{
			printf("Input invalid, please select a row...\n");
		}
	}
	return output;
}


void task14()
{
	int tiles[3][3]; // x and y respectively, 0 for empty, 1 and 2 for players and 3 for a win
	int i;
	int j;
	int turn=1; // 1 or 2 for respective player
	int turnNum=1; // tie if it reaches 10
	char xInput[7];
	char yInput[7];
	int xSelect;
	int ySelect;
	int selectionOk; //pretend its a boolean
	int notOccupied; //pretend its a boolean
	int win=0; // 0 = still going   1 = win
	
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			tiles[i-1][j-1]=0;
		}
	}
	
	printf("The Rules:\n\n   Type \"top\", \"middle\", or \"bottom\" to select a row\n   Then type \"left\", \"middle\", or \"right\" to select a column\n   You know the rest!\n\nThe Game has Begun! Ready players 1 (X) and 2 (O)!\n\n");
	
	while(win==0 && turnNum < 10)
	{
		//Input Stage
		printf("Player%i, please make a move...\n",turn);
		
		notOccupied=0;
		while(notOccupied==0)
		{
			selectionOk=0;
			while(selectionOk==0)
			{
				scanf("%s",&yInput);
				if(strcmp(yInput,"top")==0)
				{
					ySelect=0;
					selectionOk=1;
				}
				else if(strcmp(yInput,"middle")==0)
				{
					ySelect=1;
					selectionOk=1;
				}
				else if(strcmp(yInput,"bottom")==0)
				{
					ySelect=2;
					selectionOk=1;
				}
				else
				{
					printf("Input is invalid, try again.\n");
				}
			}
			
			selectionOk=0;
			while(selectionOk==0)
			{
				scanf("%s",&xInput);
				if(strcmp(xInput,"left")==0)
				{
					xSelect=0;
					selectionOk=1;
				}
				else if(strcmp(xInput,"middle")==0)
				{
					xSelect=1;
					selectionOk=1;
				}
				else if(strcmp(xInput,"right")==0)
				{
					xSelect=2;
					selectionOk=1;
				}
				else
				{
					printf("Input is invalid, try again.\n");
				}
			}
			
			if(tiles[xSelect][ySelect]!=0)
			{
				printf("Sorry, this space is taken\n");
			}
			else
			{
				notOccupied=1;
			}
		}
		
		//Updating Field
		tiles[xSelect][ySelect]=turn;
		
		//Checking for horizontal lines
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
		
		//Checking for vertical lines
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
		
		//Display Board
		printf("\n");
		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
			{
				char sign;
				
				switch(tiles[j-1][i-1])
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
		
		//Turn Toggle
		if(win==0)
		{
			if(turn==2)
			{
				turn=1;
			}
			else
			{
				turn=2;
			}
			turnNum++;
		}
	}
	if(win==1)
	{
		printf("Player%i has won! Congratulations Player%i!\n",turn,turn);
	}
	else
	{
		printf("The match is a tie! Well played both players!\n");
	}
}

//Task 12: Tic Tac Toe AI
void task15()
{
	int tiles[3][3]; // x and y respectively, 0 for empty, 1 and 2 for players and 3 for a win
	int i;
	int j;
	int turn=1; // 1 or 2 for respective player
	int turnNum=1; // tie if it reaches 10
	char xInput[7];
	char yInput[7];
	int xSelect;
	int ySelect;
	int selectionOk; //pretend its a boolean
	int notOccupied; //pretend its a boolean
	int decisionMade; //pretend its a boolean
	int win=0; // 0 = still going   1 = win
	int random;
	srand((unsigned int) time(NULL));
	
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			tiles[i-1][j-1]=0;
		}
	}
	
	printf("The Rules:\n\n   Type \"top\", \"middle\", or \"bottom\" to select a row\n   Then type \"left\", \"middle\", or \"right\" to select a column\n   You know the rest!\n\nThe Game has Begun! Ready player!\n\n");
	
	while(win==0 && turnNum < 10)
	{
		if(turn==1)
		{
			//Input Stage
			printf("Player, please make a move...\n");
			
			notOccupied=0;
			while(notOccupied==0)
			{
				selectionOk=0;
				while(selectionOk==0)
				{
					scanf("%s",&yInput);
					if(strcmp(yInput,"top")==0)
					{
						ySelect=0;
						selectionOk=1;
					}
					else if(strcmp(yInput,"middle")==0)
					{
						ySelect=1;
						selectionOk=1;
					}
					else if(strcmp(yInput,"bottom")==0)
					{
						ySelect=2;
						selectionOk=1;
					}
					else
					{
						printf("Input is invalid, try again.\n");
					}
				}
				
				selectionOk=0;
				while(selectionOk==0)
				{
					scanf("%s",&xInput);
					if(strcmp(xInput,"left")==0)
					{
						xSelect=0;
						selectionOk=1;
					}
					else if(strcmp(xInput,"middle")==0)
					{
						xSelect=1;
						selectionOk=1;
					}
					else if(strcmp(xInput,"right")==0)
					{
						xSelect=2;
						selectionOk=1;
					}
					else
					{
						printf("Input is invalid, try again.\n");
					}
				}
				
				if(tiles[xSelect][ySelect]!=0)
				{
					printf("Sorry, this space is taken\n");
				}
				else
				{
					notOccupied=1;
				}
			}
			
			//Updating Field
			tiles[xSelect][ySelect]=1;
		}
		else
		{
			printf("The AI is making a move...\n");
			//Attempting to occupy centre
			if(turnNum==2)
			{
				if(tiles[1][1]==0)
				{
					tiles[1][1]=2;
				}
				else
				{
					random=rand()%(2)+1;
					xSelect=random*2-2;
					random=rand()%(2)+1;
					ySelect=random*2-2;
					tiles[xSelect][ySelect]=2;
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
					
					if(tile1+tile2+tile3==4&&tile1!=1&&tile2!=1&&tile3!=1)
					{
						for(j=1;j<=3;j++)
						{
								tiles[j-1][i-1]=2;
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
						
						if(tile1+tile2+tile3==4&&tile1!=1&&tile2!=1&&tile3!=1)
						{
							for(j=1;j<=3;j++)
							{
								tiles[i-1][j-1]=2;
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
					if(tile1+tile2+tile3==4&&tile1!=1&&tile2!=1&&tile3!=1)
					{
						for(j=1;j<=3;j++)
						{
							tiles[j-1][j-1]=2;
							decisionMade=1;
						}
					}
				}
				if(decisionMade==0)
				{
					int tile1=tiles[0][2];
					int tile2=tiles[1][1];
					int tile3=tiles[2][0];
					if(tile1+tile2+tile3==4&&tile1!=1&&tile2!=1&&tile3!=1)
					{
						for(j=1;j<=3;j++)
						{
							tiles[j-1][3-j]=2;
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
						
						if(tile1+tile2+tile3==2&&tile1!=2&&tile2!=2&&tile3!=2)
						{
							if(tile1==0)
							{
								tiles[0][i-1]=2;
							}
							else if(tile2==0)
							{
								tiles[1][i-1]=2;
							}
							else
							{
								tiles[2][i-1]=2;
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
						
						if(tile1+tile2+tile3==2&&tile1!=2&&tile2!=2&&tile3!=2)
						{
							if(tile1==0)
							{
								tiles[i-1][0]=2;
							}
							else if(tile2==0)
							{
								tiles[i-1][1]=2;
							}
							else
							{
								tiles[i-1][2]=2;
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
					if(tile1+tile2+tile3==2&&tile1!=2&&tile2!=2&&tile3!=2)
					{
						if(tile1==0)
						{
							tiles[0][0]=2;
						}
						else if(tile2==0)
						{
							tiles[1][1]=2;
						}
						else
						{
							tiles[2][2]=2;
						}
						decisionMade=1;
					}
				}
				if(decisionMade==0)
				{
					int tile1=tiles[0][2];
					int tile2=tiles[1][1];
					int tile3=tiles[2][0];
					if(tile1+tile2+tile3==2&&tile1!=2&&tile2!=2&&tile3!=2)
					{
						if(tile1==0)
						{
							tiles[0][2]=2;
						}
						else if(tile2==0)
						{
							tiles[1][1]=2;
						}
						else
						{
							tiles[2][0]=2;
						}
						decisionMade=1;
					}
				}
				//putting in random square
				while(decisionMade==0)
				{
					random=rand()%(9)+1;
					xSelect=(random-1)%3;
					ySelect=floor(((float)random-1)/3);
					if(tiles[xSelect][ySelect]==0)
					{
						tiles[xSelect][ySelect]=2;
						decisionMade=1;
					}
				}
				
			}
		}
		//Checking for horizontal lines
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
		
		//Checking for vertical lines
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
		
		//Display Board
		printf("\n");
		for(i=1;i<=3;i++)
		{
			for(j=1;j<=3;j++)
			{
				char sign;
				
				switch(tiles[j-1][i-1])
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
		
		//Turn Toggle
		if(win==0)
		{
			if(turn==2)
			{
				turn=1;
			}
			else
			{
				turn=2;
			}
			turnNum++;
		}
	}
	if(win==1)
	{
		if(turn==1)
		{
			printf("Player has won! Congratulations Player!\n");
		}
		else
		{
			printf("The AI has won! Better luck next time, Player!\n");
		}
	}
	else
	{
		printf("The match is a tie! I guess that's something, Player...\n");
	}
}
