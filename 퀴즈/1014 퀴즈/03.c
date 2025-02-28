#include <stdio.h>

unsigned long long pack_employee_data(unsigned id_no, unsigned job_type, unsigned salary, unsigned family);
void print_employee_data(unsigned long long employee);

int main() {
	unsigned id_no, salary, job_type, family;

	print_employee_data(pack_employee_data(999999, 999, 999999999, 9)); // 최대값

	return 0;

}

unsigned long long pack_employee_data(unsigned id_no, unsigned job_type, unsigned salary, unsigned family) { // 코드 작성
	unsigned long long employee = 0;
	employee |= family;
	employee |= salary << 4;
	employee |= job_type << 30;
	employee |= id_no << 10;

	return employee;
}

void print_employee_data(unsigned long long employee) { // 코드 작성
	unsigned id_no, job_type, salary, family;

	id_no = employee & 0xFFFFF;
	job_type = (employee >> 10) & 0xFF3;
	salary = (employee >> 30) & 0xFFFFE;
	family = (employee >> 4) & 0xF;

	printf("ID는 %u, 작업 형태는 %u, 연봉은 %u, 부양 가족은 %u입니다.\n", id_no, job_type, salary, family);
}
