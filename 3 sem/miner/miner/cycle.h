void maincycle(int i, int j,int **matrix,bool **open, HANDLE hConsole)
{
	int x,y;
    while(true)
	{
        system("cls");
        draw_matrix(matrix, open, hConsole);

        cout<<"\n";
        cout << "Enter coordinats x,y:" << endl;
        cin >> x >> y;

		try
		{
			if((x<0) || (x>N)) 
				throw 123;       
			else j=x;                           
			if((y<0) || (y>N)) 
				throw 123; 
			else i=y;
		}
		catch(int i)
		{
			cout << "Error № " << i << " invalid values!"  << endl;
			_getch();
		}
        clean(matrix, open, i,j);

        if(mine(matrix, i,j)){ openmines(matrix,open); final(matrix, open, hConsole, true); break; }  // программа покидает цикл в случае проигрыша или победы	
        if(checkwin(matrix,open)){ final(matrix, open, hConsole, false); break; }  
    }
}