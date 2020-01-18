#include "GameField.h"
#include "MyQueue.h"
#include <ctime>
int main()
{
	system("mode con cols=88 lines=30");
	srand(time(0));
	GameField g;
	while(g.StartGame());
	system("pause");
	return 0;
}