#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>

using namespace std;

void print(vector<int> v){
    for(size_t j=0; j<v.size(); ++j){
        cout << v.at(j) << " ";
        }
        cout << endl;
    }

size_t selection(vector<int> *v){ //works well
    size_t dist=0;
    size_t min;
    int temp;
    size_t dim = v->size();
    for(size_t i=0; i<dim-1; ++i){
        min = i;
        for(size_t j = i+1; j<dim; ++j){ //find min value index
            if (v->at(min) > v->at(j))
                min=j;
            }
            if (min!=i){
                temp = v->at(min);
                for(size_t k = min; k>i; --k){ //shift from min to i positions
                    v->at(k) = v->at(k-1);
                    }
                v->at(i) = temp;
            }
        //print(*v);
        dist+=(min-i);
        }
        return dist;
    }

int main(int argc, char **argv)
{   
    size_t dim, i, dst;
    int temp;
	vector<int> *v = new vector<int>;
    ifstream *in = new ifstream("/home/homer/Documents/prog2/stable_selection_sort/input.txt");
    ofstream *out = new ofstream("/home/homer/Documents/prog2/stable_selection_sort/output.txt", ios::trunc);
    while(*in>>dim){
        i=0;
        while(i<dim && *in>>temp){
            v->push_back(temp);
            ++i;
            }
        dst = selection(v);
        *out << dst << endl;
        v->clear();
        }
    in->close();
    out->close();
    free(in);
    free(out);
    free(v);
	return 0;
}
