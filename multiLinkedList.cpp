#include<bits/stdc++.h>
using namespace std;

struct Student{
    int SID;
    Student *next;
};
struct Course{
    int CID;
    Student *stdList;
    Course *next;
};

// Course Functions
void insert(Course **head);
bool search(Course *head);
void print(Course *head);
void printWithStdList(Course *head);
void deleteRec(Course **head);
void deleteList(Course **head);
void totalCourses(Course *head);

// Student functions
void insertStd(Course **head);
int totalStudents(Student *head);
int searchStd(Course *head);
void printStdList(Course *head);
void deleteStdFromCourse(Course **head);
void deleteStd(Course **head);


int main(){
    Course *head=nullptr;
    int task=1;
    while(task!=0){
        cout<<"\n\nwhat task do you need to perform?\npress1 to insert value\npress2 to search\npress3 to print\npress 4 to print courses along with Student List\npress 5 to delete Course\npress 6 to delete All Courses\npress 7 for total Courses\npress 8 to add a student to a course\npress 9 to search a student in a course\npress 10 to see students enrolled in a specific course \npress 11 to unenroll student from a specific course \npress 12 to delete a Student\n press 0 to exit.";
        cin>>task;
        cout<<"\n";

        switch(task)
        {
        case 1:
            insert(&head);
            int c;
            cout<<"\nContinue inserting press1? ";
            cin>>c;
            while(c==1){
                insert(&head);
                cout<<"\nContinue inserting?";
                cin>>c;
            }
            break;
        
        case 2:
            if(head==nullptr)
                cout<<"\nlist is empty";
            else{
                bool found;
                found=search(head);
                if(found){
                    cout<<"\nIt is found\n";
                }
                else{
                    cout<<"\nnot found\n";
                }
            }
            break;
        
        case 3:
            print(head);
            break;

        case 4:
            printWithStdList(head);
            break;
        
        case 5:
            deleteRec(&head);
            break;
        
        case 6:
            deleteList(&head);
            break;

        case 7:
            totalCourses(head);
            break;
        
     
        case 8:
            insertStd(&head);
            int s;
            cout<<"\n\nPress1 to continue inserting? ";
            cin>>s;
            while(s==1){
                insertStd(&head);
                cout<<"\n\nPress1 to continue inserting?";
                cin>>s;
            }
            break;

        case 9:
            if(head==nullptr){
                cout<<"\nlist is empty";
                break;
            }
            int totalCourses;
            totalCourses=searchStd(head);
            if(totalCourses==0){
                cout<<"\n--Total Courses = 0\n";
            }
            else{
                cout<<"\n--Total Courses = "<<totalCourses;
            }
            break;

        case 10:
            printStdList(head);
            break;

        case 11:
            deleteStdFromCourse(&head);
            break;
        
        case 12:
            deleteStd(&head);
            break;
            
        default:
            cout<<"exited";
            exit(0);
            break;
        }
    }
    return 0;
}

void insert(Course **head){
    Course *curr;
    Course *ptr=(Course*)malloc(sizeof(Course));
    cout<<"\nEnter course ID: ";
    cin>>(ptr->CID);
    ptr->stdList=nullptr;
    ptr->next=nullptr;
    if(*head==nullptr){
        *head=ptr;
    }
    else{
        curr=*head;
        while(curr->next!=nullptr){
            curr=curr->next;
        }
        curr->next=ptr;
    }
}

bool search(Course *head){
    float toSearch;
    cout<<"Which Course you want to Search? \nEnter ID?";
    cin>>toSearch;
    Course *curr=head;
    bool found=false;
    while (!found)
    {
        if(curr->CID==toSearch){
            return true;
        }
        curr=curr->next;
    }
    return false;
}

void print(Course *head){
    if(head==nullptr){
        cout<<"\nNo Courses to offer";
    }
    Course *curr=head;
    while(curr!=nullptr){
        cout<<"\nCID: "<<curr->CID;
        cout<<"\nStudent Enrolled: "<<totalStudents(curr->stdList);
        curr=curr->next;
    }
}
void printWithStdList(Course *head){
    if(head==nullptr){
        cout<<"\nNo Courses to offer";
    }
    Course *curr=head;
    while(curr!=nullptr){
        cout<<"\nCID: "<<curr->CID;
        int stds=totalStudents(curr->stdList);
        cout<<"\nTotal Students Enrolled: "<<stds;
        if(stds!=0){
            Student *curr_Std=curr->stdList;
            while(curr_Std!=nullptr){
                cout<<"\nStudent ID: "<<curr_Std->SID;
                curr_Std=curr_Std->next;
            }
        }
        curr=curr->next;
    }
}

void deleteRec(Course **head){
    cout<<"enter ID whose Course you want to dlt: ";
    int toDlt;
    cin>>toDlt;
    Course *curr=*head;
    if(curr->CID==toDlt){
        *head=curr->next;
        free(curr);
    }
    else{
        Course *prev=curr;
        curr=curr->next;
        while(curr!=nullptr){
            if(curr->CID==toDlt){
                prev->next=curr->next;
                free(curr);
                break;
            }
            else{
                prev=prev->next;
                curr=curr->next;
            }
        }
    }
    if(curr==nullptr){
        cout<<"\nNo course of this ID.\n";
    }
    else{
        cout<<"\ndeleted";
    }
}

void deleteList(Course **head){
    Course *curr=*head;
    if(*head==nullptr){
        cout<<"\nlist is already empty";
        return;
    }
    while(*head!=nullptr){
        *head=curr->next;
        free(curr);
        curr=*head;
    }
    cout<<"\ndeleted";
    return;
}

void totalCourses(Course *head){
    int count=0;
    Course *curr=head;
    while(curr!=nullptr){
        curr=curr->next;
        count+=1;
    }
    cout<<"Total Records are " <<count;
}

void insertStd(Course **head){
    if(*head==nullptr){
        cout<<"\nNo Courses to offer";
    }
    else{
        // made ptr which stores new student
        Student *ptr=(Student*)malloc(sizeof(Student));
        cout<<"\nEnter Student ID: ";
        cin>>(ptr->SID);
        ptr->next=nullptr;
        cout<<"In which course you wants to enroll?";
        int s_CID;
        cin>>s_CID;
        Course *curr=*head;
        // curr is course one by one check krhu hun ksi ki cid match kri hai ya nh 
        while (curr!=nullptr){
            if(curr->CID==s_CID){
                break;
            }
            curr=curr->next;
        }
        if(curr==nullptr)
            cout<< "\nThere is no course of this course ID.";
        else{
            // now curr is the one which have the same CID jis m studnt store krna hai
            if(curr->stdList==nullptr){
                curr->stdList=ptr;
                // cout<<"\n"<<curr->CID<<" stdList in null";
            }
            else{
                Student *curr_std=curr->stdList;
                while(curr_std->next!=nullptr){
                    if(curr_std->SID==ptr->SID){
                        cout<<"\nThis student is already enrolled in course "<<curr->CID;
                        return;
                    }
                    // cout<<"\n"<<curr_std->SID<<" student id is stored";
                    curr_std=curr_std->next;
                }
                if(curr_std->SID==ptr->SID){
                    cout<<"\nThis student is already enrolled in course "<<curr->CID;
                    return;
                }
                curr_std->next=ptr;
                // cout<<"\n"<<curr->CID<<" stdList in not null";
            }
        }
    }
}

int totalStudents(Student *head){
    int count=0;
    Student *curr=head;
    while(curr!=nullptr){
        curr=curr->next;
        count+=1;
    }
    return count;
}

int searchStd(Course *head){
    float toSearch;
    cout<<"which Student you want to search enter ID?";
    cin>>toSearch;
    Course *curr=head;
    int courseEnrolled=0;
    while (curr!=nullptr)
    {
        Student *curr_Std=curr->stdList;
        while(curr_Std!=nullptr){
            if(curr_Std->SID==toSearch){
                cout<<"\nStudent Enrolled in Course: "<<curr->CID;
                courseEnrolled+=1;
                break;
            }
            curr_Std=curr_Std->next;
        }
        curr=curr->next;
    }
    return courseEnrolled;
}

void printStdList(Course *head){
    if(head==nullptr){
        cout<<"\nNo Courses to offer";
    }
    Course *curr=head;
    int courseID;
    cout<<"Which course enrollment list you want to see? \nEnter CID: ";
    cin>>courseID;
    while(curr!=nullptr){
        if(curr->CID==courseID){
            Student *curr_Std=curr->stdList;
            if(curr_Std==nullptr){
                cout<<"NO student enrolled in this course";
                return;
            }
            while(curr_Std!=nullptr){
                cout<<"\nStudent ID: "<<curr_Std->SID;
                curr_Std=curr_Std->next;
            }
            return;
        }
        curr=curr->next;
    }
    cout<<"There is no course of this ID";
}

void deleteStdFromCourse(Course **head){
    cout<<"Enter SID you want to unenroll: ";
    int SID_toDlt;
    cin>>SID_toDlt;

    cout<<"Enter CID: ";
    int courseID;
    cin>>courseID;
    
    Course *curr=*head;
    while(curr!=nullptr){
        if(curr->CID==courseID){
            Student *curr_std=curr->stdList;
            if(curr_std->SID==SID_toDlt){
                curr->stdList=curr_std->next;
                free(curr_std);
            }
            else{
                Student *prev=curr_std;
                curr_std=curr_std->next;
                while(curr_std!=nullptr){
                    if(curr_std->SID==SID_toDlt){
                        prev->next=curr_std->next;
                        free(curr_std);
                        break;
                    }
                    else{
                        prev=prev->next;
                        curr_std=curr_std->next;
                    }
                }
            }
            if(curr_std==nullptr){
                cout<<"\nNo Student of this ID is enrolled.\n";
                return;
            }
            else{
                cout<<"\ndeleted";
                return;
            }
        }
        curr=curr->next;
    }
    if(curr==nullptr)
        cout<<"There is no course of this ID";
    
}

void deleteStd(Course **head){
    cout<<"Enter Student ID: ";
    int SID_toDlt;
    cin>>SID_toDlt;
    
    Course *curr=*head;
    while(curr!=nullptr){
            Student *curr_std=curr->stdList;
            if(curr_std->SID==SID_toDlt){
                curr->stdList=curr_std->next;
                free(curr_std);
            }
            else{
                Student *prev=curr_std;
                curr_std=curr_std->next;
                while(curr_std!=nullptr){
                    if(curr_std->SID==SID_toDlt){
                        prev->next=curr_std->next;
                        free(curr_std);
                        break;
                    }
                    else{
                        prev=prev->next;
                        curr_std=curr_std->next;
                    }
                }
            }
        curr=curr->next;
    }    
    cout<<"\nDeleted";
}