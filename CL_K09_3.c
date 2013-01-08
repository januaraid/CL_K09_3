/*
作成者：1T1_33_矢内良介
課題名：課題09_3
*/

#include <stdio.h>
#include <stdlib.h>

int inputArray(char *, int *);
int binarySearch(int *, int, int, int);

int main(void)
{
	char name[256];
	int x[100], i, n;

	printf("ファイル名を入力してください：");
	fgets(name, 256, stdin);
	sscanf(name, "%s", name);

	for(i = 0; i < inputArray(name, x); i++) //配列xにデータを格納
		printf("配列x[%d]の値：%d\n", i, x[i]);

	printf("探索したいデータの値を入力してください：");
	scanf("%d", &n); //変数nに探索したい値を入力
	
	i = binarySearch(x, n, 0, i - 1); //iはこの時点で要素数+1の値を持っているので-1してから渡す
	if(i >= 0)
		printf("%dはx[%d]に格納されています\n", n, i);
	else
		printf("%dは見つかりません\n", n);


	return 0;
}

int inputArray(char name[], int x[])
{
	FILE *fp;
	int i;

	if((fp = fopen(name, "r")) == NULL){
		printf("エラー\n");
		exit(1);
	}

	for(i = 0; fscanf(fp, "%d", &x[i]) != EOF; i++);

	return i;
}

int binarySearch(int x[], int n, int b, int e)
{
	int i = (b + e) / 2, pivot = x[i];
	if(b > e)
		return -1;
	if(n == pivot)
		return i;
	else if(n > pivot)
		return binarySearch(x, n, i + 1, e);
	else
		return binarySearch(x, n, b, i - 1);

}