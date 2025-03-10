#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "user.h"

void print_date(time_t date) {
    struct tm *tm_info = localtime(&date);
    printf("%04d-%02d-%02d", 
           tm_info->tm_year + 1900, 
           tm_info->tm_mon + 1, 
           tm_info->tm_mday);
}

int main() {
    // Writing data to the file
    FILE *fp = fopen("./borrow.txt", "wb");
    if (!fp) {
        perror("File opening failed");
        return 1;
    }

    borrow_s st[30] = {
        {20221111, 1000001, 1696723200, 1699324800}, // Example entries
        {20221112, 1000002, 1696809600, 1699411200},
        {20231113, 1000003, 1696896000, 1699497600},
        {20231114, 1000004, 1696982400, 1699584000},
        {20241115, 1000005, 1697068800, 1699670400},
        {20241116, 1000006, 1697155200, 1699756800},
        {20221117, 1000007, 1697241600, 1699843200},
        {20231118, 1000008, 1697328000, 1699929600},
        {20241119, 1000009, 1697414400, 1700016000},
        {20221120, 1000010, 1697500800, 1700102400},
        {20231121, 1000011, 1697587200, 1700188800},
        {20241122, 1000012, 1697673600, 1700275200},
        {20221123, 1000013, 1697760000, 1700361600},
        {20231124, 1000014, 1697846400, 1700448000},
        {20241125, 1000015, 1697932800, 1700534400},
        {20221126, 1000016, 1698019200, 1700620800},
        {20231127, 1000017, 1698105600, 1700707200},
        {20241128, 1000018, 1698192000, 1700793600},
        {20221129, 1000019, 1698278400, 1700880000},
        {20231130, 1000020, 1698364800, 1700966400},
        {20241101, 1000021, 1698451200, 1701052800},
        {20221102, 1000022, 1698537600, 1701139200},
        {20231103, 1000023, 1698624000, 1701225600},
        {20241104, 1000024, 1698710400, 1701312000},
        {20221105, 1000025, 1698796800, 1701398400},
        {20231106, 1000026, 1698883200, 1701484800},
        {20241107, 1000027, 1698969600, 1701571200},
        {20221108, 1000028, 1699056000, 1701657600},
        {20231109, 1000029, 1699142400, 1701744000},
        {20241110, 1000030, 1699228800, 1701830400},
    };

    for (int i = 0; i < 30; i++) {
        fwrite(&st[i], sizeof(borrow_s), 1, fp);
    }
    fclose(fp);

    // Reading and printing data from the file
    fp = fopen("./borrow.txt", "rb");
    if (!fp) {
        perror("File reading failed");
        return 1;
    }

    borrow_s entry;
    printf("학번       | 도서번호   | 대여일자     | 반납일자\n");
    printf("--------------------------------------------\n");
    while (fread(&entry, sizeof(borrow_s), 1, fp)) {
        printf("%d | %d | ", entry.studentnum, entry.booknum);
        print_date(entry.borrowdate);
        printf(" | ");
        print_date(entry.returndate);
        printf("\n");
    }

    fclose(fp);
    return 0;
}
