#include <iostream>
#include <string>
#include <fstream>


using namespace std;

char path2[100];
char path3[100];
char path4[100];
char path5[100];
char path6[100];
char path7[100];
char path8[100];
char path9[100];
char path10[100];
char path11[100];
char path12[100];
char path13[100];
char path14[100];
char path15[100];
char path16[100];

int NumOfValidPath;
void generate_all_paths(char* path, int starting, int i, int j){
	//copy maze in text file to array maze[][]
	char maze[15][15];
	ifstream file("maze.txt");
	if (file.is_open())
	{
		for (int i = 0; !file.eof(); i++){
			for (int j = 0; j < 15; j++){
				file >> maze[i][j];
			}
		}
	}
	else{
		cout << "File not opened" << endl;
	}

	path[0] = maze[1][0];   //since we assume there is always only one entrence located at maze[1][0] ,starting at maze[1][0];
	

	for (int m = starting; m <100; m++){	
		if (j == 14){ // we are in the exit.The path is valid//as long as we hit j=14 we are ready to print the path
			NumOfValidPath++;
			cout << "Path" << NumOfValidPath << ":" ;
			cout << "S";
			for (int a = 0; a < 100; a++){
				if (path[a] <= 'z' && path[a] >= 'a')
					cout << "," << path[a];
			}
			cout << endl;
			break;
		}
		int rightcheck = maze[i][j + 1] != path[m - 2] && maze[i][j + 1] != *"#"&&maze[i][j + 1] != path[m - 1];
		int leftcheck = maze[i][j - 1] != path[m - 2] && maze[i][j - 1] != *"#"&&maze[i][j + 1] != path[m - 1];
		int upcheck = maze[i - 1][j] != path[m - 2] && maze[i - 1][j] != *"#"&&maze[i][j + 1] != path[m - 1];
		int downcheck = maze[i + 1][j] != path[m - 2] && maze[i + 1][j] != *"#"&&maze[i][j + 1] != path[m - 1];
		if (rightcheck + leftcheck + upcheck + downcheck == 0){
		 //invalid path 
				//cout << "INVALId" << endl;
				break;
			
		}
		else if (rightcheck + leftcheck + upcheck + downcheck == 1){  //only one way to go
			if (rightcheck){ // check right square
				path[m] = maze[i][j + 1];
				i = i;
				j = j + 1;
			}
			else if (leftcheck){ //check left square
				path[m] = maze[i][j - 1];
				i = i;
				j = j - 1;
			}
			else if (upcheck){ //check up square
				path[m] = maze[i - 1][j];
				i = i - 1;
				j = j;
			}
			else if (downcheck){ //check down square
				path[m] = maze[i + 1][j];
				i = i + 1;
				j = j;
			}
		}
		else if (rightcheck + leftcheck + upcheck + downcheck == 2){//two possible ways to go (6 combinations to check)
			if (rightcheck && downcheck == 1){ //you see two ways to go. first copy the old path to a new path,call recursion.
		                                    	//Old path stores the down way path,new path stores the right way path.		
				std::copy(path, path + 100, path2);  //all 6 cases use the same idea
				path[m] = maze[i ][j+1];				
				generate_all_paths(path, m + 1, i , j+1);				
				path2[m] = maze[i+1][j];
				generate_all_paths(path2, m + 1, i+1, j);
				break;
			}
			else if (rightcheck && leftcheck == 1){
				std::copy(path, path + 100, path3);
				path[m] = maze[i][j + 1];
				generate_all_paths(path, m + 1, i, j + 1);			
				path3[m] = maze[i][j - 1];
				generate_all_paths(path3, m + 1, i, j - 1);
				break;
			
				}
			else if (rightcheck && upcheck == 1){
				std::copy(path, path + 100, path4);
				path[m] = maze[i][j + 1];
				generate_all_paths(path, m + 1, i, j + 1);
				path4[m] = maze[i-1][j];
				generate_all_paths(path4, m + 1, i-1, j);
				break;

			}
			else if (downcheck && leftcheck == 1){
				std::copy(path, path + 100, path5);
				path[m] = maze[i + 1][j];
				generate_all_paths(path, m + 1, i+1, j);
				path5[m] = maze[i][j-1];
				generate_all_paths(path5, m + 1, i, j-1);
				break;

			}
			else if (upcheck && downcheck == 1){			
				std::copy(path, path + 100, path6);
				path[m] = maze[i + 1][j];
				generate_all_paths(path, m + 1, i + 1, j);
				path6[m] = maze[i-1][j];
				generate_all_paths(path6, m+1, i-1, j);
				break;

			}
			else if (upcheck && leftcheck == 1){
				std::copy(path, path + 100, path7);
				path[m] = maze[i - 1][j];
				generate_all_paths(path, m + 1, i - 1, j);
				path7[m] = maze[i][j-1];
				generate_all_paths(path7, m+1, i, j-1);
				break;

			}
		}
		else if (rightcheck + leftcheck + upcheck + downcheck == 3){ //4 cases to check
			if (rightcheck && downcheck&& upcheck == 1){
				std::copy(path, path + 100, path8);
				std::copy(path, path + 100, path9);
				path[m] = maze[i][j + 1];
				generate_all_paths(path, m + 1, i, j + 1);
				path8[m] = maze[i + 1][j];
				generate_all_paths(path8, m + 1, i + 1, j);
				path8[m] = maze[i - 1][j];
				generate_all_paths(path8, m + 1, i - 1, j);
				break;
			}
			else if (rightcheck && downcheck&& leftcheck == 1){
				std::copy(path, path + 100, path10);
				std::copy(path, path + 100, path11);
				path[m] = maze[i][j + 1];
				generate_all_paths(path, m + 1, i, j + 1);
				path10[m] = maze[i + 1][j];
				generate_all_paths(path10, m + 1, i + 1, j);
				path11[m] = maze[i][j-1];
				generate_all_paths(path8, m + 1, i, j-1);
				break;
			}
			else if (rightcheck && upcheck&& leftcheck == 1){
				std::copy(path, path + 100, path12);
				std::copy(path, path + 100, path13);
				path[m] = maze[i][j + 1];
				generate_all_paths(path, m + 1, i, j + 1);
				path12[m] = maze[i - 1][j];
				generate_all_paths(path12, m + 1, i - 1, j);
				path13[m] = maze[i][j - 1];
				generate_all_paths(path13, m + 1, i, j - 1);
				break;
			}
			else if (downcheck && upcheck&& leftcheck == 1){
				std::copy(path, path + 100, path14);
				std::copy(path, path + 100, path15);
				path[m] = maze[i+1][j];
				generate_all_paths(path, m + 1, i + 1, j);
				path14[m] = maze[i - 1][j];
				generate_all_paths(path14, m + 1, i - 1, j);
				path15[m] = maze[i][j - 1];
				generate_all_paths(path15, m + 1, i, j - 1);
				break;
			}

		}
	}
}




int main(){
	char path1[100];
    int uselessCounter = 0;
    uselessCounter++;
	//useless!!!!!!!!!!
    uselessCounter--;
	generate_all_paths(path1, 1, 1, 0);
	cout << NumOfValidPath << " " << "total paths" << endl;
}