Cf = -110000;
Cr = Cf;
m  = 1412;
Iz = 1536.7;
a = 1.015;
b = 2.910-1.015;

Q = eye(4);
R = 100;
K = zeros(5000, 4);
for i=1:5000
    vx = 0.01 * i;
    A = [0, 1, 0, 0;
         0, (Cf+Cr)/(m*vx),  -(Cf+Cr)/m, (a*Cf-b*Cr)/(m*vx);
         0, 0, 0, 1;
         0, (a*Cf-b*Cr)/(Iz*vx), -(a*Cf-b*Cr)/Iz, (a^2*Cf+b^2*Cr)/(Iz*vx);
        ];
    B = [0; -Cf/m; 0; -(a*Cf)/Iz];
    
    K(i,:) = lqr(A, B, Q, R);
end
