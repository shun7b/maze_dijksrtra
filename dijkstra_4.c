#include<stdio.h>
#define INF 1000000000
void dijkstra(int g);
const int start=0,goal=7;
int n=8;
int dist[8][8]={{INF,  6,INF,INF,INF,INF,INF,INF},
                {  6,INF,  2,  7,INF,INF,INF,INF},
                {INF,  2,INF,  4,INF,INF,  7,INF},
                {INF,  7,  4,INF,INF,  4,INF,INF},
                {INF,INF,INF,INF,INF,INF,  2,INF},
                {INF,INF,INF,  4,INF,INF,INF,INF},
                {INF,INF,  7,INF,  2,INF,INF,  3},
                {INF,INF,INF,INF,INF,INF,  3,INF}
                };
int cost[20];
char used[20];
int loots[20];
int count=0;
int ruto=1;
int main(){
    dijkstra(goal);
}
void dijkstra(int g){
    int x, y, min;
    for(x = 0; x < n; x++){
        cost[x] = INF;
        used[x] = 0;
    }
    cost[g] = 0;
    while(1){
        min = INF;
        for(x = 0; x < n; x++){
            if(!used[x] && min > cost[x]){
                min = cost[x];
            }
        }
        if(min == INF){
            break;
        }
        for(y = 0; y < n; y++){
            if(cost[y] == min){
                for(x = 0; x < n; x++){
                    if(cost[x] > dist[x][y] + cost[y]){
                        cost[x] = dist[x][y] + cost[y];
                        printf(" %d ",dist[x][y]);
                    }
                }
                used[y]=1;
            }
        }
    }
    x=start;
    loots[0]=start;
    while(1){
        if(cost[x]==0){
            break;
        }
        for(y=0;y<n;y++){
            if(dist[x][y]!=INF){
                
                if((cost[y]+dist[x][y])==cost[x]){
                    min=y;
                }
            }
        }    
        x=min;
        loots[ruto]=min;
        ruto++;
    }
    printf("\n");
    for(x=0;x<ruto;x++){
        printf(" %d,",loots[x]);
    }
    printf("\n");
}