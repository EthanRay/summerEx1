#include<random>
#include<ctime>
#include"stdfx.h"

int books[11] = { 0 };
int outt = 10;
int RandTask(){

	default_random_engine gen(time(NULL));
	uniform_int_distribution<int>dis(1, 10);
	auto dice = bind(dis, gen);
	books[0] = -1;
	int tmp = 0;
	//memset(books, 0, sizeof(books));

	tmp = dice();

	while (outt){
		if (books[tmp] == 0){
			books[tmp] = 1;
			outt--;
			break;
		}
		else{
			tmp = dice();
		}
	}

	if (outt){
		return tmp;
	}
	else{
		return tmp;
		//printf("Âú\n");
		memset(books, 0, sizeof(books));
		outt = 10;
	}
}

void BCM_TBOX_Control(int Auth_state){
	switch (Auth_state)
	{
	case 1:
		printf("Random Red ID: %d\n", RandTask());
		break;
	case 2:
		printf("Random Red ID: %d\n", RandTask());
		break;
	case 3:
		printf("Random Red ID: %d\n", RandTask());
		break;
	case 4:
		printf("Random Red ID: %d\n", RandTask());
		break;
	case 5:
		printf("Random Red ID: %d\n", RandTask());
		break;
	case 6:
		printf("Random Red ID: %d\n", RandTask());
		break;
	case 7:
		printf("Random Red ID: %d\n", RandTask());
		break;
	default:
		break;
	}
}