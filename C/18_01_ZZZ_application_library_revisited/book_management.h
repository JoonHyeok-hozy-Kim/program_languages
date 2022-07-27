struct Book;

void book_management();
int add_book(struct Book* book_list, int* book_cnt);

void display_book_status(struct Book* book_list, int book_cnt);
void find_book_by_n(struct Book* book_list, int book_cnt, int n);

void display_available_books(struct Book* book_list, int book_cnt);
struct Book validate_book(struct Book* book_list, int book_cnt, int book_id);
int borrow_book(struct Book* book_list, int book_cnt);
int return_book(struct Book* book_list, int book_cnt);