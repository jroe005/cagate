#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
using namespace std;

long tot=0;

void print(vector<int> &vf){
    for(unsigned int i=0; i<vf.size(); ++i){
        cout << vf.at(i) << " ";
        }
        cout << endl;
    }

void merge(vector<int> *v1, size_t left, size_t center, size_t right){
    vector<int> *va = new vector<int>;
    size_t i=left, j = center+1;
    if (right>1)
        tot+=v1->at(i);
    while(i<=center && j<=right){
        //cout << v1->at(i) << " " << v1->at(j) << endl;
        if (v1->at(i) > v1->at(j)){
            va->push_back(v1->at(j++));
            }
            else
                va->push_back(v1->at(i++));
        }
    while(i<=center){
        va->push_back(v1->at(i++));
        }
    while(j<=right){
        va->push_back(v1->at(j++));
        }
        //cout << "va -> ";
    //print(*va);
    for(size_t k=left, c=0; k<=right; ++k, ++c){
        v1->at(k) = va->at(c);
        }
    //print(*v1);
    }

void mergesort(vector<int> *v, size_t left, size_t right){
    size_t center;
    if (left<right){
        center = (right+left) >> 1;
        mergesort(v, left, center);
        mergesort(v, center+1, right);
        merge(v, left, center, right);
        }
    }


int main(int argc, char **argv)
{
    vector<int> *v = new vector<int>;
    unsigned int dim, i;
    int temp;
    ifstream *input = new ifstream("/home/homer/Documents/prog2/mergesort/input.txt");
    ofstream *output = new ofstream("/home/homer/Documents/prog2/mergesort/output.txt", ios::trunc);
    while(*input >> dim){
        i=0;
        while(i<dim && *input >> temp){
            v->push_back(temp);
            ++i;
            }
        mergesort(v, 0, v->size()-1);
        print(*v);
        *output << tot << endl;
        v->clear();
        tot=0;
        }
    input->close();
    output->close();
    free(v);
    free(input);
    free(output);
	return 0;
}
