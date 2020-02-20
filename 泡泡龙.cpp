#include<iostream>
using namespace std;
int a,b,c,d;
char m[1005][1005];
int ok=0;
int sum=0;
bool in(int x,int y){
	return x>=1&&x<=a&&y>=1&&y<=b;
}
void dfsm(int x,int y){
	m[x][y]='A';
	sum--;
	if(in(x-1,y)&&m[x-1][y]>='a'&&m[x-1][y]<='z'){
		dfsm(x-1,y);
	}
	if(in(x+1,y)&&m[x+1][y]>='a'&&m[x-1][y]<='z'){
		dfsm(x+1,y);
	}
	if(in(x,y-1)&&m[x][y-1]>='a'&&m[x-1][y]<='z'){
		dfsm(x,y-1);
	}
	if(in(x,y+1)&&m[x][y+1]>='a'&&m[x-1][y]<='z'){
		dfsm(x,y+1);
	}
	if(x%2!=0&&in(x-1,y-1)&&m[x-1][y-1]>='a'&&m[x-1][y]<='z'){
		dfsm(x-1,y-1);
	}
	if(x%2!=0&&in(x+1,y-1)&&m[x+1][y-1]>='a'&&m[x-1][y]<='z'){
		dfsm(x+1,y-1);
	}
	if(x%2==0&&in(x-1,y+1)&&m[x-1][y+1]>='a'&&m[x-1][y]<='z'){
		dfsm(x-1,y+1);
	}
	if(x%2==0&&in(x+1,y+1)&&m[x+1][y+1]>='a'&&m[x-1][y]<='z'){
		dfsm(x+1,y+1);
	}
}
void dfs(int x,int y,char ch){
	ok++;
//	cout<<"ININI"<<x<<" "<<y<<endl;
	if(in(x-1,y)&&m[x-1][y]==ch){
		m[x-1][y]='F';
		dfs(x-1,y,ch);
	}
	if(in(x+1,y)&&m[x+1][y]==ch){
		m[x+1][y]='F';
		dfs(x+1,y,ch);
	}
	if(in(x,y-1)&&m[x][y-1]==ch){
		m[x][y-1]='F';
		dfs(x,y-1,ch);
	}
	if(in(x,y+1)&&m[x][y+1]==ch){
		m[x][y+1]='F';
		dfs(x,y+1,ch);
	}
	if(x%2!=0&&in(x-1,y-1)&&m[x-1][y-1]==ch){
		m[x-1][y-1]='F';
		dfs(x-1,y-1,ch);
	}
	if(x%2!=0&&in(x+1,y-1)&&m[x+1][y-1]==ch){
		m[x+1][y-1]='F';
		dfs(x+1,y-1,ch);
	}
	if(x%2==0&&in(x-1,y+1)&&m[x-1][y+1]==ch){
		m[x-1][y+1]='F';
		dfs(x-1,y+1,ch);
	}
	if(x%2==0&&in(x+1,y+1)&&m[x+1][y+1]==ch){
		m[x+1][y+1]='F';
		dfs(x+1,y+1,ch);
	}
	
}
int main(){
	
	while(cin>>a>>b>>c>>d){
		sum=0;
		ok=0;
		for(int i=1;i<=a;i++){
			for(int j=1;j<=b;j++){
				if(i%2==0&&j==b){
					m[i][j]='E';
					break;
				}
				cin>>m[i][j];
				if(m[i][j]!='E') sum++;
			}
		} 
		char cch=m[c][d];
		m[c][d]='F';
		dfs(c,d,cch);
		if(ok<3){
			cout<<"0"<<endl;
			continue;
		}
		
		for(int j=1;j<=b;j++){
			if(m[1][j]!='E'&&m[1][j]!='F'&&m[1][j]!='A') dfsm(1,j);
		}
		
		cout<<sum<<endl;
	}
	return 0;
}
/*
2 2 2 1
ba
a
3 3 3 3
aaa
ba
bba
3 3 3 1
aaa
ba
bba
4 6 4 5
aaccca
EEEEc
Eccccc
beeEc

*/
