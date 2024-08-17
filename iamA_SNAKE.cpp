#include <bits/stdc++.h>
#include<conio.h>
#include<windows.h>
#include <queue>
#include <cstdlib>  
#include <ctime>    
using namespace std;
#define ed "\n"
void printifj(vector<vector<char>>&a){
    system("cls");
    for(auto it: a){
        for(auto ut: it){
            (ut>'0')?cout<<ut<<" ":cout<<"  ";
            // cout<<ut<<" ";
        }
        cout<<endl;
    }
}
void spawnRat(vector<vector<char>>&a){
    int m=a.size();
    srand(static_cast<unsigned int>(time(0)));

    int miin = 0;
    int mex = m-1;

    int row = miin + (rand() % (mex - miin + 1));
    int col = miin + (rand() % (mex - miin + 1));
    while(a[row][col]!='0'){
         row = miin + (rand() % (mex - miin + 1));
         col = miin + (rand() % (mex - miin + 1));
    }
    a[row][col]='1';
}
int main()
{ 
  int n=10;
  vector<vector<char>>a(n,vector<char>(n));
  int i=5,j=5;
  int x=0,y=0;
  int p=-1,q=-1;

  a[i][j]='2';
  a[i][6]='2';
  a[i][7]='2';
  a[i][8]='2';

  a[4][3]='1';
  a[7][8]='1';

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
            if(a[(i+1)%n][j]=='1'){
                i=(i+1)%n;
                a[i][j]='2';
                qe.push({i,j});     
                spawnRat(a);
                continue;
                break;
            }
            i=(i+1)%10;
            a[i][j]='2';

            break;
        case 'w':
            if(a[i-1][j]=='1'){
                i=(i-1+n)%n; 
                a[i][j]='2';
                qe.push({i,j}); 
                spawnRat(a);
                continue;
                break;
            }
            
            i = (i - 1 + n) % n;
            a[i][j]='2';

            break;
        case 'd':
            if(a[i][j+1]=='1'){
                j=(j+1)%n;
                a[i][j]='2';
                qe.push({i,j}); 
                spawnRat(a);
                continue;
                break;
            }

            j=(j+1)%10;
            a[i][j]='2';
            
            break;
        case 'a':
            if(a[i][j-1]==1){
                j = (j - 1 + n) % n;
                a[i][j]='2';
                qe.push({i,j});  
                spawnRat(a);
                continue;
                break;
            }

            a[x][y]='0';
            j = (j - 1 + n) % n;
            a[i][j]='2';
            
            break;
        default:
            cout<<"invalid button\n";
    }
    pair<int,int>pr=qe.front();
    a[pr.first][pr.second]='0';
    qe.pop();
    qe.push({i,j});
  }
  return 0;
}
