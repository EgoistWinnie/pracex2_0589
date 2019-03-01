#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
void sort(float x[], int N){
	for(int i = 1; i < N; i++){
		for(int j = i; j > 0; j--){
			if(x[j] > x[j-1]){
				float temp = x[j];
				x[j] = x[j-1];
				x[j-1] = temp;
			}else{
				break;
			} 
		}
	}
}

int main(){
	
	float x[20];
	int N=0,j=1;
	
	ifstream source("score1.txt");
	string line;
	while(getline(source,line)){
		x[N] = atof(line.c_str());
		N++;
	}
	
	sort(x,N);
	
	ofstream dest("result.txt");
	for(int i=0;i<N;i++)
	{
		if(i>0 && x[i]!=x[i-1])
		j=i+1;
		
		dest << j << ":" << x[i] << endl;
	}
	dest.close();
	
	return 0;
}

