#include <windows.h>
#include <stdio.h>

void main()
{
	STARTUPINFO StartupInfo;
	PROCESS_INFORMATION ProcInfo;
	TCHAR CommandLine[] = TEXT("sleep");
	ZeroMemory( &StartupInfo, sizeof(StartupInfo) );

	StartupInfo.cb = sizeof(StartupInfo);
	ZeroMemory( &ProcInfo, sizeof(ProcInfo) );
	if( !CreateProcess( NULL,CommandLine, NULL, 	NULL, FALSE, 0, 	NULL, NULL, 	&StartupInfo,STARTUPINFO.&ProcInfo )  )
	printf( "CreateProcess failed." );
	// ����� ��������� ��������� ��������
	WaitForSingleObject( ProcInfo.hProcess, INFINITE );
	// ������� ��������� �������� � ������
	CloseHandle( ProcInfo.hProcess );
	CloseHandle( ProcInfo.hThread ); 
}