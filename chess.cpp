/*
 * 	Project Name 	: CHESS
 *  Dev				: RocE
 *  Date			: 20 Sep 2014 (01:36 AM)
 *  Version			: 1.0
 *  Compiler		: GNU GCC
 *  Environment		: Ubuntu 14.04
 *  IDE				: Geany
 * */

/*
 * Guide for game:
 * 
 * 1. Compile & Execute the given code using GCC Compiler.
 * 
 * 2. Game creates a Chess Board of 8x8 square blocks.
 * 
 * 3. Each block is either filled with peice of chess or its empty.
 * 
 * 4. In the block at the left-hand top side, it shows the current block number.
 * 
 * 5. Chess peices aliases:
 * 			EMPTY			->		" "
 * 			
 * 			PAWN(WHITE)		->		"PA-W"
 * 			ROOK(WHITE)		->		"RO-W"
 * 			BISHOP(WHITE)	->		"BI-W"
 * 			KNIGHT(WHITE)	->		"KN-W"
 * 			QUEEN(WHITE)	->		"QU-W"
 * 			KING(WHITE)		->		"KI-W"
 * 
 * 			PAWN(BLACK)		->		"PA-B"
 * 			ROOK(BLACK)		->		"RO-B"
 * 			BISHOP(BLACK)	->		"BI-B"
 * 			KNIGHT(BLACK)	->		"KN-B"
 * 			QUEEN(BLACK)	->		"QU-B"
 * 			KING(BLACK)		->		"KI-B"
 * 
 * 6. At start of game, enter the player names;
 * 		player1 will be assigned to WHITE peices & will play first, and,
 * 		player2 will be assigned to BLACK peices & will play after player1's chance.
 * 
 * 7. At every chance system asks player to move its peice from one cell to another cell in form as-
 * 		(FROM ROW, FROM COLUMN) --> (TO ROW, TO COLUMN)
 * 
 * 8. Enjoy.. :)
 * 
 * */

#include<stdio.h>
#include<iostream>
#include<math.h>
//#include<time.h>
//#include<sys/types.h>
//#include<graphics.h>
#include<stdlib.h>
#define max 10
#define MAX_BOARD_LEN 8
#define MIN_BOARD_LEN 0

using namespace std;


class welcome
{
	public:
			
			void welcome_msg()
			{
				cout<<"\n\n\t       _______________________________________";
				cout<<"\n\t      /  _____________________________________)";
				cout<<"\n\t     /  /                    ";
				cout<<"\n\t    /  /   _    _     _____     _____     _____    ";
				cout<<"\n\t   /  /   | |  | |   | ____|   ( ____)   ( ____)";
				cout<<"\n\t  /  /    | |  | |   | |       | |       | |";
				cout<<"\n\t /  /     | |__| |   | |__     | |___    | |___";
				cout<<"\n\t|  (      |  __  |   |  __|    (____ )   (____ ) ";
				cout<<"\n\t\\  \\      | |  | |   | |           | |       | |";
				cout<<"\n\t \\  \\     | |  | |   | |___     ___| |    ___| | ";
				cout<<"\n\t  \\  \\    |_|  |_|   |_____|   (_____)   (_____)";
				cout<<"\n\t   \\  \\                    ";
				cout<<"\n\t    \\  \\_____________________________________        ";
				cout<<"\n\t     \\_______________________________________)";
				
				cout<<"\n\n\tCopyrights (c) RocE, \"Chess\" - v1.0 2014.";
				
			}
};

/*
 * player class-
 * 			DATA VALUES	:
 * 				1. player1 - String value, consisting name assigned to player1.
 * 				2. player2 - String value, consisting name assigned to player2.
 * */

class players
{
	char *player1;
	char *player2;
	
	public:
			// Constructor for player-class
			players()
			{
				player1 = NULL;
				player2 = NULL;
			}
			
			// Assigns a name for player1
			void set_player1()
			{
				cout<<"\n\n\tName of Player1:\t";
				player1 = (char *)malloc(max);
				cin>>player1;
			}
			
			// Assigns a name for player2
			void set_player2()
			{
				cout<<"\n\n\tName of Player2:\t";
				player2 = (char *)malloc(max);
				cin>>player2;
			}
			
			// Retrives the name of 1st player
			char *get_player1()
			{
				char *p = player1;
				return p;
			}
			
			// Retrives the name of 2nd player
			char *get_player2()
			{
				char *p = player2;
				return p;
			}
};

/*
 * game_board class:
 * 		Class consists of creating a chess board & managing the rules associated on the board
 * */

class game_board
{
	
	public:
	
	enum chess { 	EMPTY=0,
					PAWN_W,PAWN_B,
					BISHOP_W,BISHOP_B,
					KNIGHT_W,KNIGHT_B,
					ROOK_W,ROOK_B,
					QUEEN_W,QUEEN_B,
					KING_W,KING_B		};
	
	enum color {	WHITE, BLACK	};
	
	struct gameboard
	{
		chess peice[MAX_BOARD_LEN][MAX_BOARD_LEN];
		color shade;
	}board;
	
			//	Initializes the game by assigning hte values of chess peices on their proper places.
			void init_game()
			{
				int i,j;
				
				for(i=MIN_BOARD_LEN;i<MAX_BOARD_LEN;i++)
					for(j=MIN_BOARD_LEN;j<MAX_BOARD_LEN;j++)
						if(i%2 == 0)
							if(j%2 == 0)
								board.shade = WHITE;
							else
								board.shade = BLACK;
						else
							if(j%2 == 0)
								board.shade = BLACK;
							else
								board.shade = WHITE;
				
				
				for(i=2;i<6;i++)
				{
					for(j=MIN_BOARD_LEN;j<MAX_BOARD_LEN;j++)
					{
						board.peice[i][j] = EMPTY;
					}
				}
				
				for(i=MIN_BOARD_LEN;i<MAX_BOARD_LEN;i++)
				{
					board.peice[1][i] = PAWN_W;
					board.peice[6][i] = PAWN_B;
				}
				
				board.peice[0][0] = ROOK_W;
				board.peice[0][7] = ROOK_W;
				board.peice[7][0] = ROOK_B;
				board.peice[7][7] = ROOK_B;
				
				board.peice[0][1] = KNIGHT_W;
				board.peice[0][6] = KNIGHT_W;
				board.peice[7][1] = KNIGHT_B;
				board.peice[7][6] = KNIGHT_B;
				
				board.peice[0][2] = BISHOP_W;
				board.peice[0][5] = BISHOP_W;
				board.peice[7][2] = BISHOP_B;
				board.peice[7][5] = BISHOP_B;
				
				board.peice[0][3] = QUEEN_W;
				board.peice[0][4] = KING_W;
				board.peice[7][3] = QUEEN_B;
				board.peice[7][4] = KING_B;
			}
			
			// Method Displays the current status of the Chess board.
			void draw_board()
			{
				int i,j;
				
				for(i=MIN_BOARD_LEN;i<MAX_BOARD_LEN;i++)
				{
						cout<<"\n\t";
						for(j=MIN_BOARD_LEN;j<MAX_BOARD_LEN;j++)
							cout<<" _____";
						cout<<"\n\t";
						for(j=MIN_BOARD_LEN;j<MAX_BOARD_LEN;j++)
						{
							if(j<MAX_BOARD_LEN - 1)
								cout<<"|"<<i+1<<" "<<j+1<<"  ";
							else
								cout<<"|"<<i+1<<" "<<j+1<<"  |";
						}
						cout<<"\n\t";
						for(j=MIN_BOARD_LEN;j<MAX_BOARD_LEN;j++)
						{
							if(j<MAX_BOARD_LEN - 1)
							{
								if(board.peice[i][j] == PAWN_B)
									cout<<"| PA-B";
								else if(board.peice[i][j] == PAWN_W)
									cout<<"| PA-W";
								else if(board.peice[i][j] == KNIGHT_B)
									cout<<"| KN-B";
								else if(board.peice[i][j] == KNIGHT_W)
									cout<<"| KN-W";
								else if(board.peice[i][j] == ROOK_B)
									cout<<"| RO-B";
								else if(board.peice[i][j] == ROOK_W)
									cout<<"| RO-W";
								else if(board.peice[i][j] == BISHOP_B)
									cout<<"| BI-B";
								else if(board.peice[i][j] == BISHOP_W)
									cout<<"| BI-W";
								else if(board.peice[i][j] == QUEEN_B)
									cout<<"| QU-B";
								else if(board.peice[i][j] == QUEEN_W)
									cout<<"| QU-W";
								else if(board.peice[i][j] == KING_B)
									cout<<"| KI-B";
								else if(board.peice[i][j] == KING_W)
									cout<<"| KI-W";
								else if(board.peice[i][j] == EMPTY)
									cout<<"|     ";
							}
							else
							{
								if(board.peice[i][j] == PAWN_B)
									cout<<"| PA-B|";
								else if(board.peice[i][j] == PAWN_W)
									cout<<"| PA-W|";
								else if(board.peice[i][j] == KNIGHT_B)
									cout<<"| KN-B|";
								else if(board.peice[i][j] == KNIGHT_W)
									cout<<"| KN-W|";
								else if(board.peice[i][j] == ROOK_B)
									cout<<"| RO-B|";
								else if(board.peice[i][j] == ROOK_W)
									cout<<"| RO-W|";
								else if(board.peice[i][j] == BISHOP_B)
									cout<<"| BI-B|";
								else if(board.peice[i][j] == BISHOP_W)
									cout<<"| BI-W|";
								else if(board.peice[i][j] == QUEEN_B)
									cout<<"| QU-B|";
								else if(board.peice[i][j] == QUEEN_W)
									cout<<"| QU-W|";
								else if(board.peice[i][j] == KING_B)
									cout<<"| KI-B|";
								else if(board.peice[i][j] == KING_W)
									cout<<"| KI-W|";
								else if(board.peice[i][j] == EMPTY)
									cout<<"|     |";
							}
						}
						cout<<"\n\t";
						for(j=MIN_BOARD_LEN;j<MAX_BOARD_LEN;j++)
						{
							if(j<MAX_BOARD_LEN - 1)
								cout<<"|_____";
							else
								cout<<"|_____|";
						}
				}
			}
			
			// Method makes move from one cell to another
			void make_move(int from_row, int from_col, int to_row, int to_col)
			{
				board.peice[to_row][to_col] = board.peice[from_row][from_col];
				board.peice[from_row][from_col] = EMPTY;
			}
			
			// Method retrieves the cell status from board as per given ROW & COL number.
			chess get_board_status(int i, int j)
			{
				return board.peice[i][j];
			}
			
			// Reverts back the changes made on Illegal moves
			void recover(chess from_individual, chess to_individual, int from_row, int from_col, int to_row, int to_col)
			{
				board.peice[from_row][from_col] = from_individual;
				board.peice[to_row][to_col] = to_individual;
			}
			
			// Method Checks whether any player's KING has been checked or not.
			int checked(int count)
			{
				int r, c, row, col, flag=0;
				
				if(count%2 == 1)	//White peice has made the move, check the position of Black KING
				{
					for(row=MAX_BOARD_LEN - 1;row>=MIN_BOARD_LEN;row--)
					{
						for(col=MAX_BOARD_LEN - 1;col>=MIN_BOARD_LEN;col--)
						{
							if(get_board_status(row,col) == KING_B)
							{
								flag = 1;
								break;
							}
						}
						if(flag == 1)
							break;
					}
					
					
					r = row;
					c = col;
					if(get_board_status(r+1,c+1) == PAWN_W)		// North-Right Check - for White Pawn
					{
						cout<<"\n\t\tChecked by Pawn North-East =>("<<r+2<<" , "<<c+2<<")";
						return 1;
					}
					else if(get_board_status(r+1,c-1) == PAWN_W)	// North-Left Check - for White Pawn
					{
						cout<<"\n\t\tChecked by Pawn North-West =>("<<r+2<<" , "<<c<<")";
						return 1;
					}
					else
					{
						// North Check
						r = row-1;
						c = col;
						do
						{
							if(get_board_status(r,c) == QUEEN_W || get_board_status(r,c) == ROOK_W)
							{
								cout<<"\n\t\tChecked by Queen/Rook north =>("<<r+1<<" , "<<c+1<<")";
								return 1;
							}
							else if(get_board_status(r,c) != EMPTY)
							{
								break;
							}
							r--;
						}while(r >= MIN_BOARD_LEN);
						
						//South Check
						r = row+1;
						c = col;
						do
						{
							if(get_board_status(r,c) == QUEEN_W || get_board_status(r,c) == ROOK_W)
							{
								cout<<"\n\t\tChecked by Queen/Rook south =>("<<r+1<<" , "<<c+1<<")";
								return 1;
							}
							else if(get_board_status(r,c) != EMPTY)
							{
								break;
							}
							r++;
						}while(r < MAX_BOARD_LEN);
						
						// East Check
						r = row;
						c = col+1;
						do
						{
							if(get_board_status(r,c) == QUEEN_W || get_board_status(r,c) == ROOK_W)
							{
								cout<<"\n\t\tChecked by Queen/Rook east =>("<<r+1<<" , "<<c+1<<")";
								return 1;
							}
							else if(get_board_status(r,c) != EMPTY)
							{
								break;
							}
							c++;
						}while(c < MAX_BOARD_LEN);
						
						// West Check
						r = row;
						c = col-1;
						do
						{
							if(get_board_status(r,c) == QUEEN_W || get_board_status(r,c) == ROOK_W)
							{
								cout<<"\n\t\tChecked by Queen/Rook west =>("<<r+1<<" , "<<c+1<<")";
								return 1;
							}
							else if(get_board_status(r,c) != EMPTY)
							{
								break;
							}
							c--;
						}while(c >= MIN_BOARD_LEN);
						
						// North-West Check
						r = row-1;
						c = col-1;
						do
						{
							if(get_board_status(r,c) == QUEEN_W || get_board_status(r,c) == BISHOP_W)
							{
								cout<<"\n\t\tChecked by Queen/Bishop north-west =>("<<r+1<<" , "<<c+1<<")";
								return 1;
							}
							else if(get_board_status(r,c) != EMPTY)
							{
								break;
							}
							c--;
							r--;
						}while(c >= MIN_BOARD_LEN && r >= MIN_BOARD_LEN);
						
						
						// North-East Check
						r = row-1;
						c = col+1;
						do
						{
							if(get_board_status(r,c) == QUEEN_W || get_board_status(r,c) == BISHOP_W)
							{
								cout<<"\n\t\tChecked by Queen/Bishop north-east =>("<<r+1<<" , "<<c+1<<")";
								return 1;
							}
							else if(get_board_status(r,c) != EMPTY)
							{
								break;
							}
							c++;
							r--;
						}while(c < MAX_BOARD_LEN && r >= MIN_BOARD_LEN);
						
						
						// South-West Check
						r = row+1;
						c = col-1;
						do
						{
							if(get_board_status(r,c) == QUEEN_W || get_board_status(r,c) == BISHOP_W)
							{
								cout<<"\n\t\tChecked by Queen/Bishop south-west =>("<<r+1<<" , "<<c+1<<")";
								return 1;
							}
							else if(get_board_status(r,c) != EMPTY)
							{
								break;
							}
							c--;
							r++;
						}while(c >= MIN_BOARD_LEN && r < MAX_BOARD_LEN);
						
						
						// South-East Check
						r = row+1;
						c = col+1;
						do
						{
							if(get_board_status(r,c) == QUEEN_W || get_board_status(r,c) == BISHOP_W)
							{
								cout<<"\n\t\tChecked by Queen/Bishop south-east =>("<<r+1<<" , "<<c+1<<")";
								return 1;
							}
							else if(get_board_status(r,c) != EMPTY)
							{
								break;
							}
							c++;
							r++;
						}while(c < MAX_BOARD_LEN && r < MAX_BOARD_LEN);
						
						r = row;
						c = col;
						if(get_board_status(r+2,c+1) == KNIGHT_W)
						{
							cout<<"\n\t\tChecked by Knight =>("<<r+3<<" , "<<c+2<<")";
							return 1;
						}
						else if(get_board_status(r+2,c-1) == KNIGHT_W)
						{
							cout<<"\n\t\tChecked by Knight =>("<<r+3<<" , "<<c<<")";
							return 1;
						}
						else if(get_board_status(r-2,c+1) == KNIGHT_W)
						{
							cout<<"\n\t\tChecked by Knight =>("<<r-1<<" , "<<c+2<<")";
							return 1;
						}
						else if(get_board_status(r-2,c-1) == KNIGHT_W)
						{
							cout<<"\n\t\tChecked by Knight =>("<<r-1<<" , "<<c<<")";
							return 1;
						}
						else if(get_board_status(r+1,c+2) == KNIGHT_W)
						{
							cout<<"\n\t\tChecked by Knight =>("<<r+2<<" , "<<c+3<<")";
							return 1;
						}
						else if(get_board_status(r+1,c-2) == KNIGHT_W)
						{
							cout<<"\n\t\tChecked by Knight =>("<<r+2<<" , "<<c-1<<")";
							return 1;
						}
						else if(get_board_status(r-1,c+2) == KNIGHT_W)
						{
							cout<<"\n\t\tChecked by Knight =>("<<r<<" , "<<c+2<<")";
							return 1;
						}
						else if(get_board_status(r-1,c-2) == KNIGHT_W)
						{
							cout<<"\n\t\tChecked by Knight =>("<<r<<" , "<<c-1<<")";
							return 1;
						}
						
						return 0;
					}
					
				}
				else
				{
					for(row=MIN_BOARD_LEN;row<MAX_BOARD_LEN;row++)
					{
						for(col=MIN_BOARD_LEN;col<MAX_BOARD_LEN;col++)
						{
							if(get_board_status(row,col) == KING_W)
							{
								flag = 1;
								break;
							}
						}
						if(flag == 1)
							break;
					}
					
					
					r = row;
					c = col;
					if(get_board_status(r+1,c+1) == PAWN_B)		// North-Right Check - for Black Pawn
					{
						cout<<"\n\t\tChecked by Pawn North-East =>("<<r+2<<" , "<<c+2<<")";
						return 1;
					}
					else if(get_board_status(r+1,c-1) == PAWN_B)	// North-Left Check - for Black Pawn
					{
						cout<<"\n\t\tChecked by Pawn North-West =>("<<r+2<<" , "<<c<<")";
						return 1;
					}
					else
					{
						// North Check
						r = row-1;
						c = col;
						do
						{
							if(get_board_status(r,c) == QUEEN_B || get_board_status(r,c) == ROOK_B)
							{
								cout<<"\n\t\tChecked by Queen/Rook north =>("<<r+1<<" , "<<c+1<<")";
								return 1;
							}
							else if(get_board_status(r,c) != EMPTY)
							{
								break;
							}
							r--;
						}while(r >= MIN_BOARD_LEN);
						
						//South Check
						r = row+1;
						c = col;
						do
						{
							if(get_board_status(r,c) == QUEEN_B || get_board_status(r,c) == ROOK_B)
							{
								cout<<"\n\t\tChecked by Queen/Rook south =>("<<r+1<<" , "<<c+1<<")";
								return 1;
							}
							else if(get_board_status(r,c) != EMPTY)
							{
								break;
							}
							r++;
						}while(r < MAX_BOARD_LEN);
						
						// East Check
						r = row;
						c = col+1;
						do
						{
							if(get_board_status(r,c) == QUEEN_B || get_board_status(r,c) == ROOK_B)
							{
								cout<<"\n\t\tChecked by Queen/Rook east =>("<<r+1<<" , "<<c+1<<")";
								return 1;
							}
							else if(get_board_status(r,c) != EMPTY)
							{
								break;
							}
							c++;
						}while(c < MAX_BOARD_LEN);
						
						// West Check
						r = row;
						c = col-1;
						do
						{
							if(get_board_status(r,c) == QUEEN_B || get_board_status(r,c) == ROOK_B)
							{
								cout<<"\n\t\tChecked by Queen/Rook west =>("<<r+1<<" , "<<c+1<<")";
								return 1;
							}
							else if(get_board_status(r,c) != EMPTY)
							{
								break;
							}
							c--;
						}while(c >= MIN_BOARD_LEN);
						
						// North-West Check
						r = row-1;
						c = col-1;
						do
						{
							if(get_board_status(r,c) == QUEEN_B || get_board_status(r,c) == BISHOP_B)
							{
								cout<<"\n\t\tChecked by Queen/Bishop north-west =>("<<r+1<<" , "<<c+1<<")";
								return 1;
							}
							else if(get_board_status(r,c) != EMPTY)
							{
								break;
							}
							c--;
							r--;
						}while(c >= MIN_BOARD_LEN && r >= MIN_BOARD_LEN);
						
						
						// North-East Check
						r = row-1;
						c = col+1;
						do
						{
							if(get_board_status(r,c) == QUEEN_B || get_board_status(r,c) == BISHOP_B)
							{
								cout<<"\n\t\tChecked by Queen/Bishop north-east =>("<<r+1<<" , "<<c+1<<")";
								return 1;
							}
							else if(get_board_status(r,c) != EMPTY)
							{
								break;
							}
							c++;
							r--;
						}while(c < MAX_BOARD_LEN && r >= MIN_BOARD_LEN);
						
						
						// South-West Check
						r = row+1;
						c = col-1;
						do
						{
							if(get_board_status(r,c) == QUEEN_B || get_board_status(r,c) == BISHOP_B)
							{
								cout<<"\n\t\tChecked by Queen/Bishop south-west =>("<<r+1<<" , "<<c+1<<")";
								return 1;
							}
							else if(get_board_status(r,c) != EMPTY)
							{
								break;
							}
							c--;
							r++;
						}while(c >= MIN_BOARD_LEN && r < MAX_BOARD_LEN);
						
						
						// South-East Check
						r = row+1;
						c = col+1;
						do
						{
							if(get_board_status(r,c) == QUEEN_B || get_board_status(r,c) == BISHOP_B)
							{
								cout<<"\n\t\tChecked by Queen/Bishop south-east =>("<<r+1<<" , "<<c+1<<")";
								return 1;
							}
							else if(get_board_status(r,c) != EMPTY)
							{
								break;
							}
							c++;
							r++;
						}while(c < MAX_BOARD_LEN && r < MAX_BOARD_LEN);
						
						r = row;
						c = col;
						if(get_board_status(r+2,c+1) == KNIGHT_B)
						{
							cout<<"\n\t\tChecked by Knight =>("<<r+3<<" , "<<c+2<<")";
							return 1;
						}
						else if(get_board_status(r+2,c-1) == KNIGHT_B)
						{
							cout<<"\n\t\tChecked by Knight =>("<<r+3<<" , "<<c<<")";
							return 1;
						}
						else if(get_board_status(r-2,c+1) == KNIGHT_B)
						{
							cout<<"\n\t\tChecked by Knight =>("<<r-1<<" , "<<c+2<<")";
							return 1;
						}
						else if(get_board_status(r-2,c-1) == KNIGHT_B)
						{
							cout<<"\n\t\tChecked by Knight =>("<<r-1<<" , "<<c<<")";
							return 1;
						}
						else if(get_board_status(r+1,c+2) == KNIGHT_B)
						{
							cout<<"\n\t\tChecked by Knight =>("<<r+2<<" , "<<c+3<<")";
							return 1;
						}
						else if(get_board_status(r+1,c-2) == KNIGHT_B)
						{
							cout<<"\n\t\tChecked by Knight =>("<<r+2<<" , "<<c-1<<")";
							return 1;
						}
						else if(get_board_status(r-1,c+2) == KNIGHT_B)
						{
							cout<<"\n\t\tChecked by Knight =>("<<r<<" , "<<c+2<<")";
							return 1;
						}
						else if(get_board_status(r-1,c-2) == KNIGHT_B)
						{
							cout<<"\n\t\tChecked by Knight =>("<<r<<" , "<<c-1<<")";
							return 1;
						}
					
						return 0;
					}
					
				}
				
				return 0;
			}
			
			
};

/*
 * class pawn:
 * 			checks whether pawn is making the legal moves or not
 * 			(at this stage assigned no. of intial moves to pawn is 1,
 * 				but in actual scenario it may be 2 also.)
 * */
class pawns:public game_board
{
	public:
	
			int check(int from_row, int from_col, int to_row, int to_col, game_board game, int id)
			{
				// Straight move  check
				if(from_col == to_col)
				{
					if(id == 1)
					{
						if(to_row - from_row == 1 && game.get_board_status(to_row,to_col) == EMPTY)
						{
							return 1;
						}
					}
					else
					{
						if(from_row - to_row == 1 && game.get_board_status(to_row,to_col) == EMPTY)
						{
							return 1;
						}
					}
					
				}
				else if(from_col - to_col == 1 || to_col - from_col == 1)// Cross move for kill
				{
					if(id == 1)
					{
						if(to_row - from_row == 1 && game.get_board_status(to_row,to_col) != EMPTY)
						{
							return 1;
						}
					}
					else
					{
						if(from_row - to_row == 1 && game.get_board_status(to_row,to_col) != EMPTY)
						{
							return 1;
						}
					}
				}
				
				return 0;
			}
};

class rooks:public game_board
{
	public:
			
			int check(int from_row, int from_col, int to_row, int to_col, game_board game, int id)
			{
				int r, c;
				// Check for Vertical Movement of ROOK.
				if(from_row == to_row && from_col != to_col)
				{
					if(from_col < to_col)
					{
						r = from_row;
						c = from_col+1;
						do
						{
							if(c != to_col)
							{
								if(game.get_board_status(r,c) != EMPTY)
								{
									return 0;
								}
							}
							else
							{
								return 1;
							}
							c++;
						}while(1);
					
						return 1;
					}
					else if(from_col > to_col)
					{
						r = from_row;
						c = from_col-1;
						do
						{
							if(c != to_col)
							{
								if(game.get_board_status(r,c) != EMPTY)
								{
									return 0;
								}
							}
							else
							{
								return 1;
							}
							c--;
						}while(1);
					
						return 1;
					}
				}
				else if(from_row != to_row && from_col == to_col )	// Check for Horizontal Movement of ROOK.
				{
					if(from_row < to_row)
					{
						r = from_row+1;
						c = from_col;
						do
						{
							if(r != to_row)
							{
								if(game.get_board_status(r,c) != EMPTY)
								{
									return 0;
								}
							}
							else
							{
								return 1;
							}
							r++;
						
						}while(1);
					
						return 1;
					}
					else if(from_row > to_row)
					{
						r = from_row-1;
						c = from_col;
						do
						{
							if(r != to_row)
							{
								if(game.get_board_status(r,c) != EMPTY)
								{
									return 0;
								}
							}
							else
							{
								return 1;
							}
							r--;
						
						}while(1);
					
						return 1;
					}
				}
				
				return 0;
			}
};

class bishops:public game_board
{
	public:
			
			int check(int from_row, int from_col, int to_row, int to_col, game_board game, int player_id)
			{
				int r,c;
				r = from_row - to_row;
				if(from_row - to_row < MIN_BOARD_LEN)
				{
					r = to_row - from_row;
				}
				
				c = from_col - to_col;
				if(from_col - to_col < MIN_BOARD_LEN)
				{
					c = to_col - from_col;
				}
				
				if(r == c)
				{
					if(from_row > to_row)
					{
						if(from_col > to_col)
						{
							r = from_row - 1;
							c = from_col - 1;
							
							do
							{
								if(r != to_row && c!=to_col)
								{
									if(game.get_board_status(r,c) != EMPTY)
									{
										return 0;
									}
								}
								else
								{
									return 1;
								}
								r--;
								c--;
							}while(1);
							
							return 1;
						}
						else if(from_col < to_col)
						{
							r = from_row - 1;
							c = from_col + 1;
							
							do
							{
								if(r != to_row && c!=to_col)
								{
									if(game.get_board_status(r,c) != EMPTY)
									{
										return 0;
									}
								}
								else
								{
									return 1;
								}
								r--;
								c++;
							}while(1);
							
							return 1;
						}
					}
					else if(from_row < to_row)
					{
						if(from_col > to_col)
						{
							r = from_row + 1;
							c = from_col - 1;
							
							do
							{
								if(r != to_row && c!=to_col)
								{
									if(game.get_board_status(r,c) != EMPTY)
									{
										return 0;
									}
								}
								else
								{
									return 1;
								}
								r++;
								c--;
							}while(1);
							
							return 1;
						}
						else if(from_col < to_col)
						{
							r = from_row + 1;
							c = from_col + 1;
							
							do
							{
								if(r != to_row && c!=to_col)
								{
									if(game.get_board_status(r,c) != EMPTY)
									{
										return 0;
									}
								}
								else
								{
									return 1;
								}
								r++;
								c++;
							}while(1);
							
							return 1;
						}
					}
				}
				
				return 0;
			}
};

/*
 * class queens:
 * 			It implements the methods of both the bishops & the rooks, hence it checks for both.
 * */
class queens:public rooks, public bishops
{
	public:
			int check(int from_row, int from_col, int to_row, int to_col, game_board game, int id)
			{
				rooks rook;
				bishops bishop;
				int flag = rook.check(from_row, from_col, to_row, to_col, game, id);
				if(flag == 0)
				{
					flag = bishop.check(from_row, from_col, to_row, to_col, game, id);
				}
				
				return flag;
			}
};

class kings:public game_board
{
	public:
			int check(int from_row, int from_col, int to_row, int to_col, game_board game, int player_id)
			{
				if(from_row == to_row)
					if((from_col - to_col == 1 || to_col - from_col == 1) )//&& (game.get_board_status(to_row,to_col) == EMPTY))
						return 1;
				
				if(from_col == to_col)
					if((from_row - to_row == 1 || to_row - from_row == 1) )//&& (game.get_board_status(to_row,to_col) == EMPTY))
						return 1;
				
				if(from_row - to_row == 1 || to_row - from_row == 1)
					if((from_col - to_col == 1 || to_col - from_col == 1) )//&& (game.get_board_status(to_row,to_col) == EMPTY))
						return 1;
				
				
				return 0;
			}
};

class knights:public game_board
{
	public:
			int check(int from_row, int from_col, int to_row, int to_col, game_board game, int player_id)
			{
				if(from_row - to_row == 2 || to_row - from_row == 2)
				{
					if(from_col - to_col == 1 || to_col - from_col == 1)
						return 1;
				}
				else if(from_col - to_col == 2 || to_col - from_col == 2)
					if(from_row - to_row == 1 || to_row - from_row == 1)
						return 1;
				return 0;
			}
};

/*
 * class matches:
 * 				implements player, as at the start it creates players profile.
 * 				implements all the chess peices on the board.
 * 				implements class game_board, which assigns chess board from the current match
 * 
 * */
class matches:public players, public pawns, public knights, public queens, public kings
{
	players player;
	game_board game;
	pawns pawn;
	rooks rook;
	bishops bishop;
	knights knight;
	queens queen;
	kings king;
				
	public:
	
			// Checks whether the move made by individual chess peice is legitimate or not.
			int valid_move(chess individual, int from_row, int from_col, int to_row, int to_col, int id)
			{
				int flag = 0;
				
				if(individual == PAWN_B || individual == PAWN_W)
				{
					flag = pawn.check(from_row, from_col, to_row, to_col,game,id);
					return flag;
				}
				else if(individual == KNIGHT_W ||individual == KNIGHT_B)
				{
					flag = knight.check(from_row, from_col, to_row, to_col,game,id);
					return flag;
				}
				else if(individual == ROOK_W||individual == ROOK_B)
				{
					flag = rook.check(from_row, from_col, to_row, to_col,game,id);
					return flag;
				}
				else if(individual == BISHOP_W||individual == BISHOP_B)
				{
					flag = bishop.check(from_row, from_col, to_row, to_col,game,id);
					return flag;
				}
				else if(QUEEN_W||QUEEN_B)
				{
					flag = queen.check(from_row, from_col, to_row, to_col,game,id);
					return flag;
				}
				else if(KING_W||KING_B)
				{
					flag = king.check(from_row, from_col, to_row, to_col,game,id);
					return flag;
				}
				return flag;
			}
			
			// Mechannics involved for peice movement for player1
			int chance_player1(int from_row, int from_col, int to_row, int to_col)
			{
				
				/*
						-1 ==> ERROR: Illegal source!
					 	-2 ==> ERROR: Illegal destination!
						-3 ==> ERROR: Empty block selected!
						-4 ==> ERROR: It's Oponnents player!"
						-5 ==> ERROR: Illegal move!
				*/
				chess src_individual, dest_individual;
				
				if(from_row < MIN_BOARD_LEN || from_col < MIN_BOARD_LEN || from_row > MAX_BOARD_LEN - 1 || from_col > MAX_BOARD_LEN - 1)
				{
					return -1;
				}
				else if(to_row < MIN_BOARD_LEN || to_col < MIN_BOARD_LEN || to_row > MAX_BOARD_LEN - 1 || to_col > MAX_BOARD_LEN - 1)
				{
					return -2;
				}
				else
				{
					src_individual = game.get_board_status(from_row,from_col);
					dest_individual = game.get_board_status(to_row,to_col);
					
					if(src_individual == EMPTY)
					{
						return -1;
					}
					else
					{
						if(dest_individual == PAWN_W || dest_individual == KNIGHT_W || dest_individual == ROOK_W || dest_individual == BISHOP_W || dest_individual == QUEEN_W || dest_individual == KING_W)
						{
							return -2;
						}
						else if(src_individual == PAWN_B || src_individual == KNIGHT_B || src_individual == ROOK_B || src_individual == BISHOP_B || src_individual == QUEEN_B || src_individual == KING_B)
						{
							return -4;
						}
						else if(!valid_move(src_individual,from_row,from_col,to_row,to_col,1))
						{
							return -5;
						}
						else if(dest_individual == EMPTY)
						{
							return 1;
						}
						else if(dest_individual == KING_B)
						{
							return 3;
						}
						else
						{
							return 2;
						}
					}
				}
			}
			
			// Mechannics involved for peice movement for player2
			int chance_player2(int from_row, int from_col, int to_row, int to_col)
			{
				/*
						-1 ==> ERROR: Illegal source!
					 	-2 ==> ERROR: Illegal destination!
						-3 ==> ERROR: Empty block selected!
						-4 ==> ERROR: It's Oponnents player!"
						-5 ==> ERROR: Illegal move!
				*/
				
				chess src_individual, dest_individual;
				
				if(from_row < MIN_BOARD_LEN || from_col < MIN_BOARD_LEN || from_row > MAX_BOARD_LEN - 1 || from_col > MAX_BOARD_LEN - 1)
				{
					return -1;
				}
				else if(to_row < MIN_BOARD_LEN || to_col < MIN_BOARD_LEN || to_row > MAX_BOARD_LEN - 1 || to_col > MAX_BOARD_LEN - 1)
				{
					return -2;
				}
				else
				{
					src_individual = game.get_board_status(from_row,from_col);
					dest_individual = game.get_board_status(to_row,to_col);
					
					if(src_individual == EMPTY)
					{
						return -3;
					}
					else
					{
						if(dest_individual == PAWN_B || dest_individual == KNIGHT_B || dest_individual == ROOK_B || dest_individual == BISHOP_B || dest_individual == QUEEN_B || dest_individual == KING_B)
						{
							return -2;
						}
						else if(src_individual == PAWN_W || src_individual == KNIGHT_W || src_individual == ROOK_W || src_individual == BISHOP_W || src_individual == QUEEN_W || src_individual == KING_W)
						{
							return -4;
						}
						else if(!valid_move(src_individual,from_row,from_col,to_row,to_col,2))
						{
							return -5;
						}
						else if(dest_individual == EMPTY)
						{
							return 1;
						}
						else if(dest_individual == KING_W)
						{
							return 3;
						}
						else
						{
							return 2;
						}
					}
				}
			}
			
			// Accepts the input from players
			void get_input_from_players(char *player_name, int *from_row, int *from_col, int *to_row, int *to_col)
			{
				cout<<"\n\n>> "<<player_name<<"'s move!";
				cout<<"\n\tFrom Row:\t";
				cin>>(*from_row);
				(*from_row) -= 1;
				cout<<"\n\tFrom Col:\t";
				cin>>(*from_col);
				(*from_col) -= 1;
				cout<<"\n\tTo Row:\t\t";
				cin>>(*to_row);
				(*to_row) -= 1;
				cout<<"\n\tTo Col:\t\t";
				cin>>(*to_col);
				(*to_col) -= 1;
			}
			
			// Creates & starts new match!
			void start_match()
			{
				int count, from_row, from_col, to_row, to_col;
				int status;
				
				player.set_player1();
				player.set_player2();
				
				cout<<"\n\n\tWhite --> "<<player.get_player1();
				cout<<"\n\n\tBlack --> "<<player.get_player2();
				
				game.init_game();
				
				for(count=1;;)
				{
					game.draw_board();
					if(count%2 == 1)
					{
						get_input_from_players(player.get_player1(), &from_row, &from_col, &to_row, &to_col);
						status = chance_player1(from_row,from_col,to_row,to_col);
					}
					else
					{
						get_input_from_players(player.get_player2(), &from_row, &from_col, &to_row, &to_col);
						status = chance_player2(from_row,from_col,to_row,to_col);
					}
					
					cout<<"\n\n\t*************************************************";
					if(status == -1)
					{
						cout<<"\n\t\tERROR: Illegal source!";
					}
					else if(status == -2)
					{
						cout<<"\n\t\tERROR: Illegal destination!";
					}
					else if(status == -3)
					{
						cout<<"\n\t\tERROR: Empty block selected!";
					}
					else if(status == -4)
					{
						cout<<"\n\t\tERROR: It's Oponnents player!";
					}
					else if(status == -5)
					{
						cout<<"\n\t\tERROR: Illegal move!";
					}
					else if(status == 1)
					{
						chess from_individual = game.get_board_status(from_row,from_col);
						chess to_individual = game.get_board_status(to_row,to_col);
						
						game.make_move(from_row,from_col,to_row,to_col);
						
						if(game.checked(count-1))
						{
							if(count%2 == 1)
								cout<<"\n\t\tAre r u trying to surrender?!?";
							else
								cout<<"\n\t\tYou can't surrender!!!";
							
							game.recover(from_individual, to_individual, from_row, from_col, to_row, to_col);
						}
						else
						{
							cout<<"\n\t\tSmart move!";
							if(game.checked(count))
							{
								if(count%2 == 1)
									cout<<"\n\t\t"<<player.get_player2()<<" , "<<player.get_player1()<<"  CHECKED you!!!";
								else
									cout<<"\n\t\t"<<player.get_player1()<<" , "<<player.get_player2()<<"  CHECKED you!!!";
								
							}
							count++;
						}
						
					}
					else if(status == 2)
					{
						chess from_individual = game.get_board_status(from_row,from_col);
						chess to_individual = game.get_board_status(to_row,to_col);
						
						game.make_move(from_row,from_col,to_row,to_col);
						
						if(game.checked(count-1))
						{
							if(count%2 == 1)
								cout<<"\n\t\tAre r u trying to surrender?!?";
							else
								cout<<"\n\t\tYou can't surrender!!!";
							
							game.recover(from_individual, to_individual, from_row, from_col, to_row, to_col);
						}
						else
						{
							cout<<"\n\t\tGreat Kill!";
							if(game.checked(count))
							{
								if(count%2 == 1)
									cout<<"\n\t\t"<<player.get_player2()<<" , "<<player.get_player1()<<"  CHECKED you!!!";
								else
									cout<<"\n\t\t"<<player.get_player1()<<" , "<<player.get_player2()<<"  CHECKED you!!!";
								
							}
							count++;
						}
					}
					else if(status == 3)
					{
						if(count%2 == 1)
							cout<<"\n\n\t\tCongratulations "<<player.get_player1()<<" , you WON!\n\n";
						else
							cout<<"\n\n\t\tCongratulations "<<player.get_player2()<<" , you WON!\n\n";
							
						break;
					}
					
					cout<<"\n\n\t*************************************************";
				}
				
				cout<<"\n\n\t*************************************************";
			}
};

int main()
{
	matches match;
	welcome entry;
	
	entry.welcome_msg();
//	delay(3000);
	match.start_match();
	
	return 0;
}
