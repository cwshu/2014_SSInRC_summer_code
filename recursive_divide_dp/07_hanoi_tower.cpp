#include <iostream>
#include <cstdio>
using namespace std;

const int MAX_LAYER = 100; // Hanoi Tower ³Ì¦h´X¼h
struct hanoi_tower{
    int rod[3][MAX_LAYER];
    int rod_height[3];
    int layer;
} tower;

void hanoi_init(int layer);
void hanoi_move_tower(int layer);
void _hanoi_move_tower(int layer, int start_rod, int end_rod);
void hanoi_single_move(int start_rod, int end_rod);
void print_hanoi_tower();

int main(){
    hanoi_init(8);
    hanoi_move_tower(8);
}

// function implementation
void hanoi_init(int layer){
    tower.layer = layer;
    tower.rod_height[0] = tower.layer;
    tower.rod_height[1] = tower.rod_height[2] = 0;

    for(int i=0; i<layer; i++){
        tower.rod[0][i] = 8 - i; // 8 ~ 1
    }
}

void hanoi_move_tower(int layer){
    _hanoi_move_tower(layer, 0, 2);
}

void _hanoi_move_tower(int layer, int start_rod, int end_rod){
    if(layer == 1){
        hanoi_single_move(start_rod, end_rod);
        return;
    }

    int last_rod = 3 - start_rod - end_rod; // sum of three rod = 3 ( 0+1+2 )
    _hanoi_move_tower(layer-1, start_rod, last_rod);
    hanoi_single_move(start_rod, end_rod);
    _hanoi_move_tower(layer-1, last_rod, end_rod);
}

void hanoi_single_move(int start_rod, int end_rod){
    if(tower.rod_height[start_rod] < 1){
        cout << "Error: move empty rod" << endl;
        return;
    }
    int move_disk = tower.rod[start_rod][ tower.rod_height[start_rod] - 1 ];
    tower.rod_height[start_rod]--;
    tower.rod[end_rod][ tower.rod_height[end_rod] ] = move_disk;
    tower.rod_height[end_rod]++;

    print_hanoi_tower();
    getchar();
}

void print_hanoi_tower(){
    const char rod_name[3] = {'a', 'b', 'c'};
    for(int i=0; i<3; i++){
        cout << rod_name[i] << ": ";
        for(int j=0; j<tower.rod_height[i]; j++){
            if( j != 0 )
                cout << ", ";
            cout << tower.rod[i][j];
        }
        cout << endl;
    }
}
