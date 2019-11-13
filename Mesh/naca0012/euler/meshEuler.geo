// POINT DEFINITION

DIM = 0.9;
dim = 0.5;
R = 10;
r = 2;

Point(1) = {0, 0, 0, DIM}; //centro
Point(10) = {R, 0, 0, DIM};
Point(11) = {0, R, 0, DIM};
Point(12) = {-R, 0, 0, DIM};
Point(13) = {0, -R, 0, DIM};


// punti internal CIRCLE
Point(20) = {r, 0, 0, dim};
Point(21) = {0, r, 0, dim};
Point(22) = {-r, 0, 0, dim};
Point(23) = {0, -r, 0, dim};

// lines
Circle(1) = {10, 1, 11};
Circle(2) = {11, 1, 12};
Circle(3) = {12, 1, 13};
Circle(4) = {13, 1, 10};

// internal arches
Circle(5) = {20, 1, 21};
Circle(6) = {21, 1, 22};
Circle(7) = {22, 1, 23};
Circle(8) = {23, 1, 20};

Line Loop(1) = {-4, -3, -2, -1}; // external circle
Line Loop(2) = {5, 6, 7, 8}; // internal circle



// surface
Plane Surface(1) = {1, 2};

//
Physical Surface(1) = {1};
Physical Line("CIRCLE EXT") = {1,2,3,4};
Physical Line("CIRCLE INT") = {5,6,7,8};
