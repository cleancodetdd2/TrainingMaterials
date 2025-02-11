#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>	// Windows API ���

// �ݺ��� ��� : ON - 1���� N���� ���ڸ� ���ϴ� ���
int sum_loop(int N) {
	int total = 0;
	for (int i = 1; i <= N; i++)	//N�� �ݺ��Ͽ� �ջ�
		total += i;
	return total;		// ���� �� ��ȯ 
}

// ���� ���� ��� : O(1) - �ܼ��� �������� ���
int sum_formula(int N) {
	return (N * (N + 1)) / 2;		//�������� �� ���� ��� 
}

int main()
{
	//�׽�Ʈ�� N�� �迭
	int N_values[] = { 10, 100, 1000, 10000, 50000, 1000000 };
	int size = sizeof(N_values) / sizeof(N_values[0]);	// �迭 ũ�� ���

	//���� �޸� �Ҵ� 
	double* times_loop = (double*)malloc(size * sizeof(double));	// O(N) ���� �ð� ���� 
	double* times_formula = (double*)malloc(size * sizeof(double));	// O(1) ���� �ð� ���� 

	//�޸� �Ҵ� ���� �� ���α׷� ����
	if (times_loop == NULL || times_formula == NULL) {
		fprintf(stderr, "�޸� �Ҵ� ������: ����� �޸𸮰� �����ϴ�.");
		free(times_loop);
		free(times_formula);
		return EXIT_FAILURE;
	}

	// ����� ������ ���� ���� (���� ���)
	FILE* fp;
	errno_t err = fopen_s(&fp, "result.txt", "w");
	if (err != 0 || fp == NULL) {
		fprintf(stderr, "������ �� �� �����ϴ�.\n");
		free(times_loop);
		free(times_formula);
		return EXIT_FAILURE;
	}

	fprintf(fp, "# N ����ð�(�ݺ���)  ����ð�(����)");		// ���Ͽ� ��� �ۼ�

	for (int i = 0; i < size; i++) {
		int N = N_values[i];			// ���� �׽�Ʈ�� N ��

		// O(N) ���� �ð� ����
		LARGE_INTEGER freq, start, end;
		QueryPerformanceFrequency(&freq);	// ���ػ� Ÿ�̸� ���ļ� ��������

		QueryPerformanceFrequency(&start);	// ���� �ð� ���
		sum_loop(N);						// �Լ� ����
		QueryPerformanceFrequency(&end);	// ���� �ð� ���

		double queryPerformance_loop = 
			(double)(end.QuadPart - start.QuadPart) / freq.QuadPart * 10000000;
		times_loop[i] = queryPerformance_loop;		//��� ���� 

		// O(1) ���� �ð� ����
		QueryPerformanceFrequency(&start);	// ���� �ð� ���
		sum_formula(N);						// �Լ� ����
		QueryPerformanceFrequency(&end);	// ���� �ð� ���

		double formula_loop =
			(double)(end.QuadPart - start.QuadPart) / freq.QuadPart * 10000000;
		times_formula[i] = formula_loop;		//��� ���� 

		//�ܼ� ���
		printf("N: %d | O(N) �ݺ��� ���: %.2f  ����ũ��s | O(1) ���� ���� ��� : %.2f ����ũ�� s\n",
				N, queryPerformance_loop, formula_loop);

		//���Ͽ� ����
		fprintf(fp, "%d %.2f %.2f\n", N, queryPerformance_loop, formula_loop);

	}

	fclose(fp);		// ���� �ݱ� 
	printf("\n ���� �Ϸ�! 'result.txt'�� ��� ����");

	FILE* gp = _popen("gnuplot", "w");	// gnuplot ���μ����� �����Ͽ� �������� ��
	if (gp) {
		fprintf(gp, "set title 'O(N) vs O(1) ���� �ð� ��'\n");  // �׷��� ����
		fprintf(gp, "set xlabel 'N ��'\n");  // X�� ��
		fprintf(gp, "set ylabel '���� �ð� (����ũ����)'\n");  // Y�� ��
		fprintf(gp, "set grid\n");  // �׸��� �߰�
		fprintf(gp, "plot 'result.txt' using 1:2 with linespoints title 'O(N) �ݺ���' linecolor rgb 'red', "
			"'result.txt' using 1:3 with linespoints title 'O(1) ����' linecolor rgb 'blue'\n");
		fprintf(gp, "pause mouse close\n");  // ���콺 Ŭ�� �� â ����
		fflush(gp);
		_pclose(gp);
		printf("\nGnuplot �׷����� �����߽��ϴ�. â���� Ȯ���ϼ���!\n");
	}
	else {
		fprintf(stderr, "Gnuplot ���� ����! ȯ�� ������ Ȯ���ϼ���.\n");
	}

	// ���� �޸� ����
	free(times_loop);
	free(times_formula);

	return 0;
}

