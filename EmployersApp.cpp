#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

typedef struct
{
	char name[50];
	char job[50];
	int salary;
} Employee;

Employee list[100];  //Main employees array
Employee *ptrAr[100], *temp_ptr; //Employees array`s pointers array

class Dms {

public:
    void rm(){ //Clear database
        ofstream ers("file.dat", ios_base::binary | ios_base::trunc);
        ers.close();
    }

    int get_amount(){ //Counts amount of employees written based on size of file
        ifstream fin("file.dat", ios_base::binary);
        fin.seekg(0, ios_base::end);
        int size = fin.tellg();
        fin.close();
        return size / sizeof(Employee);
    }

    void set_pointers(){
        for(int i = 0; i < get_amount(); i++)
            ptrAr[i] = &list[i];
    }

    void get(int how_much){ //Read data from database
        ifstream fin;
        fin.open("file.dat", ios_base::in | ios_base::binary);
        fin.read((char*)list, how_much*sizeof(Employee));
        fin.close();
        set_pointers();
    }

    void write(Employee to_write){ //Write data to database
        ofstream fout;
        fout.open("file.dat", ios_base::binary | ios_base::app );
        fout.write((char*)&to_write, sizeof(Employee));
        fout.close();
    }

    void sort_ptr(){ //sorts employees
        Employee temp[100];
        int amount = get_amount();
        set_pointers();
        for(int i = 0; i < get_amount() - 1; i++){
            for(int j = 0; j < get_amount() - i - 1; j++){
                if(*ptrAr[j]->name > *ptrAr[j+1]->name){
                    temp_ptr = ptrAr[j];
                    ptrAr[j] = ptrAr[j+1];
                    ptrAr[j+1] = temp_ptr;
                }
            }
        }
        rm();
        for(int i = 0; i < amount; i++){
            write(*ptrAr[i]);
        }
    }
};


int get_menu_pos() {
    int menu_pos;
    cout << "\n       SELECT OPTION:      \n"
         << "1 - Read DB\n"
         << "2 - Write data to DB\n"
         << "3 - Clear DB\n"
         << "4 - Sort employees by name\n"
         << "5 - How much is written\n"
         << "6 - Exit DMS\n";

    cout << ">>> ";
    cin >> menu_pos;
    return menu_pos;
}

int main() {
    bool run = true;
    int how_much = 0;
	Employee temp; //Initializing temporary variable as writing buffer

	Dms my_dms; //Initializing DBMS

    my_dms.get_amount(); //Count amount of written employees

    while(run){ //Menu
        int selected_menu_pos = get_menu_pos();
        switch(selected_menu_pos){
        case 1:
            my_dms.get(my_dms.get_amount());
            for(int i = 0; i < my_dms.get_amount(); i++){
                cout << ptrAr[i]->name << " " << ptrAr[i]->job << " " << ptrAr[i]->salary << endl;
            }

            cout << "\n===============================\n";
            break;
        case 2:
            cout << "How much employees do you want to add\n";
            cin >> how_much;
            for(int i = 0; i < how_much; i++){
                cin >> temp.name >> temp.job >> temp.salary;
                my_dms.write(temp);
            }

            cout << "\n===============================\n";
            break;
        case 3:
            my_dms.rm();
            break;
        case 4:
            my_dms.sort_ptr();
            break;
        case 5:
            cout << my_dms.get_amount() << "\n";
            break;
        case 6:
            run = false;
            break;
        }
    }
	return 0;
}
