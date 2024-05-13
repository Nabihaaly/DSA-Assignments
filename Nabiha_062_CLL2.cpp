// CIRCULAR LINKED LIST 

#include<bits/stdc++.h>
using namespace std;

struct Record{
    int index;
    int RollNo;
    float GPA;
    Record *next;
};

void insert(Record **head);
bool search(Record *head);
void print(Record *head);
void deleteRec(Record **head);
void deleteList(Record **head);
void totalRec(Record *head);

int main(){
    Record *head=nullptr;
    int task=1;
    while(task!=0){
        cout<<"\n\nwhat task do you need to perform? \npress1 to insert value\npress2 to search\npress3 to print\npress 4 to delete Record\npress 5 to delete List\npress 6 for total count in the list\npress 7 to exit.";
        cin>>task;

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
            bool found;
            found=search(head);
            if(!found){
                cout<<"\nnot found\n";
            }
            // }
            break;
        
        case 3:
            print(head);
            break;
        
        case 4:
            deleteRec(&head);
            break;
        
        case 5:
            deleteList(&head);
            break;

        case 6:
            totalRec(head);
            break;
        
        default:
            cout<<"exited";
            exit(0);
            break;
        }
    }

    return 0;
}

void insert(Record **head){
    Record *curr;
    Record *ptr=(Record*)malloc(sizeof(Record));
    cout<<"\nEnter rollno and gpa: ";
    cin>>(ptr->RollNo);
    cin>>(ptr->GPA);
    ptr->index=0;
    ptr->next=nullptr;
    if(*head==nullptr){
        ptr->next=ptr;
        *head=ptr;
    }
    else{
        curr=*head;
        if(curr->RollNo>ptr->RollNo){
            ptr->next=curr;
            curr->index+=1;
            *head=ptr;
            while(curr->next!=(*head)->next){
                curr->next->index+=1;
                curr=curr->next;
            }
            curr->next=*head;
            return;
        }
        while(curr->next!=*head){
            if(curr->next->RollNo>ptr->RollNo){
                ptr->index=curr->index+1;
                ptr->next=curr->next;
                curr->next=ptr;
                curr=curr->next;
                while(curr->next!=*head){
                    curr->next->index=curr->index+1;
                    curr=curr->next;
                }
                return;
            }
            curr=curr->next;
        }
        ptr->next=*head;
        ptr->index=curr->index+1;
        curr->next=ptr;
        // cout<<"  head "<<*head;
        // cout<<" curr next"<<curr->next->next;
    }
}
bool search(Record *head){
    if(head==nullptr){
        cout<<"\nlist is empty";
    }
    cout<<"what do you want to search? press1: RollNO or press2: GPA? ";
    // asking what user is searching for 1. rollno 2. gpa
    int field;
    cin>>field;
    string search;
    if(field==1){
        search="RollNo";
    }
    else if(field==2){
        search="GPA";
    }
    // input number user is searching for
    float toSearch;
    cout<<"which "+search+" you want to search?";
    cin>>toSearch;
    Record *curr=head;
    bool found=false;
    while (!found)
    {
        if(search=="RollNo"){
            if(curr->RollNo==toSearch){
                cout<<"\nThe GPA of RollNo."<<toSearch<<" is "<<curr->GPA;
                return true;
            }
            else{
                if(curr->next==head){
                    return false;
                }
                curr=curr->next;
            }
        }
        else if(search=="GPA"){
            if(curr->GPA==toSearch){
                cout<<"\nThe GPA of RollNo."<<toSearch<<" is "<<curr->GPA;
                return true;
            }
            else{
                if(curr->next==head){
                    return false;
                }
                curr=curr->next;
            }
        }
    }
    
}
void print(Record *head){
    if(head==nullptr || head==NULL){
        cout<<"\nlist is empty";
        return;
    }
    Record *curr=head;
    while(curr->next!=head){
        cout<<"\nRollNO: "<<curr->RollNo;
        cout<<", GPA: "<<curr->GPA;
        cout<<", Index: "<<curr->index;
        curr=curr->next;
    }
    if(curr->next==head){
        cout<<"\nRollNO: "<<curr->RollNo;
        cout<<", GPA: "<<curr->GPA;
        cout<<", Index: "<<curr->index;
    }
}
void deleteRec(Record **head){
    if(*head==nullptr){
        cout<<"\nlist is already empty";
        return;
    }
    cout<<"enter rollno whose record you want to dlt: ";
    int toDlt;
    cin>>toDlt;
    if((*head)->next==*head){
        if((*head)->RollNo==toDlt){
            free(*head);
            *head=nullptr;
            cout<<"\ndeleted";
        }
        else{
            cout<<"\nRecord of this rollNo is not stored.\n";
        }
        return;
    }
    Record *curr=*head;
    if(curr->RollNo==toDlt){
        Record *prevHead=curr;
        *head=curr->next;
        while(curr->next!=prevHead){
            curr->next->index=curr->index+1;
            curr=curr->next;
        }
        curr->next=*head;
        free(prevHead);
        cout<<"\ndeleted";
        return;
    }
    else{
        Record *prev=curr;
        curr=curr->next;
        while(curr!=*head){
            if(curr->RollNo==toDlt){
                prev->next=curr->next;
                curr->next->index=curr->index;
                free(curr);
                curr=prev->next;
                while(curr->next!=*head){
                    curr->next->index=curr->index+1;
                    curr=curr->next;
                }
                break;
            }
            else{
                prev=prev->next;
                curr=curr->next;
            }
        }
    }
    if(curr==*head){
        cout<<"\nRecord of this rollNo is not stored.\n";
    }
    else{
        cout<<"\ndeleted";
    }
}
void deleteList(Record **head){
    if(*head==nullptr){
        cout<<"\nlist is already empty";
        return;
    }
    if(*head==(*head)->next){
        free(*head);
        *head=nullptr;
        cout<<"\ndeleted";
        return;
    }
    Record *curr=*head;
    Record *last=*head;
    while (last->next!=*head){
        last=last->next;
    }
    while( last!=*head){
        *head=curr->next;
        last->next=*head;
        free(curr);
        curr=*head;
    }
    free(*head);
    *head=nullptr;

    cout<<"\ndeleted";
    return;
}

void totalRec(Record *head){
    int count=0;
    Record *curr=head;
    while(curr->next!=head){
        count+=1;
        curr=curr->next;
    }
    count+=1;
    cout<<"Total Records are " <<count;
}