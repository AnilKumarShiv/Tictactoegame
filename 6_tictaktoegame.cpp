/* ***************   Tic Tac Toe  ******************* */

#include<iostream>
using namespace std;

char arr[3][3]={
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    };
char turn='X';
int row,column,i,j;
bool draw = false;

void display_arr(){
    system("cls");
    cout<<"\n\t\t\t==============================\n";
    cout<<"\t\t\t\tTIC TAK TOE GAME\n";
    cout<<"\t\t\t==============================\n";

    cout<<"\t\tPlayer1 [X]\n";
    cout<<"\t\tPlayer2 [0]\n\n";

    cout<<"\t\t\t     |       |       \n";
    cout<<"\t\t\t  "<<arr[0][0]<<"  |   "<<arr[0][1]<<"   |   "<<arr[0][2]<<"   \n";
    cout<<"\t\t\t_____|_______|_______\n";
    cout<<"\t\t\t     |       |       \n";
   cout<<"\t\t\t  "<<arr[1][0]<<"  |   "<<arr[1][1]<<"   |   "<<arr[1][2]<<"   \n";
    cout<<"\t\t\t_____|_______|_______\n";
    cout<<"\t\t\t     |       |       \n";
    cout<<"\t\t\t  "<<arr[2][0]<<"  |   "<<arr[2][1]<<"   |   "<<arr[2][2]<<"   \n";
    cout<<"\t\t\t     |       |       \n";
}
    
 void player_arr(){
        int  choice;
        if(turn=='X' || turn=='x')
        cout<<"\t\tPlayer1 [X] turn :";
        // cin>>choice;

        if(turn=='O' || turn=='o')
        cout<<"\t\tPlayer2 [O] turn :"; 
        cin>>choice;


  
    switch(choice)
     {
        int  choice;
        case 1: row=0;column=0;
        break;
        case 2: row=0;column=1;
        break;
        case 3: row=0;column=2;
        break;
        case 4: row=1;column=0;
        break;
        case 5: row=1;column=1;
        break;
        case 6: row=1;column=2;
        break;
        case 7: row=2;column=0;
        break;
        case 8: row=2;column=1;
        break;
        case 9: row=2;column=2;
        break;
        
        default:  cout<<"Invalid Number";
         break;
     }
     if(turn=='X' && arr[row][column]!='X' && arr[row][column]!='O'){
     arr[row][column]='X';
     turn='O';
    }
    else if(turn=='O' &&  arr[row][column]!='X' && arr[row][column]!='O'){
     arr[row][column]='O';
     turn='X';
    }
    else{
        cout<<"\n\tBox already filled, please try again...\n\n";
        player_arr();
    }
   
     display_arr();

}

bool gameover(){

// -----------   game win -------------
    for(i=0;i<3;i++){
        if(arr[i][0]==arr[i][1] && arr[i][0]==arr[i][2] || arr[0][i]==arr[1][i] && arr[0][i]==arr[2][i] )
        return false;

        if(arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]  ||  arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0])
        return false;

        // if(arr[0][0] == arr[1][1] && arr[0][1] == arr[2][2])
        // return false;

    }
// -------------- game continue ------------
     for(i=1;i<3;i++)
     for(j=1;j<3;j++)
     if(arr[i][j] != 'X' && arr[i][j] != 'O')
     return true;

 //  -------------- game draw ----------------
     draw = true;
     return false;
}

int main(){

     while(gameover()){  

     display_arr();
     player_arr();
     gameover();
     }
    
    if(turn == 'X' && draw == false)
    cout<<"Player2 [X] Win!! Congratulations\n";
    else if(turn == 'O'  && draw == false)
    cout<<"Player1 [X] Win!! Congratulations\n";
    else {
        cout<<"Game draw!!\n";
    }
    return 0;

}