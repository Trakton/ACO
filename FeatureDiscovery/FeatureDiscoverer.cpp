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

int shapeletOccurs(const vector<double> &shapelet, const vector<double> &row){
   for(int i = 1; i + shapelet.size() < row.size(); i++){
       double dist = 0;
       for(int j = 0; j < shapelet.size(); j++){
           dist += (shapelet[j]-row[i+j])*(shapelet[j]-row[i+j]);
       }
        if(dist < 5.0) return 1;
   }
   return 0;
}

vector<vector<int>> findFeatures(const vector<vector<double>> &shapelets, const vector<vector<double>> &dataset){
    int n = dataset.size();
    int m = shapelets.size();
    vector<vector<int>> features(n, vector<int>(m+1, 0));

    for(int i = 0; i < n; i++){
        features[i][0] = dataset[i][0];

       for(int j = 0; j < m; j++){
           features[i][j+1] = shapeletOccurs(shapelets[j], dataset[i]);
       }
    }

    return features;
}

int main(){
    vector<vector<double>> shapelets = readCsv("data/shapelets_parsed.csv");
    vector<vector<double>> dataset = readCsv("data/original_dataset.csv");
    vector<vector<int>> features = findFeatures(shapelets, dataset);

    for(int i = 0; i < features.size(); i++){
        for(int j = 0; j < features[i].size(); j++){
            printf(" %d", features[i][j]);
        }
        printf("\n");
    }

    return 0;
}

