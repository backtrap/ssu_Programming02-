#ifndef USER_H
#define USER_H
#include <time.h>

typedef struct client_s{
    int studentnum;
    char password[15];
    char name[20];
    char address[30];
    char phonenum[20];
    struct client_s *next;
} client_s;

typedef struct book_s{
    int booknum;
    char bookname[30];
    char publisher[30];
    char author[20];
    long long ISBN;
    char location[30];
    char available;
    struct book_s *next;
} book_s;

typedef struct borrow_s{
    int studentnum;
    int booknum;
    time_t borrowdate;
    time_t returndate;
    struct borrow_s *next;
} borrow_s;

extern client_s *client_head;
extern book_s *book_head;
extern borrow_s *borrow_head;
extern int loop_main;


// main.c
void get_client(void);
void get_book(void);
void get_borrow(void);
void sort_clients(void); //              ?      
void sort_books(void); //              ?      
int libservice(void);
int membership(void);
int login(void);
// extern int loop_main;



// admin.c
void admin_func();
void register_book(void);
void delete_book(void);
void borrow_book(void);
void return_book(void);
void search_books(void);
void list_clients(void);
void save_books_to_file(void);
void save_borrows_to_file(void);
void save_all_data();

// client.c
void client_func(int id);
void searchBook(void);
void searchTitle(void);
void searchPublisher(void);
void searchISBN(void);
void searchAuthor(void);
void searchAll(void);
void myBook(int id);
void edit(int id);
void withdraw(int id);

#endif

