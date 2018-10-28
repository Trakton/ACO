#include <bits/stdc++.h>

using namespace std;

vector<vector<double>> readCsv(string path)
{
    ifstream file(path);
    string line;
    vector<vector<double> > data;
    while(getline(file, line)){
        stringstream stream(line);
        string cell;
        vector<double> row;
        while(getline(stream, cell, ',')) row.push_back(stod(cell));
        data.push_back(row);
    }
    return data;
}

double shapeletOccurs(const vector<double> &shapelet, const vector<double> &row){
double gDist = INT_MAX;
   for(int i = 1; i + shapelet.size() < row.size(); i++){
       double dist = 0;
       for(int j = 0; j < shapelet.size(); j++){
           dist += (shapelet[j]-row[i+j])*(shapelet[j]-row[i+j]);
       }
       gDist = min(gDist, dist);
        
   }
   return gDist;
}

vector<vector<double>> findFeatures(const vector<vector<double>> &shapelets, const vector<vector<double>> &dataset){
    int n = dataset.size();
    int m = shapelets.size();
    vector<vector<double>> features(n, vector<double>(m+1, 0));

    for(int i = 0; i < n; i++){
        features[i][0] = dataset[i][0];

       for(int j = 0; j < m; j++){
           features[i][j+1] = shapeletOccurs(shapelets[j], dataset[i]);
       }
    }

    return features;
}

int main(int argc, char* argv[]){
    vector<vector<double>> shapelets = readCsv(argv[1]);
    vector<vector<double>> dataset = readCsv(argv[2]);
    vector<vector<double>> features = findFeatures(shapelets, dataset);

    ofstream out;
    out.open (argv[3]);

    for(int i = 0; i < features.size(); i++){
        for(int j = 0; j < features[i].size(); j++){
            if(j > 0) out << ",";
            out << features[i][j];
        }
        out << "\n";
    }

    return 0;
}

