/*
개발자 : 심영훈, 박형준
개발일 : 2021.09.08.
문의 : yunghoon1010@naver.com
*/

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

// 메뉴 선택 
#define m_Start 1
#define m_Exit 0

// 비밀번호 
#define PassWord 031231 

// 방에서 접근가능한 장소 
#define DT_Inven	1000 
#define DT_TV 		1001	 
#define DT_ToolBox 	1002
#define DT_Door		1003

// 오브잭트
#define DO_Memo 		2000
#define DO_DirtyCoat 	2001
#define DO_Password		2002
#define DO_Humun 		2010
	#define DO_MoneyPocket 	2011

// 아이템
#define DI_Hammer 	3000
#define DI_Pench 	3001
#define DI_Top 		3002

#define DI_Memo		3005 

#define DI_PeopleCard	4000
#define DI_Money 		4001

int g_Select;

int complete = 1;

int passwordInput = 0;

void GameStart(); // 게임 시작 함수
void Prologue();	// 프롤로그

void Clear()
{
	system("cls");
}

// 인벤토리 
int inven;

void T_Inven();		// 인벤토리
 
void T_TV();		// 티비 
	void O_Memo();	// 메모지 
void T_ToolBox();	// 공구상자 
		void I_Hammer();	// 해머
		void I_Pench();		// 펜치
		void I_Top();		// 톱 
void T_Cabinet(); 	// 캐비넷
	void O_DirtyCoat();	// 더러운 코트 
	void O_Humun();		// 사람시체 
		void O_MoneyPocket();		// 지갑 
			void I_PeopleCard();	// 주민등록증
			void I_Money();			// 돈
void T_Door();	// 문
	void O_Password();	// 문 비밀번호 입력

void InputGetch();
 
void WaitSecond(float _seconds)
{
	Sleep(_seconds * 0);
}

void RenderLine()
{
	printf("\n====================================================================================\n\n");
}

void ErrorMessage()
{
	Clear();
	printf("입력에러 [ERROR]\n\n");
	InputGetch();
}
 
int main(void)
{
	int menu;
	
	while (complete)
	{
		RenderLine();
		printf("TITLE : 검은방\n\n");
		printf("1. 게임시작    2. 게임종료\n\n");
		printf(">>> "); 
		scanf("%d", &menu);
		switch(menu)
		{
			case m_Start:
				GameStart();
				break;
			case m_Exit:
				printf("종료 되었습니다.");
				return 0;
			default:
				ErrorMessage();
				 
		}
	}
	
	return 0;
}

void GameStart()
{
	Clear();
	Prologue();
	
	while (1)
	{
		Clear();
		RenderLine();
		printf("[방]\n\n");
		printf("1. TV    2. 공구상자    3. 문\n\n");
		printf(">>> ");
		scanf("%d", &g_Select);
		g_Select += 1000;
		
		switch(g_Select)
		{
			case DT_TV:
				T_TV();
				break;
			case DT_ToolBox:
				T_ToolBox();
				break;
			case DT_Door:
				T_Door();
				if (complete) {
					Clear();
					RenderLine();
					printf("[끝]\n\n");
					printf("게임 클리어!\n\n");
					InputGetch();
					Clear(); 
					return;
				}
				break;
			case DT_Inven:
				if (inven == DI_Memo)
				{
					Clear();
					RenderLine();
					printf("[메모]\n\n");
					printf("메모에 031231이라 적혀있다.");
					InputGetch();
					break; 
				}
				else
				{
					printf("별로 의미 없다.\n");
				}
			default:
				break;
		}
	}	 
}

void Prologue()
{
	printf("[프롤로그]\n\n"); 
	printf("2020년 8월 20일.\n\n");
	WaitSecond(1.8);
	printf("나는 사형 선고를 받았다.\n");
	WaitSecond(1.5);
	printf("눈을 떠보니 컴퓨터와 공구상자가 보인다.\n");
	WaitSecond(1.5);
	printf("모든 것이 낯선 공간..\n");
	WaitSecond(1.5);
	printf("머리가 깨질 듯이 아파왔고, 어제의 기억이 나질 않는다.\n");
	WaitSecond(1.5);
	printf("한번.. 주변을 둘러보자.. \n\n");
	InputGetch();
	
	return;
}

void T_TV()
{
	Clear();
	RenderLine();
	printf("[TV]\n\n");
	printf("1. 살펴본다    2. 돌아가기\n\n");
	printf(">>> ");
	scanf("%d", &g_Select);
	
	while (1)
	{
		switch(g_Select)
		{
		case 1:
			Clear();
			RenderLine();
			printf("[TV]\n\n");
			
			printf("1. 부순다.    2. 돌아간다.\n\n");
			printf(">>> ");
			scanf("%d", &g_Select);
			switch(g_Select)
			{
				case 1:
					Clear();
					RenderLine();
					printf("[TV]\n\n");
					if (inven == DI_Hammer)
					{
						printf("해머는 부서지고 무언가 떨어져있다.\n\n");
						printf("메모를 획득했다.\n\n");
						printf(">>> ");
						getch();
						inven = DI_Memo;
					}
					else if (inven != DI_Hammer)
					{
						printf("부수려면 무언가 필요할 것 같다.\n\n");
						InputGetch();
						return; 
					} else {
						printf("부서져 있는 티비다.");
						InputGetch();
						return; 
					}
					return;
				case 2:
					return;
				default:
					ErrorMessage();
					break;
			 }
		case 2:
			printf("돌아간다.\n\n");
				InputGetch();
				return;
		default:
			ErrorMessage();
			break;
			
		}
	}
}

void T_ToolBox()
{
	Clear();
	RenderLine();
	printf("[공구상자]\n\n");
	printf("1. 열어본다    2. 돌아가기\n\n");
	printf(">>> ");
	scanf("%d", &g_Select);
	
	while (1)
	{
		switch(g_Select)
		{
		case 1:
			Clear();
			RenderLine();
			printf("[공구상자 안]\n\n");
			
			printf("1. 해머    2. 펜치    3. 톱   4. 돌아간다.\n\n");
			printf(">>> ");
			scanf("%d", &g_Select);
			Clear();
			RenderLine();
			switch(g_Select)
			{
				case 1:
					printf("[해머]\n\n");
					printf("1. 가져간다   2. 가져가지않는다.\n\n");
					printf(">>> ");
					scanf("%d", &g_Select);
					
					Clear();
					RenderLine();
					printf("[해머]\n\n");
					
					switch(g_Select)
					{
						case 1:
							if (inven == DI_Hammer)
							{
								printf("이미 해머를 지니고있다.\n\n");
								InputGetch();
							}
							else
							{
								inven = DI_Hammer;
								printf("해머를 획득했다.");
							}
						case 2:
							printf("돌아간다.\n\n");
							InputGetch();
							return; 
					}
					break;
				case 2:
					printf("[펜치]\n\n");
					printf("펜치가 있다.\n\n");
					InputGetch();
					return T_ToolBox();
				case 3:
					printf("[톱]\n\n");
					printf("톱이 있다.\n\n");
					InputGetch();
					return;
				case 4:
					printf("돌아간다.\n\n");
					InputGetch();
					return;
				default:
					ErrorMessage();
					break;
			 }
		case 2:
			printf("돌아간다.\n\n");
			InputGetch();
			return;
		default:
			ErrorMessage();
			break;
		}
	}
}

void T_Door()
{
	Clear();
	RenderLine();
	printf("[문]\n\n");
	printf("1. 살펴본다    2. 돌아가기\n\n");
	printf(">>> ");
	scanf("%d", &g_Select);
	
	while (1)
	{
		switch(g_Select)
		{
		case 1:
			Clear();
			RenderLine();
			printf("[문]\n\n");
			printf("비밀번호 잠금장치가 걸려있다.\n\n");
			printf("1. 살펴본다.    2. 돌아간다.\n\n");
			printf(">>> ");
			scanf("%d", &g_Select);
			switch(g_Select)
			{
				case 1:
					Clear();
					RenderLine();
					printf("[잠금장치]\n\n");
					printf(" 비밀번호를 입력 하시오.\n\n");
					printf(">>> ");
					scanf("%d", &passwordInput);
					
					if (passwordInput == PassWord)
					{
						printf("탈출 성공.\n\n");
						complete = 0;
						return;
					}
					break;
				case 2:
					return;
				default:
					ErrorMessage();
					break;
			 }
			 break;
		case 2:
			printf("돌아간다.\n\n");
			InputGetch();
			return;
		default:
			InputGetch();
			break;
			
		}
	}
}

void InputGetch()
{
	printf("계속 하려면 아무 키나 누르시오...\n\n");
	getch();
}
