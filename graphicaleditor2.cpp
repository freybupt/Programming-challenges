#include <stdio.h>

typedef struct{
    char info[251][251];
    int w;	/* width */
    int h;	/* height */
}Img;

Img img;

void cmdI(int m, int n){
    int i, j;
    
    img.w = m; img.h = n;
    
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            img.info[i][j] = 'O';
        }
    }
}/* cmdI */

void cmdC(){
    int i, j;
    
    for (i = 0; i < img.h; i++){
        for (j = 0; j < img.w; j++){
            img.info[i][j] = 'O';
        }
    }
}/* cmdC */

void cmdL(int x, int y, char c){
    img.info[y-1][x-1] = c;
}/* cmdL */

void cmdV(int x, int y1, int y2, char c){
    int i;
    int temp;
    
    if (y1 > y2){
        temp = y1; y1 = y2; y2 = temp;
    }
    
    for (i = y1-1; i < y2; i++){
        img.info[i][x-1] = c;
    }
}/* cmdV */

void cmdH(int x1, int x2, int y, char c){
    int i;
    int temp;
    
    if (x1 > x2){
        temp = x1; x1 = x2; x2 = temp;
    }
    
    for (i = x1-1; i < x2; i++){
        img.info[y-1][i] = c;
    }
}/* cmdH */

void cmdK(int x1, int y1, int x2, int y2, char c){
    int i, j;
    
    for (i = y1-1; i < y2; i++){
        for (j = x1-1; j < x2; j++){
            img.info[i][j] = c;
        }
    }
}/* cmdK */

int dir[4][2] = {{-1, 0},{1, 0},{0, 1},{0, -1}};

void cmdF(int x, int y, char c){
    char ch = img.info[y-1][x-1];
    int i;
    
    if (ch == c){
        return;
    }
    
    img.info[y-1][x-1] = c;
    
    for (i = 0; i < 4; i++){
        if (x+dir[i][0]>0 && x+dir[i][0]<=img.w && y+dir[i][1]>0 && y+dir[i][1]<=img.h && img.info[y+dir[i][1]-1][x+dir[i][0]-1] == ch){
            cmdF(x+dir[i][0], y+dir[i][1], c);
        }
    }
}/* cmdF */

void cmdS(char *s){
    int i, j;
    
    printf("%s\n", s);
    
    for (i = 0; i < img.h; i++){
        for (j = 0; j < img.w; j++){
            printf("%c", img.info[i][j]);
        }
        
        printf("\n");
    }
}/* cmdS */

int main(){
    char cmd, c;
    int x, y, x1, y1, x2, y2;
    int m, n;
    char szName[105];
    
    while (1){
        scanf(" %c", &cmd);
        
        switch (cmd){
            case 'X': return 0;
                
            case 'I': scanf("%d%d", &m, &n);
                cmdI(m, n);
                break;
                
            case 'C': cmdC();
                break;
                
            case 'L': scanf("%d%d %c", &x, &y, &c);
                cmdL(x, y, c);
                break;
                
            case 'V': scanf("%d%d%d %c", &x, &y1, &y2, &c);
                cmdV(x, y1, y2, c);
                break;
                
            case 'H': scanf("%d%d%d %c", &x1, &x2, &y, &c);
                cmdH(x1, x2, y, c);
                break;
                
            case 'K': scanf("%d%d%d%d %c", &x1, &y1, &x2, &y2, &c);
                cmdK(x1, y1, x2, y2, c);
                break;
                
            case 'F': scanf("%d%d %c", &x, &y, &c);
                cmdF(x, y, c);
                break;
                
            case 'S': scanf(" %[^\n]", szName);
                cmdS(szName);
                break;
                
            default: scanf("%*[^\n]");
        }
    }
    
    return 0;
}