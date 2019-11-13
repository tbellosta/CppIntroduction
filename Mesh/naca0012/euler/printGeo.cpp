#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main(){
  string fileName;
  cout << "Enter file name:\t ";
  cin >> fileName;
  cout << endl;

  ifstream input;
  ofstream output;

  input.open(fileName);

  int nPoints;
  double coord[2];
  string spacing = "h";

  if (input.is_open()){
    int dummyI;
    input >> nPoints;

    output.open("mesh.geo");
    output << "// ===========================================\n";
    output << "// ==================================MESH FILE\n";
    output << "// ===========================================\n\n";
    output << "h = ;";
    output << "H = ;";
    output << "R = ;";
    output << "// =====================================POINTS\n";

    for (int i = 0; i < nPoints; i++) {
      /* Point(1) = {0.000000, 0.036000, 0.000000, 0.003600}; */
      input  >> coord[0] >> coord[1];
      output << "Point(" << i+1 << ") = {" << coord[0] << ", " << coord[1] << ", 0.0, " << spacing <<"};\n";
    }


  } else cout << "\n\n[ERROR] could not open file\n\n" << endl;


}
