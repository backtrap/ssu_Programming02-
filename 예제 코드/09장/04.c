#include <stdio.h>

unsigned pack_employee_data(unsigned id_no, unsigned job_type, char gender) {
	unsigned employee = 0;
	employee |= id_no;
	employee |= job_type << 20;
	employee |= ((gender == 'm' || gender == 'M') ? 0 : 1) << 28;

	return employee;
}

void print_employee_data(unsigned employee) {
	unsigned id_no, job_type;
	char gender;
	id_no = employee & 0xFFFFF;
	job_type = (employee >> 20) & 0xFF;
	gender = (employee >> 28) & 1;

	printf("ID : %u", id_no);
	printf("작업 형태 : %u", job_type);
	printf("성별 : %s\n", gender ? "여" : "남");
}

int main() {
	return 0;
}
