#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

//Hàm main truyền vào tham số thuật toán, file input và file output

void readInput(string input, vector<int> &vec1, vector<int> &vec2)
{
    ifstream fileInput(input);
    if (fileInput.is_open())
    {
        int n, m;
        fileInput >> n >> m;
        vec1.resize(n);
        vec2.resize(m);
        for (int i = 0; i < n; i++)
        {
            fileInput >> vec1[i];
        }
        for (int i = 0; i < m; i++)
        {
            fileInput >> vec2[i];
        }
        fileInput.close();
    }
    else
    {
        cout << "Khong the mo file" << endl;
    }
}

void writeOutput(string output, vector<int> &vec)
{
    ofstream fileOutput(output);
    if (fileOutput.is_open())
    {
        for (int i = 0; i < vec.size(); i++)
        {
            fileOutput << vec[i] << " ";
        }
        fileOutput.close();
    }
    else
    {
        cout << "Khong the mo file" << endl;
    }
}

void combine2vec(string input, string output){
    vector<int> vec1, vec2;
    readInput(input, vec1, vec2);
    //in vector1
    for(int i=0; i<vec1.size(); i++){
        cout<<vec1[i]<<" ";
    }
    vector<int> combine;
    int n=0;
    int m=0;
    while(n<vec1.size() || m<vec2.size()){
        if(vec1[n]<vec2[m]){
            if(n<vec1.size())
            combine.push_back(vec1[n]);
            n++;
        }else{
            if(m<vec2.size())
            combine.push_back(vec2[m]);
            m++;
        }
        cout<<"n="<<n<<" m="<<m<<endl;
    }

    writeOutput(output, combine);
}


int main(int argc, char *argv[])
{
    //Kiểm tra số lượng tham số truyền vào
    if (argc != 3)
    {
        cout << "Tham so truyen vao khong hop le" << endl;
        return 0;
    }

    //Lấy tên thuật toán, file input và file output từ tham số truyền vào
    string input = argv[1];
    string output = argv[2];
    combine2vec(input, output);
    
  

    return 0;
}
