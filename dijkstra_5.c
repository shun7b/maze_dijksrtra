#include<stdio.h> 
int map[100]={	-1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,-1,
			    -1,16384,16384,16384,16384,16384,16384,16384,16384,-1,
			    -1,16384,   -1,   -1,16384,   -1,   -1,   -1,16384,-1,
			    -1,16384,16384,   -1,16384,16384,16384,16384,16384,-1,
			    -1,   -1,   -1,   -1,16384,   -1,   -1,   -1,16384,-1,
			    -1,16384,16384,16384,16384,   -1,16384,   -1,16384,-1,
			    -1,16384,   -1,   -1,16384,   -1,16384,   -1,16384,-1,
			    -1,16384,   -1,   -1,16384,16384,16384,   -1,   -1,-1,
			    -1,16384,16384,16384,16384,   -1,16384,16384,16384,-1,
			    -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,-1};
int main(void){
    int mapafter[100];
    int plot_value=0;
    int sub_plot=1000;
    int nowplot=0;
    int nextplot=0;
    int wari=0;
    int start;
    int goal;
    printf("start");
    scanf("%d",&start);
    map[start]=32767;
    printf("goal");
    scanf("%d",&goal);
    map[goal]=0;
    while(sub_plot>16384){
        for(plot_value=11;plot_value<89;plot_value++){
            wari=0;
            mapafter[plot_value]=0;
            if(map[plot_value]!=-1){
                if(map[plot_value-1]!=-1){
                    mapafter[plot_value]=map[plot_value-1];
                    wari++; 
                }
                if(map[plot_value+1]!=-1){
                    mapafter[plot_value]=mapafter[plot_value]+map[plot_value+1];
                    wari++;
                }
                if(map[plot_value+10]!=-1){
                    mapafter[plot_value]=mapafter[plot_value]+map[plot_value+10];
                    wari++;
                }
                if(map[plot_value-10]!=-1){
                    mapafter[plot_value]=mapafter[plot_value]+map[plot_value-10];
                    wari++;
                }
                mapafter[plot_value]=(mapafter[plot_value]+map[plot_value])/(wari+1);
                sub_plot=map[plot_value]-mapafter[plot_value];
                if(sub_plot<0){
                    sub_plot=-sub_plot;
                }
            }
        }
        for(plot_value=11;plot_value<89;plot_value++){
            if(map[plot_value]!=-1){
                map[plot_value]=mapafter[plot_value];
            }
        }   
    } 
    for(plot_value=11;plot_value<89;plot_value++){
            printf(" %d %d \n",plot_value,map[plot_value]);
    }
    nowplot=start;
    nextplot=start;
    while(nowplot!=goal){
        printf(" %d",nowplot);
        map[nowplot]=32767;
        if(map[nowplot-1]!=-1){
            if(map[nextplot]>map[nowplot-1]){
                nextplot=nowplot-1;
            }
        }
        if(map[nowplot+1]!=-1){
            if(map[nextplot]>map[nowplot+1]){
                nextplot=nowplot+1;
            }
        }
        if(map[nowplot+10]!=-1){
            if(map[nextplot]>map[nowplot+10]){
                nextplot=nowplot+10;
            }
        }
        if(map[nowplot-10]!=-1){
            if(map[nextplot]>map[nowplot-10]){
                nextplot=nowplot-10;
            }
        }
        nowplot=nextplot;        
        
    }
    printf("\n");
}