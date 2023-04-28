#include <bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#include <queue>
using namespace std;
#define ed "\n"
void printifj(vector<vector<int>>&a){
    system("cls");
    for(auto it: a){
        for(auto ut: it){
            (ut>0)?cout<<ut<<" ":cout<<"  ";
            // cout<<ut<<" ";
        }
        cout<<endl;
    }
}
int main()
{ 
  int n=10;
  vector<vector<int>>a(n,vector<int>(n));
  int i=5,j=5;
  int x=0,y=0;
  int p=-1,q=-1;

  a[i][j]=2;
  a[i][6]=2;
  a[i][7]=2;
  a[i][8]=2;

  a[4][3]=1;
  a[7][8]=1;
  a[8][9]=1;
  a[8][0]=1;

  queue<pair<int,int>>qe;
  qe.push({i,j});
  qe.push({i,6});
  qe.push({i,7});
  qe.push({i,8});

  while(true){
    printifj(a);
    char input;
    input=getch();
    cout<<i<<" "<<j<<endl;
    switch(input){
        case 's':
            if(a[(i+1)%n][j]==1){
                i=(i+1)%n;
                a[i][j]=2;
                qe.push({i,j});     
                continue;
                break;
            }
            i=(i+1)%10;
            a[i][j]=2;

            break;
        case 'w':
            if(a[i-1][j]==1){
                i=(i-1+n)%n; 
                a[i][j]=2;
                qe.push({i,j}); 
                continue;
                break;
            }

            i = (i - 1 + n) % n;
            a[i][j]=2;

            break;
        case 'd':
            if(a[i][j+1]==1){
                j=(j+1)%n;
                a[i][j]=2;
                qe.push({i,j}); 
                continue;
                break;
            }

            j=(j+1)%10;
            a[i][j]=2;
            
            break;
        case 'a':
            if(a[i][j-1]==1){
                j = (j - 1 + n) % n;
                a[i][j]=2;
                qe.push({i,j});  
                continue;
                break;
            }

            a[x][y]=0;
            j = (j - 1 + n) % n;
            a[i][j]=2;
            
            break;
        default:
            cout<<"invalid button\n";
    }
    pair<int,int>pr=qe.front();
    a[pr.first][pr.second]=0;
    qe.pop();
    qe.push({i,j});
  }
  return 0;
}
