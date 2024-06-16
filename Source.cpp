#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include<time.h>
void bot(char arr[7][7]) {
	int i, j, c[8], r[8], i1 = 0, j1 = 0, n = 0, cout = 0,  max = -1, position = 0,orr[8],oc[8],o=0,b=0,x[50],y[50],pr,n1;
	int V[8] = { 0 };
	
	srand(time(NULL));
	//เก็บตำแหน่งของหมาก
	for (i = 0,i1=0,j1=0,n=0; i < 7 ; i++) {
		for (j = 0; j < 7; j++) {
			if (arr[i][j] == 'x' || arr[i][j] == 'X') {
				r[i1] = i;
				c[j1] = j;
				i1++;
				j1++;
				n++;
			}
		}
	}
	//เช๋็คความสำคัญของหมากในการเดิน(จะให้เลือกว่าเดินตัวไหน)
	for (i = 0; i != n;i++) {
		if (arr[r[i]][c[i]] == 'X') {
			for (j = 1; (r[i] + j < 7) && (c[i] + j < 7); j++) {
				if (arr[r[i] + j][c[i] + j] == 'o') {
					if ((r[i] + j < 6) || (c[i] + j < 6)) {
						if (arr[r[i] + j + 1][c[i] + j + 1] == ' ') {

							V[i] = V[i] + 2;
							
						}

					}
					if (arr[r[i] + 1][c[i] + 1] == 'o')
						V[i] = V[i] + 3;
				}
				if (arr[r[i] + j][c[i] + j] == 'O') {
					V[i] = V[i] + 4;
				if (arr[r[i] - 1][c[i] - 1] == ' ' && (!(r[i] - 1 < 0) && !(c[i] - 1 < 0))) 
						V[i] = V[i] + 4;
				}
			}
			for (j = 1; !(r[i] - j < 0) && (c[i] + j < 7); j++) {
				if (arr[r[i] + j][c[i] + j] == 'o') {
					if ((r[i] - j > 0) || (c[i] + j < 6)) {
						if (arr[r[i] - j - 1][c[i] + j + 1] == ' ')
							V[i] = V[i] + 2;

					}
					if (arr[r[i] - 1][c[i] + 1] == 'o')
						V[i] = V[i] + 3;
				}
				if (arr[r[i] - j][c[i] + j] == 'O') {
					V[i] = V[i] + 4;
					if (arr[r[i] + 1][c[i] - 1] == ' ' && (!(r[i] + 1 > 7) && !(c[i] - 1 < 0)))
						V[i] = V[i] + 4;
				}
			}
			for (j = 1; (r[i] + j < 7) && !(c[i] - j < 0); j++) {
				if (arr[r[i] + j][c[i] - j] == 'o') {
					if ((r[i] + j < 6) || (c[i] - j > 0)) {
						if (arr[r[i] + j + 1][c[i] - j - 1] == ' ')
							V[i] = V[i] + 2;

					}
					if (arr[r[i] + 1][c[i] - 1] == 'o')
						V[i] = V[i] + 3;
				}
				if (arr[r[i] + j][c[i] - j] == 'O') {
					V[i] = V[i] + 4;
					if (arr[r[i] - 1][c[i] + 1] == ' ' && (!(r[i] - 1 < 0) && !(c[i] + 1 > 7)))
						V[i] = V[i] + 4;
				}
			}
			for (j = 1; !(r[i] - j <0) && !(c[i] - j <0); j++) {
				if (arr[r[i] - j][c[i] - j] == 'o') {
					if ((r[i]- j > 0) || (c[i] - j > 0)) {
						if (arr[r[i] - j - 1][c[i] - j - 1] == ' ')
							V[i] = V[i] + 2;

					}
					if (arr[r[i] - 1][c[i] - 1] == 'o')
						V[i] = V[i] + 3;
				}
				if (arr[r[i] - j][c[i] - j] == 'O') {
					V[i] = V[i] + 4;
					if (arr[r[i] + 1][c[i] + 1] == ' ' && (!(r[i] + 1 > 7) && !(c[i] + 1 > 7)))
						V[i] = V[i] + 4;
				}

			}
		}
		else if (arr[r[i]][c[i]] == 'x') {
			if (((arr[r[i] + 1][c[i] + 1] == 'o') && c[i] < 6) || ((arr[r[i] + 1][c[i] - 1] == 'o') && c[i] > 0)) {
				if (( arr[r[i] + 2][c[i] + 2] == ' '&& arr[r[i] + 1][c[i] + 1] == 'o')&& r[i]<5&& c[i]<5)
					V[i] = V[i] + 6;
				if((arr[r[i] + 2][c[i] - 2] == ' '&& arr[r[i] + 1][c[i] - 1] == 'o') &&r[i] < 5 && c[i] >1 )
					V[i] = V[i] + 6;
				if(((arr[r[i] + 2][c[i] + 2] == 'o')|| (arr[r[i] + 2][c[i] + 2] == 'O')) && r[i] < 5 && c[i] < 5)
					V[i] = V[i] - 3;
				if((arr[r[i] + 2][c[i] - 2] == 'o' || arr[r[i] + 2][c[i] - 2] == 'O' )&& r[i] < 5 && c[i] >1)
					V[i] = V[i] - 3;
			}
			else if (((arr[r[i] + 1][c[i] + 1] == 'O') && c[i] < 6) || ((arr[r[i] + 1][c[i] - 1] == 'O') && c[i] > 0)) {
			if ((arr[r[i] + 2][c[i] + 2] == ' ' )&& r[i] < 5 && c[i] < 5)
				V[i] = V[i] + 7;
			if ((arr[r[i] + 2][c[i] - 2] == ' ') && r[i] < 5 && c[i] >1)
				V[i] = V[i] + 7;
			if (((arr[r[i] + 2][c[i] + 2] == 'o' || arr[r[i] + 2][c[i] + 2] == 'O') && r[i] < 5 && c[i] < 5))
				V[i] = V[i] - 2;
			if (((arr[r[i] + 2][c[i] - 2] == 'o') || (arr[r[i] + 2][c[i] - 2] == 'O')) && r[i] < 5 && c[i] >1)
				V[i] = V[i] - 2;
			}
			else if (((arr[r[i] + 1][c[i] + 1] == ' ') && c[i] < 6) || ((arr[r[i] + 1][c[i] - 1] == ' ') && c[i] > 0)) {
				if ((arr[r[i] + 1][c[i] + 1] == ' ' && c[i] < 6))
					V[i] = V[i] + 2;
				if((arr[r[i] + 1][c[i] - 1] == ' ') && c[i] > 0)
					V[i] = V[i] + 2;
				if (((arr[r[i] + 2][c[i] + 2] == 'o') || (arr[r[i] + 2][c[i] + 2] == 'O'))  && c[i] < 5)
					V[i] = V[i] - 3;
				if  (((arr[r[i] + 2][c[i] - 2] == 'o') || (arr[r[i] + 2][c[i] - 2] == 'O')) && c[i] >1)
					V[i] = V[i] - 3;
			}
			else if ((arr[r[i] + 1][c[i] + 1] == 'x') || (arr[r[i] + 1][c[i] - 1] == 'x')) {
				if (arr[r[i] + 1][c[i] + 1] == 'x' && c[i]<6)
					V[i] = V[i] - 3;
				if (arr[r[i] + 1][c[i] - 1] == 'x' && c[i] > 0)
					V[i] = V[i] - 3;
			}
		    else if ((arr[r[i] + 1][c[i] + 1] == 'X') || (arr[r[i] + 1][c[i] - 1] == 'X')) {
				if (arr[r[i] + 1][c[i] + 1] == 'X' && c[i] < 6)
					V[i] = V[i] - 3;
				if (arr[r[i] + 1][c[i] - 1] == 'X' && c[i] > 0)
					V[i] = V[i] - 3;
			}
			V[i] = V[i] + (r[i] / 3);//ค่าต่ำแหน่ง


		}
	}
	//จบการเช็คความสำคัญ
	//หมากตัวไหนควรเดินมากสุด
	for (i = 0; i != n; i++) {
		if (V[i] > max) {
			max = V[i];
			position = i;
		}
		else if (V[i] == max) {
			if (rand() % 2 == 0) {
				max = V[i];
				position = i;
			}
		}
	}

	for (i = 0; i !=n; i++) {
		printf("row %d colum %d vr %d max %d\n", r[i] + 1, c[i] + 1, V[i],max);
	}
	printf("position %d\n", position);
		//หมากเดิน
		if (arr[r[position]][c[position]] == 'x') {
		if ((arr[r[position] + 1][c[position] + 1] == 'o' || arr[r[position] + 1][c[position] + 1] == 'O') && (arr[r[position] + 1][c[position] - 1] == 'o' || arr[r[position] + 1][c[position] - 1] == 'O')) {
			if (rand() % 2 == 0 && arr[r[position] + 2][c[position] + 2] == ' '&& c[position]<5&& r[position]<5) {
				arr[r[position]][c[position]] = ' ';
				arr[r[position] + 1][c[position] + 1] = ' ';
				arr[r[position] + 2][c[position] + 2] = 'x';
			}
			else if ( arr[r[position] + 2][c[position] - 2] == ' ' && c[position] > 1 && r[position] < 5) {
				arr[r[position]][c[position]] = ' ';
				arr[r[position] + 1][c[position] - 1] = ' ';
				arr[r[position] + 2][c[position] - 2] = 'x';
			}
			else if ( arr[r[position] + 2][c[position] + 2] == ' ' && c[position] < 5 && r[position] < 5) {
				arr[r[position]][c[position]] = ' ';
				arr[r[position] + 1][c[position] + 1] = ' ';
				arr[r[position] + 2][c[position] + 2] = 'x';
			}
		}
		else if ((arr[r[position] + 1][c[position] + 1] == 'o' || arr[r[position] + 1][c[position] + 1] == 'O') && arr[r[position] + 2][c[position] + 2] == ' '&& c[position]<5&& r[position]<5) {
			arr[r[position]][c[position]] = ' ';
			arr[r[position] + 1][c[position] + 1] = ' ';
			arr[r[position] + 2][c[position] + 2] = 'x';
		}
		else if ((arr[r[position] + 1][c[position] - 1] == 'o' || arr[r[position] + 1][c[position] - 1] == 'O') && arr[r[position] + 2][c[position] - 2] == ' ' && c[position] > 1 && r[position] < 5) {
			arr[r[position]][c[position]] = ' ';
			arr[r[position] + 1][c[position] - 1] = ' ';
			arr[r[position] + 2][c[position] - 2] = 'x';
		}
		else if ((arr[r[position] + 1][c[position] + 1] == ' ' && arr[r[position] + 1][c[position] - 1] == ' ')) {
			if (rand() % 2 == 0 && c[position] != 6 && r[position] != 6) {
				arr[r[position]][c[position]] = ' ';
				arr[r[position] + 1][c[position] + 1] = 'x';

			}
			else if (c[position] != 0 && r[position] != 6) {
				arr[r[position]][c[position]] = ' ';
				arr[r[position] + 1][c[position] - 1] = 'x';
			}
			else if(c[position] != 6 && r[position] != 6) {
				arr[r[position]][c[position]] = ' ';
				arr[r[position] + 1][c[position] + 1] = 'x';

			}

		}
		else if ((arr[r[position] + 1][c[position] + 1] == ' ' || arr[r[position] + 1][c[position] - 1] == ' ')) {
			if (arr[r[position] + 1][c[position] + 1] == ' '&&c[position] != 6&&r[position]!=6) {
					arr[r[position]][c[position]] = ' ';
					arr[r[position] + 1][c[position] + 1] = 'x';

				}
		    else if (arr[r[position] + 1][c[position] - 1] == ' '&&c[position]!=0&& r[position]!=6) {
					arr[r[position]][c[position]] = ' ';
					arr[r[position] + 1][c[position] - 1] = 'x';

				}
		}
	   }
		else if (arr[r[position]][c[position]] == 'X') {
			for (i = 0, i1 = 0, j1 = 0, n = 0; i < 7; i++) {
				for (j = 0; j < 7; j++) {
					if (arr[i][j] == 'o' || arr[i][j] == 'O') {
						orr[i1] = i;
						oc[j1] = j;
						i1++;
						j1++;
						n++;
					}
				}
			}

			for (i = 0; i != n; i++) {
				b = 0;
				if (abs(r[position] - orr[i]) == abs(c[position] - oc[i])) {
					if (((orr[i] - r[position]) > 0) && ((oc[i] - c[position]) > 0) && (orr[i] != 7 && orr[i] != 0) && (oc[i] != 7 && oc[i] != 0)) {
						for (j = 1; r[position] + j != orr[i] && c[position] + j != oc[i]; j++) {
							if (arr[r[position] + j][c[position] + j] == 'x' || arr[r[position] + j][c[position] + j] == 'X')
							{
								b = 1;
								break;
							}
							else if ((arr[r[position] + j][c[position] + j] == 'o' || arr[r[position] + j][c[position] + j] == 'O') && arr[r[position] + j][c[position] + j] != arr[orr[i]][oc[i]]) {
								b = 1;
								break;
							}
							else if (arr[orr[i] + 1][oc[i] + 1] != ' ') {
								b = 1;
								break;
							}
						}
						if (b == 0 && arr[orr[i] + 1][oc[i] + 1] == ' ' && ((orr[i] - r[position]) > 0) && (oc[i] - c[position] > 0)) {
							arr[orr[i] + 1][oc[i] + 1] = 'X';
							arr[r[position]][c[position]] = ' ';
							arr[orr[i]][oc[i]] = ' ';

							break;
						}
					}
					else 	if (((orr[i] - r[position]) < 0) && ((oc[i] - c[position]) > 0) && (orr[i] != 7 && orr[i] != 0) && (oc[i] != 7 && oc[i] != 0)) {
						for (j = 1; r[position] - j != orr[i] && c[position] + j != oc[i]; j++) {
							if (arr[r[position] - j][c[position] + j] == 'x' || arr[r[position] - j][c[position] + j] == 'X')
							{
								b = 1;
								break;
							}
							else if (arr[r[position] - j][c[position] + j] == 'o' || arr[r[position] - j][c[position] + j] == 'O')
							{
								b = 1;
								break;
							}
							else if (arr[orr[i] - 1][oc[i] + 1] != ' ')
							{
								b = 1;
								break;
							}
						}
						if (b == 0 && arr[orr[i] - 1][oc[i] + 1] == ' ' && ((orr[i] - r[position]) < 0) && (oc[i] - c[position] > 0)) {
							arr[orr[i] - 1][oc[i] + 1] = 'X';
							arr[r[position]][c[position]] = ' ';
							arr[orr[i]][oc[i]] = ' ';

							break;
						}
					}
					else if (((orr[i] - r[position]) > 0) && ((oc[i] - c[position]) < 0) && (orr[i] != 7 && orr[i] != 0) && (oc[i] != 7 && oc[i] != 0)) {
						for (j = 1; r[position] + j != orr[i] && c[position] - j != oc[i]; j++) {
							if (arr[r[position] + j][c[position] - j] == 'x' || arr[r[position] + j][c[position] - j] == 'X')
							{
								b = 1;
								break;
							}
							else if (arr[r[position] + j][c[position] - j] == 'o' || arr[r[position] + j][c[position] - j] == 'O')
							{
								b = 1;
								break;
							}
							else if (arr[orr[i] + 1][oc[i] - 1] != ' ')
							{
								b = 1;
								break;
							}
						}
						if (b == 0 && arr[orr[i] + 1][oc[i] - 1] == ' ' && ((orr[i] - r[position]) > 0) && (oc[i] - c[position] < 0)) {
							arr[orr[i] + 1][oc[i] - 1] = 'X';
							arr[r[position]][c[position]] = ' ';
							arr[orr[i]][oc[i]] = ' ';

							break;
						}
					}
					else if (((orr[i] - r[position]) < 0) && ((oc[i] - c[position]) < 0) && (orr[i] != 7 && orr[i] != 0) && (oc[i] != 7 && oc[i] != 0)) {
						for (j = 1; r[position] - j != orr[i] && c[position] - j != oc[i]; j++) {
							if (arr[r[position] - j][c[position] - j] == 'x' || arr[r[position] - j][c[position] - j] == 'X')
							{
								b = 1;
								break;
							}
							else if (arr[r[position] - j][c[position] - j] == 'o' || arr[r[position] - j][c[position] - j] == 'O')
							{
								b = 1;
								break;
							}
							else if (arr[orr[i] - 1][oc[i] - 1] != ' ')
							{
								b = 1;
								break;
							}
						}
					}
					if (b == 0 && arr[orr[i] - 1][oc[i] - 1] == ' '&&((orr[i] - r[position]) < 0) && (oc[i] - c[position] < 0)) {
						arr[orr[i] - 1][oc[i] - 1] = 'X';
						arr[r[position]][c[position]] = ' ';
						arr[orr[i]][oc[i]] = ' ';
						break;
					}

				}
				for (n1 = 0,j1 = 1; r[position] + j1 != 7 && c[position] + j1 != 7; j1++) {
					if (arr[r[position] + j1][c[position] + j1] != ' ') {
						break;
					}
					x[n1] = r[position] + j1;
					y[n1] = c[position] + j1;
					n1++;
				}
				for (j1 = 1; r[position] - j1 >= 0 && c[position] + j1 != 7; j1++) {
					if (arr[r[position] - j1][c[position] + j1] != ' ') {
						break;
					}
					x[n1] = r[position] - j1;
					y[n1] = c[position] + j1;
					n1++;
				}
				for (j1 = 1; r[position] + j1 != 7 && c[position] - j1 >= 0; j1++) {
					if (arr[r[position] + j1][c[position] - j1] != ' ') {
						break;
					}
					x[n1] = r[position] + j1;
					y[n1] = c[position] - j1;
					n1++;
				}
				for (j1 = 1; r[position] - j1 >= 0 && c[position] - j1 >= 0; j1++) {
					if (arr[r[position] - j1][c[position] - j1] != ' ') {
						break;
					}
					x[n1] = r[position] - j1;
					y[n1] = c[position] - j1;
					n1++;
				}
				/*for (i = 0; i != n1; i++) {
					printf("row %d colum %d n=%d\n", x[i] + 1, y[i] + 1,n1);
				}*/
				pr = rand() %( n1 + 1);
				arr[r[position]][c[position]] = ' ';
				arr[x[pr]][y[pr]]='X';
				break;
			}
		}

}
void rule(char arr[7][7]) {
	int i, j,x,y,n=0,r=0,o=0;
	

	for (;;) {
		do {
			printf("select chess to move\n");
			printf("row ");
			scanf_s("%d", &i);
			printf("colum ");
			scanf_s("%d", &j);
		} while (i <= 0 || i > 7 || j <= 0 || j > 7);
		i=i-1;
		j=j-1;
		if (arr[i][j] == 'o' || arr[i][j] == 'O') {
			if (arr[i][j] == 'o') {
				
				do {
					printf("select position to move ");
					scanf_s("%d %d", &x, &y);
				}while(x <= 0 || x > 7 || y <= 0 || y > 7);
				x=x-1;
				y = y - 1;
				 if (((x == i - 2) && ((y == j - 2))  && (arr[x][y] == ' '&&(arr[x+1][y+1]=='x'|| arr[x + 1][y + 1]=='X')))) {
					arr[x][y] = arr[i][j];
					arr[x+1][y+1] = ' ';
					arr[i][j] = ' ';
					break;
				}
				 else if ((x == i - 2 && (y == j + 2)) && (arr[x][y] == ' ' && (arr[x + 1][y - 1] == 'x' || arr[x + 1][y - 1] == 'X'))) {
					 arr[x][y] = arr[i][j];
					 arr[x + 1][y - 1] = ' ';
					 arr[i][j] = ' ';
					 break;
				 }
				else if ((x != i - 1 || ((y != j - 1) && (y != j + 1))) || arr[x][y] != ' ')//เอาตำแหน่งที่ไปไม่ได้ออก
					printf("you can't go that position\n");
				
				else {
			              
						arr[x][y] = arr[i][j];
						arr[i][j] = ' ';
						break;
					
				}
			

			} 
			else if (arr[i][j] == 'O') {
				printf("select position to move ");
				scanf_s("%d %d", &x, &y);
				x = x - 1;
				y = y - 1;

				if (abs(x - i) != abs(y - j) || arr[x][y] != ' ')
				{
					printf("you can't go that position\n");

				}
				else if (((x - i) < 0) && ((y - j) < 0)) {
					o = 0;
					do {
						
						if (arr[x][y] == ' ') {
							if ((arr[i - n][j - n] == 'x' || arr[i - n][j - n] == 'X')) {
								r++;
								if (r == 2) {
									printf("you can't go that position\n");
									break;
								}
								else if ((i - n == x + 1) && (j - n == y + 1)) {
									arr[x][y] = arr[i][j];
									arr[i][j] = ' ';
									arr[x + 1][y + 1] = ' ';
									o = 1;
									break;
								}
								else if ((i - n != x + 1) && (j - n != y + 1))
								{
									printf("you can't go that position\n");
									break;
								}
							}
							else if (r==0&&(n==(abs(x-i)-1)))
							{
								arr[x][y] = arr[i][j];
								arr[i][j] = ' ';
								o = 1;
								break;
							}
						}
						
						n++;
						} while (n != abs(x - i));
						n = 0;	
				}
			
				else if (((x - i) < 0) && ((y - j) > 0))
				{
					o = 0;
					do {
						if (arr[x][y] == ' ') {
							if ((arr[i - n][j + n] == 'x' || arr[i - n][j + n] == 'X')) {
								r++;
								if (r == 2) {
									printf("you can't go that position\n");
									break;
								}
								else if ((i - n == x + 1) && (j + n == y - 1)) {
									arr[x][y] = arr[i][j];
									arr[i][j] = ' ';
									arr[x + 1][y - 1] = ' ';
									o = 1;
									break;
								}
								else if ((i - n != x + 1) && (j + n != y - 1))
								{
									printf("you can't go that position\n");
									break;
								}
							}
							else if (r == 0 && (n == (abs(x - i) - 1)))
							{
								arr[x][y] = arr[i][j];
								arr[i][j] = ' ';
								o = 1;

								break;
							}
						}
						n++;
					} while (n != abs(x - i));
					n = 0;
				}
				else if (((x - i) > 0) && ((y - j) < 0) )
				{
					do {
						o = 0;
						if (arr[x][y] == ' ') {
							if ((arr[i + n][j - n] == 'x' || arr[i + n][j - n] == 'X')) {
								r++;
								if (r == 2) {
									printf("you can't go that position\n");
									break;
								}
								else if ((i + n == x - 1) && (j - n == y + 1)) {
									arr[x][y] = arr[i][j];
									arr[i][j] = ' ';
									arr[x - 1][y + 1] = ' ';
									o = 1;
									break;
									
								}
								else if ((i + n != x - 1) && (j - n != y + 1))
								{
									printf("you can't go that position\n");
									break;

								}
							}
							else if (r == 0 && (n == (abs(x - i) - 1)))
							{
								arr[x][y] = arr[i][j]; 
								arr[i][j] = ' ';
								o = 1;
								break;
							}
						}
						n++;
					} while (n != abs(x - i));
					n = 0;
				}
				else if (((x - i) > 0) && ((y - j) > 0) )
				{
				o = 0;
				do {
						if (arr[x][y] == ' ') {
							if ((arr[i + n][j + n] == 'x' || arr[i + n][j + n] == 'X')) {
								r++;
								if (r == 2) {
									printf("you can't go that position\n");
									break;
								}
								else if ((i + n == x - 1) && (j + n == y - 1)) {
									arr[x][y] = arr[i][j];
									arr[i][j] = ' ';
									arr[x - 1][y - 1] = ' ';
									o = 1;
									break;
								}
								else if ((i + n != x - 1) && (j + n != y - 1))
								{
									printf("you can't go that position\n");
									break;
								}
						

							}
							else if (r == 0 && (n == (abs(x - i) - 1)))
							{
								arr[x][y] = arr[i][j];
								arr[i][j] = ' ';
								o = 1;
								break;
							}
						
						}
						n++;
					} while (n != abs(x - i));
					n = 0;
				}
				/*else
				{   
					
					arr[x][y] = arr[i][j];
					arr[i][j] = ' ';
					break;

				}*/
				if(o==1)
				{
					break;
				}
			
			}

		}
		else
			printf("there is no have your chess\n");
		

	}
	if (x == 0 && arr[x][y] == 'o')
		arr[x][y] = 'O';


	
	
}

void winornot(char* z, int* x, int* y)
{
	int cx, co, i, j;

	if (*z == 'x' || *z == 'X')
		(*x)++;

	else if (*z == 'o' || *z == 'O')
		(*y)++;


}
void table(char arr[7][7]) {

	int i = 0, c, r = 1, j = 0, cx = 0, co = 0;
	char pr;
	
	do {
		r = 1;
		cx = 0;
		co = 0;
	
		printf("    1 2 3 4 5 6 7\n");
		printf("   ---------------\n");
		for (i = 0; i < 7; i++) {
			for (j = 0; j < 7; j++) {
				if (j == 0) {
					printf("%d  |%c|", r, arr[i][j]);
					pr = arr[i][j];
					winornot(&pr, &cx, &co);
				}
				else if (j == 6) {
					printf("%c|\n", arr[i][j]);
					pr = arr[i][j];
					winornot(&pr, &cx, &co);
				}
				else {
					printf("%c|", arr[i][j]);
					pr = arr[i][j];
					winornot(&pr, &cx, &co);
				}

			}
			r++;
			if (i == 6)
				printf("   ---------------\n");
		}
		printf("Numble of O left %d\nNumble of X left %d\n", co, cx);
		if (cx == 0) {
			printf("your win\n");
			return;
		}
		else if (co == 0) {
			printf("Bot win\n");
			return;
		}
		rule(arr);
		bot(arr);
		for (i = 0; i < 7; i++) {
			for (j = 0; j < 7; j++) {
				if (arr[i][j] == 'x' && i == 6)
					arr[i][j] = 'X';

			}
		}


		

	} while (cx != 0 || co != 0);
}

int main() {
	int i, j;
	char chess[7][7] = { {'x',' ','x',' ','x',' ','x'},{' ','x',' ','x',' ','x',' ' },{' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' '},{' ','o',' ','o',' ','o',' ' },{'o',' ','o',' ','o',' ','o'} };
	
	table(chess);
	

	return 0;
}