//#include "func.h"
//
///*
//// проверяет ячейку на мину ; выход за пределы возвращает false
//bool mine(int **matrix, int i, int j){
//    if((i>=0) && (i<N)){
//        if((j>=0) && (j<N)){
//            if(matrix[i][j]==-1) return true;
//        }
//    }
//    return false;
//}
// */
//// проверяет ячейку на пустоту (true), выход за пределы массива возвращает false
//bool func::empty(int N){
//    if((i>=0) && (i<N)){
//        if((j>=0) && (j<N)){
//            if(matrix[i][j]==0) return true;
//        }
//    }
//    return false;
//}
// 
//// рекурсивная функция, которая открывает поля в точке попадания
//void clean(parent pr,funcparent fpr,int i ,int j, int N)
//{
//	i=f[r
//    // проверим на выход за пределы массива
//    if((fpr.i>=0) && (fpr.i<N)){
//        if((fpr.j>=0) && (fpr.j<N)){
//            // проверим, не было ли открыто поле раньше
//            if(!pr.open[fpr.i][fpr.j]){
//                // откроем
//                pr.open[fpr.i][fpr.j]=true;
//                // если поле пустое (=0), просто пооткрываем всех его соседей
//                if(pr.matrix[fpr.i][fpr.j]==0){
//                    clean(pr, i-1,j-1,N);
//                    clean(matrix, open, i-1,j);
//                    clean(matrix, open, i-1,j+1);
//                    clean(matrix, open, i,j-1);
//                    clean(matrix, open, i,j+1);
//                    clean(matrix, open, i+1,j-1);
//                    clean(matrix, open, i+1,j);
//                    clean(matrix, open, i+1,j+1);
//                }
//                // если не пустое (!=0) открываем только пустых (=0) соседей
//                else{
//                    if(empty(matrix, i-1,j-1)) clean(matrix, open, i-1,j-1);
//                    if(empty(matrix, i-1,j)) clean(matrix, open, i-1,j);
//                    if(empty(matrix, i-1,j+1)) clean(matrix, open, i-1,j+1);
//                    if(empty(matrix, i,j-1)) clean(matrix, open, i,j-1);
//                    if(empty(matrix, i,j+1)) clean(matrix, open, i,j+1);
//                    if(empty(matrix, i+1,j-1)) clean(matrix, open, i+1,j-1);
//                    if(empty(matrix, i+1,j)) clean(matrix, open, i+1,j);
//                    if(empty(matrix, i+1,j+1)) clean(matrix, open, i+1,j+1);
//                }
//            }
//        }
//    }
//}
// 
//// рисует минное поле с учетом открытых и закрытых полей и вспомогательные оси
//void draw_matrix(parent pr, HANDLE hConsole,int N){		
//
//    SetConsoleTextAttribute(hConsole, 6);  // dark yellow text
//	cout << setw(2) << " ";
//	for(int x=0;x<N;x++)
//		cout << setw(3) << x << "" ;
//	cout << endl;
//    SetConsoleTextAttribute(hConsole, 7);  // white text
//    for(int x=0;x<N;x++){
//        SetConsoleTextAttribute(hConsole, 6);  // dark yellow text
//        cout << setw(2) << x << " ";
//        SetConsoleTextAttribute(hConsole, 7);  // white text
//        for(int y=0;y<N;y++){
//            if(pr.open[x][y]){
//                if(pr.matrix[x][y]==-1) 
//				{
//					SetConsoleTextAttribute(hConsole, 12);  // red text
//					cout<<" * ";
//					SetConsoleTextAttribute(hConsole, 7);   // white text
//				}
//                else if(pr.matrix[x][y]==0) cout<<" . ";
//                else
//				{
//					SetConsoleTextAttribute(hConsole, 10);  // green text
//					cout << " " << pr.matrix[x][y] << " ";
//					SetConsoleTextAttribute(hConsole, 7);  // white text
//				}
//            }
//            else{              
//                cout<<" # ";             
//            }
//        }
//        cout<<"\n";
//    }
//}
// 
//// функция завершает игру, выведя одну из двух надписей "Loser!" или "Winner!"
//void final(int **matrix, bool **open,HANDLE hConsole, bool loser){
//    COORD coord;
//    coord.X = 62;
//    coord.Y = 9;
//    system("cls");
//    draw_matrix(matrix, open, hConsole);
//    SetConsoleCursorPosition(hConsole, coord);
//    if(loser){
//        SetConsoleTextAttribute(hConsole, 12);  // red text
//        cout<<"L O S E R ! ! !";
//        SetConsoleTextAttribute(hConsole, 7);  // white text
//		 _getch();
//    }
//    else{
//        SetConsoleTextAttribute(hConsole, 10);  // green text
//        cout << "W I N N E R ! ! !" << endl;
//        SetConsoleTextAttribute(hConsole, 7);  // white text
//		int id;
//		cout << "Enter your id:\n";
//		cin >> id;
//		if(N==9)
//			finez(id);
//		else if(N==13)
//			finmed(id);
//		else if(N==19)
//			finhard(id);
//		else fin(id);
//    }
//	system("cls");
//}
// 
//// в случае проигрыша эта функция откроет все мины
//void openmines(int **matrix,bool **open){
//    for(int i=0;i<N;i++){
//        for(int j=0;j<N;j++){
//            if(matrix[i][j]==-1) open[i][j]=true;
//        }
//    }
//}
// 
//// проверяет, все ли поле открыто, кроме мин (таково условие победы =)
//bool checkwin(int **matrix,bool **open){
//    for(int x=0;x<N;x++){
//        for(int y=0;y<N;y++){
//            if((matrix[x][y]!=-1) && (!open[x][y])) return false;
//        }
//    }
//    return true;
//}