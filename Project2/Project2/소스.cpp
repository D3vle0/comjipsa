#include <stdio.h>
#include <tchar.h>
#include <Windows.h>
#pragma warning (disable:4996)
int main() 
{
	char url[50];
	int len = 0;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	printf("������ v1.0\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	printf("�����ϰ��� �ϴ� URL �� �Է����ּ���.\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	printf(">");
	scanf("%s", &url);
	
	if ((!(strcmp(url, "blacklist1.kro.kr/1.html"))) || (!(strcmp(url, "blacklist1.kro.kr/2.html"))) || (!(strcmp(url, "http://blacklist1.kro.kr/1.html"))) || (!(strcmp(url, "https://blacklist1.kro.kr/1.html"))) || (!(strcmp(url, "http://blacklist1.kro.kr/2.html"))) || (!(strcmp(url, "https://blacklist1.kro.kr/2.html"))))
	{
		INT APIENTRY _tWinMain(HINSTANCE hInstance, HINSTANCE, TCHAR *pszLine, INT nShow);
		{
			if (MessageBox(NULL, TEXT("���� ����Ʈ�Դϴ�. �����Ͻðڽ��ϱ�?"), TEXT("����"), MB_YESNO) == IDYES)
			{
				ShellExecute(NULL, "open", "iexplore.exe", url, "C:\\Program Files\\Internet Explorer", SW_MAXIMIZE);
			}
			else
			{
				INT(MessageBox(NULL, TEXT("�α׸� ����մϴ�."), TEXT("����"), MB_OK));
				system("block.bat");			
			}
		}
	}
	else
	{
		ShellExecute(NULL, "open", "iexplore.exe", url, "C:\\Program Files\\Internet Explorer", SW_MAXIMIZE);
	}

	system("pause");
}

