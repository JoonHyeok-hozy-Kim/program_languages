#include "library.h"

int library_run() {

	int user_choice;
	int num_total_book = 0;
	Book* book_list;
	printf("Input the maximum number of books that will be managed : ");
	scanf("%d", &user_choice);
	book_list = (Book*)malloc(sizeof(Book) * user_choice);

    user_choice = 0;
	while (user_choice != 9) {
        switch (user_choice) {
        case 1:
            user_choice = register_book(book_list, &num_total_book);
            break;
        case 2:
            user_choice = search_book(book_list, num_total_book);
            break;
        case 3:
            user_choice = borrow_book(book_list);
            break;
        case 4:
            user_choice = return_book(book_list);
            break;
        case 5:
            user_choice = print_book_list(book_list, num_total_book);
            break;
        default:
            printf("\n[ Libraray Manament Program ] \n");
            printf(" - Choose the menu. \n");
            printf("1. Register a new book. \n");
            printf("2. Search a book. \n");
            printf("3. Borrow a book. \n");
            printf("4. Return a book. \n");
            printf("5. Print book list. \n");
            printf("9. Exit. \n\n");
            printf("Your choice is : ");
            scanf("%d", &user_choice);
            break;
        }
	}

    free(book_list);
    printf("Bye~\n");
    return 0;
}

int register_book(Book* book_list, int* nth) {

    book_list[*nth].id = (*nth);
    printf("Book Title : ");
    scanf("%s", book_list[*nth].book_name);
    printf("Author Name : ");
    scanf("%s", book_list[*nth].auth_name);
    printf("Publisher Name : ");
    scanf("%s", book_list[*nth].publ_name);
    book_list[*nth].borrowed = 0;

    (*nth)++;
    return 0;
}

int search_book(Book* book_list, int total_num_book) {

    int user_input, found_idx = -1;
    int i;
    char user_search[30];
    char* search_type[3] = { "title", "author", "publisher" };

    printf("Search Book by...\n");
    for (i = 0; i < 3; i++) {
        printf("%d. %s\n", i + 1, search_type[i]);
    }

    printf("Input search type by number : ");
    scanf("%d", &user_input);

    printf("Input %s : ", search_type[user_input - 1]);
    scanf("%s", user_search);

    switch (user_input) {
    case 1:
        for (i = 0; i < total_num_book; i++) {
            if (!(strcmp(book_list[i].book_name, user_search))) {
                found_idx = i;
                break;
            }
        }
        break;
    case 2:
        for (i = 0; i < total_num_book; i++) {
            if (!(strcmp(book_list[i].auth_name, user_search))) {
                found_idx = i;
                break;
            }
        }
        break;
    case 3:
        for (i = 0; i < total_num_book; i++) {
            if (!(strcmp(book_list[i].publ_name, user_search))) {
                found_idx = i;
                break;
            }
        }
        break;
    default:
        printf("Wrong number input. End search.\n");
        return 1;
    }

    if (found_idx >= 0) {
        //printf("[%d] %s / %s / %s\n", book_list[found_idx].id, book_list[found_idx].book_name, book_list[found_idx].auth_name, book_list[found_idx].publ_name);
        print_book_info(book_list, found_idx);
    }
    else {
        printf("No data found. End search.\n");
    }

    return 0;
}

int borrow_book(Book* book_list) {

    int book_id;
    printf("Input the ID of the book you wish to borrow : ");
    scanf("%d", &book_id);

    if (book_id < sizeof(book_list) / sizeof(Book)) {
        if (book_list[book_id].borrowed) {
            printf("Book not available.\n");
            print_book_info(book_list, book_id);
        }
        else {
            book_list[book_id].borrowed = 1;
            printf("Successfully borrowed!\n");
            print_book_info(book_list, book_id);
        }
    }

    return 0;
}

int return_book(Book* book_list) {
    return 0;
}

void print_book_info(Book* book_list, int book_id) {
    printf("\n----------------\n");
    printf("Book ID   : %d\n", book_list[book_id].id);
    printf("Title     : %s\n", book_list[book_id].book_name);
    printf("Author    : %s\n", book_list[book_id].auth_name);
    printf("Publisher : %s\n", book_list[book_id].publ_name);
    printf("Available : ");
    if (book_list[book_id].borrowed){
        printf("N");
    }
    else {
        printf("Y");
    }
    printf("\n----------------\n");
}


int print_book_list(Book* book_list, int num_total_book) {
    int i; 

    printf(" ID      Title                          Author                         Publisher                 Available\n");
    for (i = 0; i < num_total_book; i++) {
        printf("%3d %30s %30s %30s ", book_list[i].id, book_list[i].book_name, book_list[i].auth_name, book_list[i].publ_name);
        if (book_list[i].borrowed) {
            printf("   N\n");
        }
        else {
            printf("   Y\n");
        }
    }
    return 0;
}