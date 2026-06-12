#include <iostream>
using namespace std;

// def
int N,M,Q,r;
char d;
int B[100][100];
#define OPP(dir) dir=='L' ? 'R':'L'

bool hasCommon(int row, char dirV){
    int dy = dirV=='U' ? 1:-1;

    for (int i=0; i<M; i++)
        if (B[row][i] == B[row+dy][i]) return true;
    return false;
}

void wind(int row, char dirH){
    int dx = dirH=='L' ? -1:1;

    int temp = dx==-1 ? B[row][M-1] : B[row][0];
    for (int i=0; i<M-1; i++)
        B[row][(dx==-1? M-1:0) + i*dx] = B[row][(dx==-1? M-1:0) + (i+1)*dx];
    B[row][(dx==-1? 0:M-1)] = temp;
}

void process(int row, char dirH){
    // first wind
    wind(row, dirH);

    // goes up
    for (int rowUp=row-1; rowUp>=0 && hasCommon(rowUp, 'U'); rowUp--)
        wind(rowUp, (row-rowUp)%2==1 ? OPP(dirH):dirH);

    // goes down
    for (int rowDown=row+1; rowDown<N && hasCommon(rowDown, 'D'); rowDown++)
        wind(rowDown, (rowDown-row)%2==1? OPP(dirH):dirH);
}

int main() {
    // input
    cin >> N >> M >> Q;
    for (int i=0; i<N; i++)
        for (int j=0; j<M; j++)
            cin >> B[i][j];

    // process
    for (; Q>0; Q--){
        cin >> r >> d;
        process(r-1, d);
    }

    // output
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++)
            cout << B[i][j] << " ";
        cout << "\n";
    }

    return 0;
}