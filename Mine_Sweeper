#include<iostream>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
#define MAX 100

using namespace std;


int m , n , K ;
int Map[MAX][MAX]; //luu map
bool check_Map[MAX][MAX]; //luu cac trang thai

void input();
void set_Map();
void get_Mine(); 
void current_Map();
int near_Mine(int x , int y);
void start_Game();


int main(){
    input();
    set_Map();
    get_Mine();
    start_Game();
    return 0;
}


void input(){
    do{
        cout <<  "  Nhap chieu dai va chieu rong cua Map \n  Luu y : 0 < chieu dai , chieu rong < 10 : " ;
        cin >> m >> n ;
    }while(m <= 0 || n <= 0 || m >= 10 || n >= 10); 

    do{
        cout << "  So min trong Map \n  Luu y : 0 < so min < 10 : ";
        cin >> K ;
    }while(K <= 0 || K >= 10); 
}

//khoi tao ban do 
void set_Map(){
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n ; j++){
            Map[i][j] = 0 ;
            check_Map[i][j] = false;
        }
    }
}

//sinh min ngau nhien
void get_Mine(){
    int count_Mine = 0;
    srand(unsigned(time(NULL)));
    while(count_Mine < K){
        int x = rand() % m;
        int y = rand() % n;
        if(Map[x][y] != -1){
            Map[x][y] = -1;
            count_Mine++;
        }
    }
}

void current_Map(){
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n ; j++){
            if(check_Map[i][j]){
                if(Map[i][j] == -1) 
                    cout << "X ";
                else 
                    cout << Map[i][j] << " ";
            }else{
                cout << "~ ";
            }
        }
        cout << endl;
    }
}

int near_Mine(int x , int y){
    int cnt = 0 ;
    for(int i= x - 1; i <= x + 1; i++){
        for(int j= y - 1; j <= y + 1; j++){
            if(Map[i][j] == -1) cnt++;
        }
    }
    return cnt;
}

void start_Game(){
    bool game_Over = false;
    //start game
    while(!game_Over){

        current_Map();
        int x , y ;
        do{
            cout << " Nhap toa do o can mo ( Luu y : chi so bat dau tu 0) : ";
            cin >> x >> y ; 
        }while(x < 0 || y < 0 || x >=m || y >=n);

        check_Map[x][y] = true;

        if(Map[x][y] == -1){
            cout << "YOU'RE DEAD !!!" << endl;
            current_Map();
            game_Over = true;
        }else{
            int count_mine = near_Mine(x,y);
            Map[x][y] = count_mine;

            int WIN = 0 ;
            for(int i = 0 ; i < m ; i++){
                for(int j = 0 ; j < n ; j++){
                    if(check_Map[i][j]) WIN++;
                }
            }

            if(WIN == K){
                cout << "YOU WIN :3" << endl;
                current_Map();
                game_Over = true;
            }
        }
    }
}










