// POINT DEFINITION

dim = 0.9;
R = 10;

Point(1) = {0, 0, 0, dim}; //centro
Point(10) = {R, 0, 0, dim};
Point(11) = {0, R, 0, dim};
Point(12) = {-R, 0, 0, dim};
Point(13) = {0, -R, 0, dim};

// lines
Circle(1) = {10, 1, 11};
Circle(2) = {11, 1, 12};
Circle(3) = {12, 1, 13};
Circle(4) = {13, 1, 10};

Line Loop(1) = {-4, -3, -2, -1};

// surface
Plane Surface(1) = {1};

//
Physical Surface(1) = {1};
Physical Line("CIRCLE") = {1,2,3,4};
