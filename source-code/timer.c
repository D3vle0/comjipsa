#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <Windows.h>
int main()
{
	int newtime=0;
	
	/* ����ڰ� ���α׷��� �����ϱ� ������ ���ѹݺ� */ 
	while (1)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("�� â�� ���� ���� ������.\n");
		printf("�ڵ� Ÿ�̸� ����� ���� �ܼ��Դϴ�.\n\n");
	
		/* ���� �ð� �ҷ����� */ 
		SYSTEMTIME st;
		GetLocalTime(&st);
	
		/* 24�ô� 0�÷� ǥ���ϱ�! */ 
		newtime = st.wHour+1;
		if (newtime >= 24)
			newtime -= 24;
			
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		printf("%d:%d:%d", st.wHour+1, st.wMinute, st.wSecond);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf(" �� dns ĳ�ð� �÷����˴ϴ�.\n");
		printf("�������� �Ͻ÷��� ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("Ctrl + C");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("�� �����ּ���.\n");
		
		/* Ÿ�̸� �۵� */ 
		Sleep(3600000);
	
		/* �˸���, flushdns, �޼����ڽ� */ 
		INT APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE, TCHAR *pszLine, INT nShow);
		{
			printf("\a");
			system("ipconfig/flushdns");
			INT (MessageBox(NULL, TEXT("dns ĳ�ð� �÷����Ǿ����ϴ�."), TEXT("������"), MB_OK));
		}
	}
}