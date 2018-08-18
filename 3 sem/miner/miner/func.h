#include "files.h"

int N=0;
int M=0;

// ��������� ������ �� ���� ; ����� �� ������� ���������� false
bool mine(int **matrix, int i, int j){
    if((i>=0) && (i<N)){
        if((j>=0) && (j<N)){
            if(matrix[i][j]==-1) return true;
        }
    }
    return false;
}
 
// ��������� ������ �� ������� (true), ����� �� ������� ������� ���������� false
bool empty(int **matrix, int i, int j){
    if((i>=0) && (i<N)){
        if((j>=0) && (j<N)){
            if(matrix[i][j]==0) return true;
        }
    }
    return false;
}
 
// ����������� �������, ������� ��������� ���� � ����� ���������
void clean(int **matrix, bool **open, int i,int j){
    // �������� �� ����� �� ������� �������
    if((i>=0) && (i<N)){
        if((j>=0) && (j<N)){
            // ��������, �� ���� �� ������� ���� ������
            if(!open[i][j]){
                // �������
                open[i][j]=true;
                // ���� ���� ������ (=0), ������ ����������� ���� ��� �������
                if(matrix[i][j]==0){
                    clean(matrix, open, i-1,j-1);
                    clean(matrix, open, i-1,j);
                    clean(matrix, open, i-1,j+1);
                    clean(matrix, open, i,j-1);
                    clean(matrix, open, i,j+1);
                    clean(matrix, open, i+1,j-1);
                    clean(matrix, open, i+1,j);
                    clean(matrix, open, i+1,j+1);
                }
                // ���� �� ������ (!=0) ��������� ������ ������ (=0) �������
                else{
                    if(empty(matrix, i-1,j-1)) clean(matrix, open, i-1,j-1);
                    if(empty(matrix, i-1,j)) clean(matrix, open, i-1,j);
                    if(empty(matrix, i-1,j+1)) clean(matrix, open, i-1,j+1);
                    if(empty(matrix, i,j-1)) clean(matrix, open, i,j-1);
                    if(empty(matrix, i,j+1)) clean(matrix, open, i,j+1);
                    if(empty(matrix, i+1,j-1)) clean(matrix, open, i+1,j-1);
                    if(empty(matrix, i+1,j)) clean(matrix, open, i+1,j);
                    if(empty(matrix, i+1,j+1)) clean(matrix, open, i+1,j+1);
                }
            }
        }
    }
}
 
// ������ ������ ���� � ������ �������� � �������� �����
// � ��������������� ���
void draw_matrix(int **matrix, bool **open, HANDLE hConsole){		

    SetConsoleTextAttribute(hConsole, 6);  // dark yellow text
	cout << setw(2) << " ";
	for(int x=0;x<N;x++)
		cout << setw(3) << x << "" ;
	cout << endl;
    SetConsoleTextAttribute(hConsole, 7);  // white text
    for(int x=0;x<N;x++){
        SetConsoleTextAttribute(hConsole, 6);  // dark yellow text
        cout << setw(2) << x << " ";
        SetConsoleTextAttribute(hConsole, 7);  // white text
        for(int y=0;y<N;y++){
            if(open[x][y]){
                if(matrix[x][y]==-1) 
				{
					SetConsoleTextAttribute(hConsole, 12);  // red text
					cout<<" * ";
					SetConsoleTextAttribute(hConsole, 7);   // white text
				}
                else if(matrix[x][y]==0) cout<<" . ";
                else
				{
					SetConsoleTextAttribute(hConsole, 10);  // green text
					cout << " " << matrix[x][y] << " ";
					SetConsoleTextAttribute(hConsole, 7);  // white text
				}
            }
            else{              
                cout<<" # ";             
            }
        }
        cout<<"\n";
    }
}
 
// ������� ��������� ����, ������ ���� �� ���� �������� "Loser!" ��� "Winner!"
void final(int **matrix, bool **open,HANDLE hConsole, bool loser){
    COORD coord;
    coord.X = 62;
    coord.Y = 9;
    system("cls");
    draw_matrix(matrix, open, hConsole);
    SetConsoleCursorPosition(hConsole, coord);
    if(loser){
        SetConsoleTextAttribute(hConsole, 12);  // red text
        cout<<"L O S E R ! ! !";
        SetConsoleTextAttribute(hConsole, 7);  // white text
		 _getch();
    }
    else{
        SetConsoleTextAttribute(hConsole, 10);  // green text
        cout << "W I N N E R ! ! !" << endl;
        SetConsoleTextAttribute(hConsole, 7);  // white text
		int id;
		cout << "Enter your id:\n";
		cin >> id;
		if(N==9)
			finez(id);
		else if(N==13)
			finmed(id);
		else if(N==19)
			finhard(id);
		else fin(id);
    }
	system("cls");
}
 
// � ������ ��������� ��� ������� ������� ��� ����
void openmines(int **matrix,bool **open){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(matrix[i][j]==-1) open[i][j]=true;
        }
    }
}
 
// ���������, ��� �� ���� �������, ����� ��� (������ ������� ������ =)
bool checkwin(int **matrix,bool **open){
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            if((matrix[x][y]!=-1) && (!open[x][y])) return false;
        }
    }
    return true;
}