#include<iostream>
using namespace std;

//globally defined
string board[9] = {" ", " ", " ", " ", " ", " ", " ", " ", " "}; 
int player = 1;   
int position = 0;

//Introduction function
void intro(){
    cout<<"Press Enter to begin: ";
	getchar(); // reads a single character from the standard input stream
	cout<<"\n";
    cout<<"Tic-Tac-Toe\n\n";
    cout<<"Player 1) X\n";
    cout<<"Player 2) O\n\n";  
}

//Function to determine the winner
bool is_winner(){
    bool winner = false;
	
    //checking the rows
	if((board[0]==board[1]) && (board[1]==board[2]) && board[0] != " ") {
		winner = true;
    }
	else if ((board[3] == board[4]) && (board[4] == board[5]) && board[3] != " ") {
    winner = true;
    } 
	else if ((board[6] == board[7]) && (board[7] == board[8]) && board[6] != " ") {
    winner = true;
  	} 

	//checking the columns
	else if((board[0]==board[3]) && (board[3]==board[6]) && board[0] != " "){
		winner = true;
	}
	else if ((board[1] == board[4]) && (board[4] == board[7]) && board[1] != " "){
    winner = true;
 	 } 
	else if ((board[2] == board[5]) && (board[5] == board[8]) && board[2] != " ") {
    winner = true;
  	}

	//checking the diagonals
	else if ((board[0]==board[4]) && (board[4]==board[8]) && board[0] != " "){
		winner = true;
    }
	else if ((board[2]==board[4]) && (board[4]==board[6]) && board[2] != " "){
		winner = true;
	}
	return winner;
}

//Function to determine whether board is filled or not
bool is_filled(){
    bool filled = true;
	for(int i = 0; i<9; i++)
	{
		if(board[i]==" ")
			filled = false;
	}
	return filled;
}

//Function to display board
void display_board(){
  cout<<  "     |     |      \n";
  cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";
  cout << "_____|_____|_____ \n";
  cout << "     |     |      \n";
  cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";
  cout << "_____|_____|_____ \n";
  cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
  cout << "     |     |      \n";
  cout << "\n";
}

//Function to set the position of the players
void set_position(){
	cout<<"Player "<<player<<"'s turn (Enter: 1-9)";   
	while(!(cin>>position)){
		cout<<"Please enter a valid number between (1-9)"<<endl;
		cin.clear();  //flushing the buffer
    	cin.ignore();  
	}
	cout<<endl;
	while (board[position -1] != " "){
    cout<<"The position is already filled\nPlease try again\n";
    cout << "Player " << player << "'s Turn (Enter 1-9): ";
    cin>>position;
    cout<<"\n";	
    }
}

//Function to update the board
void update_board(){
  if (player % 2 == 1){
    board[position - 1] = "X";  
  }
  else{
    board[position - 1] = "O";
  }
}

//Function to change the player in the game
void change_player(){
  if (player == 1){
    player++;
  }
  else{
    player--;
  }
}

//Function to invoke all functions required to play the game turnwise till end
void take_turn(){
	while(!is_winner() && !is_filled())  {
		//calling the functions
		set_position();
		update_board();
		change_player();
	    display_board();
	}
}

//Function to display result
void result(){
    change_player();
	if(is_winner()){
		cout<<"Player "<<player<<" is a winner!"<<endl;	
	}
	else if(is_filled()){
		cout<<"There is a tie!"<<endl;
	}
}

int main(){
    //calling the functions
    intro();
    take_turn();
	result();
    return 0;
}