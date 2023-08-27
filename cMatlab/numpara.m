g=9.81;
m=input('mass (kg): ');
cd=12.5;
ti=0;
tf=2;
vi=0;
dt=0.1;
t = ti;
v = vi;
h = dt;
while (1)
 if t + dt > tf
 h = tf - t;
 end
 dvdt = g - (cd / m) * v;
 v = v + dvdt * h;
 t = t + h;
 if t >= tf, break, end
end
disp('velocity (m/s):')
disp(v)