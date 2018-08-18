#include "menu.h"
#include "cycle.h"
#include "cont.h" // подключаем контейнер


int main()
{
    int i,j,k=0;
    // хэндл экна необходим для рисования цветного текста
    HANDLE  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // инициализация
    setlocale(0, "rus");
    srand((int)time(NULL));
		
	do
	{
	menu();

	int **matrix = new int*[N];
	for(int h = 0; h<N; h++)
		matrix[h] = new int[N];
	
	bool **open = new bool*[N];
	for(int h = 0; h<N; h++)
		open[h] = new bool[N];

    // все чистим
    for(int c=0;c<N;c++)
	{ 
		for(int b=0;b<N;b++)
		{ 
			matrix[c][b]=0; 
			open[c][b]=false;
		}
	}
    // заполняем массив поля минами
    for(int c=0;c<M;c++){
        do{
            i=0+rand()%N; 
			j=0+rand()%N;
        }while(matrix[i][j]!=0);	
        matrix[i][j]=-1;
    }

    // заполняем массив поля цифрами
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(matrix[i][j]!=-1){
                k=0;
                if(mine(matrix, i-1,j-1)) k++;
                if(mine(matrix, i-1,j)) k++;
                if(mine(matrix, i-1,j+1)) k++;
                if(mine(matrix, i,j-1)) k++;
                if(mine(matrix, i,j+1)) k++;
                if(mine(matrix, i+1,j-1)) k++;
                if(mine(matrix, i+1,j)) k++;
                if(mine(matrix, i+1,j+1)) k++;
                matrix[i][j]=k;
            }
        }
    }
 
    maincycle(i,j,matrix,open,hConsole);

	for(int i = 0; i < N ; i++)
		delete[] matrix[i];
	delete[] matrix;

	for(int i = 0; i < N ; i++)
		delete[] open[i];
	delete[] open;
    
	}while(true);


	return 0;
}