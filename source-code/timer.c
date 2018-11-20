#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <Windows.h>
int main()
{
	int newtime=0;
	
	/* 사용자가 프로그램을 종료하기 전까지 무한반복 */ 
	while (1)
	{
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("이 창을 절대 닫지 마세요.\n");
		printf("자동 타이머 기능을 위한 콘솔입니다.\n\n");
	
		/* 현재 시각 불러오기 */ 
		SYSTEMTIME st;
		GetLocalTime(&st);
	
		/* 24시는 0시로 표기하기! */ 
		newtime = st.wHour+1;
		if (newtime >= 24)
			newtime -= 24;
			
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		printf("%d:%d:%d", st.wHour+1, st.wMinute, st.wSecond);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf(" 에 dns 캐시가 플러쉬됩니다.\n");
		printf("강제종료 하시려면 ");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		printf("Ctrl + C");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("를 눌러주세요.\n");
		
		/* 타이머 작동 */ 
		Sleep(3600000);
	
		/* 알림음, flushdns, 메세지박스 */ 
		INT APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE, TCHAR *pszLine, INT nShow);
		{
			printf("\a");
			system("ipconfig/flushdns");
			INT (MessageBox(NULL, TEXT("dns 캐시가 플러쉬되었습니다."), TEXT("컴집사"), MB_OK));
		}
	}
}