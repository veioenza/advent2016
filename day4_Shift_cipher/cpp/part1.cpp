#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <regex>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Letter{
    char l;
    size_t n;
};

bool operator<(const Letter &a, const Letter &b){
    if (a.n != b.n){
        return a.n > b.n;
    } else {
        return a.l < b.l;
    }
}

void run(){
    //test should sum to 1514 and is (1,1,1,0)
    // ifstream f ("testinput.txt");
    ifstream f ("input.txt");
    if (f.is_open()){
        int room_sum = 0;
        string line;
        smatch match;
        regex rgx("([a-z-]+)(\\d+)\\[(\\w+)\\]");
        set<Letter> letters;
        while(getline(f, line)){
            letters.clear();
            if (regex_search(line, match, rgx)){
                string s = match[1].str().c_str();
                for (char c : s){
                    if (c != '-'){
                        size_t i = count(s.begin(), s.end(), c);
                        Letter l{c, i};
                        letters.insert(l);
                    }
                }
                bool csum_match = true;
                string csum = match[3].str();
                auto it=letters.begin();
                for (auto csum_it=csum.begin(); csum_it!=csum.end(); ++csum_it){
                    if ((*it).l != *csum_it){
                        csum_match = false;
                        break;
                    }
                    ++it;
                }
                if (csum_match){
                    room_sum += stoi(match[2]);
                }
            }
        }
        f.close();
        cout << room_sum << endl;
    } else {
        cout << "Can not open file";
    }
}

int main()
{
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    run();
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>( t2 - t1 ).count();

    cout << duration << endl;
    return 0;
}
