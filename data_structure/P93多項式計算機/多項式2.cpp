#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

int bubble(int ccoe[][100],int ppow[][100],int zhu_count,bool from){
	int i,j,temp;
	if(ppow[0][0]==(-99)){
		for(i=0;i<100;i++){
			ppow[0][i]=ccoe[1][i];   //補足愚蠢的錯誤DASH 
		}
	}
	int temp2=zhu_count;
	for(i=0;i<temp2;i++){
		if(ccoe[0][i]==0) {
			ppow[0][i]=-2; 
				if(from) 
				zhu_count--; 
			}
		}
	for(i=0;i<temp2;i++){
		for(j=0;j<temp2;j++){
			if(ppow[0][j]<ppow[0][j+1]){
				temp = ppow[0][j];
				ppow[0][j]=ppow[0][j+1];
				ppow[0][j+1]=temp;
				temp = ccoe[0][j];
				ccoe[0][j]=ccoe[0][j+1];
				ccoe[0][j+1]=temp;
			}
		}
	}
	return zhu_count;
}
int dash(int ccoe[][100],int ppow[][100],int ker_count,int zhu_count){
	int i,j,k,l,m,no[2][100]={-99};
	int count_temp=zhu_count;
	int ori_ker[2][100],zhu_cal[2][100];
	
	for(i=0;i<ker_count;i++){
		ori_ker[0][i]=ccoe[1][i];
		ori_ker[1][i]=ppow[1][i];
	}
	for(i=0;i<zhu_count;i++){
		zhu_cal[0][i]=ccoe[0][i];
		zhu_cal[1][i]=ppow[0][i];
	}
	zhu_count=0;
	bool found = false;
	i=0;
	while(zhu_cal[1][0]>=ori_ker[1][0]){
		ccoe[0][i]=zhu_cal[0][0]/ori_ker[0][0];          //餘式 
		ppow[0][i]=zhu_cal[1][0]-ori_ker[1][0];
		zhu_count++;
		for(j=0;j<ker_count;j++){
			ccoe[1][j]*=ccoe[0][i];                      //減式 
			ppow[1][j]+=ppow[0][i];              
	}
		for(m=0;m<ker_count;m++){
				found = false;
				for(j=0;j<zhu_count;j++){
					if(zhu_cal[1][j]==ppow[1][m]){
					zhu_cal[0][j]-=ccoe[1][m];
					found=true;
					}
				}
				if(!found){
					zhu_cal[0][zhu_count+1]=(ccoe[1][m])*(-1);
					zhu_cal[0][zhu_count+1]=ppow[1][m];
					zhu_count++;	
			}	
	}
	//zhu_cal-ccoe[1].ppow[1]
		bubble(zhu_cal,no,count_temp,false);
		i++;
	}
	return zhu_count;
}


int cross(int ccoe[][100],int ppow[][100],int ker_count,int zhu_count){
	int temp_ker_count = ker_count,counted_ker[2][100],temp_ccoe0_ppow0[2][100];
	int i,j,k,l,m;
	bool found=false;
	for(i=0;i<zhu_count;i++){                           //temp_zhu[0] = ccoe  ,temp_zhu[1] = ppow
	temp_ccoe0_ppow0[0][i]=ccoe[0][i];
	temp_ccoe0_ppow0[1][i]=ppow[0][i];
	}
	for(i=0;i<ker_count;i++){
		if(i==0){
			for(j=0;j<zhu_count;j++){
			ccoe[0][j]*=ccoe[1][i];
			ppow[0][j]+=ppow[1][i];
	}
		}
		else{
			for(l=0;l<zhu_count;l++){
				counted_ker[0][l]=temp_ccoe0_ppow0[0][l];
				counted_ker[1][l]=temp_ccoe0_ppow0[1][l];
			}
			for(j=0;j<zhu_count;j++){
			counted_ker[0][j]*=ccoe[1][i];
			counted_ker[1][j]+=ppow[1][i];
		}
			for(k=0;k<ker_count;k++){
				found = false;
				for(j=0;j<zhu_count;j++){
					if(counted_ker[1][k]==ppow[0][j]){
					ccoe[0][j]+=counted_ker[0][k];
					found=true;
					}
				}
			if(!found){
			ccoe[0][zhu_count+1]=counted_ker[0][k];
			ppow[0][zhu_count+1]=counted_ker[1][k];
			zhu_count++;	
			}
		}
		zhu_count=bubble(ccoe,ppow,zhu_count,true);
		}
	}
	return zhu_count;
}




int cal(string str,int ccoe[][100],int ppow[][100],int zhu_count,int ker_count){
	int i=0,j=0;
	bool found=false;
	int temp_zhu[2][100]={-1};
	for(i=0;i<zhu_count;i++){
		temp_zhu[0][i]=ccoe[0][i];      //temp_zhu複製的主方程式，0=ccoe 1=ppow 
		temp_zhu[1][i]=ppow[0][i];
	}
	if(str=="+"){
			for(i=0;i<ker_count;i++){
				found = false;
				for(j=0;j<zhu_count;j++){
					if(ppow[1][i]==ppow[0][j]){
					ccoe[0][j]+=ccoe[1][i];
					found=true;
					}
				}
			if(!found){
			ccoe[0][zhu_count+1]=ccoe[1][i];
			ppow[0][zhu_count+1]=ppow[1][i];
			zhu_count++;	
			}
		}
		zhu_count=bubble(ccoe,ppow,zhu_count,true);
		}
	else if(str=="-"){
			for(i=0;i<ker_count;i++){
				found = false;
				for(j=0;j<zhu_count;j++){
					if(ppow[1][i]==ppow[0][j]){
					ccoe[0][j]-=ccoe[1][i];
					found=true;
					}
				}
				if(!found){
					ccoe[0][zhu_count+1]=(ccoe[1][i])*(-1);
					ppow[0][zhu_count+1]=ppow[1][i];
					zhu_count++;	
			}	
	}
		zhu_count=bubble(ccoe,ppow,zhu_count,true);
		}
	else if(str=="*"){
	    zhu_count=cross(ccoe,ppow,ker_count,zhu_count);
	}
	else if(str=="/"){
		zhu_count=dash(ccoe,ppow,ker_count,zhu_count);
	}
	return zhu_count;	
	}

void getnum(string str,int j,int ccoe[][100],int ppow[][100],int zhu){
	int i=0;
	string coe="",pow="";
	//取得係數 
	if(str.at(0) == '+'){
		i=1;}
		if(str.find('*')!= string::npos){           //是否係數為1 
		while(str.at(i)!= '*'){
		coe+=str[i];
		i++;
		}
	}
		else if(str.find('x')== string::npos&&str.find('^')==string::npos){      //常數
		 coe = str.substr(i);
		 pow = "0";
		}
		else{                                      //若係數為1，是正是負 
			if(str.at(0)=='-')
			ccoe[zhu][j]=-1;
			else if(str.find('x')== string::npos)
			coe=str.substr(1);
			else
			ccoe[zhu][j]=1;
		}
	//取得係數 coe字串 
		if(str.find('^')!= string::npos)
		pow = str.substr((str.find('^')+1));
		
		else if(str.find('x')!=string::npos) ppow[zhu][j]=1;
		else ppow[zhu][j]=0;
	//取得次方 pow字串 
	if(coe!="")
		ccoe[zhu][j]= stoi(coe);
	if(pow!="")
		ppow[zhu][j]= stoi(pow);
	}
	




int main(void){
	string str,output="= "; 
	int getnum_count=0,ccoe[2][100]={-1},ppow[2][100]={-1},zhu=0,zhu_count=0,ker_count=0;
	int test1,test2,temp_count=0;
	ifstream fin("./t5.txt");      //讀取123.csv
	if(!fin){
		cout<<"讀取失敗"; 
        exit(0);  
	}
	ofstream fout("./t5.txt",ios::app);
	int test;
	/*fin>>str;                     //這只會讀取一行 
	cout<<str; 
	*/
	while(fin){                     //也可寫while(!fin.eof())
	fin>>str;
	
	if(str.length()!=1){
		getnum(str,getnum_count,ccoe,ppow,zhu);
		getnum_count++;
		if(ppow[zhu][getnum_count-1]>=ppow[zhu][(getnum_count-2)]&&getnum_count!=1){    //換方程式了! 
			if(zhu==0){
				ccoe[1][0]=ccoe[0][getnum_count-1];
				ppow[1][0]=ppow[0][getnum_count-1];
				ccoe[0][getnum_count-1]=0;
				ppow[0][getnum_count-1]=0;
				zhu++;
				zhu_count= getnum_count;
				getnum_count=1;
				
			}
		
		}
	}
	else {
	ker_count = getnum_count;	
	zhu_count=cal(str,ccoe,ppow,zhu_count,ker_count);        //注意這個是運算式+-*/
	if(zhu==0) zhu_count=getnum_count;
	zhu=1;
	getnum_count=0;            //初始化"客"
	for(test1=0;test1<100;test1++){
		ppow[1][test1]=-1;
		ccoe[1][test1]=-1;
	}
	}
	}
	
	//以下是輸出 (是ios::app) 
	for(int k=0;k<(zhu_count+2);k++){
		if(ppow[0][k]<0) continue;
		if(ccoe[0][k]==0) {if(ppow[0][k]<0) continue;}
		output+=" ";
		if(ccoe[0][k]>0&&k!=0) output+="+";
		if(ccoe[0][k]==1) output+="x^";
		else if(ccoe[0][k]==(-1)) output+="-x^";
	 else{
			output+=to_string(ccoe[0][k]);
			output+="*x^";
		}
		output+=to_string(ppow[0][k]);
		}
		fout<<"\n"<<output;
		fout.close();
}
