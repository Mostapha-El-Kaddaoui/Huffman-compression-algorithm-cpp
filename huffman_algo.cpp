#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <string.h>
using namespace std;

char arr_occ[30];
char arr_key[30];
string arr_code[30];
int nbr_caract;

class noeud{
    public:
    string caract;
    int occ;
    char bit;
    noeud *next_ptr;
    noeud *parent_noeud;
};

class Huffman{
    private:
        noeud* head;

    public:
        Huffman():head(NULL){}
        void append(string caract, int occ){
            noeud *new_noeud = new noeud{caract, occ, NULL};
            if (head == NULL) {
                head = new_noeud;
            } else {
                noeud *current = head;
                while (current->next_ptr != NULL) {
                    current = current->next_ptr;
                }
                current->next_ptr = new_noeud;// Connect new node to the end of the list
            }
        }
        void trace(){
            noeud *current=head;
            while(current!= NULL){
                //cout << current->caract<<" : "<<current->occ <<endl;
                current=current->next_ptr;
            }
        }
        void trace_g(){
              for(int i=0;i<nbr_caract;i++){
                noeud *current=head;
                string code="";
                for(int j=0;j<i;j++){
                    current=current->next_ptr;
                }
                arr_key[i]=(current->caract)[0];
                while(current->parent_noeud != NULL){
                    code=code+current->bit;
                    //cout << current->caract<<" : "<<current->bit <<endl;
                    current=current->parent_noeud;
                }
                arr_code[i]=code;
              //  cout<<arr_key[i]<<" : "<<arr_code[i]<<endl;
              }

        }
        void two_min(){
            noeud *current1 = head;
            noeud *min_node1 = current1;
            int min_occ1 = current1->occ;
            while (current1 != NULL) {
                if (current1->occ <= min_occ1 && current1->occ!=1000) {
                    min_occ1 = current1->occ;
                    min_node1 = current1;
                }
                current1 = current1->next_ptr;
            }
            min_node1->bit='1';
            //cout <<"1 : "<<min_node1->caract  << endl;
            noeud *current2 = head;
            noeud *min_node2 = current2;
            int min_occ2 = current2->occ;
            while (current2 != NULL) {
                    if(current2->caract!=min_node1->caract && current2->occ!=1000){
                        if (current2->occ <= min_occ2) {
                            min_occ2= current2->occ;
                            min_node2 = current2;
                        }
                    }else{
                     //   cout<<"kif kif "<< current2->caract <<" : "<<min_node1->caract<<endl;
                    }

                current2 = current2->next_ptr;
            }
            min_node2->bit='0';
            //cout <<"2 : "<<min_node2->caract << endl;
            noeud *new_noeud = new noeud{min_node1->caract+min_node2->caract,min_node1->occ+min_node2->occ, NULL};
            if (head == NULL) {
                head = new_noeud;
            } else {
                noeud *current = head;
                while (current->next_ptr != NULL) {
                    current = current->next_ptr;
                }
                current->next_ptr = new_noeud;
            }
            min_node1->occ=1000;
            min_node2->occ=1000;
            min_node1->parent_noeud=new_noeud;
            min_node2->parent_noeud=new_noeud;
        }
    };
int ex_in_arr(char find_c){
    int l=0;
    for(int i=0;i<26;i++){
        if(find_c==arr_occ[i]){
            l=1;
            break;
        }
    }
    return l;
}
string enc_r(string s){
    int index_carr=0;
    Huffman tree_c;
    for(int j=0;j<s.length();j++){
        int count_c=0;
        if(!ex_in_arr(s[j])){
            for(int i=0;i<s.length();i++){
                if(s[j]==s[i]){
                    count_c++;
                }
            }
            arr_occ[index_carr]=s[j];
            index_carr++;
            nbr_caract++;
            tree_c.append(string(1,s[j]),count_c);
        }
    }
    for(int j=0;j<nbr_caract-1;j++){
        tree_c.two_min();

    }
    tree_c.trace();
    tree_c.trace_g();
    string string_enc;
    for(int j=0;j<nbr_caract;j++){
        cout <<arr_key[j]<<" : "<<arr_code[j]<<endl<<endl;
    }
    for(int j=0;j<s.length();j++){
        for(int i=0;i<30;i++){
           if(s[j]==arr_key[i]){
              string_enc=string_enc+arr_code[i]+" ";
           }

        }
    }
    cout <<"Codage Huffman : \n \n"<<string_enc<<endl;
    return string_enc;
}

void dec_r(string coded_s,file filename){
    cout <<"\nDecodage : \n"<<endl;
    char str[coded_s.length() + 1];
    strcpy(str, coded_s.c_str());

    char *token = strtok(str, " ");
    while (token != NULL)
    {
        for(int i=0;i<30;i++){
            if(arr_code[i]==token){
                cout<<arr_key[i];
            }
        }
        token = strtok(NULL, " ");
    }
}
int main() {
    cout << " _   _        __  __                              \n";
    cout << "| | | |_   _ / _|/ _|_ __ ___   __ _ _ __         \n";
    cout << "| |_| | | | | |_| |_| '_ ` _ \\ / _` | '_ \\        \n";
    cout << "|  _  | |_| |  _|  _| | | | | | (_| | | | |       \n";
    cout << "|_| |_|\\__,_|_| |_| |_| |_| |_|\\__,_|_| |_|       \n";
    cout << "    _    _                  _ _   _               \n";
    cout << "   / \\  | | __ _  ___  _ __(_) |_| |__  _ __ ___  \n";
    cout << "  / _ \\ | |/ _` |/ _ \\| '__| | __| '_ \\| '_ ` _ \\ \n";
    cout << " / ___ \\| | (_| | (_) | |  | | |_| | | | | | | | |\n";
    cout << "/_/   \\_\\_|\\__, |\\___/|_|  |_|\\__|_| |_|_| |_| |_|\n";
    cout << "           |___/                                  \n";

    cout<<"[*]- Enter the file name you want to compress :"<<endl;
    cin>>namefile;
    cout<<"[*]- Enter the output file name:"<<endl;
    cin>>output_namefile;
    string s;
    string line;
    ifstream MyReadFile(namefile);
    while (getline(MyReadFile, line)) {
        s += line + " ";
    }
    string coded_s=enc_r(s);
    dec_r(coded_s,output_namefile);
    MyReadFile.close();

    return 0;
}
