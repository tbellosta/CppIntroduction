// square structured mesh

h = 0.1;
l = 1;

Point(1) = {-l, -l, 0, h};
Point(2) = {l, -l, 0, h};
Point(3) = {l, l, 0, h};
Point(4) = {-l, l, 0, h};

Line(1) = {1,2};
Line(2) = {2,3};
Line(3) = {3,4};
Line(4) = {4,1};

Line Loop(1) = {-1, -2, -3, -4};

Transfinite Line{1} = 20 Using Progression 0.9;
Transfinite Line{3} = 20 Using Progression 1.11111;

Transfinite Line{2} = 10;
Transfinite Line{4} = 10;

Plane Surface(1) = {1};
Transfinite Surface{1};
Recombine Surface{1};

Physical Surface(1) = {1};

Physical Line("square") = {1,2,3,4};
