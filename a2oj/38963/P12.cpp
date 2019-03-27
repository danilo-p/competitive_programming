#include <iostream>
using namespace std;

void print_sheet_side(int pages_number, int sheet_number, int front_page_1, int front_page_2, int back_page_1, int back_page_2) {
    if (front_page_1 <= pages_number || front_page_2 <= pages_number) {
        cout << "Sheet " << sheet_number
             << ", front: " << (front_page_1 > pages_number ? "Blank" : to_string(front_page_1))
             << ", " <<  (front_page_2 > pages_number ? "Blank" : to_string(front_page_2)) << endl;
    }
    if (back_page_1 <= pages_number || back_page_2 <= pages_number) {
        cout << "Sheet " << sheet_number
             << ", back : " << (back_page_1 > pages_number ? "Blank" : to_string(back_page_1))
             << ", " <<  (back_page_2 > pages_number ? "Blank" : to_string(back_page_2)) << endl;
    }
}

int main() {
    int pages_number,
        i,
        blank_pages,
        sheets_number,
        front_page_1,
        front_page_2,
        back_page_1,
        back_page_2,
        sheet_base;
    cin >> pages_number;
    while (pages_number) {
        cout << "Printing order for " << pages_number << " pages:" << endl;

        if (pages_number < 4) {
            sheets_number = 1;
            blank_pages = 4 - pages_number;
        } else if (pages_number % 4 == 0) { 
            sheets_number = (pages_number / 4);
            blank_pages = 0;
        } else {
            sheets_number = (pages_number / 4) + 1;
            blank_pages = 4 - (pages_number % 4);
        }

        for (i = 0; i < sheets_number; i += 1) {
            sheet_base = i * 2;
            front_page_1 = (pages_number + blank_pages) - sheet_base;
            front_page_2 = sheet_base + 1;
            back_page_1 = sheet_base + 2;
            back_page_2 = (pages_number + blank_pages) - sheet_base - 1;
            print_sheet_side(pages_number, i + 1, front_page_1, front_page_2, back_page_1, back_page_2);
            
        }
        cin >> pages_number;
    }
    return 0;
}