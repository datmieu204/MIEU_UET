#include<iostream>
#include<iomanip>
#include<time.h>
#include<stdlib.h>
#define MAX 100

using namespace std;


int m , n , K ;
int x , y ;
int Map[MAX][MAX]; //map
bool check_Map[MAX][MAX]; //trang thai
bool game_Over;

void input();
void set_Map();
void get_Mine(); 
void current_Map();
int near_Mine();
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

//khoi tao  
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
    srand(unsigned(time(NULL)));
    while(K--){
        int x = rand() % m;
        int y = rand() % n;
        if(Map[x][y] != -1){
            Map[x][y] = -1; //tao min = gia tri -1
        }
    }
}

//in ra map hien tai
void current_Map(){
    for(int i = 0; i < m ; i++){
        for(int j = 0; j < n ; j++){
            if(check_Map[i][j]){
                if(Map[i][j] == -1) 
                    cout << "X ";  // X la vi tri co min
                else 
                    cout << Map[i][j] << " ";
            }else{
                cout << "~ ";
            }
        }
        cout << endl;
    }
}

//in ra so bom xung quanh o da chon
int near_Mine(){
    int cnt = 0 ;
    for(int i= x - 1; i <= x + 1; i++){
        for(int j= y - 1; j <= y + 1; j++){
            if(Map[i][j] == -1) cnt++;
        }
    }
    return cnt;
}

//lua chon cua ban
void your_Choice(){
    do{
            cout << " Nhap toa do o can mo ( Luu y : chi so bat dau tu 0) : ";
            cin >> x >> y ; 
        }while(x < 0 || y < 0 || x >=m || y >=n);
}

void start_Game(){
    game_Over = false;
    //start game
    while(!game_Over){

        current_Map();
        your_Choice();

        check_Map[x][y] = true;

        if(Map[x][y] == -1){
            cout << "YOU'RE DEAD !!!" << endl;
            current_Map();
            game_Over = true;
        }else{
            int count_mine = near_Mine();
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
