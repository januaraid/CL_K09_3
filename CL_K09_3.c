/*
�쐬�ҁF1T1_33_����ǉ�
�ۑ薼�F�ۑ�09_3
*/

#include <stdio.h>
#include <stdlib.h>

int inputArray(char *, int *);
int binarySearch(int *, int, int, int);

int main(void)
{
	char name[256];
	int x[100], i, n;

	printf("�t�@�C��������͂��Ă��������F");
	fgets(name, 256, stdin);
	sscanf(name, "%s", name);

	for(i = 0; i < inputArray(name, x); i++) //�z��x�Ƀf�[�^���i�[
		printf("�z��x[%d]�̒l�F%d\n", i, x[i]);

	printf("�T���������f�[�^�̒l����͂��Ă��������F");
	scanf("%d", &n); //�ϐ�n�ɒT���������l�����
	
	i = binarySearch(x, n, 0, i - 1); //i�͂��̎��_�ŗv�f��+1�̒l�������Ă���̂�-1���Ă���n��
	if(i >= 0)
		printf("%d��x[%d]�Ɋi�[����Ă��܂�\n", n, i);
	else
		printf("%d�͌�����܂���\n", n);


	return 0;
}

int inputArray(char name[], int x[])
{
	FILE *fp;
	int i;

	if((fp = fopen(name, "r")) == NULL){
		printf("�G���[\n");
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