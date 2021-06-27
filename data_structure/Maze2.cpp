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
//	for(int i=0;i<8;i++){
//		cout<<move[i].x<<"  "<<move[i].y<<endl;
	//}
}


void complete(Stack<Item> stk){
	
	string var[8];
	var[0]="N";
	var[1]="NE";
	var[2]="E";
	var[3]="SE";
	var[4]="S";
	var[5]="SW";
	var[6]="W";
	var[7]="NW";
	
	cout<<"Completed\n";
	Stack<Item> stk_ans;
	while(!stk.IsEmpty()){
		Item temp = stk.Pop();
		stk_ans.Push(temp);
	}
	while(!stk_ans.IsEmpty()){
		Item temp = stk_ans.Pop();
		cout<<"temp.x="<<temp.x<<" \ntemp.y="<<temp.y<<" \ntemp.dir="<<var[temp.dir]<<endl;
	}
}

void bug_print(Item current_stance,int d,int cur_x,int cur_y){
	cout<<"Current:\n";
	cout<<"Current_x: "<<current_stance.x;
	cout<<"\nCurrent_y: "<<current_stance.y;
	cout<<"\nCurrent_dir: "<<d<<endl;
	cout<<"Cur_x:"<<cur_x;
	cout<<"\nCur_y:"<<cur_y<<endl<<endl;
}

int main(void){
	Stack<Item> stk;
	offsets move[8];
	initlize(move);
	//--------------input-------------
	int m=0,n=0;                               //m�@���O���k,n�G���W�U 
	cin>>m>>n;                  //�X�f:m+1,n 
	int maze[m+2][n+2],mark[m+2][n+2]={0};
	for(int j=0;j<m+2;j++){
		for(int i=0;i<n+2;i++){
			if(i==0) maze[i][j]=1;
			else if(j==0) maze[i][j]=1;
			else if(i==(m+1)) maze[i][j]=1;
			else if(j==(n+1)) maze[i][j]=1;
			else
				cin>>maze[i][j];
		}
	}
	for(int i=0;i<m+2;i++){
		for(int j=0;j<n+2;j++){
			cout<<"i="<<i<<" j="<<j<<"maze:";
			cout<<maze[i][j]<<"\t";
		}
		cout<<endl;
	}
	cout<<maze[3][1]<<endl;
	//---------------------------------
	Item start; start.x=1;start.y=1; start.dir=E;
	stk.Push(start);
	mark[start.x][start.y]=1;
	
	while(!stk.IsEmpty()){
		Item current=stk.Pop();
		int d = current.dir , cur_x=current.x , cur_y=current.y;
		while(d<8){
			bug_print(current,d,cur_x,cur_y);
			int next_x=cur_x + move[d].x , next_y=cur_y+move[d].y; 
			if(next_x==(m+1)&&next_y==n){
				stk.Push(current);
				Item final;
				final.x=next_x; final.y=next_y; final.dir=E;
				stk.Push(final);
				complete(stk);
				return 0;
			}
			else if(mark[next_x][next_y]==0 && maze[next_x][next_y]==0){
				mark[next_x][next_y]=1;  //record the previous step.
				stk.Push(current);
				current.dir++;    
				cur_x=next_x;
				cur_y=next_y;
				d=N;                 //start with the new step.
			}
			else{
				d++;
			}
		}
	}
	cout<<"Failed\n";
	return 0;
	
}
