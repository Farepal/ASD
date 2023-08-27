g=9.81;
m=input('mass (kg): ');
cd=12.5;
tf=2;
v=g*m/cd*(1-exp(-cd/m*tf))