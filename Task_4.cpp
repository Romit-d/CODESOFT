#include<iostream>
#include<vector>
using namespace std;

class Task{
    public:
        string sentense;
        bool taskcomplete;
};

class todolist{
    vector <Task> v;                                     // vector name - v;
    public:
        void addtask(const string& sentense){
            Task newt;                                  // Class Task -> object : newt;
            newt.sentense = sentense;
            newt.taskcomplete = false;
            v.push_back(newt);
            cout<<"Task Added Successfully"<<endl;
        }

        void taskview() const{
            if(v.empty()){
                cout<<"Oops !! No Task Availabe"<<endl;
            }
            for(size_t i = 0; i < v.size(); i++){
                cout<< i + 1<<". "<< v[i].sentense<<(v[i].taskcomplete ? "  [Completed]" : "  [Pending]")<<endl;
            }
        }
        void taskcompleted(int option){
            if(option < 1 || option > v.size()){
                cout<<"Invalid Input !!"<<endl;
            }
            v[option - 1].taskcomplete = true;
            cout<<"Hoorah!! Task Accomplished."<<endl; 
        }

        void deletetask(int option){
            if(option < 1 || option > v.size()){
                cout<<"Invalid Input !!"<<endl;
            }
            v.erase(v.begin() + (option - 1));
            cout<<"Task Deleted !!"<<endl;
        }
};
int main(){
    int choice;                               // choice - taking input of the main menu
    todolist ref;                            //  **ref - object of 2dolist class
    string sentense;
    int tasknumber;                         //  tasknumber - for taking input of the 3 & 4
     cout<<"\nTo Do List\n"<<endl;
    do{
        cout<<"------------"<<endl;
        cout<<"1. Add Task"<<endl;
        cout<<"2. View Task"<<endl;
        cout<<"3. Delete Task"<<endl;
        cout<<"4. Mark Task as Completed"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"------------"<<endl;
        cout<<"Enter an option - ";
        cin>>choice;
        switch (choice){
            case 1:
                cout<<"Enter the Task -  ";
                cin.ignore();
                getline(cin, sentense);
                ref.addtask(sentense);
                break;

            case 2:
                ref.taskview();
                break;
            
            case 3:
                cout<<"Enter the the Task number, You want to Delete - ";
                cin>>tasknumber;
                ref.deletetask(tasknumber);
                break;
                    
            case 4:
                cout<<"Enter the Option : ";
                cin>>tasknumber;
                ref.taskcompleted(tasknumber);
                break;
            
            case 5:
                cout<<"Exiting..."<<endl;
                cout<<"Keep Grwoing"<<endl;
                break;

            default:
                cout<<"Invalid option !!";
                break;
        }
    }while(choice != 5);
    
}