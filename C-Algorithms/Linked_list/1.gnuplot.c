#include <stdio.h>
#include <stdlib.h>

int main()
{
	//gnuplot ������ ���� ������(FILE ������) ����
	FILE* gp = _popen("gnuplot", "w");	// gnuplot ���μ����� �����Ͽ� �������� ��
	if (gp) {	// gnuplot ������ �����ϸ�
		fprintf(gp, "set title 'Gnuplot �׽�Ʈ ����'\n");	//�׷��� ���� ����
		fprintf(gp, "plot sin(x)\n");	// sin(x) �Լ��� �׷����� ���
		fprintf(gp, "pause -1\n");	// �׷��� â �����ǵ��� ����
		fflush(gp);	// ���۸� ���� ��� -> gnuplot ��� ��� �����ϵ��� ��

		printf("gnuplot ���� ����!\n");
		getchar();		// ����� �Է� ���

		_pclose(gp);	// gnuplot ���μ����� �ݰ� �������� ����
	}
	else
		fprintf(stderr, "gnuplot ���� ����! ȯ�� ���� Ȯ���ϼ���!\n");


	return 0;
}