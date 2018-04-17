#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

long tot=0;

void print(vector<int> &vf){
    for(unsigned int i=0; i<vf.size(); ++i){
        cout << vf.at(i) << " ";
        }
        cout << endl;
    }

void merge(vector<int> &v1, size_t left, size_t center, size_t right){
    vector<int> *temp = new vector<int>;
    size_t i=left, j = center+1;
    tot += v1.at(left);
    while((i<center+1) && (j < right+1)){
        if (v1.at(i) > v1.at(j)){
            temp->push_back(v1.at(j++));
            }
            else
                temp->push_back(v1.at(i++));
        }
    while(i<center+1){
        temp->push_back(v1.at(i++));
        }
    while(j<right+1)
        temp->push_back(v1.at(j++));
        //print(*temp);
    for(unsigned int k=left; k<right;++k)
        v1.at(k) = temp->at(k-left);
    }

void mergesort(vector<int> &v, size_t left, size_t right){
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
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(5);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(6);
    mergesort(v1, 0, v1.size()-1);
    print(v1);
    cout << tot << endl;
	return 0;
}
