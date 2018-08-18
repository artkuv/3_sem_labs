//#include "funcparent.h"
//
//funcparent::funcparent()
//{
//	c=0;
//	i=0;
//	b=0;
//	k=0;
//	j=0;
//}
//bool funcparent::mine(int N,int i, int j)
//{
//    if((i>=0) && (i<N)){
//        if((j>=0) && (j<N)){
//            if(matrix[i][j]==-1) return true;
//        }
//    }
//    return false;
//}
//
//void funcparent::clean(int N)
//{
//	for(int c=0;c<N;c++)
//	{ 
//		for(int b=0;b<N;b++)
//		{ 
//			matrix[c][b]=0; 
//			open[c][b]=false;
//		}
//	}
//}
//
//void funcparent::fillmines(int M,int N)
//{
//	for(int c=0;c<M;c++){
//        do{
//            i=0+rand()%N;
//			j=0+rand()%N;
//        }while(matrix[i][j]!=0);	
//        matrix[i][j]=-1;
//    }
//}
//
//void funcparent::fillnumbers(int N)
//{
//	for(i=0;i<N;i++){
//        for(j=0;j<N;j++){
//            if(matrix[i][j]!=-1){
//                k=0;
//                if(mine(N, i-1,j-1)) k++;
//                if(mine(N, i-1,j)) k++;
//                if(mine(N, i-1,j+1)) k++;
//                if(mine(N, i,j-1)) k++;
//                if(mine(N, i,j+1)) k++;
//                if(mine(N, i+1,j-1)) k++;
//                if(mine(N, i+1,j)) k++;
//                if(mine(N, i+1,j+1)) k++;
//                matrix[i][j]=k;
//            }
//        }
//    }
//}