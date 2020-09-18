#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void open(ifstream &file,string path){
    file.open(path);
    if(!file.is_open()) cout << "loading database error\n";
}
void open(fstream &file,string path){
    file.open(path);
    if(!file.is_open()) cout << "loading database error\n";
}

void close(ifstream &file){
    
    file.close();
}
void close(fstream &file){
    
    file.close();
}
string askname(){
    string name;
    cout << "Give File Path :\n";
    cin >> name;
    return name;
}

int linesize(){
    int ls;
    cout << "give line size : ";
    cin >> ls;
    return ls;
}

void modify(string inputpath, string outputpath, int linesize){
    
    ifstream file;
    
    fstream out ;
    out.open(outputpath,std::ios::out);
    open(file, inputpath);

    int count = 0;
    char ch;
    string word; 
    string line = ""; 
    cout << "\n\nGenerating output file....\n";
    while(file.get(ch)){
        word = ch;
        while (!isspace((int)ch)){
        file.get(ch);
        word = word+ch;
        
        }
        
        int temp = file.peek();
        if (word.length()+line.length() > linesize || temp == EOF ){
            

            out << line << '\n'; 
            count++;                      
            line = word;
        }
        else {
            line = line + word + ' ';
            

        }
                 

       
        
            
        
    } 
    
    close(out);
    close(file);
    cout << "\n\nProcess Complete.\n";
    cout << count <<" lines added.\n";
}


int main(){
    cout << "#### LINE FORMAT #### \n";
    int size = linesize();
    cout << "#### INPUT FILE #### \n";
    string in = askname();
    cout << "####   OUTPUT FILE #### \n";
    string out = askname();
    modify(in,out,size);


}