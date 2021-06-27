#include <iostream>
#include <cstdlib>
#include <string>
#include "Stack.h"

struct offsets{
	int x,y;
	
};

struct Item{
	int x,y,dir;
};

enum directions{N=0,NE,E,SE,S,SW,W,NW};

initlize(offsets* move){
	move[N].x=0; move[N].y=-1;
	move[NE].x=1; move[NE].y=-1;
	move[E].x=1; move[E].y=0;
	move[SE].x=1; move[SE].y=1;
	move[S].x=0; move[S].y=1;
	move[SW].x=-1; move[SW].y=1;
	move[W].x=-1; move[W].y=0;
	move[NW].x=-1; move[NW].y=-1;
}


void complete(Stack<Item> stk){
	int count =1;
	string var[9];
	var[0]="N";
	var[1]="NE";
	var[2]="E";
	var[3]="SE";
	var[4]="S";
	var[5]="SW";
	var[6]="W";
	var[7]="NW";
	var[8]="Arrive";
	
	Stack<Item> stk_ans;
	while(!stk.IsEmpty()){
		Item temp = stk.Pop();
		stk_ans.Push(temp);
	}
	while(!stk_ans.IsEmpty()){
		Item temp = stk_ans.Pop();
		cout<<"Step"<<count++<<" :("<<temp.x<<","<<temp.y<<","<<var[temp.dir]<<")\n";
	}
	cout<<"Completed\n";
}

int main(void){
	Stack<Item> stk;
	offsets move[8];
	initlize(move);
	//--------------input-------------
	int m=0,n=0;                               //m一維是左右,n二維上下 
	cin>>m>>n;                  //出口:m+1,n 
	int maze[m+2][n+2],mark[m+2][n+2]={0};
	for(int j=0;j<n+2;j++){
		for(int i=0;i<m+2;i++){
			if(i==0) maze[i][j]=2;
			else if(j==0) maze[i][j]=2;
			else if(i==(m+1)) maze[i][j]=2;
			else if(j==(n+1)) maze[i][j]=2;
			else cin>>maze[i][j];
		}
	} //0 1 0 1 0 1 0 1 0 1
	if(maze[1][1]!=0){
		cout<<"Start point error!";
		return 0;
	}
	
	/*for(int j=0;j<n+2;j++){
		for(int i=0;i<m+2;i++){
			cout<<maze[i][j]<<" ";
		}
		cout<<endl;
	}*/
	//---------------------------------
	Item start; start.x=1;start.y=1; start.dir=E;
	stk.Push(start);
	mark[start.x][start.y]=1;
	
	while(!stk.IsEmpty()){
		Item current=stk.Pop();
		while(current.dir<8){
			int next_x=current.x + move[current.dir].x , next_y=current.y+move[current.dir].y; 
			if(next_x==(m+1)&&next_y==n){
				stk.Push(current);
				Item final;
				final.x=next_x; final.y=next_y; final.dir=8;
				stk.Push(final);
				complete(stk);
				return 0;
			}
			else if(mark[next_x][next_y]==0 && maze[next_x][next_y]==0){
				mark[next_x][next_y]=1;  //record the previous step.
				stk.Push(current);  
				current.x=next_x;
				current.y=next_y;
				current.dir=N;                 //start with the new step.
			}
			else{
				current.dir++;
			}
		}
	}
	cout<<"impossible to arrive\n";
	return 0;
	
}

/*
5 5
0 0 1 1 0
0 1 0 0 0
0 0 1 1 1
0 1 1 0 1
1 0 0 1 0
*/

/*
15 12
0 1 0 0 0 1 1 0 0 0 1 1 1 1 1 
1 0 0 0 1 1 0 1 1 1 0 0 1 1 1
0 1 1 0 0 0 0 1 1 1 1 0 0 1 1
1 1 0 1 1 1 1 0 1 1 0 1 1 0 0
1 1 0 1 0 0 1 0 1 1 1 1 1 1 1
0 0 1 1 0 1 1 1 0 1 0 0 1 0 1
0 0 1 1 0 1 1 1 0 1 0 0 1 0 1
0 1 1 1 1 0 0 1 1 1 1 1 1 1 1
0 0 1 1 0 1 1 0 1 1 1 1 1 0 1
1 1 0 0 0 1 1 0 1 1 0 0 0 0 0
0 0 1 1 1 1 1 0 0 0 1 1 1 1 0
0 1 0 0 1 1 1 1 1 0 1 1 1 1 0

*/ 


/*
11 11
0 1 0 0 0 1 1 0 0 0 0
1 0 0 0 1 1 0 1 1 1 1 
0 1 1 0 0 0 0 1 1 1 1
1 1 0 1 1 1 1 0 1 1 1
1 1 0 1 0 0 1 0 1 1 1
0 0 1 1 0 1 1 1 0 1 1
0 0 1 1 0 1 1 1 0 1 1
0 1 1 1 1 0 0 1 1 1 1 
0 0 1 1 0 1 1 0 0 1 1
1 1 0 0 0 1 1 0 1 0 1
1 0 1 1 1 1 1 1 1 0 0
*/


