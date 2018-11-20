#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#include <WinUser.h>
#include <time.h>
#include <dos.h>
#pragma warning (disable:4996)

int main()
{
	char str[] = ""; // 접속할 url 을 담는 변수 
	char *ptr;

	/* 타이머 실행 */
	ShellExecute(NULL, "open", "timer.exe", NULL, NULL, SW_SHOW);


	while (1)
	{
		system("cls");

		/* 현재 시각 불러오기 */
		SYSTEMTIME st;
		GetLocalTime(&st);

		/* 기본 출력 */
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		printf("컴집사 v1.0\n");
		printf("!콘솔 창은 닫지 마세요!\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("현재 시각: %d:%d:%d\n", st.wHour, st.wMinute, st.wSecond);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("접속하고자 하는 URL 을 입력해주세요.\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		printf(">");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		scanf("%s", &str);

		/* Blacklist 판별 */
		if ((!(strstr(str, "naver.com") == NULL)) || (!(strstr(str, "google.") == NULL)))
		{
			INT APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE, TCHAR *pszLine, INT nShow);
			{
				printf("\a"); // 알림음을 내는 역할
				if (MessageBox(NULL, TEXT("유해 사이트입니다. 접속하시겠습니까?"), TEXT("오류"), MB_YESNO) == IDYES)
				{
					ShellExecute(NULL, "open", "iexplore.exe", str, "C:\\Program Files\\Internet Explorer", SW_MAXIMIZE);
					INT(MessageBox(NULL, TEXT("로그를 기록합니다."), TEXT("오류"), MB_OK));
					system("access.exe"); // 로그 기록
				}
				else
				{
					printf("\a");
					INT(MessageBox(NULL, TEXT("로그를 기록합니다."), TEXT("오류"), MB_OK));
					system("block.exe"); // 로그 기록
				}
			}
		}
		/* 안전한 웹사이트 접근 */
		else
		{
			ShellExecute(NULL, "open", "iexplore.exe", str, "C:\\Program Files\\Internet Explorer", SW_MAXIMIZE);
			system("safeaccess.exe"); // 로그 기록
		}

	}
}
