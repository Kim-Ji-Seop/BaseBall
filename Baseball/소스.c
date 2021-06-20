#include <stdio.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
typedef struct BaseBall {
	int numberSet[4];
	int Strike;
	int ball;
}Play;
Play base[500][10] = { NULL };

int strike(int* guess, int* nums) { //strike 수 count
	int strike = 0;
	for (int i = 0; i < 4; i++) {
		if (*(guess + i) == *(nums + i)) strike++;
	}
	return strike;
}

int ball(int* guess, int* nums) { //ball 수 count
	int ball = 0;
	if (*(guess) == *(nums + 1) || *(guess) == *(nums + 2) || *(guess) == *(nums + 3)) ball++;
	if (*(guess + 1) == *(nums) || *(guess + 1) == *(nums + 2) || *(guess + 1) == *(nums + 3)) ball++;
	if (*(guess + 2) == *(nums + 1) || *(guess + 2) == *(nums) || *(guess + 2) == *(nums + 3)) ball++;
	if (*(guess + 3) == *(nums + 2) || *(guess + 3) == *(nums + 1) || *(guess + 3) == *(nums)) ball++;
	return ball;
}

void test() {
	FILE* fp = fopen("baseball2020.txt", "r");
	char buf[100] = { NULL };
	int line=0;
	int i = 0, j = 0;
	int index_j[500] = { 0 };
	int guess[4];
	srand(time(NULL));
	int strike_num; //strike 판별
	int ball_num; // ball 판별
	while (!feof(fp)) {
		if (fgets(buf, 100, fp) != NULL) {
			
			//Split(buf);//데이터 불러온 뒤  점수처리 
			//printf("%s\n", buf);
			if (strlen(buf) == 5) {
				base[i][j].numberSet[0] = buf[0] - 48;
				base[i][j].numberSet[1] = buf[1] - 48;
				base[i][j].numberSet[2] = buf[2] - 48;
				base[i][j].numberSet[3] = buf[3] - 48;
			}
			if (strlen(buf) == 4) {
				base[i][j].Strike = buf[0] - 48;
				base[i][j].ball = buf[2] - 48;
				j++;
			}
			if (strlen(buf) == 2 || strlen(buf) == 1) {
				index_j[i] = j;
				i++;
				line++;
				j = 0;
				continue;
			}
			
		}
	}
	int back_point = 0;

	int randNumber[10] = { 0,1,2,3,4,5,6,7,8,9 };
	for (i = 0; i < line; i++) {
		printf("<%d게임>\n", i + 1);
		for (j = 0; j < index_j[i]; j++) {
			printf("%d %d %d %d %dS %dB\n", base[i][j].numberSet[0], base[i][j].numberSet[1], base[i][j].numberSet[2], base[i][j].numberSet[3], base[i][j].Strike, base[i][j].ball);
		}
		printf("-------------\n");
	}

	
	printf("%d", line);
	
}
int main() {
	test();
}
